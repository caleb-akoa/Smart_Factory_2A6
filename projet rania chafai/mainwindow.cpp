#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connexion.h"
#include"machine.h"
#include "employe.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlQuery>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabMachine->setModel(m.afficherMachine());
    ui->tabEmploye->setModel(e.afficherEmploye());
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

/**********************MACHINE***************************/
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
        //refresh
        ui->tabMachine->setModel(m.afficherMachine());
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("Ajout Machine effectue \n"
                                             "click cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                                 QObject::tr("Ajout Machine non effectue \n"
                                             "click cancel to exit."), QMessageBox::Cancel);
    }
}


void MainWindow::on_pushButton_supprimerM_clicked()
{
    int idMachine= ui->lineEdit_idSupprimerM->text().toInt();

    bool test=m.supprimerMachine(idMachine);

          if (test)
          {
              //refresh
              ui->tabMachine->setModel(m.afficherMachine());
              QMessageBox::information(nullptr, QObject::tr("ok"),
                                       QObject::tr("suppression Machine effectuee \n"
                                                   "click cancel to exit."), QMessageBox::Cancel);
          }
          else
          {
              QMessageBox::critical(nullptr, QObject::tr("ok"),
                                       QObject::tr("suppression Machine non effectue \n"
                                                   "click cancel to exit."), QMessageBox::Cancel);
          }
}

void MainWindow::on_pushButton_modifierMachine_4_clicked()
{
    int idM= ui->lineEdit_idModifierM->text().toInt();

    float prix= ui->lineEdit_prix_2->text().toFloat();
    QString nom= ui->lineEdit_nom_4->text();
    QString reference= ui->lineEdit_reference_2->text();
    QString categorie= ui->lineEdit_categorie_2->text();
     machine m(idM, prix, nom, reference, categorie);


        bool test=m.modifierMachine();
        if (test)
        {
//            int idM= ui->lineEdit_idModifierM->text().toInt();
            float prix= ui->lineEdit_prix_2->text().toFloat();
            QString nom= ui->lineEdit_nom_4->text();
            QString reference= ui->lineEdit_reference_2->text();
            QString categorie= ui->lineEdit_categorie_2->text();
             machine m(idM, prix, nom, reference, categorie);

            //refresh
            ui->tabMachine->setModel(m.afficherMachine());
            QMessageBox::information(nullptr, QObject::tr("ok"),
                                     QObject::tr("modification effectue \n"
                                                 "click cancel to exit."), QMessageBox::Cancel);
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("not ok"),
                                     QObject::tr("modification non effectue \n"
                                                 "click cancel to exit."), QMessageBox::Cancel);
        }
}

//void MainWindow::on_pushButton_modifierEmploye_4_clicked()
//{
//    int idEmploye= ui->lineEdit_idModifierE->text().toInt();

//    QString nom =ui->lineEdit_nom_2->text();
//    QString prenom =ui->lineEdit_prenom_2->text();
//    QString naissance= ui->dateEdit_naissance_2->text();
//    QString poste= ui->comboBox_poste_2->currentText();
//    float salaire= ui->lineEdit_salaire_2->text().toFloat();
//    int telephone= ui->lineEdit_telephone_2->text().toInt();
//    QString mail =ui->lineEdit_mail_2->text();
//    QString domicile= ui->lineEdit_domicile_2->text();
//    int cin= ui->lineEdit_cin_2->text().toInt();
//    QString sexe= ui->lineEdit_sexe_2->text();

//    employe e(nom,prenom,idEmploye,naissance,poste,salaire,telephone,mail,domicile,cin,sexe);

//    bool test=e.modifierEmploye();
//    if(test)
//    {
//        ui->tabEmploye->setModel(e.afficherEmploye());
//        QMessageBox::information(nullptr, QObject::tr("ok"),
//                                 QObject::tr("modification Employe effectuee \n"
//                                             "click cancel to exit."), QMessageBox::Cancel);
//    }
//    else
//    {
//        QMessageBox::critical(nullptr, QObject::tr("ok"),
//                                 QObject::tr("modification Employe non effectue \n"
//                                             "click cancel to exit."), QMessageBox::Cancel);
//    }

//}

void MainWindow::on_pushButton_rechercherModM_clicked()
{
    int idu= ui->lineEdit_idModifierM->text().toInt();
    m.SetIdMachine(idu);
    bool test=m.rechercherModifier(idu);
    if(test)
    {
        m.verifMachine();

        m.SetIdMachine(ui->lineEdit_id_2->text().toInt());
        m.SetPrix(ui->lineEdit_prix_2->text().toFloat());
        m.SetNom(ui->lineEdit_nom_4->text());
        m.SetReference(ui->lineEdit_reference_2->text());
        m.SetCategorie(ui->lineEdit_categorie_2->text());
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("recherche effectue \n"
                                             "click cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                                 QObject::tr("recherche non effectue \n"
                                             "click cancel to exit."), QMessageBox::Cancel);
    }
}


