#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /********** 类中变量初始化（主要针对指针） **********/
    loginwindow = NULL;
    registerwindow = NULL;
    userdetailwindow=NULL;
    bookdetailwindow=NULL;
    addbookwindow = NULL;

    booksearchwidget = NULL;
    bookborrowinfowidget=NULL;
    usermanagementwidget=NULL;
    bookmanagementwidget=NULL;

    people=NULL;
    timer = NULL;

    /********** 标题界面部分 **********/
    // 标题界面背景
    ui->widget_Title->setAutoFillBackground(true);
    QPalette palette;
    palette.setBrush(QPalette::Background, QBrush(QPixmap(":/images/titleBackground.jpg")));
    ui->widget_Title->setPalette(palette);
    // 配置标题界面中的按钮：登录、注册、退出登录
    ui->Button_login->setFlat(true);
    ui->Button_register->setFlat(true);
    ui->Button_quitLogin->setFlat(true);

    ui->Button_quitLogin->setDisabled(true); // 默认 退出登录按钮 隐藏
    ui->Button_quitLogin->hide();
    // 标题界面中的label更新（根据people的值，在timer中定时更新）
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

    /********** 连接数据库 **********/
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setPort(3306);
    db.setDatabaseName("mydatabase"); // 数据库名
    db.setUserName("root");  // 数据库用户名
    db.setPassword("root");  // 数据库的密码
    if(!db.open())
    {
        QMessageBox::critical(NULL, "Error", "注意：无法创建数据库连接！", QMessageBox::Yes);
    }

    /********** tabWidget界面部分 **********/
    // 删除UI控件自带的页面，注意：需要从大到小删除
    ui->tabWidget->removeTab(1);
    ui->tabWidget->removeTab(0);

    // 初始时，默认使用者为 游客 ，所以tabWidget只添加并显示 图书搜索页面
    booksearchwidgetCreate(); // 新建
    bookquerySearchUpdate(); // 刷新显示，默认“所有类型”
    ui->tabWidget->addTab(booksearchwidget,"图书搜索");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SLOT_updatetime()
{
    QDateTime current_date_time = QDateTime::currentDateTime();
    QString current_date = current_date_time.toString("yyyy-MM-dd  hh:mm:ss  ddd");
    QString text = "当前用户: " + people->user_Name + "     当前时间: " + current_date + "  ";
    ui->label_Title->setText(text);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    // 防止内存泄漏和野指针
    delete timer;
    timer=NULL;
    delete people;
    people=NULL;

    //window 自动清理
    if(loginwindow!=NULL)
    {
        loginwindow->close();
    }
    if(registerwindow!=NULL)
    {
        registerwindow->close();
    }
    if(userdetailwindow!=NULL)
    {
        userdetailwindow->close();
    }
    if(bookdetailwindow!=NULL)
    {
        bookdetailwindow->close();
    }
    if(addbookwindow!=NULL)
    {
        addbookwindow->close();
    }

    // widget手动清除内存
    if(booksearchwidget!=NULL)
    {
        delete booksearchwidget;
        booksearchwidget=NULL;
    }
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
    if(bookmanagementwidget!=NULL)
    {
        delete bookmanagementwidget;
        bookmanagementwidget=NULL;
    }
}


/****************************************************************************/
/******************************** 登录、注册界面相关 ********************************/
/****************************************************************************/
void MainWindow::on_Button_login_clicked()
{
    // 登录时，登录和注册按钮失能
    ui->Button_login->setDisabled(true);
    ui->Button_register->setDisabled(true);

    // 登录界面 新建与显示
    loginwindowCreateAndShow();
}

