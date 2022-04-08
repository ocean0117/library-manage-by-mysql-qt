/********************************************************************************
** Form generated from reading UI file 'addbookwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDBOOKWINDOW_H
#define UI_ADDBOOKWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
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

class Ui_AddBookWindow
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_10;
    QTableWidget *tableWidget;
    QSpacerItem *horizontalSpacer_11;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_6;
    QPushButton *Button_addSomeBooksClear;
    QPushButton *Button_addSomeBooks;
    QPushButton *Button_loadFile;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_10;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_userID;
    QLineEdit *LineEdit_bookID;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_userID_3;
    QLineEdit *LineEdit_publisher;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_password_3;
    QLineEdit *LineEdit_booknum;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *Button_addOneBook;
    QSpacerItem *horizontalSpacer_3;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_userID_2;
    QComboBox *comboBox_type;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_userID_4;
    QComboBox *comboBox_year;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_userName;
    QLineEdit *LineEdit_bookName;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_password;
    QLineEdit *LineEdit_auther;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_password_2;
    QLineEdit *LineEdit_price;
    QLabel *label_2;
    QPushButton *Button_addOneBookClear;
    QSpacerItem *horizontalSpacer_9;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_8;

    void setupUi(QWidget *AddBookWindow)
    {
        if (AddBookWindow->objectName().isEmpty())
            AddBookWindow->setObjectName(QStringLiteral("AddBookWindow"));
        AddBookWindow->resize(850, 500);
        AddBookWindow->setMinimumSize(QSize(850, 440));
        AddBookWindow->setMaximumSize(QSize(950, 921));
        gridLayout_3 = new QGridLayout(AddBookWindow);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        groupBox_2 = new QGroupBox(AddBookWindow);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalSpacer_10 = new QSpacerItem(252, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_10, 1, 0, 1, 1);

        tableWidget = new QTableWidget(groupBox_2);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        gridLayout_2->addWidget(tableWidget, 0, 0, 1, 10);

        horizontalSpacer_11 = new QSpacerItem(258, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_11, 1, 8, 1, 2);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(600, 0));

        gridLayout_2->addWidget(label_4, 2, 0, 1, 9);

        horizontalSpacer_6 = new QSpacerItem(251, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_6, 2, 9, 1, 1);

        Button_addSomeBooksClear = new QPushButton(groupBox_2);
        Button_addSomeBooksClear->setObjectName(QStringLiteral("Button_addSomeBooksClear"));
        Button_addSomeBooksClear->setMinimumSize(QSize(120, 30));
        Button_addSomeBooksClear->setMaximumSize(QSize(120, 30));

        gridLayout_2->addWidget(Button_addSomeBooksClear, 1, 4, 1, 1);

        Button_addSomeBooks = new QPushButton(groupBox_2);
        Button_addSomeBooks->setObjectName(QStringLiteral("Button_addSomeBooks"));
        Button_addSomeBooks->setMinimumSize(QSize(120, 30));
        Button_addSomeBooks->setMaximumSize(QSize(120, 30));

        gridLayout_2->addWidget(Button_addSomeBooks, 1, 1, 1, 1);

        Button_loadFile = new QPushButton(groupBox_2);
        Button_loadFile->setObjectName(QStringLiteral("Button_loadFile"));
        Button_loadFile->setMinimumSize(QSize(120, 30));
        Button_loadFile->setMaximumSize(QSize(120, 30));

        gridLayout_2->addWidget(Button_loadFile, 1, 3, 1, 1);


        gridLayout_3->addWidget(groupBox_2, 3, 0, 1, 1);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalSpacer_4 = new QSpacerItem(295, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_4);

        label = new QLabel(AddBookWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout_11->addWidget(label);

        horizontalSpacer_5 = new QSpacerItem(295, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_5);


        gridLayout_3->addLayout(horizontalLayout_11, 0, 0, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        groupBox = new QGroupBox(AddBookWindow);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setMaximumSize(QSize(815, 16777215));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_userID = new QLabel(groupBox);
        label_userID->setObjectName(QStringLiteral("label_userID"));

        horizontalLayout_4->addWidget(label_userID);

        LineEdit_bookID = new QLineEdit(groupBox);
        LineEdit_bookID->setObjectName(QStringLiteral("LineEdit_bookID"));
        LineEdit_bookID->setMinimumSize(QSize(171, 0));
        LineEdit_bookID->setMaximumSize(QSize(171, 16777215));

        horizontalLayout_4->addWidget(LineEdit_bookID);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_userID_3 = new QLabel(groupBox);
        label_userID_3->setObjectName(QStringLiteral("label_userID_3"));

        horizontalLayout_6->addWidget(label_userID_3);

        LineEdit_publisher = new QLineEdit(groupBox);
        LineEdit_publisher->setObjectName(QStringLiteral("LineEdit_publisher"));
        LineEdit_publisher->setMinimumSize(QSize(171, 0));
        LineEdit_publisher->setMaximumSize(QSize(171, 16777215));

        horizontalLayout_6->addWidget(LineEdit_publisher);


        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_password_3 = new QLabel(groupBox);
        label_password_3->setObjectName(QStringLiteral("label_password_3"));

        horizontalLayout_5->addWidget(label_password_3);

        LineEdit_booknum = new QLineEdit(groupBox);
        LineEdit_booknum->setObjectName(QStringLiteral("LineEdit_booknum"));
        LineEdit_booknum->setMinimumSize(QSize(171, 0));
        LineEdit_booknum->setMaximumSize(QSize(171, 16777215));

        horizontalLayout_5->addWidget(LineEdit_booknum);


        verticalLayout_3->addLayout(horizontalLayout_5);


        gridLayout->addLayout(verticalLayout_3, 0, 1, 1, 4);

        horizontalSpacer_2 = new QSpacerItem(326, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 0, 1, 2);

        Button_addOneBook = new QPushButton(groupBox);
        Button_addOneBook->setObjectName(QStringLiteral("Button_addOneBook"));
        Button_addOneBook->setMinimumSize(QSize(120, 30));
        Button_addOneBook->setMaximumSize(QSize(120, 30));

        gridLayout->addWidget(Button_addOneBook, 1, 2, 1, 1);

        horizontalSpacer_3 = new QSpacerItem(325, 27, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 1, 4, 1, 3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_userID_2 = new QLabel(groupBox);
        label_userID_2->setObjectName(QStringLiteral("label_userID_2"));

        horizontalLayout_3->addWidget(label_userID_2);

        comboBox_type = new QComboBox(groupBox);
        comboBox_type->setObjectName(QStringLiteral("comboBox_type"));
        comboBox_type->setMinimumSize(QSize(171, 0));
        comboBox_type->setMaximumSize(QSize(171, 16777215));

        horizontalLayout_3->addWidget(comboBox_type);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_userID_4 = new QLabel(groupBox);
        label_userID_4->setObjectName(QStringLiteral("label_userID_4"));
        label_userID_4->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_7->addWidget(label_userID_4);

        comboBox_year = new QComboBox(groupBox);
        comboBox_year->setObjectName(QStringLiteral("comboBox_year"));
        comboBox_year->setMinimumSize(QSize(171, 0));
        comboBox_year->setMaximumSize(QSize(171, 16777215));

        horizontalLayout_7->addWidget(comboBox_year);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_2->addItem(horizontalSpacer);


        gridLayout->addLayout(verticalLayout_2, 0, 5, 1, 2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_userName = new QLabel(groupBox);
        label_userName->setObjectName(QStringLiteral("label_userName"));
        label_userName->setMinimumSize(QSize(77, 0));
        label_userName->setMaximumSize(QSize(77, 16777215));

        horizontalLayout->addWidget(label_userName);

        LineEdit_bookName = new QLineEdit(groupBox);
        LineEdit_bookName->setObjectName(QStringLiteral("LineEdit_bookName"));
        LineEdit_bookName->setMinimumSize(QSize(171, 0));
        LineEdit_bookName->setMaximumSize(QSize(171, 16777215));

        horizontalLayout->addWidget(LineEdit_bookName);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_password = new QLabel(groupBox);
        label_password->setObjectName(QStringLiteral("label_password"));

        horizontalLayout_2->addWidget(label_password);

        LineEdit_auther = new QLineEdit(groupBox);
        LineEdit_auther->setObjectName(QStringLiteral("LineEdit_auther"));
        LineEdit_auther->setMinimumSize(QSize(171, 0));
        LineEdit_auther->setMaximumSize(QSize(171, 16777215));

        horizontalLayout_2->addWidget(LineEdit_auther);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_password_2 = new QLabel(groupBox);
        label_password_2->setObjectName(QStringLiteral("label_password_2"));

        horizontalLayout_8->addWidget(label_password_2);

        LineEdit_price = new QLineEdit(groupBox);
        LineEdit_price->setObjectName(QStringLiteral("LineEdit_price"));
        LineEdit_price->setMinimumSize(QSize(171, 0));
        LineEdit_price->setMaximumSize(QSize(171, 16777215));

        horizontalLayout_8->addWidget(LineEdit_price);


        verticalLayout->addLayout(horizontalLayout_8);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(600, 0));

        gridLayout->addWidget(label_2, 2, 0, 1, 6);

        Button_addOneBookClear = new QPushButton(groupBox);
        Button_addOneBookClear->setObjectName(QStringLiteral("Button_addOneBookClear"));
        Button_addOneBookClear->setMinimumSize(QSize(120, 30));
        Button_addOneBookClear->setMaximumSize(QSize(120, 30));

        gridLayout->addWidget(Button_addOneBookClear, 1, 3, 1, 1);

        Button_addOneBook->raise();
        label_2->raise();
        Button_addOneBookClear->raise();

        horizontalLayout_10->addWidget(groupBox);

        horizontalSpacer_9 = new QSpacerItem(103, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_9);


        gridLayout_3->addLayout(horizontalLayout_10, 1, 0, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalSpacer_7 = new QSpacerItem(295, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_7);

        label_3 = new QLabel(AddBookWindow);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_9->addWidget(label_3);

        horizontalSpacer_8 = new QSpacerItem(295, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_8);


        gridLayout_3->addLayout(horizontalLayout_9, 2, 0, 1, 1);


        retranslateUi(AddBookWindow);

        QMetaObject::connectSlotsByName(AddBookWindow);
    } // setupUi

    void retranslateUi(QWidget *AddBookWindow)
    {
        AddBookWindow->setWindowTitle(QApplication::translate("AddBookWindow", "Form", 0));
        groupBox_2->setTitle(QString());
        label_4->setText(QApplication::translate("AddBookWindow", "\345\244\207\346\263\250\357\274\232\345\217\257\344\273\245\345\234\250\350\241\250\346\240\274\344\270\255\345\241\253\345\206\231\347\233\270\345\272\224\344\277\241\346\201\257\357\274\214\346\210\226\350\200\205\351\200\232\350\277\207\346\226\207\344\273\266\345\212\240\350\275\275\343\200\202\n"
"\351\200\232\350\277\207\346\226\207\344\273\266\345\212\240\350\275\275\346\227\266\357\274\214\345\241\253\345\206\231\351\241\272\345\272\217\346\214\211\347\205\247\350\241\250\346\240\274\351\241\272\345\272\217\345\241\253\345\206\231\357\274\214\344\270\215\345\220\214\344\271\246\347\261\215\344\277\241\346\201\257\351\234\200\350\246\201\346\215\242\350\241\214\351\232\224\345\274\200\343\200\202", 0));
        Button_addSomeBooksClear->setText(QApplication::translate("AddBookWindow", "\346\270\205  \347\251\272", 0));
        Button_addSomeBooks->setText(QApplication::translate("AddBookWindow", "\346\267\273\345\212\240/\346\233\264\346\226\260\344\271\246\347\261\215", 0));
        Button_loadFile->setText(QApplication::translate("AddBookWindow", "\345\212\240\350\275\275\346\226\207\344\273\266", 0));
        label->setText(QApplication::translate("AddBookWindow", "<html><head/><body><p><span style=\" font-size:x-large; font-weight:600;\">\346\267\273\345\212\240/\346\233\264\346\226\260\345\215\225\345\206\214\344\271\246\347\261\215</span></p></body></html>", 0));
        groupBox->setTitle(QString());
        label_userID->setText(QApplication::translate("AddBookWindow", "\347\274\226    \345\217\267\357\274\232", 0));
        label_userID_3->setText(QApplication::translate("AddBookWindow", "\345\207\272 \347\211\210 \347\244\276\357\274\232", 0));
        LineEdit_publisher->setText(QString());
        label_password_3->setText(QApplication::translate("AddBookWindow", "\346\225\260    \351\207\217\357\274\232", 0));
        Button_addOneBook->setText(QApplication::translate("AddBookWindow", "\346\267\273\345\212\240/\346\233\264\346\226\260\344\271\246\347\261\215", 0));
        label_userID_2->setText(QApplication::translate("AddBookWindow", "\345\210\206    \347\261\273\357\274\232", 0));
        label_userID_4->setText(QApplication::translate("AddBookWindow", "\345\207\272\347\211\210\345\271\264\344\273\275\357\274\232", 0));
        label_userName->setText(QApplication::translate("AddBookWindow", "\344\271\246    \345\220\215\357\274\232", 0));
        label_password->setText(QApplication::translate("AddBookWindow", "\344\275\234    \350\200\205\357\274\232", 0));
        label_password_2->setText(QApplication::translate("AddBookWindow", "\344\273\267    \346\240\274\357\274\232", 0));
        LineEdit_price->setText(QString());
        label_2->setText(QApplication::translate("AddBookWindow", "\345\244\207\346\263\250\357\274\232\345\275\223\344\271\246\347\261\215\347\274\226\345\217\267\345\255\230\345\234\250\346\227\266\350\241\250\347\244\272\346\233\264\346\226\260\344\271\246\347\261\215\344\277\241\346\201\257\343\200\202\346\255\244\345\244\226\357\274\214\346\233\264\346\226\260\346\227\266\357\274\214\346\225\260\351\207\217\345\272\224\350\257\245\345\244\247\344\272\216\347\255\211\344\272\216\345\200\237\351\230\205\346\225\260\351\207\217\343\200\202", 0));
        Button_addOneBookClear->setText(QApplication::translate("AddBookWindow", "\346\270\205  \347\251\272", 0));
        label_3->setText(QApplication::translate("AddBookWindow", "<html><head/><body><p><span style=\" font-size:x-large; font-weight:600;\">\346\267\273\345\212\240/\346\233\264\346\226\260\345\244\232\345\206\214\344\271\246\347\261\215</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class AddBookWindow: public Ui_AddBookWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDBOOKWINDOW_H
