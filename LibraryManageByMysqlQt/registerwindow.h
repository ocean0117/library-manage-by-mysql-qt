#ifndef REGISTERWINDOW_H
#define REGISTERWINDOW_H

#include <QDialog>
#include <QMessageBox>
namespace Ui {
class RegisterWindow;
}

class RegisterWindow : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterWindow(QWidget *parent = 0);
    ~RegisterWindow();

private slots:
    void on_Button_quit_clicked();
    void on_Button_yes_clicked();

signals:
    void Signal_registerQuit();
    void Signal_register(QVector<QString>);

private:
    void closeEvent(QCloseEvent *event);

private:
    Ui::RegisterWindow *ui;
};

#endif // REGISTERWINDOW_H
