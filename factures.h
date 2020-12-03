#ifndef FACTURES_H
#define FACTURES_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>

class Factures
{
    QString NomFournisseur ;
    QString Designation  ;
    int Valeur;
    int ID_Facture  ;
public:
    Factures(){}
    Factures(QString,QString,int,int);

    QString getNomFournisseur(){return NomFournisseur;}
    QString getDesignation(){return Designation;}
    int getValeur(){return Valeur;}
    int getID_Facture(){return ID_Facture;}

    void setNomFournisseur (QString NomFournisseur ); //{NomFournisseur=NomFournisseur;}
    void setDesignation (QString Designation ); //{Designation=Designation;}
    void setValeur (int Valeur ) {this->Valeur=Valeur;}
    void setID_Facture (int ID_Facture ) {this->ID_Facture=ID_Facture;}

    bool ajouterFactures();
    bool supprimerFactures(int);
    QSqlQueryModel  * afficherFactures() ;
     bool modifierFactures(int);
    QSqlQueryModel * trierFacturesOrdre ();
    QSqlQueryModel * trierFacturesQuantite ();
    QSqlQueryModel * trierFacturesOrdreD ();

};

#endif // FACTURES_H
