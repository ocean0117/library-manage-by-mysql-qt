#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    // 添加MainWindow的标题
    w.setWindowTitle("图书管理系统");
    w.show();

    return a.exec();
}
