#include "mainwindow.h"
#include "globals.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    if(database.isOpen()){
        ui->setupUi(this);
    }else {
        QMessageBox::critical(this, "Database not connected !", "Cannot connect to the database ...");
//        QApplication::quit();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_connect_clicked()
{


    QString email = ui->utilisateur->text();
    QString password = ui->motdepasse->text();

    //                if (email == "test" && password == "test")
    //                {
    //                  ui->stackedWidget->setCurrentIndex(1);

    //                }
    //                else
    //                {
    //                    QMessageBox::critical (this, "login", "email ou password sont incorrectes");
    //                }

    QSqlQuery qry;

    //                qry.exec("select count(*) from users where username ='"+email+"' and password = '"+password+"' ");
    //                qry.next();
    //                int count_user = qry.value(0).toInt();


    //                qry.prepare("select * from users");
    qry.exec("select * from users where username ='"+email+"' and password = '"+password+"' ");

    int count_user = 0;
    while (qry.next()) {
        count_user++;
        //
    }

    if (count_user == 1) {
        ui->stackedWidget->setCurrentIndex(1);
    }
    else if (count_user > 1 ) {
        QMessageBox::critical (this, "Error", "Something went wrong !");
    }
    else{
        QMessageBox::critical (this, "Error", "Invalid username or password !");
    }

}


void MainWindow::on_ajoutercmd_clicked()
{

    ui->stackedWidget->setCurrentIndex(5);
    ui->tabWidget_2->setCurrentIndex(0);
}

void MainWindow::on_modifercmd_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
    ui->tabWidget_2->setCurrentIndex(1);
}

void MainWindow::on_suppcmd_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
    ui->tabWidget_2->setCurrentIndex(2);
}

void MainWindow::on_affcmd_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
    ui->tabWidget_2->setCurrentIndex(3);
}

void MainWindow::on_chercmd_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
    ui->tabWidget_2->setCurrentIndex(4);
}

void MainWindow::on_retour_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_retour_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_retour_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_retour_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_retour_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_retour_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_retour_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_retour_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_retour_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_retour_10_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}



void MainWindow::on_pushButton_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}



void MainWindow::on_pushButton_45_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void MainWindow::on_pushButton_58_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_ajouter_clicked()
{

    ui->stackedWidget->setCurrentIndex(3);
    ui->tabWidget->setCurrentIndex(0);
}

void MainWindow::on_modifier_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->tabWidget->setCurrentIndex(1);
}

void MainWindow::on_supprimer_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->tabWidget->setCurrentIndex(2);
}

void MainWindow::on_afficher_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->tabWidget->setCurrentIndex(3);
}

void MainWindow::on_chercher_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    ui->tabWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_13_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
    ui->tabWidget_2->setCurrentIndex(5);
}



void MainWindow::on_ajoutercl_clicked()
{
    QString ID = ui->ID->text();
    QString NOM = ui->NOM->text();
    QString PRENOM = ui->PRENOM->text();
    QString MAIL = ui->MAIL->text();
    QString VILLE = ui->VILLE->text();
    QSqlQuery query;
    query.prepare("INSERT INTO users (ID, NOM, PRENOM, USERNAME, PASSWORD) "
                  "VALUES (?, ?, ?, ?, ?)");
    query.bindValue(0,ID);
    query.bindValue(1, NOM);
    query.bindValue(2, PRENOM);
    query.bindValue(3, MAIL);
    query.bindValue(4, VILLE);
    query.exec();

}
