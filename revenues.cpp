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

bool Revenues::ajouter()
{
  QSqlQuery query ;
  //QString res = QString::number(ID_Revenue);

  query.prepare("insert into REVENUE (NOMPRODUIT,ID_REVENUE,QUANTITEVENDUE,VALEURSUNITAIRE,ID_CLIENT,DATEVENTE)""values(:NOMPRODUIT,:ID_REVENUE,:QUANTITEVENDUE,:VALEURSUNITAIRE,:ID_CLIENT,:DATEVENTE)");

  query.bindValue(":NOMPRODUIT", this->NomProduit);
  query.bindValue(":ID_REVENUE", this->ID_Revenue);
  query.bindValue(":QUANTITEVENDUE", this->QuantiteVendue);
  query.bindValue(":VALEURSUNITAIRE", this->NomProduit);
  query.bindValue(":ID_CLIENT", this->ID_Client);
  query.bindValue(":DATEVENTE", this->DateVente);
  return query.exec();
}
