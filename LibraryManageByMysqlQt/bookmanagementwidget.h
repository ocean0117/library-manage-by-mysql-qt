#ifndef BOOKMANAGEMENTWIDGET_H
#define BOOKMANAGEMENTWIDGET_H

#include <QWidget>
#include <QTableWidgetItem>
#include <QMessageBox>
#include "datastructure.h"

namespace Ui {
class BookManagementWidget;
}

class BookManagementWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BookManagementWidget(QWidget *parent = 0);
    ~BookManagementWidget();

private slots:
    void on_Button_Search_clicked();
    void SLOT_bookmanagementResult(QVector<Book>);
    void SLOT_enableButton_SearchBookDetail();
    void SLOT_disableButton_SearchBookDetail();

    void SLOT_enableButton_addBook();
    void SLOT_disableButton_addBook();

    void on_Button_addBook_clicked();
    void on_Button_deleteBook_clicked();

signals:
    void Signal_SearchBookDetailInfo(QString);
    void Signal_addBook();
    void Signal_deleteBook(QVector<QString>);

private:
    int rowcount;
    int numbook;
    QTableWidgetItem** tablecheckitem;

private:
    Ui::BookManagementWidget *ui;
};

#endif // BOOKMANAGEMENTWIDGET_H
