#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*** 指针初始化，避免野指针 ***/
    timer = NULL;
    loginwindow = NULL;
    registerwindow = NULL;
    booksearchwidget = NULL;
    bookborrowinfowidget=NULL;
    usermanagementwidget=NULL;
    userdetailwnidow=NULL;
    people=NULL;

    /*** 标题界面UI设计 ***/
    // 标题栏背景
    ui->widget_Title->setAutoFillBackground(true);
    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/images/titleBackground.jpg")));
    ui->widget_Title->setPalette(palette);
    // 登录和注册按钮
    ui->Button_login->setFlat(true);
    ui->Button_register->setFlat(true);
    ui->Button_quitLogin->setFlat(true);
    ui->Button_quitLogin->setDisabled(true);
    ui->Button_quitLogin->hide();
    // label界面更新
    people = new People();
    people->user_Type = People::VISITOR;
    people->user_Name =  "游客";
    people->user_ID="";
    people->user_Password="";
    people->user_canBorrow=false;
    people->booknum=0;

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(SLOT_updatetime()));
    timer->start(500);
    // 登录和注册按钮 信号槽函数
    connect(ui->Button_login, SIGNAL(clicked()), this, SLOT(SLOT_setWindowLogin()));
    connect(ui->Button_register,SIGNAL(clicked()),this,SLOT(SLOT_setWindowRegister()));

    /*** 数据库连接 ***/
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setPort(3306);
    db.setDatabaseName("mydatabase"); // 数据库名
    db.setUserName("root");  // 数据库用户名
    db.setPassword("root");  // 数据库的密码
    if(!db.open())
    {
        QMessageBox::critical(0, QObject::tr("无法打开数据库"), "注意：无法创建数据库连接！", QMessageBox::Yes);
    }

    /*** tabWidget界面UI设计 ***/
    ui->tabWidget->removeTab(1); // 删除控件自带的，注意：需要从大到小删除
    ui->tabWidget->removeTab(0);
    // 默认界面：（图书搜索界面），它在退出整个界面时才删除
    booksearchwidget = new BookSearchWidget();
    ui->tabWidget->addTab(booksearchwidget,"图书搜索");
    connect(booksearchwidget,SIGNAL(Signal_bookquerySearch(BookQuery)),this,SLOT(SLOT_bookquerySearch(BookQuery)));
    connect(this,SIGNAL(Signal_bookqueryResult(QVector<Book>,People*)),booksearchwidget,SLOT(SLOT_bookqueryResult(QVector<Book>,People*)));
    connect(booksearchwidget,SIGNAL(Signal_bookBorrow(QVector<QString>)),this,SLOT(SLOT_bookBorrow(QVector<QString>)));
    connect(this,SIGNAL(Signal_loginQuit()),booksearchwidget,SLOT(SLOT_loginQuit()));
    BookQuery bookquery; bookquerySearch(bookquery,true); //（图书搜索界面），只刷新table显示，默认“所有类型”，注意：只用在初始化时
}

MainWindow::~MainWindow()
{
    delete ui;

    // 防止内存泄漏和野指针
    delete timer;
    timer=NULL;
    delete booksearchwidget;
    booksearchwidget=NULL;
    delete people;
    people=NULL;
    if(bookborrowinfowidget!=NULL)
    {
        delete bookborrowinfowidget;
        bookborrowinfowidget=NULL;
    }
    if(usermanagementwidget!=NULL)
    {
        delete usermanagementwidget;
        usermanagementwidget=NULL;
    }
    if(userdetailwnidow!=NULL)
    {
        delete userdetailwnidow;
        userdetailwnidow=NULL;
    }
}

void MainWindow::SLOT_updatetime()
{
    QDateTime current_date_time = QDateTime::currentDateTime();
    QString current_date = current_date_time.toString("yyyy-MM-dd  hh:mm:ss  ddd");
    QString text = "当前用户: " + people->user_Name + "     当前时间: " + current_date + "  ";
    ui->label_Title->setText(text);
}

