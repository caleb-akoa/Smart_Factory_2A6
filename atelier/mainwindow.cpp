#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "produit.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(Etmp.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_Produit_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_39_clicked()
{
     ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_pushButton_entrepot_clicked()
{
     ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_pushButton_26_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_supprimer_clicked()
{
    int id=ui->lineEdit_idSup->text().toInt();
    bool test=Etmp.supprimer();
    if(test)
    {
        QMessageBox::information(nullptr,QObject ::tr("ok"),
        QObject::tr("suppression effectuee \n click cancel to exit "),QMessageBox::Cancel);


    }
    else
        QMessageBox::critical(nullptr,QObject ::tr("Not ok"),QObject::tr("suppression non effectuee\n "
                                                                         "click cancel to exit"),QMessageBox::Cancel);

}

void MainWindow::on_pushButton_clicked()
{  ;
    int id=ui->lineEdit_id->text().toInt();
    QString nom=ui->lineEdit_nom->text();
    QString marque=ui->lineEdit_marque->text();
    int nb=ui->lineEdit_nombres->text().toInt();
    int prix=ui->lineEdit_prix->text().toInt();
    Produit p(nom,prix,nb,id);
    bool Stest=p.ajouter();
    if(Stest)
    {
QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("ajout effectuee\n" "click cancel to exit"),QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr,QObject ::tr("Not ok"),QObject::tr("ajout non effectuee\n "
                                                                         "click cancel to exit"),QMessageBox::Cancel);
}
