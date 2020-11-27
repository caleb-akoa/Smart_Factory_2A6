#include "matierep.h"
#include "ui_matierep.h"
#include "dialog.h"
#include "matierep.h"

matiereP::matiereP(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::matiereP)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(reject()));
     QObject::connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(reject()));
      QObject::connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(reject()));
       QObject::connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(reject()));
        QObject::connect(ui->pushButton_10, SIGNAL(clicked()), this, SLOT(reject()));

         ui->afficherMatierePremiere->setModel(mp.afficher());
}

matiereP::~matiereP()
{
    delete ui;
}

void matiereP::on_pushButton_2_clicked()
{
    int identifiant = ui->lineEdit_idMP->text().toInt();
    QString libelle =  ui->lineEdit_libelle->text();
    QString reference = ui->lineEdit_reference->text();
    QString description = ui->textEdit->toPlainText();
    int prix =  ui->lineEdit_prixHT->text().toInt();
    int quantite =  ui->lineEdit_quantite->text().toInt();

    info_mp mp(identifiant,libelle,reference,description,prix,quantite);
    bool test = mp.ajouter();
    ui->afficherMatierePremiere->setModel(mp.afficher());//actualiser
     if(test)
     {

          qDebug()<<"Envoi effectue"<<endl;
     }
    else
          qDebug()<<"Envoi non effectue"<<endl;
}

void matiereP::on_pushButton_clicked()
{
    int identifiant = ui->lineEdit_8->text().toInt();
    QString libelle =  ui->lineEdit_Nom_3->text();
    QString reference = ui->lineEdit->text();
    QString description = ui->plainTextEdit->toPlainText();
    int prix =  ui->lineEdit_2->text().toInt();
    int quantite =  ui->lineEdit_3->text().toInt();

    info_mp mp(identifiant,libelle,reference,description,prix,quantite);
    bool test = mp.miseAjour(identifiant);
    ui->afficherMatierePremiere->setModel(mp.afficher());//actualiser
     if(test)
     {

          qDebug()<<"Envoi effectue"<<endl;
     }
    else
          qDebug()<<"Envoi non effectue"<<endl;

}

void matiereP::on_lineEdit_7_textChanged(const QString &arg1)
{
    ui->tableView_2->setModel(mp.chercher(arg1));
 //  ui->afficherMatierePremiere->setModel(mp.afficher());
}

void matiereP::on_pushButton_3_clicked()
{
    QString nom= ui->lineEdit_7->text();
    bool test=mp.supprimer(nom);
    if(test)
    {
          ui->afficherMatierePremiere->setModel(mp.afficher());
         qDebug()<<"Suppression effectue"<<endl;

    }
   else
         qDebug()<<"Suppression non effectue"<<endl;
}

void matiereP::on_pushButton_4_clicked()
{
       ui->afficherMatierePremiere->setModel(mp.trier_nom());
}

void matiereP::on_pushButton_8_clicked()
{
     ui->afficherMatierePremiere->setModel(mp.trier_quantite());
}
