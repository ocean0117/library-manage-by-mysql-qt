#ifndef USERDETAILWINDOW_H
#define USERDETAILWINDOW_H

#include <QDialog>
#include <QDate>
#include <QMessageBox>
#include "datastructure.h"
namespace Ui {
class UserDetailWindow;
}

class UserDetailWindow : public QDialog
{
    Q_OBJECT

public:
    explicit UserDetailWindow(QWidget *parent = 0);
    ~UserDetailWindow();
private:
    int rowcount;
    int numbook;

    UserDetial userdetialNow;
    UserDetial userdetialOld;

    void closeEvent(QCloseEvent *event);
    void userdetailUpdate(UserDetial userdetialNow);

signals:
    void Signal_userdetailwindowClosed();
    void Signal_changeUserInfo(UserDetial);
    void Signal_deleteUser(UserDetial);

private slots:
    void SLOT_SearchUserDetailUpdate(UserDetial);
    void on_Button_changeUserInfo_clicked();

    void on_Button_deleteUser_clicked();
    void SLOT_OnlyUserDetailUpdate(UserDetial);


private:
    Ui::UserDetailWindow *ui;
};

#endif // USERDETAILWINDOW_H
