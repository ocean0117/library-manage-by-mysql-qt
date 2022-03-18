#ifndef BOOKMANAGEMENTWIDGET_H
#define BOOKMANAGEMENTWIDGET_H

#include <QWidget>

namespace Ui {
class BookManagementWidget;
}

class BookManagementWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BookManagementWidget(QWidget *parent = 0);
    ~BookManagementWidget();

private:
    Ui::BookManagementWidget *ui;
};

#endif // BOOKMANAGEMENTWIDGET_H
