#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_pushButton_supprimerEmploye_clicked()////////////////////////////////////
{
    ui->stackedWidget->setCurrentIndex(5);
    ui->lineEdit_nom_5->hide();
    ui->lineEdit_prenom_3->hide();
    ui->lineEdit_identifiant_3->hide();
    ui->dateEdit_naissance_3->hide();
    ui->lineEdit_poste_3->hide();
    ui->lineEdit_salaire_3->hide();
    ui->lineEdit_telephone_3->hide();
    ui->lineEdit_mail_3->hide();
    ui->lineEdit_domicile_3->hide();
    ui->lineEdit_cin_3->hide();
    ui->lineEdit_sexe_3->hide();
    ui->pushButton_supprimerE->hide();
}

void MainWindow::on_pushButton_modifierEmploye_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_afficherEmploye_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_supprimerEmploye_2_clicked()//////////////////////////////////////
{
    ui->stackedWidget->setCurrentIndex(5);
    ui->stackedWidget->setCurrentIndex(5);
    ui->lineEdit_nom_5->hide();
    ui->lineEdit_prenom_3->hide();
    ui->lineEdit_identifiant_3->hide();
    ui->dateEdit_naissance_3->hide();
    ui->lineEdit_poste_3->hide();
    ui->lineEdit_salaire_3->hide();
    ui->lineEdit_telephone_3->hide();
    ui->lineEdit_mail_3->hide();
    ui->lineEdit_domicile_3->hide();
    ui->lineEdit_cin_3->hide();
    ui->lineEdit_sexe_3->hide();
    ui->pushButton_supprimerE->hide();
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

void MainWindow::on_pushButton_supprimerEmploye_3_clicked()///////////////
{
    ui->stackedWidget->setCurrentIndex(5);
    ui->stackedWidget->setCurrentIndex(5);
    ui->lineEdit_nom_5->hide();
    ui->lineEdit_prenom_3->hide();
    ui->lineEdit_identifiant_3->hide();
    ui->dateEdit_naissance_3->hide();
    ui->lineEdit_poste_3->hide();
    ui->lineEdit_salaire_3->hide();
    ui->lineEdit_telephone_3->hide();
    ui->lineEdit_mail_3->hide();
    ui->lineEdit_domicile_3->hide();
    ui->lineEdit_cin_3->hide();
    ui->lineEdit_sexe_3->hide();
    ui->pushButton_supprimerE->hide();
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

void MainWindow::on_pushButton_supprimerEmploye_4_clicked()//////////////////////////////////
{
    ui->stackedWidget->setCurrentIndex(5);
    ui->stackedWidget->setCurrentIndex(5);
    ui->lineEdit_nom_5->hide();
    ui->lineEdit_prenom_3->hide();
    ui->lineEdit_identifiant_3->hide();
    ui->dateEdit_naissance_3->hide();
    ui->lineEdit_poste_3->hide();
    ui->lineEdit_salaire_3->hide();
    ui->lineEdit_telephone_3->hide();
    ui->lineEdit_mail_3->hide();
    ui->lineEdit_domicile_3->hide();
    ui->lineEdit_cin_3->hide();
    ui->lineEdit_sexe_3->hide();
    ui->pushButton_supprimerE->hide();
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

void MainWindow::on_pushButton_supprimerMachine_clicked()//////////////////////////////////
{
    ui->stackedWidget->setCurrentIndex(10);
    ui->lineEdit_idMachine_2->hide();
    ui->lineEdit_prix_3->hide();
    ui->lineEdit_nom_6->hide();
    ui->lineEdit_reference_3->hide();
    ui->lineEdit_categorie_3->hide();
    ui->pushButton_supprimerM->hide();
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

void MainWindow::on_pushButton_supprimerMachine_2_clicked()////////////////////////////
{
    ui->stackedWidget->setCurrentIndex(10);
    ui->lineEdit_idMachine_2->hide();
    ui->lineEdit_prix_3->hide();
    ui->lineEdit_nom_6->hide();
    ui->lineEdit_reference_3->hide();
    ui->lineEdit_categorie_3->hide();
    ui->pushButton_supprimerM->hide();
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

void MainWindow::on_pushButton_supprimerMachine_3_clicked()///////////////////////
{
    ui->stackedWidget->setCurrentIndex(10);
    ui->lineEdit_idMachine_2->hide();
    ui->lineEdit_prix_3->hide();
    ui->lineEdit_nom_6->hide();
    ui->lineEdit_reference_3->hide();
    ui->lineEdit_categorie_3->hide();
    ui->pushButton_supprimerM->hide();
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

void MainWindow::on_pushButton_supprimerMachine_4_clicked()//////////////////////////
{
    ui->stackedWidget->setCurrentIndex(10);
    ui->lineEdit_idMachine_2->hide();
    ui->lineEdit_prix_3->hide();
    ui->lineEdit_nom_6->hide();
    ui->lineEdit_reference_3->hide();
    ui->lineEdit_categorie_3->hide();
    ui->pushButton_supprimerM->hide();
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
    ui->lineEdit_idMachine_2->hide();
    ui->lineEdit_prix_3->hide();
    ui->lineEdit_nom_6->hide();
    ui->lineEdit_reference_3->hide();
    ui->lineEdit_categorie_3->hide();
    ui->pushButton_supprimerM->hide();
}

void MainWindow::on_pushButton_retour_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_retour_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_supprimerEmploye_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
    ui->stackedWidget->setCurrentIndex(5);
    ui->lineEdit_nom_5->hide();
    ui->lineEdit_prenom_3->hide();
    ui->lineEdit_identifiant_3->hide();
    ui->dateEdit_naissance_3->hide();
    ui->lineEdit_poste_3->hide();
    ui->lineEdit_salaire_3->hide();
    ui->lineEdit_telephone_3->hide();
    ui->lineEdit_mail_3->hide();
    ui->lineEdit_domicile_3->hide();
    ui->lineEdit_cin_3->hide();
    ui->lineEdit_sexe_3->hide();
    ui->pushButton_supprimerE->hide();
}

void MainWindow::on_pushButton_clicked()//chercher Employe//////////////////////////////////////////
{
    ui->stackedWidget->setCurrentIndex(12);
//    ui->lineEdit_chercherNom->hide();
//    ui->lineEdit_chercherCIN->hide();
    ui->lineEdit_nom_7->hide();
    ui->lineEdit_prenom_4->hide();
    ui->lineEdit_identifiant_4->hide();
    ui->dateEdit_naissance_4->hide();
    ui->lineEdit_poste_4->hide();
    ui->lineEdit_salaire_4->hide();
    ui->lineEdit_telephone_4->hide();
    ui->lineEdit_mail_4->hide();
    ui->lineEdit_domicile_4->hide();
    ui->lineEdit_cin_4->hide();
    ui->lineEdit_sexe_4->hide();
}
void MainWindow::on_pushButton_2_clicked()////////////////////////
{
   ui->stackedWidget->setCurrentIndex(12);
   ui->stackedWidget->setCurrentIndex(12);
//   ui->lineEdit_chercherNom->hide();
//   ui->lineEdit_chercherCIN->hide();
   ui->lineEdit_nom_7->hide();
   ui->lineEdit_prenom_4->hide();
   ui->lineEdit_identifiant_4->hide();
   ui->dateEdit_naissance_4->hide();
   ui->lineEdit_poste_4->hide();
   ui->lineEdit_salaire_4->hide();
   ui->lineEdit_telephone_4->hide();
   ui->lineEdit_mail_4->hide();
   ui->lineEdit_domicile_4->hide();
   ui->lineEdit_cin_4->hide();
   ui->lineEdit_sexe_4->hide();
}
void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
    ui->stackedWidget->setCurrentIndex(12);
//    ui->lineEdit_chercherNom->hide();
//    ui->lineEdit_chercherCIN->hide();
    ui->lineEdit_nom_7->hide();
    ui->lineEdit_prenom_4->hide();
    ui->lineEdit_identifiant_4->hide();
    ui->dateEdit_naissance_4->hide();
    ui->lineEdit_poste_4->hide();
    ui->lineEdit_salaire_4->hide();
    ui->lineEdit_telephone_4->hide();
    ui->lineEdit_mail_4->hide();
    ui->lineEdit_domicile_4->hide();
    ui->lineEdit_cin_4->hide();
    ui->lineEdit_sexe_4->hide();
}
void MainWindow::on_pushButton_5_clicked()
{
  ui->stackedWidget->setCurrentIndex(12);
  ui->stackedWidget->setCurrentIndex(12);
//  ui->lineEdit_chercherNom->hide();
//  ui->lineEdit_chercherCIN->hide();
  ui->lineEdit_nom_7->hide();
  ui->lineEdit_prenom_4->hide();
  ui->lineEdit_identifiant_4->hide();
  ui->dateEdit_naissance_4->hide();
  ui->lineEdit_poste_4->hide();
  ui->lineEdit_salaire_4->hide();
  ui->lineEdit_telephone_4->hide();
  ui->lineEdit_mail_4->hide();
  ui->lineEdit_domicile_4->hide();
  ui->lineEdit_cin_4->hide();
  ui->lineEdit_sexe_4->hide();
}
void MainWindow::on_pushButton_4_clicked()
{
     ui->stackedWidget->setCurrentIndex(12);
     ui->stackedWidget->setCurrentIndex(12);
//     ui->lineEdit_chercherNom->hide();
//     ui->lineEdit_chercherCIN->hide();
     ui->lineEdit_nom_7->hide();
     ui->lineEdit_prenom_4->hide();
     ui->lineEdit_identifiant_4->hide();
     ui->dateEdit_naissance_4->hide();
     ui->lineEdit_poste_4->hide();
     ui->lineEdit_salaire_4->hide();
     ui->lineEdit_telephone_4->hide();
     ui->lineEdit_mail_4->hide();
     ui->lineEdit_domicile_4->hide();
     ui->lineEdit_cin_4->hide();
     ui->lineEdit_sexe_4->hide();
}
void MainWindow::on_pushButton_retour_10_clicked()
{
   ui->stackedWidget->setCurrentIndex(1);
}
void MainWindow::on_pushButton_supprimerEmploye_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_afficherEmploye_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_modifierEmploye_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_ajouterEmploye_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_chercherMachine_clicked()////////////////////////////
{
   ui->stackedWidget->setCurrentIndex(13);
//   ui->lineEdit_chercherNom_2->hide();
//   ui->lineEdit_chercherReference->hide();
   ui->lineEdit_idMachine_3->hide();
   ui->lineEdit_prix_4->hide();
   ui->lineEdit_nom_8->hide();
   ui->lineEdit_reference_4->hide();
   ui->lineEdit_categorie_4->hide();
}

void MainWindow::on_pushButton_chercherMachine_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
//    ui->lineEdit_chercherNom_2->hide();
//    ui->lineEdit_chercherReference->hide();
    ui->lineEdit_idMachine_3->hide();
    ui->lineEdit_prix_4->hide();
    ui->lineEdit_nom_8->hide();
    ui->lineEdit_reference_4->hide();
    ui->lineEdit_categorie_4->hide();
}

void MainWindow::on_pushButton_chercherMachine_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
//    ui->lineEdit_chercherNom_2->hide();
//    ui->lineEdit_chercherReference->hide();
    ui->lineEdit_idMachine_3->hide();
    ui->lineEdit_prix_4->hide();
    ui->lineEdit_nom_8->hide();
    ui->lineEdit_reference_4->hide();
    ui->lineEdit_categorie_4->hide();
}

void MainWindow::on_pushButton_chercherMachine_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
//    ui->lineEdit_chercherNom_2->hide();
//    ui->lineEdit_chercherReference->hide();
    ui->lineEdit_idMachine_3->hide();
    ui->lineEdit_prix_4->hide();
    ui->lineEdit_nom_8->hide();
    ui->lineEdit_reference_4->hide();
    ui->lineEdit_categorie_4->hide();
}

void MainWindow::on_pushButton_chercherMachine_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
//    ui->lineEdit_chercherNom_2->hide();
//    ui->lineEdit_chercherReference->hide();
    ui->lineEdit_idMachine_3->hide();
    ui->lineEdit_prix_4->hide();
    ui->lineEdit_nom_8->hide();
    ui->lineEdit_reference_4->hide();
    ui->lineEdit_categorie_4->hide();
}

