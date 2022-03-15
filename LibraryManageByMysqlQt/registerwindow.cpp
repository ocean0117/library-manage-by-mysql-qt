#include "registerwindow.h"
#include "ui_registerwindow.h"

RegisterWindow::RegisterWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterWindow)
{
    ui->setupUi(this);
}

RegisterWindow::~RegisterWindow()
{
    delete ui;
}

void RegisterWindow::on_Button_quit_clicked()
{
    this->close();
}

void RegisterWindow::closeEvent(QCloseEvent *event)
{
    emit Signal_registerQuit();
}

void RegisterWindow::on_Button_yes_clicked()
{
    if(ui->LineEdit_userID->text().isEmpty() || ui->LineEdit_userName->text().isEmpty() || ui->LineEdit_password->text().isEmpty() || ui->LineEdit_password_2->text().isEmpty())
    {
        QMessageBox::critical(NULL, "Error", "您的信息填写不完整", QMessageBox::Yes);
        return;
    }

    if(ui->LineEdit_password->text() != ui->LineEdit_password_2->text())
    {
        QMessageBox::critical(NULL, "Error", "两次密码输入不一致", QMessageBox::Yes);
        return;
    }
    //返回注册信息
    QVector<QString> values;
    values.append(ui->LineEdit_userID->text());
    values.append(ui->LineEdit_userName->text());
    values.append(ui->LineEdit_password->text());

    emit Signal_register(values);
}
