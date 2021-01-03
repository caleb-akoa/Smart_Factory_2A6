#ifndef PRODUIT_H
#define PRODUIT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class produit
{
public:
    produit();
    produit(int,QString,QString,int,int,int);
    int get_id();
    QString get_nom();
    QString get_marque();
    int get_prix();
    int get_nombre();
    int get_ref();

    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int);
    QSqlQueryModel *recherche(int);
private :
    int id,prix,nombre,ref;
    QString nom,marque;

};


#endif // PRODUIT_H