void MainWindow::SLOT_setWindowLogin()
{
    //登录时禁用登录和注册按钮
    ui->Button_login->setDisabled(true);
    ui->Button_register->setDisabled(true);

    //显示（登录界面）
    loginwindow = new LoginWindow();
    loginwindow->setWindowTitle("登录");
    loginwindow->show();

    connect(loginwindow,SIGNAL(Signal_loginQuit()),this,SLOT(SLOT_loginQuit()));
    connect(loginwindow,SIGNAL(Signal_login(bool,QVector<QString>)),this,SLOT(SLOT_login(bool,QVector<QString>)));
}

void MainWindow::SLOT_loginQuit()
{
    delete loginwindow; //防止内存泄漏和野指针
    loginwindow=NULL;

    ui->Button_login->setEnabled(true);
    ui->Button_register->setEnabled(true);
}

void MainWindow::SLOT_login(bool isUser,QVector<QString> values)
{
    QSqlQuery query(db);

    if(isUser)
    {
        query.exec("select * from user where id = '"
                        +values.at(0)+"' and password = '"+values.at(1)+"';");
    }
    else
    {
        query.exec("select * from manager where id = '"
                        +values.at(0)+"' and password = '"+values.at(1)+"';");
    }
    if(!query.next()){
        QMessageBox::critical(NULL, "Error", "学号或密码错误，请重新输入", QMessageBox::Yes);
    }
    else
    {
        /*** 登录成功 ***/
        //关闭登录界面
        loginwindow->close();
        // title界面更新显示
        ui->Button_login->setDisabled(true);
        ui->Button_register->setDisabled(true);
        ui->Button_login->hide();
        ui->Button_register->hide();
        ui->Button_quitLogin->setEnabled(true);
        ui->Button_quitLogin->show();

        // 保存用户信息
        people->user_Name=query.value("name").toString();
        people->user_ID=query.value("id").toString();
        people->user_Password=query.value("password").toString(); 
        people->user_Type=isUser?(People::USER):(People::MANAGER); 
        people->user_canBorrow=(people->user_Type == People::USER)?query.value("canBorrow").toBool():false;
        people->booknum=0;//保持为0。管理员登陆后需要使用时，再赋值使用

        emit Signal_loginQuit();// 释放信号，（图书搜索界面）整个界面恢复初始化

        //根据登录的用户类型，新建页面
        if(people->user_Type == People::USER)
        {
            //(借阅情况界面)
            bookborrowinfowidget = new BookBorrowInfoWidget();
            ui->tabWidget->addTab(bookborrowinfowidget,"借阅情况");
            connect(this,SIGNAL(Signal_bookborrowqueryResult(QVector<BorrowBook>,People*)),bookborrowinfowidget,SLOT(SLOT_bookborrowqueryResult(QVector<BorrowBook>,People*)));
            connect(bookborrowinfowidget,SIGNAL(Signal_bookReturn(QVector<QString>)),this,SLOT(SLOT_bookReturn(QVector<QString>)));
            bookborrowqueryUpdate(); //（用户借阅情况界面），更新借阅情况页面，初始化显示
        }
        else if(people->user_Type == People::MANAGER)
        {
            //（用户管理界面）
            usermanagementwidget=new UserManagementWidget();
            ui->tabWidget->addTab(usermanagementwidget,"用户管理");
            connect(this,SIGNAL(Signal_usermanagementResult(QVector<People>)),usermanagementwidget,SLOT(SLOT_usermanagementResult(QVector<People>)));
            connect(usermanagementwidget,SIGNAL(Signal_SearchUserDetailInfo(QString)),this,SLOT(SLOT_SearchUserDetailInfo(QString)));
            connect(this,SIGNAL(Signal_enableButton_SearchUserDetail()),usermanagementwidget,SLOT(SLOT_enableButton_SearchUserDetail()));
            connect(this,SIGNAL(Signal_disableButton_SearchUserDetail()),usermanagementwidget,SLOT(SLOT_disableButton_SearchUserDetail()));
            usermanagementUpdate();//（用户管理界面），更新用户管理结果页面，初始化显示

            //（书籍管理界面）

        }
    }
}

