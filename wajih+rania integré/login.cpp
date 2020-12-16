#include "login.h"
#include "ui_login.h"
#include "user.h"

Login::Login(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_connect_clicked()
{

    QString username = ui->utilisateur->text();
    QString password = ui->motdepasse->text();

    User user(username,password);

    int login = user.login();

    if(login == 0){

        mainwindow.show();
        this->destroy();

    }else if (login == 1) {

        QMessageBox::critical (this, "Error", "Something went wrong !");

    }else {

        QMessageBox::critical (this, "Error", "Invalid username or password !");
    }

}