void MainWindow::SLOT_loginQuit()
{
    delete loginwindow; // 防止内存泄漏和野指针
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
    { //登录成功
        //关闭登录界面
        loginwindow->close();
        /*** 标题界面部分 ***/
        // 配置标题界面中的按钮：登录、注册、退出登录
        ui->Button_login->setDisabled(true);
        ui->Button_login->hide();
        ui->Button_register->setDisabled(true);
        ui->Button_register->hide();
        ui->Button_quitLogin->setEnabled(true);
        ui->Button_quitLogin->show();

        // 保存用户信息
        people->user_Name=query.value("name").toString();
        people->user_ID=query.value("id").toString();
        people->user_Password=query.value("password").toString();
        people->user_Type=isUser?(People::USER):(People::MANAGER);
        people->user_canBorrow=(people->user_Type == People::USER)?query.value("canBorrow").toBool():false;
        people->booknum=0;//保持为0。当管理员登陆后需要使用时，再赋值使用

        /*** 页面以及界面处理 ***/
        if(people->user_Type == People::USER)
        {
            // (图书搜索页面) 恢复初始化
            emit Signal_booksearchwidgetClearAndUpdate();

            //(借阅情况页面) 新建并显示
            bookborrowinfowidgetCreate(); // 新建
            bookborrowqueryUpdate(); // 初始化显示
            ui->tabWidget->addTab(bookborrowinfowidget,"借阅情况");
        }
        else if(people->user_Type == People::MANAGER)
        {
            // (图书搜索页面) 删除
            if(booksearchwidget!=NULL)
            {
                delete booksearchwidget;
                booksearchwidget=NULL;
                ui->tabWidget->removeTab(0);
            }

            //（用户管理页面）新建并显示
            usermanagementwidgetCreate();
            usermanagementUpdate();//（用户管理界面）更新，初始化显示
            ui->tabWidget->addTab(usermanagementwidget,"用户管理");

            //（书籍管理页面）新建并显示
            bookmanagementwidgetCreate();
            bookmanagementUpdate();//（书籍管理界面）更新，初始化显示
            ui->tabWidget->addTab(bookmanagementwidget,"书籍管理");
        }
    }
}

void MainWindow::on_Button_register_clicked()
{
    if(people->user_Type == People::VISITOR)
    {
        // （游客）注册时，登录和注册按钮失能
        ui->Button_login->setDisabled(true);
        ui->Button_register->setDisabled(true);
    }

    // 注册界面 新建与显示
    registerwindowCreateAndShow();
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

    if(people->user_Type == People::MANAGER)
    {
        // 管理员注册用户后，更新（用户管理界面）
        usermanagementUpdate();
    }
}

void MainWindow::on_Button_quitLogin_clicked()
{
    int user_Type_Old=people->user_Type; // 保存退出前的用户性质

    // people值恢复成默认值
    people->user_Type = People::VISITOR;
    people->user_Name =  "游客";
    people->user_ID="";
    people->user_Password="";
    people->user_canBorrow=false;
    people->booknum=0;

    // 按钮配置：(退出登录) 隐藏， (注册)、(登录) 显示
    ui->Button_quitLogin->hide();
    ui->Button_login->setEnabled(true);
    ui->Button_login->show();
    ui->Button_register->setEnabled(true);
    ui->Button_register->show();

    /*** 页面以及界面处理 ***/
    if(user_Type_Old == People::USER)
    {
        // (借阅情况页面) 删除
        delete bookborrowinfowidget;
        bookborrowinfowidget=NULL;
        ui->tabWidget->removeTab(1);

        // (图书搜索页面) 删除(需要调用析构函数来删除表中checkbox)
        delete booksearchwidget;
        booksearchwidget=NULL;
        ui->tabWidget->removeTab(0);

    }
    else if(user_Type_Old == People::MANAGER)
    {
        // (书籍管理页面) 删除
        delete bookmanagementwidget;
        bookmanagementwidget = NULL;
        ui->tabWidget->removeTab(1);
        // 书籍管理页面 的 弹窗 (书籍详细信息界面) 如果未关闭则关闭
        if(bookdetailwindow!=NULL)// 判断 (书籍详细信息界面） 是否存在，存在则关闭
        {
            bookdetailwindow->close();//自动清理
        }

        // (用户管理页面) 删除
        delete usermanagementwidget;
        usermanagementwidget=NULL;
        ui->tabWidget->removeTab(0);
        // 用户管理页面 的 弹窗 (用户详细信息界面) 如果未关闭则关闭
        if(userdetailwindow!=NULL)// 判断 (用户详细信息界面） 是否存在，存在则关闭
        {
            userdetailwindow->close(); // 已经定义相关槽函数，会自动清理
        }
    }
    // （图书搜索页面）新建
    booksearchwidgetCreate(); // 新建
    bookquerySearchUpdate(); // 刷新显示，默认“所有类型”
    ui->tabWidget->addTab(booksearchwidget,"图书搜索");
}

