#ifndef USERMANAGEMENTWIDGET_H
#define USERMANAGEMENTWIDGET_H

#include <QWidget>
#include <QTableWidgetItem>

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
    void on_Button_addUser_clicked();

    void SLOT_usermanagementResult(QVector<People>);
private:
    int rowcount;
    int numuser;
    QTableWidgetItem** tablecheckitem;

private:
    Ui::UserManagementWidget *ui;
};

#endif // USERMANAGEMENTWIDGET_H