void MainWindow::SLOT_setWindowRegister()
{
    //注册时禁用登录和注册按钮
    ui->Button_login->setDisabled(true);
    ui->Button_register->setDisabled(true);

    //显示（注册界面）
    registerwindow = new RegisterWindow();
    registerwindow->setWindowTitle("注册");
    registerwindow->show();

    connect(registerwindow,SIGNAL(Signal_registerQuit()),this,SLOT(SLOT_registerQuit()));
    connect(registerwindow,SIGNAL(Signal_register(QVector<QString>)),this,SLOT(SLOT_register(QVector<QString>)));
}

void MainWindow::SLOT_registerQuit()
{
    delete registerwindow; //防止内存泄漏和野指针
    registerwindow=NULL;

    ui->Button_login->setEnabled(true);
    ui->Button_register->setEnabled(true);
}

void MainWindow::SLOT_register(QVector<QString> values)
{
    QSqlQuery query(db);
    query.exec("select * from user where id = '"
                    +values.at(0)+"';");
    if(query.next())
    {
        QMessageBox::critical(NULL, "Error", "这个学号已经被注册，请重新确认", QMessageBox::Yes);
    }
    else
    {
        QString queryCommand="insert into user (id , name, password, canBorrow) values('" +
                values.at(0) + "','" + values.at(1) + "','" + values.at(2) + "',false);";
        query.exec(queryCommand);

        QMessageBox::information(NULL, "Info", "id为" + values.at(0) + "的普通用户注册成功", QMessageBox::Yes);

        registerwindow->close();
    }
}

void MainWindow::on_Button_quitLogin_clicked()
{
    int user_Type_Old=people->user_Type;
    ui->Button_quitLogin->hide();
    ui->Button_login->setEnabled(true);
    ui->Button_register->setEnabled(true);
    ui->Button_login->show();
    ui->Button_register->show();

    people = new People();
    people->user_Type = People::VISITOR;
    people->user_Name =  "游客";
    people->user_ID="";
    people->user_Password="";
    people->user_canBorrow=false;
    people->booknum=0;

    emit Signal_loginQuit();// 释放信号，（图书搜索界面）整个界面恢复初始化

    // 退出后，根据用户类型删除界面
    if(user_Type_Old == People::USER)
    {
        // 删除 （借阅情况界面）
        delete bookborrowinfowidget;
        bookborrowinfowidget=NULL;
        ui->tabWidget->removeTab(1);
    }
    else if(user_Type_Old == People::MANAGER)
    {
        // 删除 （用户管理界面）
        delete usermanagementwidget;
        usermanagementwidget=NULL;
        ui->tabWidget->removeTab(1);

        // 判断 (用户详细信息界面） 是否存在，存在则关闭
        if(userdetailwnidow!=NULL)
        {
            userdetailwnidow->close();
        }
        // 删除 （书籍管理界面）


    }
}

void MainWindow::SLOT_bookquerySearch(BookQuery bookquery)
{
    bookquerySearch(bookquery, false);
}

