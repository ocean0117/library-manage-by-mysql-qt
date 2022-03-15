#include "usermanagementwidget.h"
#include "ui_usermanagementwidget.h"
#include <QDebug>
UserManagementWidget::UserManagementWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserManagementWidget)
{
    ui->setupUi(this);

    /* 指针初始化，避免野指针 */
    tablecheckitem=NULL;
    numuser=0; // 当前显示的用户数量

    /*** tableWidget 表格设计 ***/
    rowcount = 0;
    rowcount =rowcount>20?rowcount:20; // rowcount需要根据检索的数量来定，如果检索不到，最小为20
    ui->tableWidget->setRowCount(rowcount);
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);	//设置为只读模式
    ui->tableWidget->setSelectionMode(QAbstractItemView::NoSelection);	//设置为不可选中

    const char* tableheader[] = {" ","用户学号","用户名","用户密码","借书权限","借阅数目"};
    QStringList header;
    for (int i = 0; i < 6; i++)
            header << tableheader[i];
    ui->tableWidget->setHorizontalHeaderLabels(header);
    ui->tableWidget->setColumnWidth(0, 80);
    for (int i = 1; i < 10; i++)
    {
        ui->tableWidget->setColumnWidth(i, 147);
    }
}

UserManagementWidget::~UserManagementWidget()
{
    delete ui;

    if(tablecheckitem!=NULL)
    {
//        qDebug() << "防止内存泄漏和野指针";
        for(int i=0;i<numuser;i++)
        {
           delete tablecheckitem[i];
        }
        delete []tablecheckitem;
        tablecheckitem=NULL;
        numuser=0;
    }
}

void UserManagementWidget::on_Button_Search_clicked()
{

}

void UserManagementWidget::on_Button_changePri_clicked()
{

}

void UserManagementWidget::on_Button_deleteUser_clicked()
{

}

void UserManagementWidget::on_Button_addUser_clicked()
{

}

void UserManagementWidget::SLOT_usermanagementResult(QVector<People> Catalog)
{
    //首先清除表内数据，然后根据回传数据以及用户类型显示表格
    if(tablecheckitem!=NULL)
    {
//        qDebug() << "防止内存泄漏和野指针";
        for(int i=0;i<numuser;i++)
        {
              delete tablecheckitem[i];
        }
        delete []tablecheckitem;
        tablecheckitem=NULL;
        numuser=0;
    }
    ui->tableWidget->clearContents(); // clear清除所有，包括表头；clearContents只清除内容，不包含表头

    //表格数据显示
    numuser = Catalog.size();
    rowcount =numuser>20?numuser:20;
    ui->tableWidget->setRowCount(rowcount);
    tablecheckitem = new QTableWidgetItem*[numuser];
    for (int i = 0; i < numuser; i++)
    {
        tablecheckitem[i] = new QTableWidgetItem();
        tablecheckitem[i]->setCheckState(Qt::Unchecked);
        ui->tableWidget->setItem(i, 0, tablecheckitem[i]);

        ui->tableWidget->setItem(i,1,new QTableWidgetItem(Catalog[i].user_ID));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(Catalog[i].user_Name));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(Catalog[i].user_Password));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(Catalog[i].user_canBorrow?"拥有借书权限":" "));
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(QString::number(Catalog[i].booknum,10)));
    }
}
