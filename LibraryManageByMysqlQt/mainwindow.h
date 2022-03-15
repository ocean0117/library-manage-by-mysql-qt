#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QDateTime>
#include <QTimer>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QWidget>
#include <QMessageBox>

#include "loginwindow.h"
#include "registerwindow.h"
#include "booksearchwidget.h"
#include "bookborrowinfowidget.h"
#include "datastructure.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    People *people;

    QTimer* timer;
    LoginWindow *loginwindow;
    RegisterWindow *registerwindow;
    BookSearchWidget *booksearchwidget;
    BookBorrowInfoWidget *bookborrowinfowidget;

    QSqlDatabase db;

    void bookquerySearch(BookQuery, bool recover);
    void bookborrowqueryUpdate();

private slots:
    void SLOT_updatetime();

    void SLOT_setWindowLogin(); //用户登录
    void SLOT_loginQuit();
    void SLOT_login(bool,QVector<QString>);

    void SLOT_setWindowRegister(); //用户注册
    void SLOT_registerQuit();
    void SLOT_register(QVector<QString>);

    void on_Button_quitLogin_clicked();

    void SLOT_bookquerySearch(BookQuery);
    void SLOT_bookBorrow(QVector<QString>);

    void SLOT_bookReturn(QVector<QString>);

signals:
    void Signal_bookqueryResult(QVector<Book>,People*);
    void Signal_bookborrowqueryResult(QVector<BorrowBook>,People*);
    void Signal_loginQuit();



private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