void MainWindow::on_pushButton_chercherMachine_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
//    ui->lineEdit_chercherNom_2->hide();
//    ui->lineEdit_chercherReference->hide();
    ui->lineEdit_idMachine_3->hide();
    ui->lineEdit_prix_4->hide();
    ui->lineEdit_nom_8->hide();
    ui->lineEdit_reference_4->hide();
    ui->lineEdit_categorie_4->hide();
}

void MainWindow::on_pushButton_retour_11_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_pushButton_ajouterMachine_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_pushButton_modifierMachine_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
}

void MainWindow::on_pushButton_afficherMachine_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_pushButton_supprimerMachine_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
    ui->lineEdit_idMachine_2->hide();
    ui->lineEdit_prix_3->hide();
    ui->lineEdit_nom_6->hide();
    ui->lineEdit_reference_3->hide();
    ui->lineEdit_categorie_3->hide();
    ui->pushButton_supprimerM->hide();
}

void MainWindow::on_pushButton_statistiques_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}

void MainWindow::on_pushButton_aide_clicked()
{
    ui->stackedWidget->setCurrentIndex(14);
}

void MainWindow::on_pushButton_retour_12_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

/**********************MACHINE***************************/
void MainWindow::on_pushButton_ajouterMachine_3_clicked()
{
    int idMachine= ui->lineEdit_idMachine->text().toInt();
    float prix= ui->lineEdit_prix->text().toFloat();
    QString nom= ui->lineEdit_nom_3->text();
    QString reference= ui->lineEdit_reference->text();
    QString categorie= ui->lineEdit_categorie->text();

    machine m(idMachine, prix, nom, reference, categorie);

    if (idMachine!=NULL && prix!=NULL && nom!=NULL && reference!=NULL && categorie!=NULL)
    {
        bool test=m.ajouterMachine();
        if (test)
        {
            //refresh
            ui->tabMachine->setModel(m.afficherMachine());
            QMessageBox::information(nullptr, QObject::tr("ok"),
                                     QObject::tr("Ajout Machine effectue \n"
                                                 "click cancel to exit."), QMessageBox::Cancel);
            ui->lineEdit_idMachine->clear();
            ui->lineEdit_prix->clear();
            ui->lineEdit_nom_3->clear();
            ui->lineEdit_reference->clear();
            ui->lineEdit_categorie->clear();
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("not ok"),
                                  QObject::tr("Ajout Machine non effectue \n"
                                              "click cancel to exit."), QMessageBox::Cancel);
        }
    }
    else
    {
        QMessageBox::warning(this, "echec","Remplissez tous les champs!");
    }
}

