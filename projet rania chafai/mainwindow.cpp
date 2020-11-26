#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connexion.h"
#include"machine.h"
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


void MainWindow::on_pushButton_employes_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_machines_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_machines_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_ajouterEmploye_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_modifierEmploye_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_afficherEmploye_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_supprimerEmploye_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_modifierEmploye_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_afficherEmploye_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_supprimerEmploye_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_retour_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_ajouterEmploye_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_afficherEmploye_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_supprimerEmploye_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_retour_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_ajouterEmploye_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_modifierEmploye_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_supprimerEmploye_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_retour_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_ajouterEmploye_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_modifierEmploye_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_afficherEmploye_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_retour_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_employes_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_ajouterMachine_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_pushButton_modifierMachine_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}

void MainWindow::on_pushButton_afficherMachine_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_pushButton_supprimerMachine_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
}

void MainWindow::on_pushButton_statistiques_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}

void MainWindow::on_pushButton_modifierMachine_2_clicked()
{
   ui->stackedWidget->setCurrentIndex(8);
}

void MainWindow::on_pushButton_afficherMachine_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_pushButton_supprimerMachine_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
}

void MainWindow::on_pushButton_statistiques_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}

void MainWindow::on_pushButton_retour_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_ajouterMachine_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_pushButton_afficherMachine_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_pushButton_supprimerMachine_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
}

void MainWindow::on_pushButton_statistiques_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}

void MainWindow::on_pushButton_ajouterMachine_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_pushButton_modifierMachine_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}

void MainWindow::on_pushButton_supprimerMachine_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
}

void MainWindow::on_pushButton_statistiques_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}

void MainWindow::on_pushButton_ajouterMachine_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_pushButton_modifierMachine_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}

void MainWindow::on_pushButton_afficherMachine_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_pushButton_statistiques_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}

void MainWindow::on_pushButton_retour_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_retour_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_ajouterMachine_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_pushButton_modifierMachine_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}

void MainWindow::on_pushButton_afficherMachine_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_pushButton_supprimerMachine_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
}

void MainWindow::on_pushButton_retour_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_retour_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_ajouterMachine_3_clicked()
{
    int idMachine= ui->lineEdit_idMachine->text().toInt();
    float prix= ui->lineEdit_prix->text().toFloat();
    QString nom= ui->lineEdit_nom->text();
    QString reference= ui->lineEdit_reference->text();
    QString categorie= ui->lineEdit_categorie->text();
    machine m(idMachine, prix, nom, reference, categorie);

    bool test=m.ajouterMachine();
    if (test)
    {
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("Ajout effectue \n"
                                             "click cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                                 QObject::tr("Ajout non effectue \n"
                                             "click cancel to exit."), QMessageBox::Cancel);
    }
}
