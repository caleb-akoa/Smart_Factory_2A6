#ifndef PRODUIT_H
#define PRODUIT_H

#include "QString"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
class Produit
{
 QString nom;
 float prix;
 int nb;
 int id;

 public:

 Produit();
 Produit(QString,float,int,int);
 bool ajouter();
 bool supprimer();
 QSqlQueryModel *afficher();
 int calculer();
 QString get_Nom();
 float get_prix();
 int get_Nb();
 int get_id();
 void setNom(QString nom);
 void setPrix(float prix);
 void setNb(int nb);
 void set(int id);
};


#endif // PRODUIT_H