/**********************EMPLOYE***************************/

void MainWindow::on_pushButton_ajouterEmploye_3_clicked()
{
    QString nom= ui->lineEdit_nom->text();
    QString prenom= ui->lineEdit_prenom->text();
    int idEmploye= ui->lineEdit_identifiant->text().toInt();
    QString naissance= ui->dateEdit_naissance->text();
    QString poste= ui->comboBox_poste->currentText();
    float salaire= ui->lineEdit_salaire->text().toFloat();
    int telephone= ui->lineEdit_telephone->text().toInt();
    QString mail= ui->lineEdit_mail->text();
    QString domicile= ui->lineEdit_domicile->text();
    int cin= ui->lineEdit_cin->text().toInt();
    QString sexe= ui->lineEdit_sexe->text();

    employe e(nom,prenom,idEmploye,naissance,poste,salaire,telephone,mail,domicile,cin,sexe);

    bool test=e.ajouterEmploye();
    if (test)
    {
        ui->tabEmploye->setModel(e.afficherEmploye());
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("Ajout Employe effectue \n"
                                             "click cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("ok"),
                                 QObject::tr("Ajout Employe non effectue \n"
                                             "click cancel to exit."), QMessageBox::Cancel);
    }
}


void MainWindow::on_pushButton_supprimerE_clicked()
{
    int idEmploye= ui->lineEdit_idSupprimerE->text().toInt();
    bool test= e.supprimerEmploye(idEmploye);

          if (test)
          {
              //refresh
              ui->tabEmploye->setModel(e.afficherEmploye());
              QMessageBox::information(nullptr, QObject::tr("ok"),
                                       QObject::tr("suppression Employe effectuee \n"
                                                   "click cancel to exit."), QMessageBox::Cancel);
          }
          else
          {
              QMessageBox::critical(nullptr, QObject::tr("ok"),
                                       QObject::tr("suppression Employe non effectue \n"
                                                   "click cancel to exit."), QMessageBox::Cancel);
          }
}

void MainWindow::on_pushButton_rechercherME_clicked()
{
    QString idEmploye= ui->lineEdit_idModifierE->text();
    e.SetIdentifiant(idEmploye.toInt());
   // employe e(nom,prenom,idEmploye,naissance,poste,salaire,telephone,mail,domicile,cin,sexe);

    bool test =e.rechercherEmploye();
    if (test)
    {
        ui->lineEdit_nom_2->show();
        ui->lineEdit_prenom_2->show();
        ui->lineEdit_identifiant_2->show();
        ui->comboBox_poste_2->show();
        ui->lineEdit_salaire_2->show();
        ui->lineEdit_telephone_2->show();
        ui->lineEdit_domicile_2->show();
        ui->lineEdit_cin_2->show();
        ui->lineEdit_sexe_2->show();
        ui->lineEdit_sexe_2->show();

        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("recherche Employe effectuee \n"
                                             "click cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("ok"),
                                 QObject::tr("recherche Employe non effectue \n"
                                             "click cancel to exit."), QMessageBox::Cancel);
    }
}


void MainWindow::on_pushButton_modifierEmploye_4_clicked()
{
    int idEmploye= ui->lineEdit_idModifierE->text().toInt();

    QString nom =ui->lineEdit_nom_2->text();
    QString prenom =ui->lineEdit_prenom_2->text();
    QString naissance= ui->dateEdit_naissance_2->text();
    QString poste= ui->comboBox_poste_2->currentText();
    float salaire= ui->lineEdit_salaire_2->text().toFloat();
    int telephone= ui->lineEdit_telephone_2->text().toInt();
    QString mail =ui->lineEdit_mail_2->text();
    QString domicile= ui->lineEdit_domicile_2->text();
    int cin= ui->lineEdit_cin_2->text().toInt();
    QString sexe= ui->lineEdit_sexe_2->text();

    employe e(nom,prenom,idEmploye,naissance,poste,salaire,telephone,mail,domicile,cin,sexe);

    bool test=e.modifierEmploye();
    if(test)
    {
        ui->tabEmploye->setModel(e.afficherEmploye());
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("modification Employe effectuee \n"
                                             "click cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("ok"),
                                 QObject::tr("modification Employe non effectue \n"
                                             "click cancel to exit."), QMessageBox::Cancel);
    }

}
