#include "addbookwindow.h"
#include "ui_addbookwindow.h"
#include <QDebug>
AddBookWindow::AddBookWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddBookWindow)
{
    ui->setupUi(this);

    fileWindow = new QWidget;

    const int numbooktype = sizeof(booktype)/sizeof(booktype[0]);

    ui->comboBox_type->addItem("");
    for (int i = 0; i<numbooktype; i++)
    {
        ui->comboBox_type->addItem(booktype[i]);
    }
    ui->comboBox_year->addItem("");
    for (int i = 0; i<100; i++) {
        ui->comboBox_year->addItem(QString::number(2022 - i));
    }

    //表格
    const QString tableheader[] = {"编号","书名","价格/元","总库存/本","类型","作者","出版社","出版年份"};
    const int numheader=sizeof(tableheader)/sizeof(tableheader[0]);

    numbook=0; //表格中的书本数量
    rowcount = 20; // rowcount每次默认最多添加20
    ui->tableWidget->setRowCount(rowcount);
    ui->tableWidget->setColumnCount(numheader);

    QStringList header;
    for (int i = 0; i < numheader; i++)
            header << tableheader[i];
    ui->tableWidget->setHorizontalHeaderLabels(header);
    for (int i = 0; i < numheader; i++)
    {
        ui->tableWidget->setColumnWidth(i, 120);
    }

    tableComboBoxItem_type = NULL;
    tableComboBoxItem_type = new QComboBox*[rowcount];
    for (int i = 0; i < rowcount; i++)
    {
        tableComboBoxItem_type[i] = new QComboBox();

        tableComboBoxItem_type[i]->addItem("");
        for (int j = 0; j<numbooktype; j++)
        {
            tableComboBoxItem_type[i]->addItem(booktype[j]);
        }

        ui->tableWidget->setCellWidget(i, 4, tableComboBoxItem_type[i]);
    }

    tableComboBoxItem_year = NULL;
    tableComboBoxItem_year = new QComboBox*[rowcount];
    for (int i = 0; i < rowcount; i++)
    {
        tableComboBoxItem_year[i] = new QComboBox();

        tableComboBoxItem_year[i]->addItem("");
        for (int j = 0; j<100; j++)
        {
            tableComboBoxItem_year[i]->addItem(QString::number(2022 - j));
        }

        ui->tableWidget->setCellWidget(i, 7, tableComboBoxItem_year[i]);
    }
}

AddBookWindow::~AddBookWindow()
{
    delete ui;

    delete fileWindow;

    if(tableComboBoxItem_type!=NULL)
    {
        for(int i=0;i<rowcount;i++)
        {
           delete tableComboBoxItem_type[i];
        }
        delete []tableComboBoxItem_type;
        tableComboBoxItem_type=NULL;

        if(tableComboBoxItem_year!=NULL)
        {
            for(int i=0;i<rowcount;i++)
            {
               delete tableComboBoxItem_year[i];
            }
            delete []tableComboBoxItem_year;
            tableComboBoxItem_year=NULL;
        }

        rowcount = 0;
    }

    numbook = 0;
}

void AddBookWindow::closeEvent(QCloseEvent *event)
{
    emit Signal_addbookwindowClosed();
}

void AddBookWindow::on_Button_addOneBook_clicked()
{
    Book addbook;
    addbook.book_id = ui->LineEdit_bookID->text().trimmed();
    if(!addbook.book_id.contains(QRegExp("^\\d+$")))//book_id很重要，判断是否为纯数字
    {
        QMessageBox::critical(NULL, "Error", "请填写正确的书籍编号，注意必须为纯数字", QMessageBox::Yes);
    }
    else
    {
        addbook.name = ui->LineEdit_bookName->text().trimmed();
        addbook.author_name = ui->LineEdit_auther->text().trimmed();
        addbook.price = ui->LineEdit_price->text().toDouble();
        addbook.num = ui->LineEdit_booknum->text().toInt();
        addbook.stock =  addbook.num;
        addbook.publisher = ui->LineEdit_publisher->text().trimmed();
        addbook.publish_year = ui->comboBox_year->currentText();
        addbook.type = ui->comboBox_type->currentText();

        if(addbook.name=="" || addbook.author_name=="" || addbook.price <=0 ||
           addbook.num <=0 || addbook.stock <=0 || addbook.publisher== "" ||
           addbook.publish_year.toInt() == 0 || addbook.type == "")
        {
            QMessageBox::critical(NULL, "Error", "请填写正确的书籍信息", QMessageBox::Yes);
        }
        else
        {
            emit Signal_addOneBook(addbook);
        }
    }
}

void AddBookWindow::on_Button_addOneBookClear_clicked()
{
    addOneBookClear();
}

void AddBookWindow::addOneBookClear()
{
    ui->LineEdit_bookID->clear();
    ui->LineEdit_bookName->clear();
    ui->comboBox_type->setCurrentIndex(0);
    ui->LineEdit_auther->clear();
    ui->LineEdit_publisher->clear();
    ui->comboBox_year->setCurrentIndex(0);
    ui->LineEdit_price->clear();
    ui->LineEdit_booknum->clear();
}