void MainWindow::on_pushButton_supprimerM_clicked()
{

    bool test=m.supprimerMachine();

    if (test)
    {
        //refresh
        ui->tabMachine->setModel(m.afficherMachine());
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("suppression Machine effectuee \n"
                                             "click cancel to exit."), QMessageBox::Cancel);
        ui->lineEdit_idMachine_2->clear();
        ui->lineEdit_prix_3->clear();
        ui->lineEdit_nom_6->clear();
        ui->lineEdit_reference_3->clear();
        ui->lineEdit_categorie_3->clear();
        ui->lineEdit_idSupprimerM->clear();
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("ok"),
                              QObject::tr("suppression Machine non effectue \n"
                                          "click cancel to exit."), QMessageBox::Cancel);
    }
}


void MainWindow::on_pushButton_rechercherSM_clicked()//recherche supprimer
{
    QString ids=ui->lineEdit_idSupprimerM->text();
    m.SetIdMachine(ids.toInt());

    if(m.verifMachine()==0)
    {
    ui->lineEdit_idMachine_2->show();
    ui->lineEdit_prix_3->show();
    ui->lineEdit_nom_6->show();
    ui->lineEdit_reference_3->show();
    ui->lineEdit_categorie_3->show();
    ui->pushButton_supprimerM->show();

    QString id=QString::number(m.GetIdMachine());
    QString pr=QString::number(m.GetPrix());

    ui->lineEdit_idMachine_2->setText(id);
    ui->lineEdit_prix_3->setText(pr);
    ui->lineEdit_nom_6->setText(m.GetNom());
    ui->lineEdit_reference_3->setText(m.GetReference());
    ui->lineEdit_categorie_3->setText(m.GetCategorie());
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("ok"),
                              QObject::tr("l'identifiant n'existe pas \n"
                                          "click cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_rechercherModM_clicked()//recherche modification
{
    QString idMachine= ui->lineEdit_idModifierM->text();
    m.SetIdMachine(idMachine.toInt());

    if(m.verifMachine()==0)
    {
        if(m.rechercherModifierMachine())
        {
            QString id=QString::number(m.GetIdMachine());
            QString pr=QString::number(m.GetPrix());

            ui->lineEdit_id_2->setText(id);
            ui->lineEdit_prix_2->setText(pr);
            ui->lineEdit_nom_4->setText(m.GetNom());
            ui->lineEdit_reference_2->setText(m.GetReference());
            ui->lineEdit_categorie_2->setText(m.GetCategorie());

//            QMessageBox::information(nullptr, QObject::tr("ok"),
//                                     QObject::tr("Machine existe \n"
//                                                 "click cancel to exit."), QMessageBox::Cancel);
        }
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                              QObject::tr("Machine n'existe pas \n"
                                          "click cancel to exit."), QMessageBox::Cancel);
        ui->lineEdit_idModifierM->clear();
    }
}

void MainWindow::on_pushButton_modifierMachine_4_clicked()
{
    QString idMachine= ui->lineEdit_id_2->text();
    QString prix=ui->lineEdit_prix_2->text();
    QString nom=ui->lineEdit_nom_4->text();
    QString reference=ui->lineEdit_reference_2->text();
    QString categorie=ui->lineEdit_categorie_2->text();

    m.SetIdMachine(idMachine.toInt());
    m.SetPrix(prix.toInt());
    m.SetNom(nom);
    m.SetReference(reference);
    m.SetCategorie(categorie);


    bool test=m.modifierMachine();
    if (test)
    {
        //refresh
        ui->tabMachine->setModel(m.afficherMachine());

        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("modification Machine effectue \n"
                                             "click cancel to exit."), QMessageBox::Cancel);

        ui->lineEdit_id_2->clear();
        ui->lineEdit_prix_2->clear();
        ui->lineEdit_nom_4->clear();
        ui->lineEdit_reference_2->clear();
        ui->lineEdit_categorie_2->clear();
        ui->lineEdit_idModifierM->clear();
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                              QObject::tr("modification Machine non effectue \n"
                                          "click cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_triMachine_clicked()
{
    QString test = ui->comboBox_triMachine->currentText();
    if(test == "Identifiant")
    {
        ui->tabMachine->setModel(m.trierMachineParID());
    }
    else if(test =="Nom")
    {
        ui->tabMachine->setModel(m.trierMachineParNom());
    }
    else if(test == "Reference")
    {
        ui->tabMachine->setModel(m.trierMachineParReference());
    }
}

void MainWindow::on_pushButton_chercherMachine_8_clicked()
{
    QString idMachine= ui->lineEdit_chercherID->text();
    m.SetIdMachine(idMachine.toInt());

    if (m.verifMachine()==0)
    {
        if (m.rechercherModifierMachine())
        {
            ui->lineEdit_idMachine_3->show();
            ui->lineEdit_prix_4->show();
            ui->lineEdit_nom_8->show();
            ui->lineEdit_reference_4->show();
            ui->lineEdit_categorie_4->show();

            QSqlQuery query;

            QString id=QString::number(m.GetIdMachine());
            QString pr=QString::number(m.GetPrix());

            ui->lineEdit_idMachine_3->setText(id);
            ui->lineEdit_prix_4->setText(pr);
            ui->lineEdit_nom_8->setText(m.GetNom());
            ui->lineEdit_reference_4->setText(m.GetReference());
            ui->lineEdit_categorie_4->setText(m.GetCategorie());
            QMessageBox::information(nullptr, QObject::tr("ok"),
                                     QObject::tr("Machine trouve par identifiant \n"
                                                 "click cancel to exit."), QMessageBox::Cancel);
            ui->lineEdit_idMachine_3->clear();
            ui->lineEdit_prix_4->clear();
            ui->lineEdit_nom_8->clear();
            ui->lineEdit_reference_4->clear();
            ui->lineEdit_categorie_4->clear();
            ui->lineEdit_chercherID->clear();
            ui->lineEdit_chercherNom_2->clear();
            ui->lineEdit_chercherReference->clear();
        }
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("ok"),
                                 QObject::tr("Machine non trouve \n"
                                             "click cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_chercherMachine_9_clicked()
{
    QString nom= ui->lineEdit_chercherNom_2->text();
    m.SetNom(nom);

    if (m.verifMachineParNom()==0)
    {
        if (m.chercherParNom())
        {
            ui->lineEdit_idMachine_3->show();
            ui->lineEdit_prix_4->show();
            ui->lineEdit_nom_8->show();
            ui->lineEdit_reference_4->show();
            ui->lineEdit_categorie_4->show();

            QSqlQuery query;

            QString id=QString::number(m.GetIdMachine());
            QString pr=QString::number(m.GetPrix());

            ui->lineEdit_idMachine_3->setText(id);
            ui->lineEdit_prix_4->setText(pr);
            ui->lineEdit_nom_8->setText(m.GetNom());
            ui->lineEdit_reference_4->setText(m.GetReference());
            ui->lineEdit_categorie_4->setText(m.GetCategorie());
            QMessageBox::information(nullptr, QObject::tr("ok"),
                                     QObject::tr("Machine trouve par nom \n"
                                                 "click cancel to exit."), QMessageBox::Cancel);
            ui->lineEdit_idMachine_3->clear();
            ui->lineEdit_prix_4->clear();
            ui->lineEdit_nom_8->clear();
            ui->lineEdit_reference_4->clear();
            ui->lineEdit_categorie_4->clear();
            ui->lineEdit_chercherID->clear();
            ui->lineEdit_chercherID->clear();
            ui->lineEdit_chercherNom_2->clear();
            ui->lineEdit_chercherReference->clear();
        }
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("ok"),
                                 QObject::tr("Machine non trouve \n"
                                             "click cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_chercherMachine_10_clicked()
{
    QString reference= ui->lineEdit_chercherReference->text();
    m.SetReference(reference);

    if (m.verifMachineParReference()==0)
    {
        if (m.chercherParReference())
        {
            ui->lineEdit_idMachine_3->show();
            ui->lineEdit_prix_4->show();
            ui->lineEdit_nom_8->show();
            ui->lineEdit_reference_4->show();
            ui->lineEdit_categorie_4->show();

            QSqlQuery query;

            QString id=QString::number(m.GetIdMachine());
            QString pr=QString::number(m.GetPrix());

            ui->lineEdit_idMachine_3->setText(id);
            ui->lineEdit_prix_4->setText(pr);
            ui->lineEdit_nom_8->setText(m.GetNom());
            ui->lineEdit_reference_4->setText(m.GetReference());
            ui->lineEdit_categorie_4->setText(m.GetCategorie());
            QMessageBox::information(nullptr, QObject::tr("ok"),
                                     QObject::tr("Machine trouve par reference \n"
                                                 "click cancel to exit."), QMessageBox::Cancel);
            ui->lineEdit_idMachine_3->clear();
            ui->lineEdit_prix_4->clear();
            ui->lineEdit_nom_8->clear();
            ui->lineEdit_reference_4->clear();
            ui->lineEdit_categorie_4->clear();
            ui->lineEdit_chercherID->clear();
            ui->lineEdit_chercherID->clear();
            ui->lineEdit_chercherNom_2->clear();
            ui->lineEdit_chercherReference->clear();

        }
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("ok"),
                                 QObject::tr("Machine non trouve \n"
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
    QString poste= ui->lineEdit_poste->text();
    int salaire= ui->lineEdit_salaire->text().toInt();
    int telephone= ui->lineEdit_telephone->text().toInt();
    QString mail= ui->lineEdit_mail->text();
    QString domicile= ui->lineEdit_domicile->text();
    int cin= ui->lineEdit_cin->text().toInt();
    QString sexe= ui->lineEdit_sexe->text();

    employe e(nom,prenom,idEmploye,naissance,poste,salaire,telephone,mail,domicile,cin,sexe);

    if (nom!=NULL && prenom!=NULL && idEmploye!=NULL && naissance!=NULL && poste!=NULL && salaire!=NULL && telephone!=NULL && mail!=NULL && domicile!=NULL && sexe!=NULL)
    {
        bool test=e.ajouterEmploye();
        if (test)
        {
            ui->tabEmploye->setModel(e.afficherEmploye());
            QMessageBox::information(nullptr, QObject::tr("ok"),
                                     QObject::tr("Ajout Employe effectue \n"
                                                 "click cancel to exit."), QMessageBox::Cancel);
            ui->lineEdit_nom->clear();
            ui->lineEdit_prenom->clear();
            ui->lineEdit_identifiant->clear();
            ui->dateEdit_naissance->clear();
            ui->lineEdit_poste->clear();
            ui->lineEdit_salaire->clear();
            ui->lineEdit_telephone->clear();
            ui->lineEdit_mail->clear();
            ui->lineEdit_domicile->clear();
            ui->lineEdit_cin->clear();
            ui->lineEdit_sexe->clear();
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("ok"),
                                  QObject::tr("Ajout Employe non effectue \n"
                                              "click cancel to exit."), QMessageBox::Cancel);
        }
    }
    else
    {
        QMessageBox::warning(this,"echec","Remplissez tous les champs!");
    }
}


void MainWindow::on_pushButton_supprimerE_clicked()
{
    bool test= e.supprimerEmploye();

    if (test)
    {
        //refresh
        ui->tabEmploye->setModel(e.afficherEmploye());

        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("suppression Employe effectuee \n"
                                             "click cancel to exit."), QMessageBox::Cancel);
        ui->lineEdit_nom_5->clear();
        ui->lineEdit_prenom_3->clear();
        ui->lineEdit_identifiant_3->clear();
        ui->dateEdit_naissance_3->clear();
        ui->lineEdit_poste_3->clear();
        ui->lineEdit_salaire_3->clear();
        ui->lineEdit_telephone_3->clear();
        ui->lineEdit_mail_3->clear();
        ui->lineEdit_domicile_3->clear();
        ui->lineEdit_cin_3->clear();
        ui->lineEdit_sexe_3->clear();
        ui->lineEdit_idSupprimerE->clear();

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("ok"),
                              QObject::tr("suppression Employe non effectue \n"
                                          "click cancel to exit."), QMessageBox::Cancel);
    }
}


void MainWindow::on_pushButton_rechercherSE_clicked()//recherche supprimer employe
{
    QString idS=ui->lineEdit_idSupprimerE->text();
    e.SetIdentifiant(idS.toInt());

    if(e.verifEmploye()==0)
    {
//        QMessageBox::information(nullptr, QObject::tr("ok"),
//                                 QObject::tr("l'identifiant existe \n"
//                                             "click cancel to exit."), QMessageBox::Cancel);

        ui->lineEdit_nom_5->show();
        ui->lineEdit_prenom_3->show();
        ui->lineEdit_identifiant_3->show();
        ui->dateEdit_naissance_3->show();
        ui->lineEdit_poste_3->show();
        ui->lineEdit_salaire_3->show();
        ui->lineEdit_telephone_3->show();
        ui->lineEdit_mail_3->show();
        ui->lineEdit_domicile_3->show();
        ui->lineEdit_cin_3->show();
        ui->lineEdit_sexe_3->show();
        ui->pushButton_supprimerE->show();

        QString id=QString::number((e.GetIdentifiant()));
        QString sl=QString::number(e.GetSalaire());
        QString cn=QString::number(e.GetCin());
        QString tel=QString::number(e.GetTelephone());
        ui->lineEdit_nom_5->setText(e.GetNom());
        ui->lineEdit_prenom_3->setText(e.GetPrenom());
        ui->lineEdit_identifiant_3->setText(id);
        ui->dateEdit_naissance_3->setDate(QDate::fromString(e.GetNaissance(),"dd/MM/yyyy"));
        ui->lineEdit_poste_3->setText(e.GetPoste());
        ui->lineEdit_salaire_3->setText(sl);
        ui->lineEdit_telephone_3->setText(tel);
        ui->lineEdit_mail_3->setText(e.GetMail());
        ui->lineEdit_domicile_3->setText(e.GetDomicile());
        ui->lineEdit_cin_3->setText(cn);
        ui->lineEdit_sexe_3->setText(e.GetSexe());


    }
    else
    {
        QMessageBox::warning(this,"echec","Employe n'existe pas!");
    }
}

void MainWindow::on_pushButton_rechercherME_clicked()//rechercher modification employe
{
    QString idEmploye= ui->lineEdit_idModifierE->text();
    e.SetIdentifiant(idEmploye.toInt());

    //    bool test =e.verifEmploye();
    if(e.verifEmploye()==0)
    {
        if (e.rechercherEmploye())
        {
            QSqlQuery query;

            QString id=QString::number((e.GetIdentifiant()));
            QString sl=QString::number(e.GetSalaire());
            QString cn=QString::number(e.GetCin());
            QString tel=QString::number(e.GetTelephone());

            ui->lineEdit_nom_2->setText(e.GetNom());
            ui->lineEdit_prenom_2->setText(e.GetPrenom());
            ui->lineEdit_identifiant_2->setText(id);
            ui->dateEdit_naissance_2->setDate(QDate::fromString(e.GetNaissance(),"dd/MM/yyyy"));
            ui->lineEdit_poste_2->setText(e.GetPoste());
            ui->lineEdit_salaire_2->setText(sl);
            ui->lineEdit_telephone_2->setText(tel);
            ui->lineEdit_mail_2->setText(e.GetMail());
            ui->lineEdit_domicile_2->setText(e.GetDomicile());
            ui->lineEdit_cin_2->setText(cn);
            ui->lineEdit_sexe_2->setText(e.GetSexe());

//            QMessageBox::information(nullptr, QObject::tr("ok"),
//                                     QObject::tr("Employe existe \n"
//                                                 "click cancel to exit."), QMessageBox::Cancel);
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("ok"),
                                  QObject::tr("Employe n'existe pas \n"
                                              "click cancel to exit."), QMessageBox::Cancel);
             ui->lineEdit_idModifierE->clear();
        }
    }
    else
    {
        QMessageBox::warning(this,"echec","Employe n'existe pas!");
    }
}



void MainWindow::on_pushButton_modifierEmploye_4_clicked()
{
    QString nom=ui->lineEdit_nom_2->text();
    QString prenom=ui->lineEdit_prenom_2->text();
    QString idEmploye= ui->lineEdit_identifiant_2->text();
    QString naissance= ui->dateEdit_naissance_2->text();
    QString poste= ui->lineEdit_poste_2->text();
    QString salaire= ui->lineEdit_salaire_2->text();
    QString telephone= ui->lineEdit_telephone_2->text();
    QString mail= ui->lineEdit_mail_2->text();
    QString domicile= ui->lineEdit_domicile_2->text();
    QString cin= ui->lineEdit_cin_2->text();
    QString sexe= ui->lineEdit_sexe_2->text();

    e.SetNom(nom);
    e.SetPrenom(prenom);
    e.SetIdentifiant(idEmploye.toInt());
    e.SetNaissance(naissance);
    e.SetPoste(poste);
    e.SetSalaire(salaire.toInt());
    e.SetTelephone(telephone.toInt());
    e.SetMail(mail);
    e.SetDomicile(domicile);
    e.SetCin(cin.toInt());
    e.SetSexe(sexe);

    // employe e(nom,prenom,idEmploye,naissance,poste,salaire,telephone,mail,domicile,cin,sexe);

    bool test=e.modifierEmploye();
    if(test)
    {
        ui->tabEmploye->setModel(e.afficherEmploye());
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("modification Employe effectuee \n"
                                             "click cancel to exit."), QMessageBox::Cancel);
        ui->lineEdit_nom_2->clear();
        ui->lineEdit_prenom_2->clear();
        ui->lineEdit_identifiant_2->clear();
        ui->dateEdit_naissance_2->clear();
        ui->lineEdit_poste_2->clear();
        ui->lineEdit_salaire_2->clear();
        ui->lineEdit_telephone_2->clear();
        ui->lineEdit_mail_2->clear();
        ui->lineEdit_domicile_2->clear();
        ui->lineEdit_cin_2->clear();
        ui->lineEdit_sexe_2->clear();
        ui->lineEdit_idModifierE->clear();
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("ok"),
                              QObject::tr("modification Employe non effectue \n"
                                          "click cancel to exit."), QMessageBox::Cancel);
    }

}


void MainWindow::on_pushButton_triEmploye_clicked()
{
    QString test = ui->comboBox_tri->currentText();
    if(test == "Nom")
    {
        ui->tabEmploye->setModel(e.trierEmployeParNom());
    }
    else if(test =="Identifiant")
    {
        ui->tabEmploye->setModel(e.trierEmployeParID());
    }
    else if(test == "Cin")
    {
        ui->tabEmploye->setModel(e.trierEmployeParCin());
    }
}

void MainWindow::on_pushButton_chercherEmploye_clicked()
{
    QString idEmploye= ui->lineEdit_chercherIdentifiant->text();
    e.SetIdentifiant(idEmploye.toInt());

    if (e.verifEmploye()==0)
    {
        if (e.rechercherEmploye())
        {
            ui->lineEdit_nom_7->show();
            ui->lineEdit_prenom_4->show();
            ui->lineEdit_identifiant_4->show();
            ui->dateEdit_naissance_4->show();
            ui->lineEdit_poste_4->show();
            ui->lineEdit_salaire_4->show();
            ui->lineEdit_telephone_4->show();
            ui->lineEdit_mail_4->show();
            ui->lineEdit_domicile_4->show();
            ui->lineEdit_cin_4->show();
            ui->lineEdit_sexe_4->show();

            QSqlQuery query;

            QString id=QString::number(e.GetIdentifiant());
            QString sl=QString::number(e.GetSalaire());
            QString cn=QString::number(e.GetCin());
            QString tel=QString::number(e.GetTelephone());

            ui->lineEdit_nom_7->setText(e.GetNom());
            ui->lineEdit_prenom_4->setText(e.GetPrenom());
            ui->lineEdit_identifiant_4->setText(id);
            ui->dateEdit_naissance_4->setDate(QDate::fromString(e.GetNaissance(),"dd/MM/yyyy"));
            ui->lineEdit_poste_4->setText(e.GetPoste());
            ui->lineEdit_salaire_4->setText(sl);
            ui->lineEdit_telephone_4->setText(tel);
            ui->lineEdit_mail_4->setText(e.GetMail());
            ui->lineEdit_domicile_4->setText(e.GetDomicile());
            ui->lineEdit_cin_4->setText(cn);
            ui->lineEdit_sexe_4->setText(e.GetSexe());
            QMessageBox::information(nullptr, QObject::tr("ok"),
                                     QObject::tr("Employe trouve par identifiant \n"
                                                 "click cancel to exit."), QMessageBox::Cancel);
            ui->lineEdit_nom_7->clear();
            ui->lineEdit_prenom_4->clear();
            ui->lineEdit_identifiant_4->clear();
            ui->dateEdit_naissance_4->clear();
            ui->lineEdit_poste_4->clear();
            ui->lineEdit_salaire_4->clear();
            ui->lineEdit_telephone_4->clear();
            ui->lineEdit_mail_4->clear();
            ui->lineEdit_domicile_4->clear();
            ui->lineEdit_cin_4->clear();
            ui->lineEdit_sexe_4->clear();
            ui->lineEdit_chercherIdentifiant->clear();
            ui->lineEdit_chercherNom->clear();
            ui->lineEdit_chercherCIN->clear();

        }
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("ok"),
                                 QObject::tr("Employe non trouve \n"
                                             "click cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_tabWidget_currentChanged(int index)
{
    QLineSeries *series = new QLineSeries();
       series->append(0,6);
       series->append(2,4);
       series->append(3,8);
       series->append(10,5);
       *series << QPoint(11,1)<<QPoint(13,3)<<QPoint(17,6)<<QPoint(18,3)<<QPoint(20,2);
       QChart *chart = new QChart();
       chart->legend()->hide();
       chart->addSeries(series);
       chart->createDefaultAxes();
       chart->setTitle("Rendement de Machines");
       QChartView *chartview=new QChartView(chart);
       chartview->setRenderHint(QPainter::Antialiasing);
       chartview->setParent(ui->horizontalFrame1);
}

void MainWindow::on_tabWidget_tabBarClicked(int index)
{
    QPieSeries *series =new QPieSeries();
    series->append("Decembre",80);
    series->append("Novembre",70);
    series->append("Janvier",50);
    series->append("Octobre",40);
    series->append("Septembre",30);

    QPieSlice *slice = series->slices().at(1);
    slice->setExploded(true);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Le Rendement Des Machines Pendant l'Hiver");

    QChartView *chartview = new QChartView(chart);
    chartview->setParent(ui->horizontalFrame);
}


void MainWindow::on_pushButton_chercherEmploye_2_clicked()
{
    QString nom= ui->lineEdit_chercherNom->text();
    e.SetNom(nom);

    if (e.verifEmployeParNom()==0)
    {
        if (e.chercherParNom())
        {
            ui->lineEdit_nom_7->show();
            ui->lineEdit_prenom_4->show();
            ui->lineEdit_identifiant_4->show();
            ui->dateEdit_naissance_4->show();
            ui->lineEdit_poste_4->show();
            ui->lineEdit_salaire_4->show();
            ui->lineEdit_telephone_4->show();
            ui->lineEdit_mail_4->show();
            ui->lineEdit_domicile_4->show();
            ui->lineEdit_cin_4->show();
            ui->lineEdit_sexe_4->show();

            QSqlQuery query;

            QString id=QString::number(e.GetIdentifiant());
            QString sl=QString::number(e.GetSalaire());
            QString cn=QString::number(e.GetCin());
            QString tel=QString::number(e.GetTelephone());

            ui->lineEdit_nom_7->setText(e.GetNom());
            ui->lineEdit_prenom_4->setText(e.GetPrenom());
            ui->lineEdit_identifiant_4->setText(id);
            ui->dateEdit_naissance_4->setDate(QDate::fromString(e.GetNaissance(),"dd/MM/yyyy"));
            ui->lineEdit_poste_4->setText(e.GetPoste());
            ui->lineEdit_salaire_4->setText(sl);
            ui->lineEdit_telephone_4->setText(tel);
            ui->lineEdit_mail_4->setText(e.GetMail());
            ui->lineEdit_domicile_4->setText(e.GetDomicile());
            ui->lineEdit_cin_4->setText(cn);
            ui->lineEdit_sexe_4->setText(e.GetSexe());
            QMessageBox::information(nullptr, QObject::tr("ok"),
                                     QObject::tr("Employe trouve par nom \n"
                                                 "click cancel to exit."), QMessageBox::Cancel);
            ui->lineEdit_nom_7->clear();
            ui->lineEdit_prenom_4->clear();
            ui->lineEdit_identifiant_4->clear();
            ui->dateEdit_naissance_4->clear();
            ui->lineEdit_poste_4->clear();
            ui->lineEdit_salaire_4->clear();
            ui->lineEdit_telephone_4->clear();
            ui->lineEdit_mail_4->clear();
            ui->lineEdit_domicile_4->clear();
            ui->lineEdit_cin_4->clear();
            ui->lineEdit_sexe_4->clear();
            ui->lineEdit_chercherNom->clear();
            ui->lineEdit_chercherIdentifiant->clear();
            ui->lineEdit_chercherCIN->clear();

        }
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("ok"),
                                 QObject::tr("Employe non trouve \n"
                                             "click cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_chercherEmploye_3_clicked()
{
    QString cin= ui->lineEdit_chercherCIN->text();
    e.SetCin(cin.toInt());

    if (e.verifEmployeParCin()==0)
    {
        if (e.chercherParCin())
        {
            ui->lineEdit_nom_7->show();
            ui->lineEdit_prenom_4->show();
            ui->lineEdit_identifiant_4->show();
            ui->dateEdit_naissance_4->show();
            ui->lineEdit_poste_4->show();
            ui->lineEdit_salaire_4->show();
            ui->lineEdit_telephone_4->show();
            ui->lineEdit_mail_4->show();
            ui->lineEdit_domicile_4->show();
            ui->lineEdit_cin_4->show();
            ui->lineEdit_sexe_4->show();

            QSqlQuery query;

            QString id=QString::number(e.GetIdentifiant());
            QString sl=QString::number(e.GetSalaire());
            QString cn=QString::number(e.GetCin());
            QString tel=QString::number(e.GetTelephone());

            ui->lineEdit_nom_7->setText(e.GetNom());
            ui->lineEdit_prenom_4->setText(e.GetPrenom());
            ui->lineEdit_identifiant_4->setText(id);
            ui->dateEdit_naissance_4->setDate(QDate::fromString(e.GetNaissance(),"dd/MM/yyyy"));
            ui->lineEdit_poste_4->setText(e.GetPoste());
            ui->lineEdit_salaire_4->setText(sl);
            ui->lineEdit_telephone_4->setText(tel);
            ui->lineEdit_mail_4->setText(e.GetMail());
            ui->lineEdit_domicile_4->setText(e.GetDomicile());
            ui->lineEdit_cin_4->setText(cn);
            ui->lineEdit_sexe_4->setText(e.GetSexe());
            QMessageBox::information(nullptr, QObject::tr("ok"),
                                     QObject::tr("Employe trouve par cin \n"
                                                 "click cancel to exit."), QMessageBox::Cancel);
            ui->lineEdit_nom_7->clear();
            ui->lineEdit_prenom_4->clear();
            ui->lineEdit_identifiant_4->clear();
            ui->dateEdit_naissance_4->clear();
            ui->lineEdit_poste_4->clear();
            ui->lineEdit_salaire_4->clear();
            ui->lineEdit_telephone_4->clear();
            ui->lineEdit_mail_4->clear();
            ui->lineEdit_domicile_4->clear();
            ui->lineEdit_cin_4->clear();
            ui->lineEdit_sexe_4->clear();
            ui->lineEdit_chercherIdentifiant->clear();
            ui->lineEdit_chercherNom->clear();
            ui->lineEdit_chercherCIN->clear();

        }
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("ok"),
                                 QObject::tr("Employe non trouve \n"
                                             "click cancel to exit."), QMessageBox::Cancel);
    }
}




