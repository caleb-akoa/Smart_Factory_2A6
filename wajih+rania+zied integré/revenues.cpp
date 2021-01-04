#include "revenues.h"

Revenues::Revenues(QString NomProduit,int QuantiteVendue,int ValeursUnitaire,int ID_Client,QString DateVente,int ID_Revenue)
{
    this->NomProduit=NomProduit;
     this->ID_Revenue=ID_Revenue;
    this->QuantiteVendue=QuantiteVendue;
    this->ValeursUnitaire=ValeursUnitaire;
    this->ID_Client=ID_Client;
   this->DateVente=DateVente;

}

bool Revenues::ajouterRevenues()
{
  QSqlQuery query ;
  QString res = QString::number(ID_Revenue);

  query.prepare("insert into REVENUE (NOMPRODUIT,ID_REVENUE,QUANTITEVENDUE,VALEURSUNITAIRE,ID_CLIENT,DATEVENTE)""values(:NOMPRODUIT,:ID_REVENUE,:QUANTITEVENDUE,:VALEURSUNITAIRE,:ID_CLIENT,:DATEVENTE)");

  query.bindValue(":NOMPRODUIT", this->NomProduit);
  query.bindValue(":ID_REVENUE", res);
  query.bindValue(":QUANTITEVENDUE", this->QuantiteVendue);
  query.bindValue(":VALEURSUNITAIRE", this->ValeursUnitaire);
  query.bindValue(":ID_CLIENT", this->ID_Client);
  query.bindValue(":DATEVENTE", this->DateVente);
  return query.exec();
}


bool Revenues::supprimerRevenues(int ID_Revenue )
{
    QSqlQuery query ;
    QString res = QString::number(ID_Revenue);

    query.prepare("Delete from REVENUE where ID_REVENUE= :ID_REVENUE");
    query.bindValue(":ID_REVENUE",res);

    return query.exec();
}

QSqlQueryModel * Revenues::afficherRevenues()
{
QSqlQueryModel * model=new QSqlQueryModel();
 model->setQuery("select * from REVENUE");
 model->setHeaderData(0,Qt::Horizontal,QObject::tr("NOMPRODUIT"));
 model->setHeaderData(1,Qt::Horizontal,QObject::tr("ID_REVENUE"));
 model->setHeaderData(2,Qt::Horizontal,QObject::tr("QUANTITEVENDUE"));
 model->setHeaderData(3,Qt::Horizontal,QObject::tr("VALEURSUNITAIRE"));
 model->setHeaderData(4,Qt::Horizontal,QObject::tr("ID_CLIENT"));
 model->setHeaderData(5,Qt::Horizontal,QObject::tr("DATEVENTE"));

return model;
}



bool Revenues::modifierRevenues(int ID_Revenue)
{
    QSqlQuery query ;
    QString res = QString::number(ID_Revenue);

    query.prepare("Update REVENUE set NOMPRODUIT=:NOMPRODUIT,QUANTITEVENDUE=:QUANTITEVENDUE,VALEURSUNITAIRE=:VALEURSUNITAIRE,DATEVENTE=:DATEVENTE where ID_REVENUE=:ID_REVENUE");
    query.bindValue(":NOMPRODUIT", this->NomProduit);
    query.bindValue(":ID_REVENUE", res);
    query.bindValue(":QUANTITEVENDUE", this->QuantiteVendue);
    query.bindValue(":VALEURSUNITAIRE", this->ValeursUnitaire);
    query.bindValue(":ID_CLIENT", this->ID_Client);
    query.bindValue(":DATEVENTE", this->DateVente);
    return query.exec();



    return query.exec();

}

QSqlQueryModel * Revenues::chercherRevenues(int ID_Revenue)

{
   QSqlQueryModel * model= new QSqlQueryModel();
QSqlQuery query;
QString res = QString::number(ID_Revenue);

query.prepare("select * from REVENUE where ID_REVENUE=:ID_REVENUE");
query.bindValue(":ID_REVENUE", ID_Revenue);


query.exec();
model->setQuery(query);
model->setHeaderData(0,Qt::Horizontal,QObject::tr("NOMPRODUIT"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("ID_REVENUE"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("QUANTITEVENDUE"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("VALEURSUNITAIRE"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("ID_CLIENT"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("DATEVENTE"));

   return model;
}

QSqlQueryModel * Revenues::chercherRevenuesN(QString NomProduit)

{
   QSqlQueryModel * model= new QSqlQueryModel();
QSqlQuery query;
QString res =NomProduit;

query.prepare("select * from REVENUE where NOMPRODUIT=:NOMPRODUIT");
query.bindValue(":NOMPRODUIT", NomProduit);


query.exec();
model->setQuery(query);
model->setHeaderData(0,Qt::Horizontal,QObject::tr("NOMPRODUIT"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("ID_REVENUE"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("QUANTITEVENDUE"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("VALEURSUNITAIRE"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("ID_CLIENT"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("DATEVENTE"));

   return model;
}

QSqlQueryModel * Revenues::chercherRevenuesC(int ID_Client)

{
   QSqlQueryModel * model= new QSqlQueryModel();
QSqlQuery query;
QString res = QString::number(ID_Client);

query.prepare("select * from REVENUE where ID_CLIENT=:ID_CLIENT");
query.bindValue(":ID_CLIENT", ID_Client);


query.exec();
model->setQuery(query);
model->setHeaderData(0,Qt::Horizontal,QObject::tr("NOMPRODUIT"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("ID_REVENUE"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("QUANTITEVENDUE"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("VALEURSUNITAIRE"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("ID_CLIENT"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("DATEVENTE"));

   return model;
}


