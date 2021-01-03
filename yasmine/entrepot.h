#ifndef ENTREPOT_H
#define ENTREPOT_H
#include "QString"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>

class entrepot
{
public:

    entrepot();
     entrepot(int,int,int,QString);
     QString get_lieu();
     int get_nbP();
     int get_num();
     int get_id();

     bool ajouter();
     bool supprimer(int);
     QSqlQueryModel * rechercher(int);
     bool modifier(int);
     QSqlQueryModel *affichertri();



private :
     int id,num,nbP;
     QString lieu;

};

#endif // ENTREPOT_H
