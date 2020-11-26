#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "revenues.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_39_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_40_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_11_clicked()
{
  ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_12_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_13_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_14_clicked()
{
     ui->stackedWidget->setCurrentIndex(6);
}



void MainWindow::on_pushButton_17_clicked()
{
   ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_pushButton_48_clicked()
{
   ui->stackedWidget->setCurrentIndex(8);
}

void MainWindow::on_pushButton_47_clicked()
{
  ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_pushButton_49_clicked()
{
   ui->stackedWidget->setCurrentIndex(10);
}

void MainWindow::on_pushButton_18_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}

void MainWindow::on_pushButton_19_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}

void MainWindow::on_pushButton_20_clicked()
{
  ui->stackedWidget->setCurrentIndex(13);
}

void MainWindow::on_pushButton_24_clicked()
{
 ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_25_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}



void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_10_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_23_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_ValidezRevenues_clicked()
{
    int ID_Revenue=ui->lineEdit_ID_Revenues->text().toInt();
    QString NomProduit=ui->lineEdit_NomProduits->text();
    int QuantiteVendue=ui->lineEdit_QuantiteVendue->text().toInt();
    int ValeursUnitaire=ui->lineEdit_ValeursUnitaire->text().toInt();
    int ID_Client=ui->lineEdit_ID_Client->text().toInt();
    QString DateVente=ui->lineEdit_DateVente->text();

    Revenues R (NomProduit,QuantiteVendue,ValeursUnitaire,ID_Client,DateVente,ID_Revenue);

    bool test=R.ajouter();
    if(test)
    {
    QMessageBox::information(nullptr,QObject::tr("OK"),
                             QObject::tr("Ajout effectué \n"
                             "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else{
    QMessageBox::critical(nullptr,QObject::tr("OK"),
                             QObject::tr("Ajout non effectué!!!! \n"
                             "Click Cancel to exit."), QMessageBox::Cancel);
    }
    }

