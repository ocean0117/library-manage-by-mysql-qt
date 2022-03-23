#ifndef ADDBOOKWINDOW_H
#define ADDBOOKWINDOW_H

#include <QWidget>
#include <QMessageBox>
#include <QComboBox>
#include <QVector>
#include <QFileDialog>
#include <QTextCodec>
#include "datastructure.h"

namespace Ui {
class AddBookWindow;
}

class AddBookWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AddBookWindow(QWidget *parent = 0);
    ~AddBookWindow();

private:
    QWidget *fileWindow;
    int rowcount;
    int numbook;
    QComboBox **tableComboBoxItem_type;
    QComboBox **tableComboBoxItem_year;

    void closeEvent(QCloseEvent *event);
    void addOneBookClear();

signals:
    void Signal_addbookwindowClosed();
    void Signal_addOneBook(Book);
    void Signal_addSomeBooks(QVector<Book>);
private slots:
    void on_Button_addOneBook_clicked();
    void on_Button_addOneBookClear_clicked();
    void on_Button_loadFile_clicked();
    void on_Button_addSomeBooksClear_clicked();
    void on_Button_addSomeBooks_clicked();

private:
    Ui::AddBookWindow *ui;
};

#endif // ADDBOOKWINDOW_H
