#include "userdetailwindow.h"
#include "ui_userdetailwindow.h"
#include <QDebug>

UserDetailWindow::UserDetailWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserDetailWindow)
{
    ui->setupUi(this);

    numbook=0; // 当前显示的book数量

    ui->LineEdit_userName->setFocusPolicy(Qt::NoFocus);
    ui->LineEdit_userID->setFocusPolicy(Qt::NoFocus);
    ui->LineEdit_password->setFocusPolicy(Qt::NoFocus);
    ui->LineEdit_usePri->setFocusPolicy(Qt::NoFocus);
    ui->LineEdit_booknum->setFocusPolicy(Qt::NoFocus);

    /*** tableWidget 表格设计 ***/
    rowcount = 0;
    rowcount =rowcount>20?rowcount:20; // rowcount需要根据检索的数量来定，如果检索不到，最小为20
    ui->tableWidget->setRowCount(rowcount);
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);	//设置为只读模式
    ui->tableWidget->setSelectionMode(QAbstractItemView::NoSelection);	//设置为不可选中

    const char* tableheader[] = { "书本编号","书籍名称","借阅日期","归还日期","剩余归还天数" };
    QStringList header;
    for (int i = 0; i < 5; i++)
            header << tableheader[i];
    ui->tableWidget->setHorizontalHeaderLabels(header);
    for (int i = 0; i < 5; i++)
    {
        ui->tableWidget->setColumnWidth(i, 160);
    }
}

UserDetailWindow::~UserDetailWindow()
{
    delete ui;
}

void UserDetailWindow::closeEvent(QCloseEvent *event)
{
    emit Signal_userdetailwindowClosed();
}

void UserDetailWindow::SLOT_SearchUserDetailUpdate(UserDetial userdetial)
{
    ui->LineEdit_userName->setText(userdetial.user.user_Name);
    ui->LineEdit_userID->setText(userdetial.user.user_ID);
    ui->LineEdit_password->setText(userdetial.user.user_Password);
    ui->LineEdit_usePri->setText(userdetial.user.user_canBorrow?"允许借阅书籍":" ");
    ui->LineEdit_booknum->setText(QString::number(userdetial.user.booknum,10));

    ui->tableWidget->clearContents(); // clear清除所有，包括表头；clearContents只清除内容，不包含表头
    //表格数据显示
    numbook = userdetial.borrowbook.size();
    rowcount =numbook>20?numbook:20;
    ui->tableWidget->setRowCount(rowcount);

    for (int i = 0; i < numbook; i++)
    {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(userdetial.borrowbook[i].book.book_id));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(userdetial.borrowbook[i].book.name));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(userdetial.borrowbook[i].dateBorrow));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(userdetial.borrowbook[i].dateReturn));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(QString::number(QDate::currentDate().daysTo(QDate::fromString(userdetial.borrowbook[i].dateReturn,"yyyy-MM-dd")),10)));

    }
}
