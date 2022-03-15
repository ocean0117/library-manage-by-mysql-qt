/********************************************************************************
** Form generated from reading UI file 'registerwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERWINDOW_H
#define UI_REGISTERWINDOW_H

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
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_RegisterWindow
{
public:
    QGridLayout *gridLayout_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_userID;
    QLineEdit *LineEdit_userID;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_userName;
    QLineEdit *LineEdit_userName;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_password;
    QLineEdit *LineEdit_password;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_password_2;
    QLineEdit *LineEdit_password_2;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *Button_quit;
    QPushButton *Button_yes;

    void setupUi(QDialog *RegisterWindow)
    {
        if (RegisterWindow->objectName().isEmpty())
            RegisterWindow->setObjectName(QStringLiteral("RegisterWindow"));
        RegisterWindow->resize(360, 250);
        RegisterWindow->setMinimumSize(QSize(360, 250));
        RegisterWindow->setMaximumSize(QSize(360, 250));
        gridLayout_2 = new QGridLayout(RegisterWindow);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label = new QLabel(RegisterWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(350, 40));
        label->setMaximumSize(QSize(350, 40));
        label->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_userID = new QLabel(RegisterWindow);
        label_userID->setObjectName(QStringLiteral("label_userID"));

        horizontalLayout_2->addWidget(label_userID);

        LineEdit_userID = new QLineEdit(RegisterWindow);
        LineEdit_userID->setObjectName(QStringLiteral("LineEdit_userID"));

        horizontalLayout_2->addWidget(LineEdit_userID);


        gridLayout_2->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_userName = new QLabel(RegisterWindow);
        label_userName->setObjectName(QStringLiteral("label_userName"));

        horizontalLayout_5->addWidget(label_userName);

        LineEdit_userName = new QLineEdit(RegisterWindow);
        LineEdit_userName->setObjectName(QStringLiteral("LineEdit_userName"));

        horizontalLayout_5->addWidget(LineEdit_userName);


        gridLayout_2->addLayout(horizontalLayout_5, 2, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_password = new QLabel(RegisterWindow);
        label_password->setObjectName(QStringLiteral("label_password"));

        horizontalLayout_3->addWidget(label_password);

        LineEdit_password = new QLineEdit(RegisterWindow);
        LineEdit_password->setObjectName(QStringLiteral("LineEdit_password"));
        LineEdit_password->setEchoMode(QLineEdit::Password);

        horizontalLayout_3->addWidget(LineEdit_password);


        gridLayout_2->addLayout(horizontalLayout_3, 3, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_password_2 = new QLabel(RegisterWindow);
        label_password_2->setObjectName(QStringLiteral("label_password_2"));

        horizontalLayout_4->addWidget(label_password_2);

        LineEdit_password_2 = new QLineEdit(RegisterWindow);
        LineEdit_password_2->setObjectName(QStringLiteral("LineEdit_password_2"));
        LineEdit_password_2->setEchoMode(QLineEdit::Password);

        horizontalLayout_4->addWidget(LineEdit_password_2);


        gridLayout_2->addLayout(horizontalLayout_4, 4, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 4, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 2, 1, 1);

        Button_quit = new QPushButton(RegisterWindow);
        Button_quit->setObjectName(QStringLiteral("Button_quit"));
        Button_quit->setMinimumSize(QSize(60, 30));
        Button_quit->setMaximumSize(QSize(60, 30));

        gridLayout->addWidget(Button_quit, 0, 3, 1, 1);

        Button_yes = new QPushButton(RegisterWindow);
        Button_yes->setObjectName(QStringLiteral("Button_yes"));
        Button_yes->setMinimumSize(QSize(60, 30));
        Button_yes->setMaximumSize(QSize(60, 30));

        gridLayout->addWidget(Button_yes, 0, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 5, 0, 1, 1);

        label_userID->raise();
        LineEdit_userID->raise();
        label->raise();

        retranslateUi(RegisterWindow);

        QMetaObject::connectSlotsByName(RegisterWindow);
    } // setupUi

    void retranslateUi(QDialog *RegisterWindow)
    {
        RegisterWindow->setWindowTitle(QApplication::translate("RegisterWindow", "Dialog", 0));
        label->setText(QApplication::translate("RegisterWindow", "\350\257\267\350\276\223\345\205\245\346\263\250\345\206\214\344\277\241\346\201\257\n"
"\357\274\210\346\235\203\351\231\220\345\260\206\347\224\261\347\256\241\347\220\206\345\221\230\346\267\273\345\212\240\357\274\211", 0));
        label_userID->setText(QApplication::translate("RegisterWindow", "\345\255\246    \345\217\267\357\274\232", 0));
        label_userName->setText(QApplication::translate("RegisterWindow", "\345\247\223    \345\220\215\357\274\232", 0));
        label_password->setText(QApplication::translate("RegisterWindow", "\345\257\206    \347\240\201\357\274\232", 0));
        label_password_2->setText(QApplication::translate("RegisterWindow", "\347\241\256\350\256\244\345\257\206\347\240\201\357\274\232", 0));
        Button_quit->setText(QApplication::translate("RegisterWindow", "\351\200\200\345\207\272", 0));
        Button_yes->setText(QApplication::translate("RegisterWindow", "\346\263\250\345\206\214", 0));
    } // retranslateUi

};

namespace Ui {
    class RegisterWindow: public Ui_RegisterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERWINDOW_H
