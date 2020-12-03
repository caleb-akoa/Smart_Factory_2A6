#include "matiere_p.h"

matiere_P::matiere_P()
{
    identifiant=0;
        libelle="";
        reference="";
        description="";
        prix=0;
        quantite=0;

    }

    matiere_P::matiere_P(int R1, QString R2, QString R3,QString R4, int R5, int R6)
    {
        identifiant=R1;
        libelle=R2;
        reference=R3;
        description=R4;
        prix=R5;
        quantite=R6;
    }


    int matiere_P::get_identifiant(){return identifiant;}
    QString matiere_P::get_libelle(){ return libelle; }
    QString matiere_P::get_reference(){return reference;}
    QString matiere_P::get_description(){ return description;}
    int matiere_P::get_quantite(){return quantite;}
    int matiere_P::get_prix(){return prix;}

    void matiere_P::setID(int n){identifiant=n;}
    void matiere_P::setNom(QString n){libelle=n;}
    void matiere_P::setReference(QString n){reference=n;}
    void matiere_P::setDescription(QString n){description=n;}
    void matiere_P::setQuantite(int n){quantite=n;}
    void matiere_P::setPrix(int n){prix=n;}



    bool matiere_P::ajouter()
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

    QSqlQueryModel * matiere_P::afficher()
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


    bool matiere_P::supprimer(int nom)
    {
    QSqlQuery query;
    query.prepare("Delete from MATIERE_PREMIERE where IDENTIFIANT=:identifiant");
    query.bindValue(":identifiant", nom);
    return    query.exec();
    }



    bool matiere_P::miseAjour(int idd)
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

    QSqlQueryModel * matiere_P::chercher(int name)

    {
        QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select * from MATIERE_PREMIERE where IDENTIFIANT=:identifiant");
    query.bindValue(":identifiant", name);
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

    QSqlQueryModel * matiere_P::trier_nom()
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

    QSqlQueryModel * matiere_P::trier_quantite()
    {
        // trier nom
        QSqlQueryModel * model=new QSqlQueryModel() ;
        model->setQuery("select * from MATIERE_PREMIERE order by quantite DESC");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("libelle"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("reference"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("description"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("quantite"));


            return model;
    }