void MainWindow::bookquerySearch(BookQuery bookquery, bool recover)
{
    QSqlQuery query(db);
    QString queryCommand;
    int flag_firstsatisfy=0;
    // 构建数据库命令
    if(recover == true)
    {
        queryCommand="select * from book;";
    }
    else
    {
        queryCommand="select * from book";
        if(!(bookquery.book_id == "" && bookquery.name == "" && bookquery.author_name == "" &&
            bookquery.begin_year == 0 && bookquery.end_year == 0 && bookquery.publisher =="" &&
            bookquery.low_price == 0 && bookquery.high_price == 0 && bookquery.have_stock == false &&
            bookquery.type == "所有类型"))
        { // 需要筛选
            queryCommand += " where ";

            if(bookquery.book_id != "")
            {
                queryCommand += "book_id='"+bookquery.book_id+"'";
                flag_firstsatisfy = 1;
            }
            if(bookquery.name != "")
            {
                if(flag_firstsatisfy == 0)
                {
                    flag_firstsatisfy=1;
                }
                else
                {
                    queryCommand += " and ";
                }
                queryCommand += "name='"+bookquery.name+"'";
            }
            if(bookquery.author_name != "")
            {
                if(flag_firstsatisfy == 0)
                {
                    flag_firstsatisfy=1;
                }
                else
                {
                    queryCommand += " and ";
                }
                queryCommand += "author_name='"+bookquery.author_name+"'";
            }
            if(!(bookquery.begin_year == 0 && bookquery.end_year == 0))
            {
                if(flag_firstsatisfy == 0)
                {
                    flag_firstsatisfy=1;
                }
                else
                {
                    queryCommand += " and ";
                }
                queryCommand += "publish_year>="+QString::number(bookquery.begin_year,10)+
                                " and publish_year<="+QString::number(bookquery.end_year,10);
            }
            if(bookquery.publisher !="")
            {
                if(flag_firstsatisfy == 0)
                {
                    flag_firstsatisfy=1;
                }
                else
                {
                    queryCommand += " and ";
                }
                queryCommand += "publisher='"+bookquery.publisher+"'";
            }
            if(!(bookquery.low_price == 0 && bookquery.high_price == 0))
            {
                if(flag_firstsatisfy == 0)
                {
                    flag_firstsatisfy=1;
                }
                else
                {
                    queryCommand += " and ";
                }
                queryCommand += "price>="+QString::number(bookquery.low_price,'f',2)+
                                " and price<="+QString::number(bookquery.high_price,'f',2);
            }
            if(bookquery.have_stock != false)
            {
                if(flag_firstsatisfy == 0)
                {
                    flag_firstsatisfy=1;
                }
                else
                {
                    queryCommand += " and ";
                }
                queryCommand += "stock!=0";
            }
            if(bookquery.type != "所有类型")
            {
                if(flag_firstsatisfy == 0)
                {
                    flag_firstsatisfy=1;
                }
                else
                {
                    queryCommand += " and ";
                }
                queryCommand += "type='"+bookquery.type+"'";
            }
        }
        queryCommand+=";";
    }
    //执行数据库命令
    query.exec(queryCommand);

    //存储搜索结果
    QVector<Book> Catalog;
    Book book;
    while(query.next())
    {
        book.book_id=query.value("book_id").toString();
        book.name=query.value("name").toString();
        book.author_name=query.value("author_name").toString();
        book.price=query.value("price").toDouble();
        book.num=query.value("num").toInt();
        book.stock=query.value("stock").toInt();
        book.publisher=query.value("publisher").toString();
        book.publish_year=query.value("publish_year").toString();
        book.type=query.value("type").toString();
        Catalog.append(book);
    }
    //返回搜索结果
    emit Signal_bookqueryResult(Catalog,people);
}

void MainWindow::bookborrowqueryUpdate()
{
    QSqlQuery query(db);
    QString queryCommand;
    if(people->user_Type == People::USER)
    {
        queryCommand="select * from borrow where user_id='" + people->user_ID +"';";
        query.exec(queryCommand);

        QVector<BorrowBook> Catalog;
        BorrowBook borrowbook;
        while(query.next())
        {
            borrowbook.userID=query.value("user_id").toString();
            borrowbook.book.book_id=query.value("book_id").toString();
            borrowbook.dateBorrow=query.value("borrow_date").toString();
            borrowbook.dateReturn=query.value("return_date").toString();
            Catalog.append(borrowbook);
        }

        for(int i=0;i<Catalog.size();i++)
        {//继续完善Catalog
            queryCommand="select * from book where book_id='" + Catalog[i].book.book_id +"';";
            query.exec(queryCommand);
            if(query.next())
            {
                Catalog[i].book.name=query.value("name").toString();
                Catalog[i].book.author_name=query.value("author_name").toString();
                Catalog[i].book.price=query.value("price").toDouble();
                Catalog[i].book.num=query.value("num").toInt();
                Catalog[i].book.stock=query.value("stock").toInt();
                Catalog[i].book.publisher=query.value("publisher").toString();
                Catalog[i].book.publish_year=query.value("publish_year").toString();
                Catalog[i].book.type=query.value("type").toString();
            }
        }
        emit Signal_bookborrowqueryResult(Catalog,people);
    }
}

