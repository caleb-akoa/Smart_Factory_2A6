#include "machine.h"
#include<QDebug>
#include"ui_mainwindow.h"
#include"mainwindow.h"

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
    QString id =QString::number(idMachine);
    QString pr= QString::number(prix);
    //la requete
    query.prepare("insert into machine (identifiant, prix,nom,reference,categorie)" "values(:id,:pr,:nom,:reference,:categorie)");

    //creation des variables
    query.bindValue(":id",id);
    query.bindValue(":pr",pr);
    query.bindValue(":nom",nom);
    query.bindValue(":reference",reference);
    query.bindValue(":categorie",categorie);

    return query.exec();
}

bool machine::supprimerMachine(int idMachine)
{
    QSqlQuery query;
    QString res=QString::number(idMachine);

    query.prepare("Delete from machine where identifiant= :idMachine");
    query.bindValue(":idMachine", res);

    return query.exec();
}

QSqlQueryModel * machine::afficherMachine()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from machine");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("identifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("prix"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("reference"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("categorie"));

    return model;
}

int machine::verifMachine()
{
    QSqlQuery query;
    int count_user = 0;

    query.prepare("select * from machine where identifiant= :idMachine");
    query.bindValue(":identifiant",idMachine);
    query.exec();

    while (query.next())
    {
        count_user++;
    }
    if (count_user==1)
    {
        return 0;
    }
    else if(count_user > 1)
    {
        return 1;
    }
    else
    {
        return 2;
    }
}

bool machine::rechercherModifier(int idu)
{
    QSqlQuery query;
    QString res= QString::number(idu);
    query.prepare("Select * from machine WHERE IDENTIFIANT=:idMachine");
    query.bindValue(":idMachine",res);

    return query.exec();
}

bool machine::modifierMachine()
{
    QSqlQuery query;
    QString idm= QString::number(idMachine);

    query.prepare("Update machine set prix=:prix,nom=:nom,reference=:reference,categorie=:categorie where identifiant=: idMachine");
    query.bindValue(":identifiant",idm);
    query.bindValue(":prix",prix);
    query.bindValue(":nom",nom);
    query.bindValue("reference",reference);
    query.bindValue("categorie",categorie);
    return query.exec();
}

QSqlQueryModel * machine::trierMachineParNom()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from machine order by nom ASC");

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("identifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("prix"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("reference"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("categorie"));

    return model;
}

QSqlQueryModel * machine::trierMachineParID()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from machine order by identifiant ASC");

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("identifiant"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("prix"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("reference"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("categorie"));

    return model;
}

QSqlQueryModel * machine::trierMachineParReference()
{
   QSqlQueryModel * model= new QSqlQueryModel();
   model->setQuery("Select * from machine order by reference ASC");

   model->setHeaderData(0,Qt::Horizontal,QObject::tr("identifiant"));
   model->setHeaderData(1,Qt::Horizontal,QObject::tr("prix"));
   model->setHeaderData(2,Qt::Horizontal,QObject::tr("nom"));
   model->setHeaderData(3,Qt::Horizontal,QObject::tr("reference"));
   model->setHeaderData(4,Qt::Horizontal,QObject::tr("categorie"));

   return model;
}