void AddBookWindow::on_Button_loadFile_clicked()
{

    QTextCodec *code=QTextCodec::codecForName("utf8");
    QString path = QFileDialog::getOpenFileName(fileWindow, tr("Open File"), ".", tr("Files(*.txt)"));
    if (!path.isEmpty())
    {
        QFile file(path);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            return;
        }
        QTextStream in(&file);
        in.setCodec(code);
        QString content0 = in.readAll();
        file.close();

        Book addbook;

        QStringList list0 = content0.split("\n");
        if(list0.size()!=0)
        {
            foreach (QString content1, list0)
            {
                QStringList list = content1.split(" ");
                if(list.size() == 8)
                {
                    addbook.book_id = list.at(0).trimmed();
                    addbook.name = list.at(1).trimmed();
                    addbook.price = list.at(2).toDouble();
                    addbook.num = list.at(3).toInt();
                    addbook.stock =  addbook.num; //不能注释，否则下满条件语句不能通过。这里赋值，只是为了不修改下面的判断条件，实际没有用
                    addbook.type = list.at(4);
                    addbook.author_name = list.at(5);
                    addbook.publisher = list.at(6);
                    addbook.publish_year = list.at(7);

                    if(numbook < 20 && addbook.book_id.contains(QRegExp("^\\d+$")))//book_id很重要，判断为纯数字
                    {
                        if(!(addbook.name=="" || addbook.author_name=="" || addbook.price <=0 ||
                           addbook.num <=0 || addbook.stock <=0 || addbook.publisher== "" ||
                           addbook.publish_year.toInt() == 0 || addbook.type == "")) // 正确的书籍信息
                        {
                            ui->tableWidget->setItem(numbook, 0, new QTableWidgetItem(addbook.book_id));
                            ui->tableWidget->setItem(numbook, 1, new QTableWidgetItem(addbook.name));
                            ui->tableWidget->setItem(numbook, 2, new QTableWidgetItem(QString::number(addbook.price,'f',2)));
                            ui->tableWidget->setItem(numbook, 3, new QTableWidgetItem(QString::number(addbook.num,10)));
                            tableComboBoxItem_type[numbook]->setCurrentText(addbook.type);
                            ui->tableWidget->setItem(numbook, 5, new QTableWidgetItem(addbook.author_name));
                            ui->tableWidget->setItem(numbook, 6, new QTableWidgetItem(addbook.publisher));
                            tableComboBoxItem_year[numbook]->setCurrentText(addbook.publish_year);

                            numbook++;
                            if(numbook>=20)
                                break;
                        }
                    }
                }
            }
        }
    }
}

void AddBookWindow::on_Button_addSomeBooksClear_clicked()
{
    const int numbooktype = sizeof(booktype)/sizeof(booktype[0]);

    if(tableComboBoxItem_type!=NULL)
    {
        for(int i=0;i<rowcount;i++)
        {
           delete tableComboBoxItem_type[i];
        }
        delete []tableComboBoxItem_type;
        tableComboBoxItem_type=NULL;

        if(tableComboBoxItem_year!=NULL)
        {
            for(int i=0;i<rowcount;i++)
            {
               delete tableComboBoxItem_year[i];
            }
            delete []tableComboBoxItem_year;
            tableComboBoxItem_year=NULL;
        }

        rowcount = 0;
    }

    numbook = 0;

    ui->tableWidget->clearContents(); // clear清除所有，包括表头；clearContents只清除内容，不包含表头

    rowcount = 20;
    tableComboBoxItem_type = new QComboBox*[rowcount];
    for (int i = 0; i < rowcount; i++)
    {
        tableComboBoxItem_type[i] = new QComboBox();

        tableComboBoxItem_type[i]->addItem("");
        for (int j = 0; j<numbooktype; j++)
        {
            tableComboBoxItem_type[i]->addItem(booktype[j]);
        }

        ui->tableWidget->setCellWidget(i, 4, tableComboBoxItem_type[i]);
    }

    tableComboBoxItem_year = NULL;
    tableComboBoxItem_year = new QComboBox*[rowcount];
    for (int i = 0; i < rowcount; i++)
    {
        tableComboBoxItem_year[i] = new QComboBox();

        tableComboBoxItem_year[i]->addItem("");
        for (int j = 0; j<100; j++)
        {
            tableComboBoxItem_year[i]->addItem(QString::number(2022 - j));
        }

        ui->tableWidget->setCellWidget(i, 7, tableComboBoxItem_year[i]);
    }
}

void AddBookWindow::on_Button_addSomeBooks_clicked()
{
    Book addbook;
    QVector<Book> addbooks;
    for(int i = 0;i < rowcount;i++)
    {
        if(ui->tableWidget->item(i, 0)!=NULL && ui->tableWidget->item(i, 1)!=NULL && ui->tableWidget->item(i, 2)!=NULL &&
           ui->tableWidget->item(i, 3)!=NULL && ui->tableWidget->item(i, 5)!=NULL && ui->tableWidget->item(i, 6)!=NULL &&
           tableComboBoxItem_type[i]->currentIndex()!=0 && tableComboBoxItem_year[i]->currentIndex()!=0)
        {
            addbook.book_id = ui->tableWidget->item(i, 0)->text().trimmed();
            if(addbook.book_id.contains(QRegExp("^\\d+$")))//book_id很重要，判断为纯数字
            {
                addbook.name = ui->tableWidget->item(i, 1)->text().trimmed();
                addbook.price = ui->tableWidget->item(i, 2)->text().toDouble();
                addbook.num = ui->tableWidget->item(i, 3)->text().toInt();
                addbook.stock = addbook.num;
                addbook.type = tableComboBoxItem_type[i]->currentText();
                addbook.author_name = ui->tableWidget->item(i, 5)->text().trimmed();
                addbook.publisher = ui->tableWidget->item(i, 6)->text().trimmed();
                addbook.publish_year = tableComboBoxItem_year[i]->currentText();

                if(!(addbook.name=="" || addbook.author_name=="" || addbook.price <=0 ||
                   addbook.num <=0 || addbook.stock <=0 || addbook.publisher== "" ||
                   addbook.publish_year.toInt() == 0 || addbook.type == "")) // 正确的书籍信息
                {
                    addbooks.append(addbook);
                }
            }
        }
    }
    emit Signal_addSomeBooks(addbooks);
}
