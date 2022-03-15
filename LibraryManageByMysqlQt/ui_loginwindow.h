/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_userID;
    QLineEdit *LineEdit_userID;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_password;
    QLineEdit *LineEdit_password;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_4;
    QRadioButton *Radio_user;
    QSpacerItem *horizontalSpacer_6;
    QRadioButton *Radio_manager;
    QSpacerItem *horizontalSpacer_5;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *Button_quit;
    QPushButton *Button_yes;

    void setupUi(QDialog *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName(QStringLiteral("LoginWindow"));
        LoginWindow->resize(360, 210);
        LoginWindow->setMinimumSize(QSize(360, 210));
        LoginWindow->setMaximumSize(QSize(360, 210));
        gridLayout_2 = new QGridLayout(LoginWindow);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_userID = new QLabel(LoginWindow);
        label_userID->setObjectName(QStringLiteral("label_userID"));

        horizontalLayout_2->addWidget(label_userID);

        LineEdit_userID = new QLineEdit(LoginWindow);
        LineEdit_userID->setObjectName(QStringLiteral("LineEdit_userID"));

        horizontalLayout_2->addWidget(LineEdit_userID);


        gridLayout_2->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_password = new QLabel(LoginWindow);
        label_password->setObjectName(QStringLiteral("label_password"));

        horizontalLayout_3->addWidget(label_password);

        LineEdit_password = new QLineEdit(LoginWindow);
        LineEdit_password->setObjectName(QStringLiteral("LineEdit_password"));
        LineEdit_password->setEchoMode(QLineEdit::Password);

        horizontalLayout_3->addWidget(LineEdit_password);


        gridLayout_2->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        Radio_user = new QRadioButton(LoginWindow);
        Radio_user->setObjectName(QStringLiteral("Radio_user"));
        Radio_user->setChecked(true);

        horizontalLayout->addWidget(Radio_user);

        horizontalSpacer_6 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_6);

        Radio_manager = new QRadioButton(LoginWindow);
        Radio_manager->setObjectName(QStringLiteral("Radio_manager"));

        horizontalLayout->addWidget(Radio_manager);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);


        gridLayout_2->addLayout(horizontalLayout, 2, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 4, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        Button_quit = new QPushButton(LoginWindow);
        Button_quit->setObjectName(QStringLiteral("Button_quit"));
        Button_quit->setMinimumSize(QSize(60, 30));
        Button_quit->setMaximumSize(QSize(60, 30));

        gridLayout->addWidget(Button_quit, 0, 3, 1, 1);

        Button_yes = new QPushButton(LoginWindow);
        Button_yes->setObjectName(QStringLiteral("Button_yes"));
        Button_yes->setMinimumSize(QSize(60, 30));
        Button_yes->setMaximumSize(QSize(60, 30));

        gridLayout->addWidget(Button_yes, 0, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 3, 0, 1, 1);


        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QDialog *LoginWindow)
    {
        LoginWindow->setWindowTitle(QApplication::translate("LoginWindow", "Dialog", 0));
        label_userID->setText(QApplication::translate("LoginWindow", "\345\255\246  \345\217\267\357\274\232", 0));
        label_password->setText(QApplication::translate("LoginWindow", "\345\257\206  \347\240\201\357\274\232", 0));
        Radio_user->setText(QApplication::translate("LoginWindow", "\346\231\256\351\200\232\347\224\250\346\210\267", 0));
        Radio_manager->setText(QApplication::translate("LoginWindow", "\347\256\241\347\220\206\345\221\230", 0));
        Button_quit->setText(QApplication::translate("LoginWindow", "\351\200\200\345\207\272", 0));
        Button_yes->setText(QApplication::translate("LoginWindow", "\347\231\273\345\275\225", 0));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
