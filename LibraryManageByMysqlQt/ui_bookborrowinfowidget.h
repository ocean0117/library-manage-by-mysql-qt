/********************************************************************************
** Form generated from reading UI file 'bookborrowinfowidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKBORROWINFOWIDGET_H
#define UI_BOOKBORROWINFOWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BookBorrowInfoWidget
{
public:
    QGridLayout *gridLayout;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *Button_allSelectBook;
    QPushButton *Button_returnBook;

    void setupUi(QWidget *BookBorrowInfoWidget)
    {
        if (BookBorrowInfoWidget->objectName().isEmpty())
            BookBorrowInfoWidget->setObjectName(QStringLiteral("BookBorrowInfoWidget"));
        BookBorrowInfoWidget->resize(956, 584);
        BookBorrowInfoWidget->setMinimumSize(QSize(778, 300));
        BookBorrowInfoWidget->setMaximumSize(QSize(1195, 736));
        gridLayout = new QGridLayout(BookBorrowInfoWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tableWidget = new QTableWidget(BookBorrowInfoWidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        gridLayout->addWidget(tableWidget, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(488, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        Button_allSelectBook = new QPushButton(BookBorrowInfoWidget);
        Button_allSelectBook->setObjectName(QStringLiteral("Button_allSelectBook"));
        Button_allSelectBook->setMinimumSize(QSize(120, 30));
        Button_allSelectBook->setMaximumSize(QSize(120, 30));

        horizontalLayout->addWidget(Button_allSelectBook);

        Button_returnBook = new QPushButton(BookBorrowInfoWidget);
        Button_returnBook->setObjectName(QStringLiteral("Button_returnBook"));
        Button_returnBook->setMinimumSize(QSize(120, 30));
        Button_returnBook->setMaximumSize(QSize(120, 30));

        horizontalLayout->addWidget(Button_returnBook);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);


        retranslateUi(BookBorrowInfoWidget);

        QMetaObject::connectSlotsByName(BookBorrowInfoWidget);
    } // setupUi

    void retranslateUi(QWidget *BookBorrowInfoWidget)
    {
        BookBorrowInfoWidget->setWindowTitle(QApplication::translate("BookBorrowInfoWidget", "Form", 0));
        Button_allSelectBook->setText(QApplication::translate("BookBorrowInfoWidget", "\345\205\250\351\200\211", 0));
        Button_returnBook->setText(QApplication::translate("BookBorrowInfoWidget", "\345\275\222\350\277\230\344\271\246\347\261\215", 0));
    } // retranslateUi

};

namespace Ui {
    class BookBorrowInfoWidget: public Ui_BookBorrowInfoWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKBORROWINFOWIDGET_H
