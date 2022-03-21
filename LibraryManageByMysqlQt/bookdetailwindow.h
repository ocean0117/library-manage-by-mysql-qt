#ifndef BOOKDETAILWINDOW_H
#define BOOKDETAILWINDOW_H

#include <QWidget>
#include <QDate>
#include <QMessageBox>
#include "datastructure.h"

namespace Ui {
class BookDetailWindow;
}

class BookDetailWindow : public QWidget
{
    Q_OBJECT

public:
    explicit BookDetailWindow(QWidget *parent = 0);
    ~BookDetailWindow();

private:
    int rowcount;
    int numuser;

    BookDetial bookdetialNow;
    BookDetial bookdetialOld;

    void closeEvent(QCloseEvent *event);
    void bookdetailUpdate(BookDetial userdetialNow);

signals:
    void Signal_bookdetailwindowClosed();
    void Signal_changeBookInfo(BookDetial);
    void Signal_deleteBook(BookDetial);

private slots:
    void SLOT_SearchBookDetailUpdate(BookDetial);

    void on_Button_changeBookInfo_clicked();
    void on_Button_deleteBook_clicked();

    void SLOT_OnlyBookDetailUpdate(BookDetial);

private:
    Ui::BookDetailWindow *ui;
};

#endif // BOOKDETAILWINDOW_H
