#ifndef USERMANAGEMENTWIDGET_H
#define USERMANAGEMENTWIDGET_H

#include <QWidget>
#include <QTableWidgetItem>
#include <QMessageBox>
#include "datastructure.h"

namespace Ui {
class UserManagementWidget;
}

class UserManagementWidget : public QWidget
{
    Q_OBJECT

public:
    explicit UserManagementWidget(QWidget *parent = 0);
    ~UserManagementWidget();

private slots:
    void on_Button_Search_clicked();
    void on_Button_changePri_clicked();
    void on_Button_deleteUser_clicked();

    void SLOT_usermanagementResult(QVector<People>);

    void SLOT_enableButton_SearchUserDetail();
    void SLOT_disableButton_SearchUserDetail();
    void on_Button_addUser_clicked();

signals:
    void Signal_SearchUserDetailInfo(QString);
    void Signal_changeUserPri(QVector<QString>);
    void Signal_deleteUser(QVector<QString>);
    void Signal_addUser();

private:
    int rowcount;
    int numuser;
    QTableWidgetItem** tablecheckitem;

private:
    Ui::UserManagementWidget *ui;
};

#endif // USERMANAGEMENTWIDGET_H
