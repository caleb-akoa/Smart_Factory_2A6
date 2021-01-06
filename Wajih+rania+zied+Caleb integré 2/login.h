#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>
#include <QMessageBox>

#include "mainwindow.h"




namespace Ui {
class Login;
}

class Login : public QMainWindow
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_connect_clicked();

private:
    Ui::Login *ui;
    MainWindow mainwindow;
};

#endif // SCREENLOGIN_H
