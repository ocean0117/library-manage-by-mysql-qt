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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BookManagementWidget
{
public:

    void setupUi(QWidget *BookManagementWidget)
    {
        if (BookManagementWidget->objectName().isEmpty())
            BookManagementWidget->setObjectName(QStringLiteral("BookManagementWidget"));
        BookManagementWidget->resize(1195, 736);
        BookManagementWidget->setMinimumSize(QSize(1195, 736));
        BookManagementWidget->setMaximumSize(QSize(1195, 736));

        retranslateUi(BookManagementWidget);

        QMetaObject::connectSlotsByName(BookManagementWidget);
    } // setupUi

    void retranslateUi(QWidget *BookManagementWidget)
    {
        BookManagementWidget->setWindowTitle(QApplication::translate("BookManagementWidget", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class BookManagementWidget: public Ui_BookManagementWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKMANAGEMENTWIDGET_H
