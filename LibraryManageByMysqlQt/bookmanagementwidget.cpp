#include "bookmanagementwidget.h"
#include "ui_bookmanagementwidget.h"

BookManagementWidget::BookManagementWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BookManagementWidget)
{
    ui->setupUi(this);
}

BookManagementWidget::~BookManagementWidget()
{
    delete ui;
}
