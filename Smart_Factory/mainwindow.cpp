#include "mainwindow.h"
#include "ui_mainwindow.h"


#include "login.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    son=new QSound(":/sons/music.wav");
    ui->table_F->setModel(tb.afficher());
     ui->afficherMatierePremiere->setModel(mp.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionSon_triggered()

    {
      son->play();
    }



void MainWindow::on_pushButton_3_clicked()
{
    Login g;
    g.NomUtilisateur = ui->nomUtilisateur->text();
    g.MotDePasse = ui->motDePasse->text().toULong();

        if(g.NomUtilisateur == "caleb" && g.MotDePasse == 1234 )
        {
                    ui->stackedWidget->setCurrentIndex(1);

        }

        else
        {
            QMessageBox::critical(this, "Echec", "Nom d'utilisateur ou Mot de passe incorrect \n Reessayez !");
            ui->motDePasse->clear();
        }
}


void MainWindow::on_pushButton_1_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}




void MainWindow::on_fournisseur_clicked()
{
      ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_matiereP_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_7_clicked()
{
     ui->afficherMatierePremiere->setModel(mp.trier_nom());
 }

void MainWindow::on_pushButton_8_clicked()
{
      ui->afficherMatierePremiere->setModel(mp.trier_quantite());
}

void MainWindow::on_pushButton_clicked()
{
 ui->table_F->setModel(tb.trier_nom());
}

void MainWindow::on_pushButton_5_clicked()
{
     ui->table_F->setModel(tb.trier_ID());
}


void MainWindow::on_ajouter_clicked()
{
    tb.setID(ui->lineEdit_identifiantF->text().toInt());
    tb.setNom(ui->lineEdit_nomF->text());
    tb.setAdresse(ui->lineEdit_adresseF->text());
    tb.setTelephone(ui->lineEdit_telephoneF->text().toInt());
    tb.setEmail(ui->lineEdit_emailF->text());

    fournisseur f(tb.get_identifiant(), tb.get_nom(), tb.get_adresse(), tb.get_telephone(), tb.get_email());

    if(  f.get_identifiant()!=0, f.get_nom()!=NULL, f.get_adresse()!=NULL, f.get_telephone()!=0, f.get_email()!=NULL )
    {

        bool test = f.ajouter();
        if(test)
        {

            ui->table_F->setModel(tb.afficher());//actualiser
            qDebug()<<"Envoi effectue"<<endl;
            QMessageBox::information(this, "Reussite", "Fournisseur ajouté !");
            ui->lineEdit_identifiantF->clear();
            ui->lineEdit_nomF->clear();
            ui->lineEdit_adresseF->clear();
            ui->lineEdit_telephoneF->clear();
            ui->lineEdit_emailF->clear();
        }
        else
         {
         qDebug()<<"Envoi non effectue"<<endl;
         QMessageBox::warning(this, "Echec", "Fournisseur non ajouté !");
         ui->lineEdit_identifiantF->clear();
         ui->lineEdit_nomF->clear();
         ui->lineEdit_adresseF->clear();
         ui->lineEdit_telephoneF->clear();
         ui->lineEdit_emailF->clear();
         }

    }
    else
         QMessageBox::critical(this, "Echec", "Remplissez tout les champs !");


}


void MainWindow::on_pushButton_M_clicked()
{

    tb.setID(ui->lineEdit_identifiantM->text().toInt());
    tb.setNom(ui->lineEdit_nom1->text());
    tb.setAdresse(ui->lineEdit_2->text());
    tb.setTelephone(ui->lineEdit_3->text().toInt());
    tb.setEmail(ui->lineEdit_4->text());

    fournisseur f(tb.get_identifiant(), tb.get_nom(), tb.get_adresse(), tb.get_telephone(), tb.get_email());

    if(  f.get_identifiant()!=0, f.get_nom()!=NULL, f.get_adresse()!=NULL, f.get_telephone()!=0, f.get_email()!=NULL )
    {

        bool test = f.modifier(f.get_identifiant());
        if(test)
        {
            ui->table_F->setModel(tb.afficher());
            qDebug()<<"Modification effectue"<<endl;

            QMessageBox::information(this, "Reussite", "Modification effectué !");
            ui->lineEdit_identifiantM->clear();
            ui->lineEdit_nom1->clear();
            ui->lineEdit_2->clear();
            ui->lineEdit_3->clear();
            ui->lineEdit_4->clear();
        }
        else
         {
         qDebug()<<"Envoi non effectue"<<endl;
         QMessageBox::information(this, "Echec", "Modification non effectué !");
         ui->lineEdit_identifiantM->clear();
         ui->lineEdit_nom1->clear();
         ui->lineEdit_2->clear();
         ui->lineEdit_3->clear();
         ui->lineEdit_4->clear();
         }

    }
    else
         QMessageBox::critical(this, "Echec", "Remplissez tout les champs !");

}

void MainWindow::on_recherche_textChanged(const QString &arg1)
{
    tb.setID(ui->recherche->text().toInt());
    ui->tableAffichage->setModel(tb.chercher(tb.get_identifiant()));
 }

void MainWindow::on_pushButton_supprimer_2_clicked()
{
     tb.setID(ui->recherche->text().toInt());
    if(tb.get_identifiant()!=0)
    {
        bool test=tb.supprimer(tb.get_identifiant());
        if(test)
        {
             ui->table_F->setModel(tb.afficher());
             qDebug()<<"Suppression effectue"<<endl;
             QMessageBox::information(this, "Reussite", "Supression effectué !");
             ui->recherche->clear();

        }
       else
        {
             qDebug()<<"Suppression non effectue"<<endl;
             QMessageBox::warning(this, "Echec", "Supression non effectué !");
             ui->recherche->clear();
        }

    }
    else
        QMessageBox::warning(this, "Echec", "Remplissez le champs !");

}


void MainWindow::on__ajoute_mp_clicked()
{    

    mp.setID(ui->lineEdit_idMP->text().toInt());
    mp.setNom(ui->lineEdit_libelle->text());
    mp.setReference(ui->lineEdit_reference->text());
    mp.setDescription(ui->textEdit->toPlainText());
    mp.setQuantite(ui->lineEdit_quantite->text().toInt());
    mp.setPrix(ui->lineEdit_prixHT->text().toInt());





       matiere_P MP(mp.get_identifiant(),mp.get_libelle(),mp.get_reference(),mp.get_description(),mp.get_prix(),mp.get_quantite());

       if(MP.get_identifiant()!=0, MP.get_libelle()!=NULL, MP.get_reference()!=NULL, MP.get_description()!=NULL, MP.get_prix()!=0, mp.get_quantite()!=0)
       {

           bool test = MP.ajouter();

            if(test)
            {
                 ui->afficherMatierePremiere->setModel(mp.afficher());//actualiser
                  QMessageBox::information(this, "Reussite", "Matiere premiere ajouté !");
                 qDebug()<<"Envoi effectue"<<endl;
                 ui->lineEdit_idMP->clear();
                 ui->lineEdit_libelle->clear();
                 ui->lineEdit_reference->clear();
                 ui->textEdit->clear();
                 ui->lineEdit_prixHT->clear();
                 ui->lineEdit_quantite->clear();
            }
           else
            {

                 qDebug()<<"Envoi non effectue"<<endl;
                 QMessageBox::information(this, "Reussite", "Matiere premiere non ajouté !");
                 ui->lineEdit_idMP->clear();
                 ui->lineEdit_libelle->clear();
                 ui->lineEdit_reference->clear();
                 ui->textEdit->clear();
                 ui->lineEdit_prixHT->clear();
                 ui->lineEdit_quantite->clear();
            }

       }
       else
             QMessageBox::warning(this, "Echec", "Remplissez tout les champs !");
}

void MainWindow::on_pushButton_12_clicked()
{

    mp.setID(ui->lineEdit_8->text().toInt());
    mp.setNom(ui->lineEdit_Nom_3->text());
    mp.setReference(ui->lineEdit->text());
    mp.setDescription(ui->plainTextEdit->toPlainText());
    mp.setQuantite(ui->lineEdit_3->text().toInt());
    mp.setPrix(ui->lineEdit_2->text().toInt());


       matiere_P MP(mp.get_identifiant(),mp.get_libelle(),mp.get_reference(),mp.get_description(),mp.get_prix(),mp.get_quantite());

       if(MP.get_identifiant()!=0, MP.get_libelle()!=NULL, MP.get_reference()!=NULL, MP.get_description()!=NULL, MP.get_prix()!=0, mp.get_quantite()!=0)
       {

           bool test = MP.miseAjour(MP.get_identifiant());

                 if(test)
                 {
                      ui->afficherMatierePremiere->setModel(mp.afficher());//actualiser

                      qDebug()<<"Envoi effectue"<<endl;
                      QMessageBox::information(this, "Reussite", "Modification effectue !");
                      ui->lineEdit_8->clear();
                      ui->lineEdit_Nom_3->clear();
                      ui->plainTextEdit->clear();
                      ui->textEdit->clear();
                      ui->lineEdit_2->clear();
                      ui->lineEdit_3->clear();
                 }
                else
                 {
                       qDebug()<<"Envoi non effectue"<<endl;
                        QMessageBox::information(this, "Reussite", "Modification non effectue !");
                        ui->lineEdit_8->clear();
                        ui->lineEdit_Nom_3->clear();
                        ui->plainTextEdit->clear();
                        ui->textEdit->clear();
                        ui->lineEdit_2->clear();
                        ui->lineEdit_3->clear();

                 }
       }
       else
             QMessageBox::critical(this, "Echec", "Remplissez tout les champs !");

}

void MainWindow::on_lineEdit_7_textChanged(const QString &arg1)
{
     mp.setID(ui->lineEdit_7->text().toInt());
    ui->tableView_2->setModel(mp.chercher(mp.get_identifiant()));
}


void MainWindow::on_pushButton_13_clicked()
{
         mp.setID(ui->lineEdit_7->text().toInt());
         if(mp.get_identifiant()!=0)
         {
                 bool test=mp.supprimer(mp.get_identifiant());
                         if(test)
                         {
                               ui->afficherMatierePremiere->setModel(mp.afficher());
                               QMessageBox::information(this, "Reussite", "Suppression effectue !");
                              ui->lineEdit_7->clear();

                         }
                        else
                            {

                             QMessageBox::information(this, "Reussite", "Suppression effectue !");
                             ui->lineEdit_7->clear();
                           }
         }
         else
               QMessageBox::critical(this, "Echec", "Remplissez tout les champs !");


}


