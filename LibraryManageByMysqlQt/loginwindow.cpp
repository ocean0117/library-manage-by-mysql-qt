#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QDebug>
LoginWindow::LoginWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_Button_quit_clicked()
{
    this->close();
}

void LoginWindow::closeEvent(QCloseEvent *event)
{
    emit Signal_loginQuit();
}

void LoginWindow::on_Button_yes_clicked()
{
    if(ui->LineEdit_userID->text().trimmed().isEmpty() || ui->LineEdit_password->text().trimmed().isEmpty())
    {
        QMessageBox::critical(NULL, "Error", "您的信息填写不完整", QMessageBox::Yes);
        return;
    }
    // 登录类型：用户或管理员
    bool isUser=(ui->Radio_user->isChecked())?true:false;

    //返回登录信息
    QVector<QString>values;
    values.append(ui->LineEdit_userID->text().trimmed());
    values.append(ui->LineEdit_password->text().trimmed());

    emit Signal_login(isUser, values);
}
