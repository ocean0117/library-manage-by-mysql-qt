#include "booksearchwidget.h"
#include "ui_booksearchwidget.h"
#include <QDebug>
BookSearchWidget::BookSearchWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BookSearchWidget)
{
    ui->setupUi(this);

    /* 指针初始化，避免野指针 */
    tablecheckitem=NULL;
    treeitemroot=NULL;
    numbook=0; //当前显示的book数量

    /*** treeWidget界面设计 **/
    ui->treeWidget->setHeaderLabels(QStringList() << "书籍种类");
    treeitemroot = new QTreeWidgetItem(QStringList() << "所有类型");
    ui->treeWidget->addTopLevelItem(treeitemroot);

    const QString booktype[] = {"文学类","艺术类","自然科学类","计算机类","思政类","经济类","哲学类","军体类",
                            "医学类","工业技术","环境科学类","历史类","地理类"};
    const int num = sizeof(booktype)/sizeof(booktype[0]);
    QTreeWidgetItem* leaf[num];

    for (int i = 0; i < num; i++)
    {
        leaf[i] = new QTreeWidgetItem(QStringList() << booktype[i]);
        treeitemroot->addChild(leaf[i]);
    }
    ui->treeWidget->expandAll();
    ui->treeWidget->setCurrentItem(treeitemroot); //默认选中 所有类型

    /*** 右侧选项界面设计 ***/
    ui->comboBox_date1->addItem("");
    ui->comboBox_date2->addItem("");
    for (int i = 0; i<100; i++) {
        ui->comboBox_date1->addItem(QString::number(2022 - i));
        ui->comboBox_date2->addItem(QString::number(2022 - i));
    }

    /*** tableWidget 表格设计 ***/
    const QString tableheader[] = {"","编号","书名","价格/元","总库存/本","已借出/本","类型","作者","出版社","出版年份"};
    int numheader=sizeof(tableheader)/sizeof(tableheader[0]);

    rowcount = 0;
    rowcount =rowcount>20?rowcount:20; // rowcount需要根据检索的数量来定，如果检索不到，最小为20
    ui->tableWidget->setRowCount(rowcount);
    ui->tableWidget->setColumnCount(numheader);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);	//设置为只读模式
    ui->tableWidget->setSelectionMode(QAbstractItemView::NoSelection);	//设置为不可选中

    QStringList header;
    for (int i = 0; i < numheader; i++)
            header << tableheader[i];
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->setColumnWidth(0, 80);
    for (int i = 1; i < numheader; i++)
    {
        ui->tableWidget->setColumnWidth(i, 120);
    }

    /*** 图书借阅按钮 **/
    ui->Button_lendBook->hide();
}

BookSearchWidget::~BookSearchWidget()
{
    delete ui;
    //防止内存泄漏和野指针
    delete treeitemroot;
    treeitemroot=NULL;

    if(tablecheckitem!=NULL)
    {
//        qDebug() << "防止内存泄漏和野指针";
        for(int i=0;i<numbook;i++)
        {
           delete tablecheckitem[i];
        }
        delete []tablecheckitem;
        tablecheckitem=NULL;
        numbook=0;
    }
}

void BookSearchWidget::on_Button_Search_clicked()
{
    Update();
}

void BookSearchWidget::SLOT_bookqueryResult(QVector<Book> Catalog,People* people)
{
    //首先清除表内数据，然后根据回传数据以及用户类型显示表格
    if(tablecheckitem!=NULL)
    {
//        qDebug() << "防止内存泄漏和野指针";
        for(int i=0;i<numbook;i++)
        {
              delete tablecheckitem[i];
        }
        delete []tablecheckitem;
        tablecheckitem=NULL;
        numbook=0;
    }
    ui->tableWidget->clearContents(); // clear清除所有，包括表头；clearContents只清除内容，不包含表头

    //表格数据显示
    numbook = Catalog.size();
    rowcount =numbook>20?numbook:20;
    ui->tableWidget->setRowCount(rowcount);
    if (people->user_Type == People::USER)
    {
        tablecheckitem = new QTableWidgetItem*[numbook];
        for (int i = 0; i < numbook; i++)
        {
            tablecheckitem[i] = new QTableWidgetItem();
            tablecheckitem[i]->setCheckState(Qt::Unchecked);
            ui->tableWidget->setItem(i, 0, tablecheckitem[i]);
        }
    }
    for (int i = 0; i < numbook; i++)
    {
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(Catalog[i].book_id));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(Catalog[i].name));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(QString::number(Catalog[i].price,'f',2)));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(QString::number(Catalog[i].num,10)));
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(QString::number(Catalog[i].num - Catalog[i].stock,10)));
        ui->tableWidget->setItem(i,6,new QTableWidgetItem(Catalog[i].type));
        ui->tableWidget->setItem(i,7,new QTableWidgetItem(Catalog[i].author_name));
        ui->tableWidget->setItem(i,8,new QTableWidgetItem(Catalog[i].publisher));
        ui->tableWidget->setItem(i,9,new QTableWidgetItem(Catalog[i].publish_year));
    }

    //图书借阅按钮，只有是具有借书权限的用户时，才显示
    if (people->user_Type == People::USER)
    {
        ui->Button_lendBook->show();
    }
    else
    {
        ui->Button_lendBook->hide();
    }
}

