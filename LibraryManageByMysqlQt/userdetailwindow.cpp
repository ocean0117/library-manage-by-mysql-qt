#include "userdetailwindow.h"
#include "ui_userdetailwindow.h"
#include <QDebug>

UserDetailWindow::UserDetailWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserDetailWindow)
{
    ui->setupUi(this);

    /********** 类中变量初始化（主要针对指针） **********/
    numbook=0; // 当前显示的book数量

    ui->LineEdit_userID->setFocusPolicy(Qt::NoFocus);//不允许编辑
    ui->LineEdit_booknum->setFocusPolicy(Qt::NoFocus);

    /*** tableWidget 表格设计 ***/
    const QString tableheader[] = { "书本编号","书籍名称","借阅日期","归还日期","剩余归还天数" };
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
    for (int i = 0; i < numheader; i++)
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
    userdetialNow = userdetial;//用于保存当前用户的值

    userdetailUpdate(userdetialNow);
}

void UserDetailWindow::userdetailUpdate(UserDetial userdetialNow)
{
    ui->LineEdit_userName->setText(userdetialNow.user.user_Name);
    ui->LineEdit_userID->setText(userdetialNow.user.user_ID);
    ui->LineEdit_password->setText(userdetialNow.user.user_Password);
    ui->checkBox_Pri->setCheckState(userdetialNow.user.user_canBorrow?(Qt::Checked):(Qt::Unchecked));
    ui->LineEdit_booknum->setText(QString::number(userdetialNow.user.booknum,10));

    ui->tableWidget->clearContents(); // clear清除所有，包括表头；clearContents只清除内容，不包含表头
    //表格数据显示
    numbook = userdetialNow.borrowbook.size();
    rowcount =numbook>20?numbook:20;
    ui->tableWidget->setRowCount(rowcount);

    for (int i = 0; i < numbook; i++)
    {
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(userdetialNow.borrowbook[i].book.book_id));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(userdetialNow.borrowbook[i].book.name));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(userdetialNow.borrowbook[i].dateBorrow));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(userdetialNow.borrowbook[i].dateReturn));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(QString::number(QDate::currentDate().daysTo(QDate::fromString(userdetialNow.borrowbook[i].dateReturn,"yyyy-MM-dd")),10)));
    }
}

void UserDetailWindow::on_Button_changeUserInfo_clicked()
{
    if(!((userdetialNow.user.user_Name ==  ui->LineEdit_userName->text().trimmed()) &&
       (userdetialNow.user.user_Password == ui->LineEdit_password->text().trimmed()) &&
       (userdetialNow.user.user_canBorrow == (ui->checkBox_Pri->checkState() == Qt::Checked))))
    {
        userdetialOld.user.user_Name =  ui->LineEdit_userName->text().trimmed();
        userdetialOld.user.user_Password = ui->LineEdit_password->text().trimmed();
        userdetialOld.user.user_canBorrow = (ui->checkBox_Pri->checkState() == Qt::Checked);

        userdetialOld.user.user_ID = ui->LineEdit_userID->text().trimmed();//ID不能改变的
        emit Signal_changeUserInfo(userdetialOld);
    }
    else
    {
        QMessageBox::critical(NULL, "Error", "用户信息未更改成功", QMessageBox::Yes);
    }
}

void UserDetailWindow::SLOT_OnlyUserDetailUpdate(UserDetial userdetialOld)
{
    userdetialNow.user.user_Name = userdetialOld.user.user_Name;
    userdetialNow.user.user_Password = userdetialOld.user.user_Password;
    userdetialNow.user.user_canBorrow = userdetialOld.user.user_canBorrow;

    userdetailUpdate(userdetialNow);
}

void UserDetailWindow::on_Button_deleteUser_clicked()
{
    emit Signal_deleteUser(userdetialNow);
}

