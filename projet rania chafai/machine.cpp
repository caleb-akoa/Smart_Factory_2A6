#include "machine.h"

machine::machine(int idMachine, float prix, QString nom,QString reference, QString categorie)
{
    this->idMachine=idMachine;
    this->prix=prix;
    this->nom=nom;
    this->reference=reference;
    this->categorie=categorie;
}

bool machine::ajouterMachine()
{
    QSqlQuery query;
    QString res =QString::number(idMachine);
    QString pr= QString::number(prix);
    //la requete
    query.prepare("insert into machine (identifiant, prix,nom,reference,categorie)" "values(:idMachine,:prix,:nom,:reference,:categorie)");

    //creation des variables
    query.bindValue(":idMachine",res);
    query.bindValue(":prix",pr);
    query.bindValue(":nom",nom);
    query.bindValue(":reference",reference);
    query.bindValue(":categorie",categorie);

    return query.exec();
}
