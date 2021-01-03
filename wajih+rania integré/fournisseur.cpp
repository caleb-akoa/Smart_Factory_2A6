#include "fournisseur.h"

fournisseur::fournisseur()
{
    identifiant=0;
    nom="";
    adresse="";
    telephone=0;
    email="";

}


fournisseur::fournisseur(int id, QString n, QString ad, int tel, QString mail)
{
   identifiant = id;
   nom=n;
   adresse=ad;
   telephone=tel;
   email=mail;
}


int fournisseur::get_identifiant(){return identifiant;}
QString fournisseur::get_nom(){return nom;}
QString fournisseur::get_adresse(){return adresse;}
int fournisseur::get_telephone(){return telephone;}
QString fournisseur::get_email(){return email;}


void fournisseur::setID(int n){ identifiant=n;}
void fournisseur::setNom(QString n){nom=n;}
void fournisseur::setAdresse(QString n){adresse=n;}
void fournisseur::setTelephone(int n){ telephone=n;}
void fournisseur::setEmail(QString n){email=n;}

bool fournisseur::ajouter()
{
QSqlQuery query;
QString res= QString::number(identifiant);
query.prepare("INSERT INTO FOURNISSEUR(IDENTIFIANT, NOM, ADRESSE, TELEPHONE, EMAIL)"
             "VALUES (:identifiant, :nom, :adresse, :telephone, :email)");
query.bindValue(":identifiant", identifiant);
query.bindValue(":nom", nom);
query.bindValue(":adresse", adresse);
query.bindValue(":telephone", telephone);
query.bindValue(":email", email);

return    query.exec();
}


QSqlQueryModel * fournisseur::afficher()
{
   QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from FOURNISSEUR");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("adresse"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("telephone"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("email"));

   return model;
}

bool fournisseur::supprimer(int id)
{
QSqlQuery query;
query.prepare("Delete from FOURNISSEUR where IDENTIFIANT = :identifiant");
query.bindValue(":identifiant", id);
return    query.exec();
}

bool fournisseur::modifier(int idd)
{
       QSqlQuery query;

      if(":identifiant", idd)
      {

          QString res= QString::number(idd);
          query.prepare("UPDATE FOURNISSEUR SET NOM=:nom,ADRESSE=:adresse,TELEPHONE=:telephone,EMAIL=:email WHERE IDENTIFIANT=:identifiant");
          query.bindValue(":identifiant", res);
          query.bindValue(":nom", nom);
          query.bindValue(":adresse", adresse);
          query.bindValue(":telephone", telephone);
          query.bindValue(":email", email);

             return    query.exec();
      }

}

QSqlQueryModel * fournisseur::chercher(int id)

{
   QSqlQueryModel * model= new QSqlQueryModel();
QSqlQuery query;

query.prepare("select * from FOURNISSEUR where IDENTIFIANT=:identifiant");
query.bindValue(":identifiant", id);

query.exec();
model->setQuery(query);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("adresse"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("telephone"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("email"));
