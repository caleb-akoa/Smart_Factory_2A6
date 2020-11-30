#ifndef INFO_FOURNISSEUR_H
#define INFO_FOURNISSEUR_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <iostream>
using namespace std;
class info_fournisseur
{
public:
    info_fournisseur();
    info_fournisseur(int, QString, QString, int, QString);

    int get_identifiant();
    QString get_nom();
    QString get_adresse();
    int get_telephone();
    QString get_email();

    bool ajouter();
    bool modifier(int idd);
    QSqlQueryModel * afficher();
    bool verifie(int);

    bool supprimer(int);
    QSqlQueryModel * trier_nom();
    QSqlQueryModel * trier_ID();
    QSqlQueryModel * chercher(int);


private:
    int identifiant, telephone;
    QString nom, email, adresse;

};

#endif // INFO_FOURNISSEUR_H
