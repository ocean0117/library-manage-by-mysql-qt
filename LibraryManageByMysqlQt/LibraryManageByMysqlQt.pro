#-------------------------------------------------
#
# Project created by QtCreator 2022-03-12T12:09:26
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LibraryManageByMysqlQt
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    loginwindow.cpp \
    registerwindow.cpp \
    booksearchwidget.cpp \
    bookborrowinfowidget.cpp \
    usermanagementwidget.cpp

HEADERS  += mainwindow.h \
    loginwindow.h \
    registerwindow.h \
    booksearchwidget.h \
    bookborrowinfowidget.h \
    datastructure.h \
    usermanagementwidget.h

FORMS    += mainwindow.ui \
    loginwindow.ui \
    registerwindow.ui \
    booksearchwidget.ui \
    bookborrowinfowidget.ui \
    usermanagementwidget.ui

RESOURCES += \
    images.qrc