void MainWindow::loginwindowCreateAndShow()
{
    loginwindow = new LoginWindow();
    loginwindow->setWindowTitle("登录");
    loginwindow->show();
    connect(loginwindow,SIGNAL(Signal_loginQuit()),this,SLOT(SLOT_loginQuit()));
    connect(loginwindow,SIGNAL(Signal_login(bool,QVector<QString>)),this,SLOT(SLOT_login(bool,QVector<QString>)));
}

void MainWindow::registerwindowCreateAndShow()
{
    registerwindow = new RegisterWindow();
    registerwindow->setWindowTitle("注册");
    registerwindow->show();
    connect(registerwindow,SIGNAL(Signal_registerQuit()),this,SLOT(SLOT_registerQuit()));
    connect(registerwindow,SIGNAL(Signal_register(QVector<QString>)),this,SLOT(SLOT_register(QVector<QString>)));
}

/****************************************************************************/
/******************************** 图书搜索页面相关 ********************************/
/****************************************************************************/
void MainWindow::booksearchwidgetCreate()
{
    booksearchwidget = new BookSearchWidget();

    connect(booksearchwidget,SIGNAL(Signal_bookquerySearch(BookQuery)),this,SLOT(SLOT_bookquerySearch(BookQuery)));
    connect(this,SIGNAL(Signal_bookqueryResult(QVector<Book>,People*)),booksearchwidget,SLOT(SLOT_bookqueryResult(QVector<Book>,People*)));
    connect(booksearchwidget,SIGNAL(Signal_bookBorrow(QVector<QString>)),this,SLOT(SLOT_bookBorrow(QVector<QString>)));
    connect(this,SIGNAL(Signal_booksearchwidgetClearAndUpdate()),booksearchwidget,SLOT(SLOT_booksearchwidgetClearAndUpdate()));
}

void MainWindow::SLOT_bookquerySearch(BookQuery bookquery)
{
    bookquerySearchUpdate(bookquery);
}

void MainWindow::bookquerySearchUpdate(BookQuery bookquery)
{
    QVector<Book> Catalog = booksData(bookquery, false);
    emit Signal_bookqueryResult(Catalog, people); //返回搜索结果
}

void MainWindow::bookquerySearchUpdate()
{
    BookQuery bookquery;
    QVector<Book> Catalog = booksData(bookquery, true);
    emit Signal_bookqueryResult(Catalog, people); //返回搜索结果
}

QVector<Book> MainWindow::booksData(BookQuery bookquery, bool recover)
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
    return Catalog;
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
            emit Signal_booksearchwidgetClearAndUpdate();
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

/****************************************************************************/
/******************************** 借阅情况页面相关 ********************************/
/****************************************************************************/
void MainWindow::bookborrowinfowidgetCreate()
{
    bookborrowinfowidget = new BookBorrowInfoWidget();
    connect(this,SIGNAL(Signal_bookborrowqueryResult(QVector<BorrowBook>,People*)),bookborrowinfowidget,SLOT(SLOT_bookborrowqueryResult(QVector<BorrowBook>,People*)));
    connect(bookborrowinfowidget,SIGNAL(Signal_bookReturn(QVector<QString>)),this,SLOT(SLOT_bookReturn(QVector<QString>)));
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
    emit Signal_booksearchwidgetClearAndUpdate();// 释放信号，（图书搜索界面）整个界面恢复初始化
    //还书后，更新借阅情况页面
    bookborrowqueryUpdate();
}

