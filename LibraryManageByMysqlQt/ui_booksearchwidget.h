/********************************************************************************
** Form generated from reading UI file 'booksearchwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKSEARCHWIDGET_H
#define UI_BOOKSEARCHWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BookSearchWidget
{
public:
    QGridLayout *gridLayout_2;
    QTreeWidget *treeWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QGridLayout *gridLayout_5;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *LineEdit_bookID;
    QLabel *label_5;
    QComboBox *comboBox_date1;
    QLabel *label_8;
    QLineEdit *LineEdit_price1;
    QGridLayout *gridLayout_3;
    QLabel *label_2;
    QLabel *label_6;
    QComboBox *comboBox_date2;
    QLabel *label_9;
    QLineEdit *LineEdit_price2;
    QLineEdit *LineEdit_bookName;
    QGridLayout *gridLayout_4;
    QLabel *label_3;
    QLineEdit *LineEdit_authorName;
    QLabel *label_7;
    QLineEdit *LineEdit_publisher;
    QCheckBox *checkBox_haveStock;
    QWidget *widget_2;
    QGridLayout *gridLayout_6;
    QPushButton *Button_Search;
    QPushButton *Button_Clear;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *Button_lendBook;

    void setupUi(QWidget *BookSearchWidget)
    {
        if (BookSearchWidget->objectName().isEmpty())
            BookSearchWidget->setObjectName(QStringLiteral("BookSearchWidget"));
        BookSearchWidget->resize(1032, 663);
        BookSearchWidget->setMinimumSize(QSize(778, 300));
        BookSearchWidget->setMaximumSize(QSize(1195, 736));
        BookSearchWidget->setAutoFillBackground(false);
        gridLayout_2 = new QGridLayout(BookSearchWidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        treeWidget = new QTreeWidget(BookSearchWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setMinimumSize(QSize(100, 0));
        treeWidget->setMaximumSize(QSize(200, 16777215));

        gridLayout_2->addWidget(treeWidget, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        widget = new QWidget(BookSearchWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(0, 140));
        widget->setMaximumSize(QSize(800, 140));
        gridLayout_5 = new QGridLayout(widget);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        LineEdit_bookID = new QLineEdit(widget);
        LineEdit_bookID->setObjectName(QStringLiteral("LineEdit_bookID"));
        LineEdit_bookID->setMaximumSize(QSize(199, 16777215));

        gridLayout->addWidget(LineEdit_bookID, 0, 1, 1, 1);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 1, 0, 1, 1);

        comboBox_date1 = new QComboBox(widget);
        comboBox_date1->setObjectName(QStringLiteral("comboBox_date1"));
        comboBox_date1->setMinimumSize(QSize(0, 0));

        gridLayout->addWidget(comboBox_date1, 1, 1, 1, 1);

        label_8 = new QLabel(widget);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 2, 0, 1, 1);

        LineEdit_price1 = new QLineEdit(widget);
        LineEdit_price1->setObjectName(QStringLiteral("LineEdit_price1"));

        gridLayout->addWidget(LineEdit_price1, 2, 1, 1, 1);


        horizontalLayout_2->addLayout(gridLayout);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_3->addWidget(label_2, 0, 0, 1, 1);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_3->addWidget(label_6, 1, 0, 1, 1);

        comboBox_date2 = new QComboBox(widget);
        comboBox_date2->setObjectName(QStringLiteral("comboBox_date2"));
        comboBox_date2->setMinimumSize(QSize(0, 0));
        comboBox_date2->setMaximumSize(QSize(199, 16777215));

        gridLayout_3->addWidget(comboBox_date2, 1, 1, 1, 1);

        label_9 = new QLabel(widget);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_3->addWidget(label_9, 2, 0, 1, 1);

        LineEdit_price2 = new QLineEdit(widget);
        LineEdit_price2->setObjectName(QStringLiteral("LineEdit_price2"));
        LineEdit_price2->setMaximumSize(QSize(199, 16777215));

        gridLayout_3->addWidget(LineEdit_price2, 2, 1, 1, 1);

        LineEdit_bookName = new QLineEdit(widget);
        LineEdit_bookName->setObjectName(QStringLiteral("LineEdit_bookName"));
        LineEdit_bookName->setMaximumSize(QSize(199, 16777215));

        gridLayout_3->addWidget(LineEdit_bookName, 0, 1, 1, 1);


        horizontalLayout_2->addLayout(gridLayout_3);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout_4->addWidget(label_3, 0, 0, 1, 1);

        LineEdit_authorName = new QLineEdit(widget);
        LineEdit_authorName->setObjectName(QStringLiteral("LineEdit_authorName"));

        gridLayout_4->addWidget(LineEdit_authorName, 0, 1, 1, 1);

        label_7 = new QLabel(widget);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_4->addWidget(label_7, 1, 0, 1, 1);

        LineEdit_publisher = new QLineEdit(widget);
        LineEdit_publisher->setObjectName(QStringLiteral("LineEdit_publisher"));

        gridLayout_4->addWidget(LineEdit_publisher, 1, 1, 1, 1);

        checkBox_haveStock = new QCheckBox(widget);
        checkBox_haveStock->setObjectName(QStringLiteral("checkBox_haveStock"));

        gridLayout_4->addWidget(checkBox_haveStock, 2, 0, 1, 2);


        horizontalLayout_2->addLayout(gridLayout_4);


        verticalLayout_2->addLayout(horizontalLayout_2);


        gridLayout_5->addLayout(verticalLayout_2, 0, 0, 1, 1);


        horizontalLayout->addWidget(widget);

        widget_2 = new QWidget(BookSearchWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setMinimumSize(QSize(0, 140));
        widget_2->setMaximumSize(QSize(16777215, 140));
        gridLayout_6 = new QGridLayout(widget_2);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        Button_Search = new QPushButton(widget_2);
        Button_Search->setObjectName(QStringLiteral("Button_Search"));
        Button_Search->setMinimumSize(QSize(120, 30));
        Button_Search->setMaximumSize(QSize(120, 30));

        gridLayout_6->addWidget(Button_Search, 0, 0, 1, 1);

        Button_Clear = new QPushButton(widget_2);
        Button_Clear->setObjectName(QStringLiteral("Button_Clear"));
        Button_Clear->setMinimumSize(QSize(120, 30));
        Button_Clear->setMaximumSize(QSize(120, 30));

        gridLayout_6->addWidget(Button_Clear, 1, 0, 1, 1);


        horizontalLayout->addWidget(widget_2);


        verticalLayout->addLayout(horizontalLayout);

        tableWidget = new QTableWidget(BookSearchWidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        verticalLayout->addWidget(tableWidget);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        Button_lendBook = new QPushButton(BookSearchWidget);
        Button_lendBook->setObjectName(QStringLiteral("Button_lendBook"));
        Button_lendBook->setMinimumSize(QSize(120, 30));
        Button_lendBook->setMaximumSize(QSize(120, 30));

        horizontalLayout_3->addWidget(Button_lendBook);


        verticalLayout->addLayout(horizontalLayout_3);


        gridLayout_2->addLayout(verticalLayout, 0, 1, 1, 1);


        retranslateUi(BookSearchWidget);

        QMetaObject::connectSlotsByName(BookSearchWidget);
    } // setupUi

    void retranslateUi(QWidget *BookSearchWidget)
    {
        BookSearchWidget->setWindowTitle(QApplication::translate("BookSearchWidget", "Form", 0));
        label_4->setText(QApplication::translate("BookSearchWidget", "<h2>\347\262\276\347\241\256\346\243\200\347\264\242</h2>", 0));
        label->setText(QApplication::translate("BookSearchWidget", "\344\271\246\347\261\215\347\274\226\345\217\267", 0));
        label_5->setText(QApplication::translate("BookSearchWidget", "\345\207\272\347\211\210\345\271\264\344\273\275", 0));
        label_8->setText(QApplication::translate("BookSearchWidget", "\344\273\267\346\240\274    ", 0));
        label_2->setText(QApplication::translate("BookSearchWidget", "\344\271\246\345\220\215", 0));
        label_6->setText(QApplication::translate("BookSearchWidget", "\342\200\224\342\200\224", 0));
        label_9->setText(QApplication::translate("BookSearchWidget", "\342\200\224\342\200\224", 0));
        label_3->setText(QApplication::translate("BookSearchWidget", "\344\275\234\350\200\205  ", 0));
        label_7->setText(QApplication::translate("BookSearchWidget", "\345\207\272\347\211\210\347\244\276", 0));
        checkBox_haveStock->setText(QApplication::translate("BookSearchWidget", "\345\217\252\351\200\211\346\213\251\346\234\211\345\211\251\344\275\231\347\232\204\344\271\246\347\261\215", 0));
        Button_Search->setText(QApplication::translate("BookSearchWidget", "\345\274\200\345\247\213\346\243\200\347\264\242", 0));
        Button_Clear->setText(QApplication::translate("BookSearchWidget", "\346\201\242\345\244\215\351\273\230\350\256\244", 0));
        Button_lendBook->setText(QApplication::translate("BookSearchWidget", "\345\200\237\351\230\205\344\271\246\347\261\215", 0));
    } // retranslateUi

};

namespace Ui {
    class BookSearchWidget: public Ui_BookSearchWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKSEARCHWIDGET_H
