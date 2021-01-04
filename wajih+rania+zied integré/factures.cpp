#include "factures.h"

Factures::Factures(QString NomFournisseur,QString Designation,int Valeur,int ID_Facture)
{
    this->NomFournisseur=NomFournisseur;
    this->Designation=Designation;
    this->Valeur=Valeur;
    this->ID_Facture=ID_Facture;
}

bool Factures::ajouterFactures()
{
  QSqlQuery query ;
  QString res = QString::number(ID_Facture);

  query.prepare("insert into FACTURE (NOMFOURNISSEUR,DESIGNATION,VALEUR,ID_FACTURE)""values(:NOMFOURNISSEUR,:DESIGNATION,:VALEUR,:ID_FACTURE)");

  query.bindValue(":NOMFOURNISSEUR", this->NomFournisseur);
  query.bindValue(":DESIGNATION", this->Designation);
  query.bindValue(":VALEUR", this->Valeur);
  query.bindValue(":ID_FACTURE", res);
  return query.exec();
}

bool Factures::supprimerFactures(int ID_Facture )
{
    QSqlQuery query ;
    QString res = QString::number(ID_Facture);

    query.prepare("Delete from FACTURE where ID_Facture= :ID_FACTURE");
    query.bindValue(":ID_FACTURE",res);

    return query.exec();
}

QSqlQueryModel * Factures::afficherFactures()
{
QSqlQueryModel * model=new QSqlQueryModel();
 model->setQuery("select * from FACTURE");
 model->setHeaderData(0,Qt::Horizontal,QObject::tr("NOMFOURNISSEUR"));
 model->setHeaderData(1,Qt::Horizontal,QObject::tr("DESIGNATION"));
 model->setHeaderData(2,Qt::Horizontal,QObject::tr("VALEUR"));
 model->setHeaderData(3,Qt::Horizontal,QObject::tr("ID_FACTURE"));


return model;
}

bool Factures::modifierFactures(int ID_Facture)
{
    QSqlQuery query ;
    QString res = QString::number(ID_Facture);

    query.prepare("Update FACTURE set NOMFOURNISSEUR=:NOMFOURNISSEUR,DESIGNATION=:DESIGNATION,VALEUR=:VALEUR where ID_FACTURE=:ID_FACTURE");
    query.bindValue(":NOMFOURNISSEUR", this->NomFournisseur);
    query.bindValue(":ID_FACTURE", res);
    query.bindValue(":DESIGNATION", this->Designation);
    query.bindValue(":VALEUR", this->Valeur);





    return query.exec();

}


QSqlQueryModel * Factures::trierFacturesOrdre ()
{


    //trier par nom
    QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("select * from FACTURE order by NOMFOURNISSEUR ASC");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("NOMFOURNISSEUR"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("DESIGNATION"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("VALEUR"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("ID_FACTURE"));


    return model;

}

QSqlQueryModel * Factures::trierFacturesQuantite ()
{


    //trier par Quantite
    QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("select * from FACTURE order by VALEUR ASC");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("NOMFOURNISSEUR"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("DESIGNATION"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("VALEUR"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("ID_FACTURE"));


    return model;

}

QSqlQueryModel * Factures::trierFacturesOrdreD ()
{


    //trier par Quantite
    QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("select * from FACTURE order by DESIGNATION ASC");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("NOMFOURNISSEUR"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("DESIGNATION"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("VALEUR"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("ID_FACTURE"));


    return model;

}

QSqlQueryModel * Factures::chercherFactures(int ID_Facture)

{
   QSqlQueryModel * model= new QSqlQueryModel();
QSqlQuery query;
QString res = QString::number(ID_Facture);

query.prepare("select * from FACTURE where ID_FACTURE=:ID_FACTURE");
query.bindValue(":ID_FACTURE", ID_Facture);


query.exec();
model->setQuery(query);
model->setHeaderData(0,Qt::Horizontal,QObject::tr("NOMFOURNISSEUR"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("DESIGNATION"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("VALEUR"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("ID_FACTURE"));

   return model;
}

QSqlQueryModel * Factures::chercherFacturesN(QString Designation)

{
   QSqlQueryModel * model= new QSqlQueryModel();
QSqlQuery query;
QString res =Designation;

query.prepare("select * from FACTURE where DESIGNATION=:DESIGNATION");
query.bindValue(":DESIGNATION", Designation);


query.exec();
model->setQuery(query);
model->setHeaderData(0,Qt::Horizontal,QObject::tr("NOMFOURNISSEUR"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("DESIGNATION"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("VALEUR"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("ID_FACTURE"));

   return model;
}

QSqlQueryModel * Factures::chercherFacturesC(QString NomFournisseur)

{
   QSqlQueryModel * model= new QSqlQueryModel();
QSqlQuery query;
QString res = NomFournisseur;

query.prepare("select * from FACTURE where NOMFOURNISSEUR=:NOMFOURNISSEUR");
query.bindValue(":NOMFOURNISSEUR", NomFournisseur);


query.exec();
model->setQuery(query);
model->setHeaderData(0,Qt::Horizontal,QObject::tr("NOMFOURNISSEUR"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("DESIGNATION"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("VALEUR"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("ID_FACTURE"));

   return model;
}
