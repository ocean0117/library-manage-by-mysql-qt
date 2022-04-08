/********************************************************************************
** Form generated from reading UI file 'usermanagementwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERMANAGEMENTWIDGET_H
#define UI_USERMANAGEMENTWIDGET_H

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

class Ui_UserManagementWidget
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
    QLabel *label_userID;
    QLineEdit *LineEdit_userID;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *Button_Search;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QPushButton *Button_addUser;
    QPushButton *Button_changePri;
    QPushButton *Button_deleteUser;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableWidget *tableWidget;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *UserManagementWidget)
    {
        if (UserManagementWidget->objectName().isEmpty())
            UserManagementWidget->setObjectName(QStringLiteral("UserManagementWidget"));
        UserManagementWidget->resize(864, 500);
        UserManagementWidget->setMinimumSize(QSize(778, 300));
        UserManagementWidget->setMaximumSize(QSize(1195, 736));
        gridLayout_3 = new QGridLayout(UserManagementWidget);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        groupBox = new QGroupBox(UserManagementWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMinimumSize(QSize(0, 130));
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
        label_userID = new QLabel(groupBox);
        label_userID->setObjectName(QStringLiteral("label_userID"));
        label_userID->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout->addWidget(label_userID);

        LineEdit_userID = new QLineEdit(groupBox);
        LineEdit_userID->setObjectName(QStringLiteral("LineEdit_userID"));
        LineEdit_userID->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout->addWidget(LineEdit_userID);


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

        groupBox_2 = new QGroupBox(UserManagementWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(0, 0));
        groupBox_2->setMaximumSize(QSize(290, 16777215));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        Button_addUser = new QPushButton(groupBox_2);
        Button_addUser->setObjectName(QStringLiteral("Button_addUser"));
        Button_addUser->setMinimumSize(QSize(150, 30));
        Button_addUser->setMaximumSize(QSize(150, 30));

        gridLayout->addWidget(Button_addUser, 2, 0, 1, 1);

        Button_changePri = new QPushButton(groupBox_2);
        Button_changePri->setObjectName(QStringLiteral("Button_changePri"));
        Button_changePri->setMinimumSize(QSize(150, 30));
        Button_changePri->setMaximumSize(QSize(150, 30));

        gridLayout->addWidget(Button_changePri, 0, 0, 1, 1);

        Button_deleteUser = new QPushButton(groupBox_2);
        Button_deleteUser->setObjectName(QStringLiteral("Button_deleteUser"));
        Button_deleteUser->setMinimumSize(QSize(150, 30));
        Button_deleteUser->setMaximumSize(QSize(150, 30));

        gridLayout->addWidget(Button_deleteUser, 1, 0, 1, 1);


        gridLayout_3->addWidget(groupBox_2, 1, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(UserManagementWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        tableWidget = new QTableWidget(UserManagementWidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        verticalLayout->addWidget(tableWidget);


        gridLayout_3->addLayout(verticalLayout, 0, 1, 3, 1);

        verticalSpacer = new QSpacerItem(287, 203, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 2, 0, 1, 1);

        groupBox->raise();
        groupBox_2->raise();
        tableWidget->raise();

        retranslateUi(UserManagementWidget);

        QMetaObject::connectSlotsByName(UserManagementWidget);
    } // setupUi

    void retranslateUi(QWidget *UserManagementWidget)
    {
        UserManagementWidget->setWindowTitle(QApplication::translate("UserManagementWidget", "Form", 0));
        groupBox->setTitle(QString());
        label_2->setText(QApplication::translate("UserManagementWidget", "<html><head/><body><p><span style=\" font-size:x-large; font-weight:600;\">\347\224\250\346\210\267\350\257\246\347\273\206\344\277\241\346\201\257</span></p></body></html>", 0));
        label_userID->setText(QApplication::translate("UserManagementWidget", "\350\257\267\350\276\223\345\205\245\347\224\250\346\210\267\345\255\246\345\217\267\357\274\232", 0));
        Button_Search->setText(QApplication::translate("UserManagementWidget", "\346\237\245\350\257\242/\346\233\264\346\224\271", 0));
        groupBox_2->setTitle(QString());
        Button_addUser->setText(QApplication::translate("UserManagementWidget", "\346\267\273\345\212\240\346\226\260\347\224\250\346\210\267", 0));
        Button_changePri->setText(QApplication::translate("UserManagementWidget", "\346\233\264\346\224\271\347\224\250\346\210\267\346\235\203\351\231\220", 0));
        Button_deleteUser->setText(QApplication::translate("UserManagementWidget", "\345\210\240\351\231\244\347\224\250\346\210\267", 0));
        label->setText(QApplication::translate("UserManagementWidget", "<h1>\347\224\250\346\210\267\344\277\241\346\201\257\345\210\227\350\241\250</h1>", 0));
    } // retranslateUi

};

namespace Ui {
    class UserManagementWidget: public Ui_UserManagementWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERMANAGEMENTWIDGET_H
