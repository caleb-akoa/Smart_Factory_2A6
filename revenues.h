#ifndef REVENUES_H
#define REVENUES_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Revenues
{
    QString NomProduit ;
    int QuantiteVendue ;
    int ValeursUnitaire;
    int ID_Client  ;
    QString DateVente ;
    int ID_Revenue;
public:
    Revenues(){}
    Revenues(QString,int,int,int,QString,int);

    QString getNomProduit(){return NomProduit;}
    int getQuantiteVendue(){return QuantiteVendue;}
    int getValeursUnitaire(){return ValeursUnitaire;}
    int getID_Client(){return ID_Client;}
    QString getDateVente(){return DateVente ;}
    int getID_Revenue(){return ID_Revenue;}

    void setNomProduit (QString NomProduits ) {NomProduit=NomProduits;}
    void setQuantiteVendue (int QuantiteVendues ) {this->QuantiteVendue=QuantiteVendues;}
    void setValeursUnitaire (int ValeursUnitaires ) {this->ValeursUnitaire=ValeursUnitaires;}
    void setID_Client (int ID_Clients ) {this->ID_Client=ID_Clients;}
    void setDateVente(QString DateVentes ) {DateVente=DateVentes;}
    void setID_Revenue (int ID_Revenues ) {this->ID_Revenue=ID_Revenues;}

    bool ajouterRevenues();
    bool supprimerRevenues(int);
    QSqlQueryModel  * afficherRevenues() ;
    bool modifierRevenues(int);
    QSqlQueryModel  * chercherRevenues(int) ;
    QSqlQueryModel  * chercherRevenuesN(QString) ;
    QSqlQueryModel  * chercherRevenuesC(int) ;

};

#endif // REVENUES_H
