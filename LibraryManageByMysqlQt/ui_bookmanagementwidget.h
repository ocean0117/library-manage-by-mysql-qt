/********************************************************************************
** Form generated from reading UI file 'bookmanagementwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKMANAGEMENTWIDGET_H
#define UI_BOOKMANAGEMENTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BookManagementWidget
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_bookID;
    QLineEdit *LineEdit_bookID;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *Button_Search;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableWidget *tableWidget;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QPushButton *Button_deleteBook;
    QPushButton *Button_addBook;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *BookManagementWidget)
    {
        if (BookManagementWidget->objectName().isEmpty())
            BookManagementWidget->setObjectName(QStringLiteral("BookManagementWidget"));
        BookManagementWidget->resize(1195, 736);
        BookManagementWidget->setMinimumSize(QSize(1195, 736));
        BookManagementWidget->setMaximumSize(QSize(1195, 736));
        gridLayout_3 = new QGridLayout(BookManagementWidget);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        groupBox = new QGroupBox(BookManagementWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(290, 130));
        groupBox->setMaximumSize(QSize(290, 130));
        groupBox->setSizeIncrement(QSize(0, 0));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(0, 0));
        label_2->setMaximumSize(QSize(290, 16777215));
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_2);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        gridLayout_2->addLayout(horizontalLayout_2, 0, 0, 1, 3);

        verticalSpacer_2 = new QSpacerItem(20, 1, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 1, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_bookID = new QLabel(groupBox);
        label_bookID->setObjectName(QStringLiteral("label_bookID"));
        label_bookID->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout->addWidget(label_bookID);

        LineEdit_bookID = new QLineEdit(groupBox);
        LineEdit_bookID->setObjectName(QStringLiteral("LineEdit_bookID"));
        LineEdit_bookID->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout->addWidget(LineEdit_bookID);


        gridLayout_2->addLayout(horizontalLayout, 2, 0, 1, 3);

        horizontalSpacer_3 = new QSpacerItem(48, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 3, 0, 1, 1);

        Button_Search = new QPushButton(groupBox);
        Button_Search->setObjectName(QStringLiteral("Button_Search"));
        Button_Search->setMinimumSize(QSize(150, 30));
        Button_Search->setMaximumSize(QSize(150, 30));

        gridLayout_2->addWidget(Button_Search, 3, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(48, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 3, 2, 1, 1);


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(BookManagementWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        tableWidget = new QTableWidget(BookManagementWidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        verticalLayout->addWidget(tableWidget);


        gridLayout_3->addLayout(verticalLayout, 0, 1, 3, 1);

        groupBox_2 = new QGroupBox(BookManagementWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(290, 0));
        groupBox_2->setMaximumSize(QSize(290, 16777215));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        Button_deleteBook = new QPushButton(groupBox_2);
        Button_deleteBook->setObjectName(QStringLiteral("Button_deleteBook"));
        Button_deleteBook->setMinimumSize(QSize(150, 30));
        Button_deleteBook->setMaximumSize(QSize(150, 30));

        gridLayout->addWidget(Button_deleteBook, 1, 0, 1, 1);

        Button_addBook = new QPushButton(groupBox_2);
        Button_addBook->setObjectName(QStringLiteral("Button_addBook"));
        Button_addBook->setMinimumSize(QSize(150, 30));
        Button_addBook->setMaximumSize(QSize(150, 30));

        gridLayout->addWidget(Button_addBook, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_2, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 439, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 2, 0, 1, 1);


        retranslateUi(BookManagementWidget);

        QMetaObject::connectSlotsByName(BookManagementWidget);
    } // setupUi

    void retranslateUi(QWidget *BookManagementWidget)
    {
        BookManagementWidget->setWindowTitle(QApplication::translate("BookManagementWidget", "Form", 0));
        groupBox->setTitle(QString());
        label_2->setText(QApplication::translate("BookManagementWidget", "<html><head/><body><p><span style=\" font-size:x-large; font-weight:600;\">\344\271\246\347\261\215\350\257\246\347\273\206\344\277\241\346\201\257</span></p></body></html>", 0));
        label_bookID->setText(QApplication::translate("BookManagementWidget", "\350\257\267\350\276\223\345\205\245\344\271\246\347\261\215\347\274\226\345\217\267\357\274\232", 0));
        Button_Search->setText(QApplication::translate("BookManagementWidget", "\346\237\245\350\257\242/\346\233\264\346\224\271", 0));
        label->setText(QApplication::translate("BookManagementWidget", "<html><head/><body><p><span style=\" font-size:xx-large; font-weight:600;\">\344\271\246\347\261\215\344\277\241\346\201\257\345\210\227\350\241\250</span></p></body></html>", 0));
        groupBox_2->setTitle(QString());
        Button_deleteBook->setText(QApplication::translate("BookManagementWidget", "\345\210\240\351\231\244\344\271\246\347\261\215", 0));
        Button_addBook->setText(QApplication::translate("BookManagementWidget", "\346\267\273\345\212\240\344\271\246\347\261\215", 0));
    } // retranslateUi

};

namespace Ui {
    class BookManagementWidget: public Ui_BookManagementWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKMANAGEMENTWIDGET_H
