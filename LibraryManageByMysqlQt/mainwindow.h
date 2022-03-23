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
#include <QSqlRecord>

#include "datastructure.h"
#include "loginwindow.h"
#include "registerwindow.h"
#include "booksearchwidget.h"
#include "bookborrowinfowidget.h"
#include "usermanagementwidget.h"
#include "userdetailwindow.h"
#include "bookmanagementwidget.h"
#include "bookdetailwindow.h"
#include "addbookwindow.h"

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
    LoginWindow *loginwindow; // (登录界面)
    RegisterWindow *registerwindow; // (注册界面)
    UserDetailWindow *userdetailwindow; // (用户详细信息界面)
    BookDetailWindow *bookdetailwindow; // (书籍详细信息界面)
    AddBookWindow *addbookwindow; // (书籍添加界面)

    BookSearchWidget *booksearchwidget; // (书籍搜索页面)
    BookBorrowInfoWidget *bookborrowinfowidget; // (借阅情况页面)
    UserManagementWidget *usermanagementwidget; // (用户管理页面)
    BookManagementWidget *bookmanagementwidget; // (书籍管理页面)

    QSqlDatabase db;
    People *people;
    QTimer* timer;

    // 界面关闭时，处理
    void closeEvent(QCloseEvent *event);

    // 登录、注册界面
    void loginwindowCreateAndShow();
    void registerwindowCreateAndShow();

    // 数据搜索页面
    void booksearchwidgetCreate();
    void bookquerySearchUpdate(BookQuery bookquery);
    void bookquerySearchUpdate();
    QVector<Book> booksData(BookQuery, bool);

    // 借阅情况页面
    void bookborrowinfowidgetCreate();
    void bookborrowqueryUpdate();

    // 用户管理页面
    void usermanagementwidgetCreate();
    void usermanagementUpdate();
    void userdetailwindowClosed();

    // 书籍管理页面
    void bookmanagementwidgetCreate();
    void bookmanagementUpdate();
    void bookdetailwindowClosed();
    void addbookwindowClosed();


private slots:
    void SLOT_updatetime();
    // 登录、注册界面
    void on_Button_login_clicked();
    void SLOT_loginQuit();
    void SLOT_login(bool,QVector<QString>);

    void on_Button_register_clicked();
    void SLOT_registerQuit();
    void SLOT_register(QVector<QString>);

    void on_Button_quitLogin_clicked();

    // 书籍搜索页面
    void SLOT_bookquerySearch(BookQuery);
    void SLOT_bookBorrow(QVector<QString>);

    // 借阅情况页面
    void SLOT_bookReturn(QVector<QString>);

    // 用户管理页面
    void SLOT_SearchUserDetailInfo(QString);
    void SLOT_userdetailwindowClosed();
    void SLOT_changeUserInfo(UserDetial);
    void SLOT_deleteUser(UserDetial);
    void SLOT_changeUserPri(QVector<QString>);
    void SLOT_deleteUser(QVector<QString>);

    // 书籍管理页面
    void SLOT_SearchBookDetailInfo(QString);
    void SLOT_bookdetailwindowClosed();
    void SLOT_changeBookInfo(BookDetial);
    void SLOT_deleteBook(BookDetial);
    void SLOT_addBook();
    void SLOT_deleteBook(QVector<QString>);
    void SLOT_addbookwindowClosed();

    void SLOT_addOneBook(Book);
    void SLOT_addSomeBooks(QVector<Book>);

signals:
    // 书籍搜索页面
    void Signal_bookqueryResult(QVector<Book>,People*);
    void Signal_booksearchwidgetClearAndUpdate();

    // 借阅情况页面
    void Signal_bookborrowqueryResult(QVector<BorrowBook>,People*);

    // 用户管理页面
    void Signal_usermanagementResult(QVector<People>);
    void Signal_SearchUserDetailUpdate(UserDetial);
    void Signal_enableButton_SearchUserDetail();
    void Signal_disableButton_SearchUserDetail();
    void Signal_OnlyUserDetailUpdate(UserDetial);

    // 书籍管理页面
    void Signal_bookmanagementResult(QVector<Book>);
    void Signal_SearchBookDetailUpdate(BookDetial);
    void Signal_enableButton_SearchBookDetail();
    void Signal_disableButton_SearchBookDetail();
    void Signal_OnlyBookDetailUpdate(BookDetial);
    void Signal_enableButton_addBook();
    void Signal_disableButton_addBook();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
