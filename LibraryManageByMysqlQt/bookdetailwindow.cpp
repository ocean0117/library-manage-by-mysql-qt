#include "bookdetailwindow.h"
#include "ui_bookdetailwindow.h"
#include <QDebug>
BookDetailWindow::BookDetailWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BookDetailWindow)
{
    ui->setupUi(this);

    numuser=0; // 当前显示的用户数量

    ui->LineEdit_bookID->setFocusPolicy(Qt::NoFocus);//不允许编辑
    ui->LineEdit_out->setFocusPolicy(Qt::NoFocus);

    /*** comboBox设计 ***/
    const int numbooktype=sizeof(booktype)/sizeof(booktype[0]);

    ui->comboBox_type->addItem("");
    for (int i = 0; i<numbooktype; i++) {
        ui->comboBox_type->addItem(booktype[i]);
    }
    ui->comboBox_year->addItem("");
    for (int i = 0; i<100; i++) {
        ui->comboBox_year->addItem(QString::number(2022 - i));
    }

    /*** tableWidget表格设计 ***/
    const QString tableheader[] = { "用户学号","用户姓名","借阅日期","归还日期","剩余归还天数" };
    int numheader=sizeof(tableheader)/sizeof(tableheader[0]);

    rowcount = 0;
    rowcount =rowcount>20?rowcount:20; // rowcount需要根据检索的数量来定，如果检索不到，最小为20
    ui->tableWidget->setRowCount(rowcount);
    ui->tableWidget->setColumnCount(numheader);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);	//设置为只读模式
    ui->tableWidget->setSelectionMode(QAbstractItemView::NoSelection);	//设置为不可选中

    QStringList header;
    for (int i = 0; i < numheader; i++)
            header << tableheader[i];
    ui->tableWidget->setHorizontalHeaderLabels(header);
    for (int i = 0; i < numheader; i++)
    {
        ui->tableWidget->setColumnWidth(i, 160);
    }
}

BookDetailWindow::~BookDetailWindow()
{
    delete ui;
}

void BookDetailWindow::closeEvent(QCloseEvent *event)
{
    emit Signal_bookdetailwindowClosed();
}

 void BookDetailWindow::SLOT_SearchBookDetailUpdate(BookDetial bookdetial)
 {
    bookdetialNow = bookdetial;//用于保存当前书籍的值

    bookdetailUpdate(bookdetialNow);
 }

 void BookDetailWindow::bookdetailUpdate(BookDetial bookdetialNow)
 {
    ui->LineEdit_bookName->setText(bookdetialNow.book.name);
    ui->LineEdit_bookID->setText(bookdetialNow.book.book_id);
    ui->comboBox_type->setCurrentText(bookdetialNow.book.type);
    ui->LineEdit_auther->setText(bookdetialNow.book.author_name);
    ui->LineEdit_publisher->setText(bookdetialNow.book.publisher);
    ui->comboBox_year->setCurrentText(bookdetialNow.book.publish_year);
    ui->LineEdit_price->setText(QString::number(bookdetialNow.book.price, 'f', 2));
    ui->LineEdit_booknum->setText(QString::number(bookdetialNow.book.num, 10));
    ui->LineEdit_out->setText(QString::number(bookdetialNow.book.num - bookdetialNow.book.stock, 10));

     ui->tableWidget->clearContents(); // clear清除所有，包括表头；clearContents只清除内容，不包含表头
     //表格数据显示
     numuser = bookdetialNow.user.size();
     rowcount =numuser>20?numuser:20;
     ui->tableWidget->setRowCount(rowcount);

     for (int i = 0; i < numuser; i++)
     {
         ui->tableWidget->setItem(i,0,new QTableWidgetItem(bookdetialNow.user[i].user.user_ID));
         ui->tableWidget->setItem(i,1,new QTableWidgetItem(bookdetialNow.user[i].user.user_Name));
         ui->tableWidget->setItem(i,2,new QTableWidgetItem(bookdetialNow.user[i].dateBorrow));
         ui->tableWidget->setItem(i,3,new QTableWidgetItem(bookdetialNow.user[i].dateReturn));
         ui->tableWidget->setItem(i,4,new QTableWidgetItem(QString::number(QDate::currentDate().daysTo(QDate::fromString(bookdetialNow.user[i].dateReturn,"yyyy-MM-dd")),10)));
     }
 }


void BookDetailWindow::on_Button_changeBookInfo_clicked()
{
    if(!((bookdetialNow.book.name ==  ui->LineEdit_bookName->text().trimmed()) &&
       (bookdetialNow.book.type == ui->comboBox_type->currentText()) &&
       (bookdetialNow.book.author_name == ui->LineEdit_auther->text().trimmed()) &&
       (bookdetialNow.book.publisher == ui->LineEdit_publisher->text().trimmed()) &&
       (bookdetialNow.book.publish_year == ui->comboBox_year->currentText()) &&
       (bookdetialNow.book.price == ui->LineEdit_price->text().trimmed().toDouble()) &&
       (bookdetialNow.book.num == ui->LineEdit_booknum->text().trimmed().toInt()) &&
       (bookdetialNow.book.stock == (bookdetialNow.book.num - ui->LineEdit_out->text().trimmed().toInt()))))
    {
        bookdetialOld.book.name =  ui->LineEdit_bookName->text().trimmed();
        bookdetialOld.book.type = ui->comboBox_type->currentText();
        bookdetialOld.book.author_name = ui->LineEdit_auther->text().trimmed();
        bookdetialOld.book.publisher = ui->LineEdit_publisher->text().trimmed();
        bookdetialOld.book.publish_year = ui->comboBox_year->currentText();
        bookdetialOld.book.price = ui->LineEdit_price->text().trimmed().toDouble();
        bookdetialOld.book.num = ui->LineEdit_booknum->text().trimmed().toInt();
        bookdetialOld.book.stock = (bookdetialOld.book.num - ui->LineEdit_out->text().trimmed().toInt());

        bookdetialOld.book.book_id = ui->LineEdit_bookID->text().trimmed();//ID不能改变的
        emit Signal_changeBookInfo(bookdetialOld);
    }
    else
    {
        QMessageBox::critical(NULL, "Error", "用户信息未更改成功", QMessageBox::Yes);
    }
}

void BookDetailWindow::on_Button_deleteBook_clicked()
{
    emit Signal_deleteBook(bookdetialNow);
}

void BookDetailWindow::SLOT_OnlyBookDetailUpdate(BookDetial bookdetialOld)
{
    bookdetialNow.book.name= bookdetialOld.book.name;
    bookdetialNow.book.author_name=bookdetialOld.book.author_name;
    bookdetialNow.book.price=bookdetialOld.book.price;
    bookdetialNow.book.num=bookdetialOld.book.num;
    bookdetialNow.book.stock=bookdetialOld.book.stock;
    bookdetialNow.book.publisher=bookdetialOld.book.publisher;
    bookdetialNow.book.publish_year=bookdetialOld.book.publish_year;
    bookdetialNow.book.type=bookdetialOld.book.type;

    bookdetailUpdate(bookdetialNow);
}
