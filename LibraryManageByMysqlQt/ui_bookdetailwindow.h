/********************************************************************************
** Form generated from reading UI file 'bookdetailwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BOOKDETAILWINDOW_H
#define UI_BOOKDETAILWINDOW_H

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

class Ui_BookDetailWindow
{
public:
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
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
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_userID_2;
    QComboBox *comboBox_type;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_userID_4;
    QComboBox *comboBox_year;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_userID_5;
    QLineEdit *LineEdit_out;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QTableWidget *tableWidget;
    QPushButton *Button_changeBookInfo;
    QPushButton *Button_deleteBook;

    void setupUi(QWidget *BookDetailWindow)
    {
        if (BookDetailWindow->objectName().isEmpty())
            BookDetailWindow->setObjectName(QStringLiteral("BookDetailWindow"));
        BookDetailWindow->resize(950, 921);
        BookDetailWindow->setMinimumSize(QSize(950, 921));
        BookDetailWindow->setMaximumSize(QSize(950, 921));
        gridLayout_2 = new QGridLayout(BookDetailWindow);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(244, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 0, 1, 1);

        label = new QLabel(BookDetailWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label, 0, 1, 1, 2);

        horizontalSpacer_3 = new QSpacerItem(244, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_3, 0, 3, 1, 1);

        groupBox = new QGroupBox(BookDetailWindow);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_userName = new QLabel(groupBox);
        label_userName->setObjectName(QStringLiteral("label_userName"));

        horizontalLayout->addWidget(label_userName);

        LineEdit_bookName = new QLineEdit(groupBox);
        LineEdit_bookName->setObjectName(QStringLiteral("LineEdit_bookName"));
        LineEdit_bookName->setMinimumSize(QSize(171, 0));

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

        horizontalLayout_8->addWidget(LineEdit_price);


        verticalLayout->addLayout(horizontalLayout_8);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

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

        horizontalLayout_5->addWidget(LineEdit_booknum);


        verticalLayout_3->addLayout(horizontalLayout_5);


        gridLayout->addLayout(verticalLayout_3, 0, 1, 1, 1);

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

        horizontalLayout_7->addWidget(comboBox_year);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_userID_5 = new QLabel(groupBox);
        label_userID_5->setObjectName(QStringLiteral("label_userID_5"));

        horizontalLayout_9->addWidget(label_userID_5);

        LineEdit_out = new QLineEdit(groupBox);
        LineEdit_out->setObjectName(QStringLiteral("LineEdit_out"));
        LineEdit_out->setMinimumSize(QSize(171, 0));

        horizontalLayout_9->addWidget(LineEdit_out);


        verticalLayout_2->addLayout(horizontalLayout_9);


        gridLayout->addLayout(verticalLayout_2, 0, 2, 1, 1);


        gridLayout_2->addWidget(groupBox, 1, 0, 1, 4);

        horizontalSpacer = new QSpacerItem(103, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 4, 1, 1);

        label_2 = new QLabel(BookDetailWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_2, 2, 1, 1, 2);

        tableWidget = new QTableWidget(BookDetailWindow);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        gridLayout_2->addWidget(tableWidget, 3, 0, 1, 5);

        Button_changeBookInfo = new QPushButton(BookDetailWindow);
        Button_changeBookInfo->setObjectName(QStringLiteral("Button_changeBookInfo"));
        Button_changeBookInfo->setMinimumSize(QSize(150, 30));
        Button_changeBookInfo->setMaximumSize(QSize(150, 30));

        gridLayout_2->addWidget(Button_changeBookInfo, 4, 1, 1, 1);

        Button_deleteBook = new QPushButton(BookDetailWindow);
        Button_deleteBook->setObjectName(QStringLiteral("Button_deleteBook"));
        Button_deleteBook->setMinimumSize(QSize(150, 30));
        Button_deleteBook->setMaximumSize(QSize(150, 30));

        gridLayout_2->addWidget(Button_deleteBook, 4, 2, 1, 1);


        retranslateUi(BookDetailWindow);

        QMetaObject::connectSlotsByName(BookDetailWindow);
    } // setupUi

    void retranslateUi(QWidget *BookDetailWindow)
    {
        BookDetailWindow->setWindowTitle(QApplication::translate("BookDetailWindow", "Form", 0));
        label->setText(QApplication::translate("BookDetailWindow", "<html><head/><body><p><span style=\" font-size:x-large; font-weight:600;\">\344\271\246\347\261\215\350\257\246\347\273\206\344\277\241\346\201\257\346\237\245\350\257\242/\346\233\264\346\224\271</span></p></body></html>", 0));
        groupBox->setTitle(QString());
        label_userName->setText(QApplication::translate("BookDetailWindow", "\344\271\246    \345\220\215\357\274\232", 0));
        label_password->setText(QApplication::translate("BookDetailWindow", "\344\275\234    \350\200\205\357\274\232", 0));
        label_password_2->setText(QApplication::translate("BookDetailWindow", "\344\273\267    \346\240\274\357\274\232", 0));
        LineEdit_price->setText(QString());
        label_userID->setText(QApplication::translate("BookDetailWindow", "\347\274\226    \345\217\267\357\274\232", 0));
        label_userID_3->setText(QApplication::translate("BookDetailWindow", "\345\207\272 \347\211\210 \347\244\276\357\274\232", 0));
        LineEdit_publisher->setText(QString());
        label_password_3->setText(QApplication::translate("BookDetailWindow", "\346\200\273 \345\272\223 \345\255\230\357\274\232", 0));
        label_userID_2->setText(QApplication::translate("BookDetailWindow", "\345\210\206    \347\261\273\357\274\232", 0));
        label_userID_4->setText(QApplication::translate("BookDetailWindow", "\345\207\272\347\211\210\345\271\264\344\273\275\357\274\232", 0));
        label_userID_5->setText(QApplication::translate("BookDetailWindow", "\345\267\262 \345\200\237 \345\207\272\357\274\232", 0));
        LineEdit_out->setText(QString());
        label_2->setText(QApplication::translate("BookDetailWindow", "<html><head/><body><p><span style=\" font-size:x-large; font-weight:600;\">\344\271\246\347\261\215\345\200\237\351\230\205\347\224\250\346\210\267\345\210\227\350\241\250</span></p></body></html>", 0));
        Button_changeBookInfo->setText(QApplication::translate("BookDetailWindow", "\346\233\264\346\224\271\344\271\246\347\261\215\344\277\241\346\201\257", 0));
        Button_deleteBook->setText(QApplication::translate("BookDetailWindow", "\345\210\240\351\231\244\344\271\246\347\261\215", 0));
    } // retranslateUi

};

namespace Ui {
    class BookDetailWindow: public Ui_BookDetailWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BOOKDETAILWINDOW_H
