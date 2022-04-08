/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QWidget *widget_Title;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label_Title;
    QPushButton *Button_login;
    QPushButton *Button_register;
    QPushButton *Button_quitLogin;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(846, 500);
        MainWindow->setMinimumSize(QSize(800, 485));
        MainWindow->setMaximumSize(QSize(1228, 921));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        widget_Title = new QWidget(centralWidget);
        widget_Title->setObjectName(QStringLiteral("widget_Title"));
        widget_Title->setMinimumSize(QSize(0, 129));
        widget_Title->setMaximumSize(QSize(1203, 129));
        gridLayout = new QGridLayout(widget_Title);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalSpacer = new QSpacerItem(20, 65, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(750, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_Title = new QLabel(widget_Title);
        label_Title->setObjectName(QStringLiteral("label_Title"));

        horizontalLayout->addWidget(label_Title);

        Button_login = new QPushButton(widget_Title);
        Button_login->setObjectName(QStringLiteral("Button_login"));
        Button_login->setMinimumSize(QSize(60, 30));
        Button_login->setMaximumSize(QSize(60, 30));

        horizontalLayout->addWidget(Button_login);

        Button_register = new QPushButton(widget_Title);
        Button_register->setObjectName(QStringLiteral("Button_register"));
        Button_register->setMinimumSize(QSize(60, 30));
        Button_register->setMaximumSize(QSize(60, 30));

        horizontalLayout->addWidget(Button_register);

        Button_quitLogin = new QPushButton(widget_Title);
        Button_quitLogin->setObjectName(QStringLiteral("Button_quitLogin"));
        Button_quitLogin->setMinimumSize(QSize(120, 30));
        Button_quitLogin->setMaximumSize(QSize(120, 30));

        horizontalLayout->addWidget(Button_quitLogin);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);


        gridLayout_2->addWidget(widget_Title, 0, 0, 1, 1);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setMinimumSize(QSize(0, 320));
        tabWidget->setMaximumSize(QSize(1203, 761));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());

        gridLayout_2->addWidget(tabWidget, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label_Title->setText(QApplication::translate("MainWindow", "\345\210\235\345\247\213\345\214\226ing...", 0));
        Button_login->setText(QApplication::translate("MainWindow", "\347\231\273\345\275\225", 0));
        Button_register->setText(QApplication::translate("MainWindow", "\346\263\250\345\206\214", 0));
        Button_quitLogin->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272\347\231\273\345\275\225", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Tab 1", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Tab 2", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
