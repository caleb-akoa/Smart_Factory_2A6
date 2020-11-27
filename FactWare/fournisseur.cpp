#include "fournisseur.h"
#include "ui_fournisseur.h"
#include <QDebug>
#include<QMessageBox>
#include "info_fournisseur.h"

fournisseur::fournisseur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fournisseur)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton_1, SIGNAL(clicked() ), this, SLOT(reject() ));
    QObject::connect(ui->pushButton_2, SIGNAL(clicked() ), this, SLOT(reject() ));
    QObject::connect(ui->pushButton_3, SIGNAL(clicked() ), this, SLOT(reject() ));
    QObject::connect(ui->pushButton_4, SIGNAL(clicked() ), this, SLOT(reject() ));


    ui->table_F->setModel(tb.afficher());
}

fournisseur::~fournisseur()
{
    delete ui;
}


void fournisseur::on_ajouter_clicked()
{
    int identifiant = ui->lineEdit_identifiantF->text().toInt();
    QString nom =  ui->lineEdit_nomF->text();
    QString adresse = ui->lineEdit_adresseF->text();
    int telephone =  ui->lineEdit_telephoneF->text().toInt();
    QString email =  ui->lineEdit_emailF->text();

    info_fournisseur f(identifiant,nom,adresse,telephone,email);
    if (identifiant!=NULL && nom!=NULL && adresse!=NULL && telephone!=NULL && email!=NULL )
           {
            bool test = f.ajouter();
            if(test)
            {

                ui->table_F->setModel(tb.afficher());//actualiser
                qDebug()<<"Envoi effectue"<<endl;
                QMessageBox::information(this, "Reussite", "Fournisseur ajouté !");
            }
            else
             {
             qDebug()<<"Envoi non effectue"<<endl;
             QMessageBox::warning(this, "Echec", "Fournisseur non ajouté !");
             }

           }
    else
         QMessageBox::warning(this, "Echec", "Remplissez tout les champs !");

}

void fournisseur::on_pushButton_M_clicked()
{
    int identifiant = ui->lineEdit_identifiantM->text().toInt();
     QString nom= ui->lineEdit_nom1->text();
     QString adresse= ui->lineEdit_2->text();
     int telephone=ui->lineEdit_3->text().toInt();
     QString email= ui->lineEdit_4->text();

     info_fournisseur f(identifiant,nom,adresse,telephone,email);


     if(identifiant!=NULL && nom!=NULL && adresse!=NULL && telephone!=NULL && email!=NULL)
     {
      bool test=f.modifier(identifiant);
      if(test)
       {
             ui->table_F->setModel(tb.afficher());
            qDebug()<<"Modification effectue"<<endl;
            QMessageBox::information(this, "Reussite", "Modification effectué !");

       }
      else
       {
           qDebug()<<"Modification non effectue"<<endl;
            QMessageBox::warning(this, "Echec", "Modification non effectué !");
       }
     }
     else
          QMessageBox::warning(this, "Echec", "Remplissez tout les champs !");
}



void fournisseur::on_recherche_textChanged(const QString &arg1)
{
    ui->tableAffichage->setModel(tb.chercher(arg1));
 //    ui->table_F->setModel(tb.afficher());
}




void fournisseur::on_pushButton_supprimer_2_clicked()
{

    QString nom = ui->recherche->text();

    if(nom!=NULL)
    {
        bool test=tb.supprimer(nom);
        if(test && nom!=NULL)
        {
             ui->table_F->setModel(tb.afficher());
             qDebug()<<"Suppression effectue"<<endl;
             QMessageBox::information(this, "Reussite", "Supression effectué !");


        }
       else
        {
             qDebug()<<"Suppression non effectue"<<endl;
             QMessageBox::warning(this, "Echec", "Supression non effectué !");
        }

    }
    else
        QMessageBox::warning(this, "Echec", "Remplissez le champs !");

}




void fournisseur::on_pushButton_clicked()
{
    ui->table_F->setModel(tb.trier_nom());
}

void fournisseur::on_pushButton_5_clicked()
{
     ui->table_F->setModel(tb.trier_ID());
}
