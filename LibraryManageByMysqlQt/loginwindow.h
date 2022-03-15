#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>
#include <QMessageBox>
namespace Ui {
class LoginWindow;
}

class LoginWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = 0);
    ~LoginWindow();

private slots:
    void on_Button_quit_clicked();
    void on_Button_yes_clicked();

private:
    void closeEvent(QCloseEvent *event);

signals:
    void Signal_loginQuit();
    void Signal_login(bool, QVector<QString>);

private:
    Ui::LoginWindow *ui;
};

#endif // LOGINWINDOW_H