void BookSearchWidget::on_Button_Clear_clicked()
{
    Clear();
}

void BookSearchWidget::on_Button_lendBook_clicked()
{
    QVector<QString> bookborrow;

    for (int i = 0; i < numbook; i++)
    {
        if (ui->tableWidget->item(i, 0)->checkState() == Qt::Checked)
        {//如果勾选框被选中
            if(ui->tableWidget->item(i, 4)->text().toInt() - ui->tableWidget->item(i, 5)->text().toInt() > 0 )
            {//如果有库存
                bookborrow.append(ui->tableWidget->item(i, 1)->text());
            }
        }
    }

    emit Signal_bookBorrow(bookborrow);
}

void BookSearchWidget::SLOT_loginQuit()
{
    Clear();
}

void BookSearchWidget::Update()
{
    // 存储搜索信息
    bookquery.book_id = ui->LineEdit_bookID->text().trimmed(); // trimmed()去除空格
    bookquery.name = ui->LineEdit_bookName->text().trimmed();
    bookquery.author_name=ui->LineEdit_authorName->text().trimmed();
    bookquery.begin_year=ui->comboBox_date1->currentText().toInt();
    bookquery.end_year=ui->comboBox_date2->currentText().toInt();
    if(bookquery.begin_year == 0 || bookquery.end_year == 0 ||
       (bookquery.begin_year!=0 && bookquery.end_year!=0 && bookquery.begin_year>bookquery.end_year))
    {//容错处理
        ui->comboBox_date1->setCurrentIndex(0);
        ui->comboBox_date2->setCurrentIndex(0);
        bookquery.begin_year=ui->comboBox_date1->currentText().toInt();
        bookquery.end_year=ui->comboBox_date2->currentText().toInt();
    }
    bookquery.publisher=ui->LineEdit_publisher->text().trimmed();
    bookquery.low_price=ui->LineEdit_price1->text().toDouble();
    bookquery.high_price=ui->LineEdit_price2->text().toDouble();
    if(bookquery.low_price <= 0.0 || bookquery.high_price <= 0.0 ||
      (bookquery.low_price > 0.0 && bookquery.high_price > 0.0 && bookquery.low_price>bookquery.high_price))
    {//容错处理
        ui->LineEdit_price1->clear();
        ui->LineEdit_price2->clear();
        bookquery.low_price=ui->LineEdit_price1->text().toDouble();
        bookquery.high_price=ui->LineEdit_price2->text().toDouble();
    }

    bookquery.have_stock=(ui->checkBox_haveStock->checkState() == Qt::Checked);
    bookquery.type=ui->treeWidget->currentItem()->text(0);

    emit Signal_bookquerySearch(bookquery);
}

void BookSearchWidget::Clear()
{
    ui->treeWidget->setCurrentItem(treeitemroot); //默认选中 所有类型

    ui->LineEdit_bookID->clear();
    ui->LineEdit_bookName->clear();
    ui->LineEdit_authorName->clear();
    ui->comboBox_date1->setCurrentIndex(0);
    ui->comboBox_date2->setCurrentIndex(0);
    ui->LineEdit_publisher->clear();
    ui->LineEdit_price1->clear();
    ui->LineEdit_price2->clear();
    ui->checkBox_haveStock->setCheckState(Qt::Unchecked);

    //清除表内数据，然后
    if(tablecheckitem!=NULL)
    {
//      qDebug() << "防止内存泄漏和野指针";
        for(int i=0;i<numbook;i++)
        {
           delete tablecheckitem[i];
        }
        delete []tablecheckitem;
        tablecheckitem=NULL;
        numbook=0;
    }
    ui->tableWidget->clearContents(); // clear清除所有，包括表头；clearContents只清除内容，不包含表头

    Update();
}
