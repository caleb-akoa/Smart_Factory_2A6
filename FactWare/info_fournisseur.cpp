#include "info_fournisseur.h"


info_fournisseur::info_fournisseur()
{
     identifiant=0;
     nom="";
     adresse="";
     telephone=0;
     email="";

}


info_fournisseur::info_fournisseur(int id, QString n, QString ad, int tel, QString mail)
{
    identifiant = id;
    nom=n;
    adresse=ad;
    telephone=tel;
    email=mail;
}


int info_fournisseur::get_identifiant(){return identifiant;}
QString info_fournisseur::get_nom(){return nom;}
QString info_fournisseur::get_adresse(){return adresse;}
int info_fournisseur::get_telephone(){return telephone;}
QString info_fournisseur::get_email(){return email;}



bool info_fournisseur::ajouter()
{
QSqlQuery query;
QString res= QString::number(identifiant);
query.prepare("INSERT INTO FOURNISSEUR(IDENTIFIANT, NOM, ADRESSE, TELEPHONE, EMAIL)"
              "VALUES (:identifiant, :nom, :adresse, :telephone, :email)");
query.bindValue(":identifiant", identifiant);
query.bindValue(":nom", nom);
query.bindValue(":adresse", adresse);
query.bindValue(":telephone", telephone);
query.bindValue(":email", email);

return    query.exec();
}


QSqlQueryModel * info_fournisseur::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from FOURNISSEUR");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("adresse"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("telephone"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("email"));

    return model;
}

bool info_fournisseur::supprimer(QString name)
{
QSqlQuery query;
query.prepare("Delete from FOURNISSEUR where NOM = :nom");
query.bindValue(":nom", name);
return    query.exec();
}



bool info_fournisseur::modifier(int idd)
{

    QSqlQuery query;
    QString res= QString::number(idd);
    query.prepare("UPDATE FOURNISSEUR SET NOM=:nom,ADRESSE=:adresse,TELEPHONE=:telephone,EMAIL=:email WHERE IDENTIFIANT=:identifiant");
    query.bindValue(":identifiant", res);
    query.bindValue(":nom", nom);
    query.bindValue(":adresse", adresse);
    query.bindValue(":telephone", telephone);
    query.bindValue(":email", email);

    return    query.exec();
}

QSqlQueryModel * info_fournisseur::chercher(QString name)

{
    QSqlQueryModel * model= new QSqlQueryModel();
QSqlQuery query;

query.prepare("select * from FOURNISSEUR where NOM=:nom");
query.bindValue(":nom", name);

query.exec();
model->setQuery(query);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("adresse"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("telephone"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("email"));

    return model;
}

QSqlQueryModel * info_fournisseur::trier_nom()
{
    // trier nom
    QSqlQueryModel * model=new QSqlQueryModel() ;
    model->setQuery("select * from FOURNISSEUR order by nom ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("telephone"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("email"));

        return model;
}



QSqlQueryModel * info_fournisseur::trier_ID()
{
    // trier nom
    QSqlQueryModel * model=new QSqlQueryModel() ;
    model->setQuery("select * from FOURNISSEUR order by identifiant ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("telephone"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("email"));

        return model;
}
