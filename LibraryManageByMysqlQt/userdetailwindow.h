#ifndef USERDETAILWINDOW_H
#define USERDETAILWINDOW_H

#include <QDialog>
#include <QDate>

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
    void closeEvent(QCloseEvent *event);

signals:
    void Signal_userdetailwindowClosed();

private slots:
    void SLOT_SearchUserDetailUpdate(UserDetial);
private:
    Ui::UserDetailWindow *ui;
};

#endif // USERDETAILWINDOW_H
