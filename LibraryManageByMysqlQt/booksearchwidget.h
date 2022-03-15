#ifndef BOOKSEARCHWIDGET_H
#define BOOKSEARCHWIDGET_H

#include <QWidget>
#include <QTreeWidgetItem>
#include <QTableWidgetItem>
#include <QDate>

#include "datastructure.h"

namespace Ui {
class BookSearchWidget;
}

class BookSearchWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BookSearchWidget(QWidget *parent = 0);
    ~BookSearchWidget();

private slots:
    void on_Button_Search_clicked();
    void on_Button_Clear_clicked();

private:
    QTreeWidgetItem *treeitemroot;
    BookQuery bookquery;
    int rowcount;
    int numbook;
    QTableWidgetItem** tablecheckitem;

    void Update();
    void Clear();
signals:
    void Signal_bookquerySearch(BookQuery);
    void Signal_bookBorrow(QVector<QString>);

private slots:
    void SLOT_bookqueryResult(QVector<Book>,People*);
    void SLOT_loginQuit();
    void on_Button_lendBook_clicked();

private:
    Ui::BookSearchWidget *ui;
};

#endif // BOOKSEARCHWIDGET_H
