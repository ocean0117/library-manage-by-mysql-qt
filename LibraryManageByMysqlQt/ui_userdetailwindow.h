/********************************************************************************
** Form generated from reading UI file 'userdetailwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERDETAILWINDOW_H
#define UI_USERDETAILWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
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

QT_BEGIN_NAMESPACE

class Ui_UserDetailWindow
{
public:
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_userName;
    QLineEdit *LineEdit_userName;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_password;
    QLineEdit *LineEdit_password;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *checkBox_Pri;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_userID;
    QLineEdit *LineEdit_userID;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_password_3;
    QLineEdit *LineEdit_booknum;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_5;
    QTableWidget *tableWidget;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *Button_changeUserInfo;
    QPushButton *Button_deleteUser;
    QSpacerItem *horizontalSpacer_8;

    void setupUi(QDialog *UserDetailWindow)
    {
        if (UserDetailWindow->objectName().isEmpty())
            UserDetailWindow->setObjectName(QStringLiteral("UserDetailWindow"));
        UserDetailWindow->resize(850, 500);
        UserDetailWindow->setMinimumSize(QSize(850, 440));
        UserDetailWindow->setMaximumSize(QSize(950, 921));
        gridLayout_2 = new QGridLayout(UserDetailWindow);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(358, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 0, 1, 2);

        label = new QLabel(UserDetailWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label, 0, 2, 1, 2);

        horizontalSpacer_3 = new QSpacerItem(358, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 0, 4, 1, 1);

        groupBox = new QGroupBox(UserDetailWindow);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_userName = new QLabel(groupBox);
        label_userName->setObjectName(QStringLiteral("label_userName"));

        horizontalLayout->addWidget(label_userName);

        LineEdit_userName = new QLineEdit(groupBox);
        LineEdit_userName->setObjectName(QStringLiteral("LineEdit_userName"));

        horizontalLayout->addWidget(LineEdit_userName);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_password = new QLabel(groupBox);
        label_password->setObjectName(QStringLiteral("label_password"));

        horizontalLayout_2->addWidget(label_password);

        LineEdit_password = new QLineEdit(groupBox);
        LineEdit_password->setObjectName(QStringLiteral("LineEdit_password"));

        horizontalLayout_2->addWidget(LineEdit_password);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        checkBox_Pri = new QCheckBox(groupBox);
        checkBox_Pri->setObjectName(QStringLiteral("checkBox_Pri"));

        horizontalLayout_3->addWidget(checkBox_Pri);


        verticalLayout_2->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_userID = new QLabel(groupBox);
        label_userID->setObjectName(QStringLiteral("label_userID"));

        horizontalLayout_4->addWidget(label_userID);

        LineEdit_userID = new QLineEdit(groupBox);
        LineEdit_userID->setObjectName(QStringLiteral("LineEdit_userID"));

        horizontalLayout_4->addWidget(LineEdit_userID);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalSpacer = new QSpacerItem(168, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_password_3 = new QLabel(groupBox);
        label_password_3->setObjectName(QStringLiteral("label_password_3"));

        horizontalLayout_5->addWidget(label_password_3);

        LineEdit_booknum = new QLineEdit(groupBox);
        LineEdit_booknum->setObjectName(QStringLiteral("LineEdit_booknum"));

        horizontalLayout_5->addWidget(LineEdit_booknum);


        verticalLayout->addLayout(horizontalLayout_5);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);


        gridLayout_2->addWidget(groupBox, 1, 0, 1, 4);

        horizontalSpacer_6 = new QSpacerItem(358, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_6, 1, 4, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(358, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_4, 2, 0, 1, 2);

        label_2 = new QLabel(UserDetailWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_2, 2, 2, 1, 2);

        horizontalSpacer_5 = new QSpacerItem(358, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_5, 2, 4, 1, 1);

        tableWidget = new QTableWidget(UserDetailWindow);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        gridLayout_2->addWidget(tableWidget, 3, 0, 1, 5);

        horizontalSpacer_7 = new QSpacerItem(297, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_7, 4, 0, 1, 1);

        Button_changeUserInfo = new QPushButton(UserDetailWindow);
        Button_changeUserInfo->setObjectName(QStringLiteral("Button_changeUserInfo"));
        Button_changeUserInfo->setMinimumSize(QSize(150, 30));
        Button_changeUserInfo->setMaximumSize(QSize(150, 30));

        gridLayout_2->addWidget(Button_changeUserInfo, 4, 1, 1, 2);

        Button_deleteUser = new QPushButton(UserDetailWindow);
        Button_deleteUser->setObjectName(QStringLiteral("Button_deleteUser"));
        Button_deleteUser->setMinimumSize(QSize(150, 30));
        Button_deleteUser->setMaximumSize(QSize(150, 30));

        gridLayout_2->addWidget(Button_deleteUser, 4, 3, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(304, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_8, 4, 4, 1, 1);


        retranslateUi(UserDetailWindow);

        QMetaObject::connectSlotsByName(UserDetailWindow);
    } // setupUi

    void retranslateUi(QDialog *UserDetailWindow)
    {
        UserDetailWindow->setWindowTitle(QApplication::translate("UserDetailWindow", "Dialog", 0));
        label->setText(QApplication::translate("UserDetailWindow", "<html><head/><body><p><span style=\" font-size:x-large; font-weight:600;\">\347\224\250\346\210\267\350\257\246\347\273\206\344\277\241\346\201\257\346\237\245\350\257\242/\346\233\264\346\224\271</span></p></body></html>", 0));
        groupBox->setTitle(QString());
        label_userName->setText(QApplication::translate("UserDetailWindow", "\345\247\223    \345\220\215\357\274\232", 0));
        label_password->setText(QApplication::translate("UserDetailWindow", "\345\257\206    \347\240\201\357\274\232", 0));
        checkBox_Pri->setText(QApplication::translate("UserDetailWindow", "\345\205\201\350\256\270\345\200\237\351\230\205\344\271\246\347\261\215", 0));
        label_userID->setText(QApplication::translate("UserDetailWindow", "\345\255\246    \345\217\267\357\274\232", 0));
        label_password_3->setText(QApplication::translate("UserDetailWindow", "\345\200\237\344\271\246\346\225\260\351\207\217\357\274\232", 0));
        label_2->setText(QApplication::translate("UserDetailWindow", "<html><head/><body><p><span style=\" font-size:x-large; font-weight:600;\">\347\224\250\346\210\267\345\200\237\344\271\246\346\203\205\345\206\265\345\210\227\350\241\250</span></p></body></html>", 0));
        Button_changeUserInfo->setText(QApplication::translate("UserDetailWindow", "\346\233\264\346\224\271\347\224\250\346\210\267\344\277\241\346\201\257", 0));
        Button_deleteUser->setText(QApplication::translate("UserDetailWindow", "\345\210\240\351\231\244\347\224\250\346\210\267", 0));
    } // retranslateUi

};

namespace Ui {
    class UserDetailWindow: public Ui_UserDetailWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERDETAILWINDOW_H
