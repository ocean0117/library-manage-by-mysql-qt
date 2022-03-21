#include "bookborrowinfowidget.h"
#include "ui_bookborrowinfowidget.h"
#include <QDebug>
BookBorrowInfoWidget::BookBorrowInfoWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BookBorrowInfoWidget)
{
    ui->setupUi(this);

    /* 指针初始化，避免野指针 */
    tablecheckitem=NULL;
    numbook=0; // 当前显示的book数量

    /*** tableWidget 表格设计 ***/
    const QString tableheader[] = { " ","编号","书名","作者","价格","借阅日期","归还期限","剩余天数"};
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
        ui->tableWidget->setColumnWidth(i, 147);
    }
}

BookBorrowInfoWidget::~BookBorrowInfoWidget()
{
    delete ui;

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

void BookBorrowInfoWidget::on_Button_allSelectBook_clicked()
{
    for(int i = 0;i < numbook;i++)
    {
        tablecheckitem[i]->setCheckState(Qt::Checked);
    }
}

void BookBorrowInfoWidget::on_Button_returnBook_clicked()
{
    QVector<QString> bookreturn;

    for (int i = 0; i < numbook; i++)
    {
        if (ui->tableWidget->item(i, 0)->checkState() == Qt::Checked)
        {//如果勾选框被选中
            bookreturn.append(ui->tableWidget->item(i, 1)->text());
        }
    }

    emit Signal_bookReturn(bookreturn);
}

void BookBorrowInfoWidget::SLOT_bookborrowqueryResult(QVector<BorrowBook> Catalog,People *people)
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
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(Catalog[i].book.book_id));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(Catalog[i].book.name));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(Catalog[i].book.type));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(QString::number(Catalog[i].book.price,'f',2)));
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(Catalog[i].dateBorrow));
        ui->tableWidget->setItem(i,6,new QTableWidgetItem(Catalog[i].dateReturn));
        ui->tableWidget->setItem(i,7,new QTableWidgetItem(QString::number(QDate::currentDate().daysTo(QDate::fromString(Catalog[i].dateReturn,"yyyy-MM-dd")),10)));
    }
}
