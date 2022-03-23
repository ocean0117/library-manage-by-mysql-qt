#include "bookmanagementwidget.h"
#include "ui_bookmanagementwidget.h"
#include <QDebug>
BookManagementWidget::BookManagementWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BookManagementWidget)
{
    ui->setupUi(this);

    /* 指针初始化，避免野指针 */
    tablecheckitem=NULL;
    numbook=0; // 当前显示的用户数量

    /*** tableWidget 表格设计 ***/
    const QString tableheader[] = {"","编号","书名","总库存/本","已借出/本","类型"};
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

BookManagementWidget::~BookManagementWidget()
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

void BookManagementWidget::on_Button_Search_clicked()
{
    QString bookID=ui->LineEdit_bookID->text().trimmed();
    if(bookID == "")
    {
        QMessageBox::critical(NULL, "Error", "请输入正确的书籍编号", QMessageBox::Yes);
    }
    else
    {
        emit Signal_SearchBookDetailInfo(bookID);
    }
}

void BookManagementWidget::SLOT_bookmanagementResult(QVector<Book> Catalog)
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
    tablecheckitem = new QTableWidgetItem*[numbook];
    for (int i = 0; i < numbook; i++)
    {
        tablecheckitem[i] = new QTableWidgetItem();
        tablecheckitem[i]->setCheckState(Qt::Unchecked);
        ui->tableWidget->setItem(i, 0, tablecheckitem[i]);

        ui->tableWidget->setItem(i,1,new QTableWidgetItem(Catalog[i].book_id));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(Catalog[i].name));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(QString::number(Catalog[i].num,10)));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(QString::number(Catalog[i].num - Catalog[i].stock,10)));
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(Catalog[i].type));
    }
}

void BookManagementWidget::SLOT_enableButton_SearchBookDetail()
{
    ui->Button_Search->setEnabled(true);
}

void BookManagementWidget::SLOT_disableButton_SearchBookDetail()
{
    ui->Button_Search->setDisabled(true);
}

void BookManagementWidget::on_Button_addBook_clicked()
{
    emit Signal_addBook();
}

void BookManagementWidget::on_Button_deleteBook_clicked()
{
    QVector<QString> deletebook;
    for (int i = 0; i < numbook; i++)
    {
        if (ui->tableWidget->item(i, 0)->checkState() == Qt::Checked && ui->tableWidget->item(i, 4)->text().toInt() == 0)
        {
            deletebook.append(ui->tableWidget->item(i, 1)->text());
        }
    }
    emit Signal_deleteBook(deletebook);
}

void BookManagementWidget::SLOT_enableButton_addBook()
{
    ui->Button_addBook->setEnabled(true);
}

void BookManagementWidget::SLOT_disableButton_addBook()
{
    ui->Button_addBook->setDisabled(true);
}
