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
    if(ui->LineEdit_userID->text().trimmed().isEmpty() || ui->LineEdit_userName->text().trimmed().isEmpty() || ui->LineEdit_password->text().trimmed().isEmpty() || ui->LineEdit_password_2->text().trimmed().isEmpty())
    {
        QMessageBox::critical(NULL, "Error", "您的信息填写不完整", QMessageBox::Yes);
        return;
    }

    if(ui->LineEdit_password->text().trimmed() != ui->LineEdit_password_2->text().trimmed())
    {
        QMessageBox::critical(NULL, "Error", "两次密码输入不一致", QMessageBox::Yes);
        return;
    }
    //返回注册信息
    QVector<QString> values;
    values.append(ui->LineEdit_userID->text().trimmed());
    values.append(ui->LineEdit_userName->text().trimmed());
    values.append(ui->LineEdit_password->text().trimmed());

    emit Signal_register(values);
}