void MainWindow::usermanagementUpdate()
{
    QSqlQuery query(db);
    QSqlQuery query0(db);

    QString queryCommand;
    if(people->user_Type == People::MANAGER)
    {
        queryCommand="select * from user;";
        query.exec(queryCommand);

        QVector<People> Catalog;
        People user;

        while(query.next())
        {
            user.user_Name=query.value("name").toString();
            user.user_ID=query.value("id").toString();
            user.user_Password=query.value("password").toString();
            user.user_Type=People::USER;
            user.user_canBorrow=query.value("canBorrow").toBool();
            //获取借阅数
            queryCommand="select * from borrow where user_id='"+user.user_ID+"';";
            query0.exec(queryCommand);
            user.booknum=query0.size();
            Catalog.append(user);
        }

        emit Signal_usermanagementResult(Catalog);
    }
}

void MainWindow::SLOT_bookBorrow(QVector<QString> bookborrow)
{
    int sucessNum=0,errorNum=0;
    int borrowNum=bookborrow.size();
    QSqlQuery query(db);
    QString queryCommand;

    QDate dateBorrow = QDate::currentDate();//.toString("yyyy-MM-dd")
    QDate dateReturn = dateBorrow.addDays(+30);//默认借30天,此外，获取剩余时间的方法：dateBorrow.daysTo(dateReturn);

    if(borrowNum>0)
    {
        if(people->user_canBorrow==true)
        {
            for (int i = 0; i < borrowNum; i++)
            {
                queryCommand="insert into borrow (user_id, book_id, borrow_date, return_date) value ('"+
                        people->user_ID+"', '"+bookborrow[i]+"', '"+dateBorrow.toString("yyyy-MM-dd")+"', '"+
                        dateReturn.toString("yyyy-MM-dd")+"');";
                if(query.exec(queryCommand) == true)
                {
                    //更新book中的剩余量
                    queryCommand="select stock from book where book_id='"+bookborrow[i]+"';";
                    query.exec(queryCommand);
                    if(query.next())
                    {
                        int stock=query.value("stock").toInt();
                        stock-=1;
                        queryCommand="update book set stock="+QString::number(stock,10)+" where book_id='"+bookborrow[i]+"';";
                        if(query.exec(queryCommand))
                        {
                            sucessNum++;
                        }
                        else
                        {
                            errorNum++;
                        }
                    }
                    else
                    {
                       errorNum++;
                    }
                }
                else
                {
                    errorNum++;
                }
            }
            QMessageBox::information(NULL, "Info", "您借阅成功"+QString::number(sucessNum,10)+"本，借阅失败"+QString::number(errorNum,10)+"本", QMessageBox::Yes);
            //借书后，更新图书检索页面
            emit Signal_loginQuit();// 释放信号，（图书搜索界面）整个界面恢复初始化
            //借书后，更新借阅情况页面
            bookborrowqueryUpdate();
        }
        else
        {
            QMessageBox::critical(NULL, "Info", "您没有借书权限，请联系管理员开启", QMessageBox::Yes);
        }
    }
    else
    {
        QMessageBox::critical(NULL, "Info", "您尚未选择任何书籍", QMessageBox::Yes);
    }
}

