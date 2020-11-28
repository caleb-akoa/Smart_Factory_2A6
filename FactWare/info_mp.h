#ifndef INFO_MP_H
#define INFO_MP_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <iostream>

class info_mp
{
public:
    info_mp();
    info_mp(int,QString,QString,QString, int, int);

    bool ajouter();
    bool verifie(int);
    bool miseAjour(int);
    QSqlQueryModel * afficher();

    bool supprimer(int);
    QSqlQueryModel * trier_nom();
    QSqlQueryModel * trier_quantite();
    QSqlQueryModel * chercher(int);


private:
    int identifiant,prix,quantite;
    QString libelle,reference,description;
};

#endif // INFO_MP_H
