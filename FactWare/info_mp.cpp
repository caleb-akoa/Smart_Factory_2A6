#include "info_mp.h"

info_mp::info_mp()
{
    identifiant=0;
    libelle="";
    reference="";
    description="";
    prix=0;
    quantite=0;

}

info_mp::info_mp(int R1, QString R2, QString R3,QString R4, int R5, int R6)
{
    identifiant=R1;
    libelle=R2;
    reference=R3;
    description=R4;
    prix=R5;
    quantite=R6;
}

bool info_mp::ajouter()
{
QSqlQuery query;
QString res= QString::number(identifiant);
query.prepare("INSERT INTO MATIERE_PREMIERE(IDENTIFIANT, LIBELLE, REFERENCE,DESCRIPTION, PRIX, QUANTITE)"
              "VALUES (:identifiant, :libelle, :reference, :description, :prix, :quantite)");
query.bindValue(":identifiant", identifiant);
query.bindValue(":libelle", libelle);
query.bindValue(":reference", reference);
query.bindValue(":description", description);
query.bindValue(":prix", prix);
query.bindValue(":quantite", quantite);

return    query.exec();
}

QSqlQueryModel * info_mp::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from MATIERE_PREMIERE");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("libelle"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("reference"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("description"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("quantite"));

    return model;
}


bool info_mp::supprimer(QString nom)
{
QSqlQuery query;
query.prepare("Delete from MATIERE_PREMIERE where LIBELLE=:libelle");
query.bindValue(":libelle", nom);
return    query.exec();
}



bool info_mp::miseAjour(int idd)
{

    QSqlQuery query;
    QString res= QString::number(idd);
    query.prepare("UPDATE MATIERE_PREMIERE  SET LIBELLE=:libelle,REFERENCE=:reference,DESCRIPTION=:description,PRIX=:prix,QUANTITE=:quantite WHERE IDENTIFIANT=:identifiant");
    query.bindValue(":identifiant", res);
    query.bindValue(":libelle", libelle);
    query.bindValue(":reference", reference);
    query.bindValue(":description", description);
    query.bindValue(":prix", prix);
    query.bindValue(":quantite", quantite);
    return    query.exec();
}

QSqlQueryModel * info_mp::chercher(QString name)

{
    QSqlQueryModel * model= new QSqlQueryModel();
QSqlQuery query;
query.prepare("select * from MATIERE_PREMIERE where LIBELLE=:libelle");
query.bindValue(":libelle", name);
query.exec();
model->setQuery(query);
model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("libelle"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("reference"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("description"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("quantite"));

    return model;
}

QSqlQueryModel * info_mp::trier_nom()
{
    // trier nom
    QSqlQueryModel * model=new QSqlQueryModel() ;
    model->setQuery("select * from MATIERE_PREMIERE order by libelle ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("libelle"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("reference"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("description"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("quantite"));


        return model;
}

QSqlQueryModel * info_mp::trier_quantite()
{
    // trier nom
    QSqlQueryModel * model=new QSqlQueryModel() ;
    model->setQuery("select * from MATIERE_PREMIERE order by quantite ASC");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("libelle"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("reference"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("description"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("quantite"));


        return model;
}