void MainWindow::SLOT_bookReturn(QVector<QString> bookreturn)
{
    int sucessNum=0,errorNum=0;
    int returnNum=bookreturn.size();
    QSqlQuery query(db);

    if(returnNum>0)
    {
        for (int i = 0; i < returnNum; i++)
        {
            QString queryCommand="delete from borrow where user_id='"+people->user_ID+"' and book_id='"+
                                 bookreturn[i]+"';";
            if(query.exec(queryCommand) == true)
            {
                //更新book中的剩余量
                queryCommand="select stock from book where book_id='"+bookreturn[i]+"';";
                query.exec(queryCommand);
                if(query.next())
                {
                    int stock=query.value("stock").toInt();
                    stock+=1;
                    queryCommand="update book set stock="+QString::number(stock,10)+" where book_id='"+bookreturn[i]+"';";
                    if(query.exec(queryCommand))
                    {
                        sucessNum++;
                    }
                    else
                    {
                        errorNum++;
                    }
                }
                else
                {
                   errorNum++;
                }
            }
            else
            {
                errorNum++;
            }
        }
        QMessageBox::information(NULL, "Info", "您归还成功"+QString::number(sucessNum,10)+"本，归还失败"+QString::number(errorNum,10)+"本", QMessageBox::Yes);
    }
    else
    {
        QMessageBox::critical(NULL, "Error", "您尚未选择任何书籍", QMessageBox::Yes);
    }

    //还书后，更新图书检索页面
    emit Signal_loginQuit();// 释放信号，（图书搜索界面）整个界面恢复初始化
    //还书后，更新借阅情况页面
    bookborrowqueryUpdate();
}

void MainWindow::SLOT_SearchUserDetailInfo(QString userID)
{   
    //查询信息
    QSqlQuery query(db);
    QSqlQuery query0(db);
    QString queryCommand;
    UserDetial userdetial;
    BorrowBook borrowbook;

    if(people->user_Type == People::MANAGER)
    {
        queryCommand="select * from user where id='"+userID+"';";
        query.exec(queryCommand);
        if(query.next())
        {
            //(用户详细信息界面)，显示出来
            userdetailwnidow = new UserDetailWindow();
            userdetailwnidow->setWindowTitle("用户详细信息");
            userdetailwnidow->show();
            connect(this,SIGNAL(Signal_SearchUserDetailUpdate(UserDetial)),userdetailwnidow,SLOT(SLOT_SearchUserDetailUpdate(UserDetial)));
            connect(userdetailwnidow,SIGNAL(Signal_userdetailwindowClosed()),this,SLOT(SLOT_userdetailwindowClosed()));

            userdetial.user.user_Name=query.value("name").toString();
            userdetial.user.user_ID=query.value("id").toString();
            userdetial.user.user_Password=query.value("password").toString();
            userdetial.user.user_canBorrow=query.value("canBorrow").toBool();
            //获取借阅数
            queryCommand="select book_id from borrow where user_id='"+userdetial.user.user_ID+"';";
            query.exec(queryCommand);
            userdetial.user.booknum=query.size();

            //继续查询借阅书本信息
            while(query.next())
            {
                borrowbook.book.book_id = query.value("book_id").toString();

                queryCommand="select * from book where book_id='" + borrowbook.book.book_id +"';";
                query0.exec(queryCommand);
                if(query0.next())
                {
                    borrowbook.book.name=query0.value("name").toString();
                }

                queryCommand="select * from borrow where user_id='" + userdetial.user.user_ID +
                             "' and book_id='"+borrowbook.book.book_id+"';";
                query0.exec(queryCommand);
                if(query0.next())
                {
                    borrowbook.dateBorrow=query0.value("borrow_date").toString();
                    borrowbook.dateReturn=query0.value("return_date").toString();
                }
                userdetial.borrowbook.append(borrowbook);
            }

            emit Signal_SearchUserDetailUpdate(userdetial);
            emit Signal_disableButton_SearchUserDetail();
        }
        else
        {
            QMessageBox::critical(NULL, "Error", "查询失败，可能没有该用户", QMessageBox::Yes);
        }
    }
}

void MainWindow::SLOT_userdetailwindowClosed()
{
    delete userdetailwnidow; //防止内存泄漏和野指针
    userdetailwnidow=NULL;
    emit Signal_enableButton_SearchUserDetail();
}