/****************************************************************************/
/******************************** 用户管理页面相关 ********************************/
/****************************************************************************/
void MainWindow::usermanagementwidgetCreate()
{
    usermanagementwidget=new UserManagementWidget();
    connect(this,SIGNAL(Signal_usermanagementResult(QVector<People>)),usermanagementwidget,SLOT(SLOT_usermanagementResult(QVector<People>)));
    connect(usermanagementwidget,SIGNAL(Signal_SearchUserDetailInfo(QString)),this,SLOT(SLOT_SearchUserDetailInfo(QString)));
    connect(this,SIGNAL(Signal_enableButton_SearchUserDetail()),usermanagementwidget,SLOT(SLOT_enableButton_SearchUserDetail()));
    connect(this,SIGNAL(Signal_disableButton_SearchUserDetail()),usermanagementwidget,SLOT(SLOT_disableButton_SearchUserDetail()));
    connect(usermanagementwidget,SIGNAL(Signal_changeUserPri(QVector<QString>)),this,SLOT(SLOT_changeUserPri(QVector<QString>)));
    connect(usermanagementwidget,SIGNAL(Signal_deleteUser(QVector<QString>)),this,SLOT(SLOT_deleteUser(QVector<QString>)));
    connect(usermanagementwidget,SIGNAL(Signal_addUser()),this,SLOT(on_Button_register_clicked()));
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

void MainWindow::SLOT_userdetailwindowClosed()
{
    userdetailwindowClosed();
}

void MainWindow::userdetailwindowClosed()
{
    userdetailwindow->close();
    delete userdetailwindow; //防止内存泄漏和野指针
    userdetailwindow=NULL;
    emit Signal_enableButton_SearchUserDetail();
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
            userdetailwindow = new UserDetailWindow();
            userdetailwindow->setWindowTitle("用户详细信息");
            userdetailwindow->show();

            connect(userdetailwindow,SIGNAL(Signal_userdetailwindowClosed()),this,SLOT(SLOT_userdetailwindowClosed()));
            connect(this,SIGNAL(Signal_SearchUserDetailUpdate(UserDetial)),userdetailwindow,SLOT(SLOT_SearchUserDetailUpdate(UserDetial)));
            connect(userdetailwindow,SIGNAL(Signal_changeUserInfo(UserDetial)),this,SLOT(SLOT_changeUserInfo(UserDetial)));
            connect(this,SIGNAL(Signal_OnlyUserDetailUpdate(UserDetial)),userdetailwindow,SLOT(SLOT_OnlyUserDetailUpdate(UserDetial)));
            connect(userdetailwindow,SIGNAL(Signal_deleteUser(UserDetial)),this,SLOT(SLOT_deleteUser(UserDetial)));

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

void MainWindow::SLOT_changeUserInfo(UserDetial userdetialOld)
{
    QSqlQuery query(db);
    QString queryCommand;
    if(people->user_Type == People::MANAGER)
    {
        //更新数据库
        queryCommand = QString("update user set name='%1', password='%2', canBorrow=%3 where id='%4';").arg(userdetialOld.user.user_Name, userdetialOld.user.user_Password,userdetialOld.user.user_canBorrow?"true":"false", userdetialOld.user.user_ID);
        query.exec(queryCommand);

        //从数据中读取新的值
        queryCommand = QString("select name,password,canBorrow from user where id='%1';").arg(userdetialOld.user.user_ID);
        query.exec(queryCommand);

        if(query.next())
        {
            userdetialOld.user.user_Name=query.value("name").toString();
            userdetialOld.user.user_Password=query.value("password").toString();
            userdetialOld.user.user_canBorrow=query.value("canBorrow").toBool();

            emit Signal_OnlyUserDetailUpdate(userdetialOld);
            usermanagementUpdate();
            if(bookdetailwindow!=NULL)
            {
                bookdetailwindow->close();
            }
            QMessageBox::information(NULL, "Info", "用户信息已更新", QMessageBox::Yes);
        }
    }
}

void MainWindow::SLOT_deleteUser(UserDetial userdetialNow)
{
    QSqlQuery query(db);
    QString queryCommand;
    if(people->user_Type == People::MANAGER)
    {
        //删除用户需要用户借阅数量为0
        queryCommand="select * from borrow where user_id='"+userdetialNow.user.user_ID+"';";
        query.exec(queryCommand);
        if(query.size()!=0)
        {
            QMessageBox::critical(NULL, "Error", "用户有借阅，不能删除", QMessageBox::Yes);
        }
        else
        {
            queryCommand = QString("delete from user where id='%1';").arg(userdetialNow.user.user_ID);
            query.exec(queryCommand);

            userdetailwindowClosed();
            usermanagementUpdate();
            QMessageBox::information(NULL, "Info", "用户删除成功", QMessageBox::Yes);
        }
    }
}

void MainWindow::SLOT_changeUserPri(QVector<QString> changepriuser)
{
    int changeNum=changepriuser.size();
    QSqlQuery query(db);
    QString queryCommand;
    bool changeuserPri=false;

    if(changeNum > 0)
    {
        for (int i = 0; i < changeNum; i++)
        {
            queryCommand = QString("select canBorrow from user where id='%1';").arg(changepriuser[i]);
            query.exec(queryCommand);
            if(query.next())
            {
                changeuserPri=query.value("canBorrow").toBool();
            }
            queryCommand = QString("update user set canBorrow=%1 where id='%2';").arg(changeuserPri?"false":"true", changepriuser[i]);
            query.exec(queryCommand);
        }
    }
    else
    {
        QMessageBox::critical(NULL, "Error", "请正确选择需要修改的用户", QMessageBox::Yes);
    }

    //更改后，判断是否有打开了(用户详细信息界面)。若打开则关闭
    if(userdetailwindow!=NULL)
    {
        userdetailwindow->close();
        delete userdetailwindow;
        userdetailwindow=NULL;
    }
    // 更改后，更新（用户管理界面）
    usermanagementUpdate();
}

void MainWindow::SLOT_deleteUser(QVector<QString> deleteuser)
{
    int sucessNum=0;
    int deleteNum=deleteuser.size();
    QSqlQuery query(db);
    QString queryCommand;

    if(deleteNum > 0)
    {
        for (int i = 0; i < deleteNum; i++)
        {
            queryCommand = QString("delete from user where id='%1';").arg(deleteuser[i]);
            if(query.exec(queryCommand) == true)
            {
                sucessNum++;
            }
        }
        if(sucessNum > 0)
        {
            QMessageBox::information(NULL, "Info", "成功删除"+QString::number(sucessNum,10)+"名用户", QMessageBox::Yes);
        }
    }
    else
    {
        QMessageBox::critical(NULL, "Error", "请正确选择需要修改的用户", QMessageBox::Yes);
    }

    //更改后，判断是否有打开了(用户详细信息界面)。若打开则关闭
    if(userdetailwindow!=NULL)
    {
        userdetailwindow->close();
        delete userdetailwindow;
        userdetailwindow=NULL;
    }

    // 更改后，更新（用户管理界面）
    usermanagementUpdate();
}

/****************************************************************************/
/******************************** 书籍管理页面相关 ********************************/
/****************************************************************************/
void MainWindow::bookmanagementwidgetCreate()
{
    bookmanagementwidget = new BookManagementWidget();
    connect(this,SIGNAL(Signal_bookmanagementResult(QVector<Book>)),bookmanagementwidget,SLOT(SLOT_bookmanagementResult(QVector<Book>)));
    connect(bookmanagementwidget,SIGNAL(Signal_SearchBookDetailInfo(QString)),this,SLOT(SLOT_SearchBookDetailInfo(QString)));
    connect(this,SIGNAL(Signal_enableButton_SearchBookDetail()),bookmanagementwidget,SLOT(SLOT_enableButton_SearchBookDetail()));
    connect(this,SIGNAL(Signal_disableButton_SearchBookDetail()),bookmanagementwidget,SLOT(SLOT_disableButton_SearchBookDetail()));
    connect(bookmanagementwidget,SIGNAL(Signal_deleteBook(QVector<QString>)),this,SLOT(SLOT_deleteBook(QVector<QString>)));
    connect(bookmanagementwidget,SIGNAL(Signal_addBook()),this,SLOT(SLOT_addBook()));
    connect(this,SIGNAL(Signal_enableButton_addBook()),bookmanagementwidget,SLOT(SLOT_enableButton_addBook()));
    connect(this,SIGNAL(Signal_disableButton_addBook()),bookmanagementwidget,SLOT(SLOT_disableButton_addBook()));
}

void MainWindow::bookmanagementUpdate()
{
    BookQuery bookquery;
    QVector<Book> Catalog = booksData(bookquery, true);

    emit Signal_bookmanagementResult(Catalog);
}

void MainWindow::SLOT_SearchBookDetailInfo(QString bookID)
{
    QSqlQuery query(db);
    QSqlQuery query0(db);
    QString queryCommand;
    BookDetial bookdetial;
    BorrowUser borrowuser;

    if(people->user_Type == People::MANAGER)
    {
        queryCommand="select * from book where book_id='"+bookID+"';";
        query.exec(queryCommand);
        if(query.next())
        {
            //(书籍详细信息界面)，显示出来
            bookdetailwindow = new BookDetailWindow();
            bookdetailwindow->setWindowTitle("书籍详细信息");
            bookdetailwindow->show();

            connect(bookdetailwindow,SIGNAL(Signal_bookdetailwindowClosed()),this,SLOT(SLOT_bookdetailwindowClosed()));
            connect(this,SIGNAL(Signal_SearchBookDetailUpdate(BookDetial)),bookdetailwindow,SLOT(SLOT_SearchBookDetailUpdate(BookDetial)));
            connect(bookdetailwindow,SIGNAL(Signal_changeBookInfo(BookDetial)),this,SLOT(SLOT_changeBookInfo(BookDetial)));
            connect(this,SIGNAL(Signal_OnlyBookDetailUpdate(BookDetial)),bookdetailwindow,SLOT(SLOT_OnlyBookDetailUpdate(BookDetial)));
            connect(bookdetailwindow,SIGNAL(Signal_deleteBook(BookDetial)),this,SLOT(SLOT_deleteBook(BookDetial)));

            bookdetial.book.book_id = query.value("book_id").toString();
            bookdetial.book.name=query.value("name").toString();
            bookdetial.book.author_name=query.value("author_name").toString();
            bookdetial.book.price=query.value("price").toDouble();
            bookdetial.book.num=query.value("num").toInt();
            bookdetial.book.stock=query.value("stock").toInt();
            bookdetial.book.publisher=query.value("publisher").toString();
            bookdetial.book.publish_year=query.value("publish_year").toString();
            bookdetial.book.type=query.value("type").toString();

            //获取借阅人员
            queryCommand="select * from borrow where book_id='"+bookdetial.book.book_id+"';";
            query.exec(queryCommand);
            //继续查询借阅人员信息
            while(query.next())
            {
                borrowuser.user.user_ID = query.value("user_id").toString();
                borrowuser.dateBorrow = query.value("borrow_date").toString();
                borrowuser.dateReturn = query.value("return_date").toString();

                queryCommand="select name from user where id='" + borrowuser.user.user_ID +"';";
                query0.exec(queryCommand);
                if(query0.next())
                {
                    borrowuser.user.user_Name = query0.value("name").toString();
                }
                bookdetial.user.append(borrowuser);
            }

            emit Signal_SearchBookDetailUpdate(bookdetial);
            emit Signal_disableButton_SearchBookDetail();

            //关闭（书籍添加页面）。判断
            if(addbookwindow!=NULL)
            {
                addbookwindow->close();
            }
        }
        else
        {
            QMessageBox::critical(NULL, "Error", "查询失败，可能没有该书籍", QMessageBox::Yes);
        }
    }
}

void MainWindow::SLOT_bookdetailwindowClosed()
{
    bookdetailwindowClosed();
}

void MainWindow::bookdetailwindowClosed()
{
    bookdetailwindow->close();
    delete bookdetailwindow; //防止内存泄漏和野指针
    bookdetailwindow=NULL;
    emit Signal_enableButton_SearchBookDetail();
}

void MainWindow:: SLOT_changeBookInfo(BookDetial bookdetialOld)
{
    QSqlQuery query(db);
    QString queryCommand;
    if(people->user_Type == People::MANAGER)
    {
        //更新数据库
        queryCommand = QString("update book set name='%1', author_name='%2', price=%3, num=%4, stock=%5, publisher='%6', publish_year='%7', type='%8' where book_id='%9';").arg(bookdetialOld.book.name, bookdetialOld.book.author_name, QString::number(bookdetialOld.book.price, 'f', 2), QString::number(bookdetialOld.book.num, 10), QString::number(bookdetialOld.book.stock, 10), bookdetialOld.book.publisher, bookdetialOld.book.publish_year, bookdetialOld.book.type, bookdetialOld.book.book_id);
        query.exec(queryCommand);

        //从数据中读取新的值
        queryCommand = QString("select * from book where book_id='%1';").arg(bookdetialOld.book.book_id);
        query.exec(queryCommand);

        if(query.next())
        {
            bookdetialOld.book.name=query.value("name").toString();
            bookdetialOld.book.author_name=query.value("author_name").toString();
            bookdetialOld.book.price=query.value("price").toDouble();
            bookdetialOld.book.num=query.value("num").toInt();
            bookdetialOld.book.stock=query.value("stock").toInt();
            bookdetialOld.book.publisher=query.value("publisher").toString();
            bookdetialOld.book.publish_year=query.value("publish_year").toString();
            bookdetialOld.book.type=query.value("type").toString();

            emit Signal_OnlyBookDetailUpdate(bookdetialOld);
            bookmanagementUpdate();
            if(userdetailwindow!=NULL)
            {
                userdetailwindow->close();
            }
            QMessageBox::information(NULL, "Info", "书籍信息已更新", QMessageBox::Yes);
        }
    }
}

void MainWindow::SLOT_deleteBook(BookDetial bookdetialNow)
{
    QSqlQuery query(db);
    QString queryCommand;
    if(people->user_Type == People::MANAGER)
    {
        //删除用户需要用户借阅数量为0
        queryCommand="select * from borrow where book_id='"+bookdetialNow.book.book_id+"';";
        query.exec(queryCommand);
        if(query.size()!=0)
        {
            QMessageBox::critical(NULL, "Error", "用户有借阅，不能删除", QMessageBox::Yes);
        }
        else
        {
            queryCommand = QString("delete from book where book_id='%1';").arg(bookdetialNow.book.book_id);
            query.exec(queryCommand);

            bookdetailwindowClosed();
            bookmanagementUpdate();

            QMessageBox::information(NULL, "Info", "书籍删除成功", QMessageBox::Yes);
        }
    }
}

void MainWindow::SLOT_addBook()
{
    if(people->user_Type == People::MANAGER)
    {
        //显示（注册界面）
        addbookwindow = new AddBookWindow();
        addbookwindow->setWindowTitle("书籍添加/更新界面");
        addbookwindow->show();

        connect(addbookwindow,SIGNAL(Signal_addbookwindowClosed()),this,SLOT(SLOT_addbookwindowClosed()));
        connect(addbookwindow,SIGNAL(Signal_addOneBook(Book)),this,SLOT(SLOT_addOneBook(Book)));
        connect(addbookwindow,SIGNAL(Signal_addSomeBooks(QVector<Book>)),this,SLOT(SLOT_addSomeBooks(QVector<Book>)));

        emit Signal_disableButton_addBook();
        //关闭（书籍详细信息页面）。判断
        if(bookdetailwindow!=NULL)
        {
            bookdetailwindow->close();
        }
    }

}

void MainWindow::SLOT_addbookwindowClosed()
{
   addbookwindowClosed();
}

void MainWindow::addbookwindowClosed()
{
    addbookwindow->close();
    delete addbookwindow; //防止内存泄漏和野指针
    addbookwindow=NULL;
    emit Signal_enableButton_addBook();
}

void MainWindow::SLOT_deleteBook(QVector<QString> deletebook)
{
    int sucessNum=0;
    int deleteNum=deletebook.size();
    QSqlQuery query(db);
    QString queryCommand;

    if(deleteNum > 0)
    {
        for (int i = 0; i < deleteNum; i++)
        {
            queryCommand = QString("delete from book where book_id='%1';").arg(deletebook[i]);
            if(query.exec(queryCommand) == true)
            {
                sucessNum++;
            }
        }
        if(sucessNum > 0)
        {
            QMessageBox::information(NULL, "Info", "成功删除"+QString::number(sucessNum,10)+"本书籍", QMessageBox::Yes);
        }
    }
    else
    {
        QMessageBox::critical(NULL, "Error", "请正确选择需要修改的用户", QMessageBox::Yes);
    }

    //更改后，判断是否有打开了(书籍详细信息界面)。若打开则关闭
    if(bookdetailwindow!=NULL)
    {
        bookdetailwindow->close();//自动回收
    }

    // 更改后，更新（书籍管理界面）
    bookmanagementUpdate();
}

void MainWindow::SLOT_addOneBook(Book addbook)
{
    if(people->user_Type == People::MANAGER)
    {
        QSqlQuery query(db);
        QString queryCommand;

        queryCommand="select * from book where book_id='"+addbook.book_id+"';";
        query.exec(queryCommand);

        if(query.size()!=0)
        {
            //已经存在，更新

            if(addbook.num < (query.value("num").toInt() - query.value("stock").toInt()))//更新后的数量小于借出量时，不进行更新
            {
                QMessageBox::critical(NULL, "Error", "请修改书籍数量大于借出量："+QString::number((query.value("num").toInt() - query.value("stock").toInt()),10), QMessageBox::Yes);
                return ;
            }

            queryCommand=QString("update book set name='%1', author_name='%2', price=%3, num=%4, stock=%5, publisher='%6', publish_year='%7', type='%8' where book_id='%9'").arg(addbook.name, addbook.author_name, QString::number(addbook.price,'f',2), QString::number(addbook.num,10), QString::number(addbook.stock,10), addbook.publisher, addbook.publish_year, addbook.type, addbook.book_id);
            query.exec(queryCommand);
        }
        else
        {
            //新书，添加
            queryCommand=QString("insert into book (book_id, name, author_name, price, num, stock, publisher, publish_year, type) values ('%1', '%2', '%3', %4, %5, %6, '%7', '%8', '%9');").arg(addbook.book_id, addbook.name, addbook.author_name, QString::number(addbook.price,'f',2), QString::number(addbook.num,10), QString::number(addbook.stock,10), addbook.publisher, addbook.publish_year, addbook.type);
            query.exec(queryCommand);
        }

        bookmanagementUpdate();
        if(userdetailwindow!=NULL)
        {
            userdetailwindow->close();
        }
        if(bookdetailwindow!=NULL)
        {
            userdetailwindow->close();
        }

        QMessageBox::information(NULL, "Info", "成功添加/更新书籍", QMessageBox::Yes);
    }
}

void MainWindow::SLOT_addSomeBooks(QVector<Book> addbooks)
{
    if(people->user_Type == People::MANAGER)
    {
        QSqlQuery query(db);
        QString queryCommand;
        int addSucess=0;
        int updateSucess=0;
        int addNum=addbooks.size();
        for(int i=0;i<addNum;i++)
        {
            queryCommand="select * from book where book_id='"+addbooks[i].book_id+"';";
            query.exec(queryCommand);

            if(query.size()!=0)
            {
                //已经存在，更新
                if(addbooks[i].num < (query.value("num").toInt() - query.value("stock").toInt()))//更新后的数量小于借出量时，不进行更新
                {
                    QMessageBox::critical(NULL, "Error", "请修改书籍数量大于借出量："+QString::number((query.value("num").toInt() - query.value("stock").toInt()),10), QMessageBox::Yes);
                    return ;
                }
                queryCommand=QString("update book set name='%1', author_name='%2', price=%3, num=%4, stock=%5, publisher='%6', publish_year='%7', type='%8' where book_id='%9'").arg(addbooks[i].name, addbooks[i].author_name, QString::number(addbooks[i].price,'f',2), QString::number(addbooks[i].num,10), QString::number(addbooks[i].stock,10), addbooks[i].publisher, addbooks[i].publish_year, addbooks[i].type, addbooks[i].book_id);
                query.exec(queryCommand);
                updateSucess++;
            }
            else
            {
                //新书，添加
                queryCommand=QString("insert into book (book_id, name, author_name, price, num, stock, publisher, publish_year, type) values ('%1', '%2', '%3', %4, %5, %6, '%7', '%8', '%9');").arg(addbooks[i].book_id, addbooks[i].name, addbooks[i].author_name, QString::number(addbooks[i].price,'f',2), QString::number(addbooks[i].num,10), QString::number(addbooks[i].stock,10), addbooks[i].publisher, addbooks[i].publish_year, addbooks[i].type);
                query.exec(queryCommand);
                addSucess++;
            }
        }

        bookmanagementUpdate();
        if(userdetailwindow!=NULL)
        {
            userdetailwindow->close();
        }

        QMessageBox::information(NULL, "Info", "成功添加书籍"+QString::number(addSucess,10)+"本、更新"+QString::number(updateSucess,10)+"本", QMessageBox::Yes);
    }
}
