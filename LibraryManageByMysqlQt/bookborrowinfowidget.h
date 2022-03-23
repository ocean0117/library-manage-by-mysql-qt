#ifndef BOOKBORROWINFOWIDGET_H
#define BOOKBORROWINFOWIDGET_H

#include <QWidget>
#include <QDate>
#include <QTableWidgetItem>
#include "datastructure.h"

namespace Ui {
class BookBorrowInfoWidget;
}

class BookBorrowInfoWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BookBorrowInfoWidget(QWidget *parent = 0);
    ~BookBorrowInfoWidget();

signals:
    void Signal_bookReturn(QVector<QString>);

private:
    QTableWidgetItem** tablecheckitem;
    int rowcount;
    int numbook;

private slots:
    void on_Button_allSelectBook_clicked();
    void on_Button_returnBook_clicked();
    void SLOT_bookborrowqueryResult(QVector<BorrowBook>,People*);

private:
    Ui::BookBorrowInfoWidget *ui;
};

#endif // BOOKBORROWINFOWIDGET_H
