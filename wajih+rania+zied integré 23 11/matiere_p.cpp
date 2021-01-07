#include "matiere_p.h"

matiere_p::matiere_p()
{
    identifiant=0;
        libelle="";
        reference="";
        description="";
        prix=0;
        quantite=0;


    }

 matiere_p::matiere_p(int R1, QString R2, QString R4, int R5, int R6)
{
    identifiant=R1;
    libelle=R2;
    description=R4;
    prix=R5;
    quantite=R6;

}

matiere_p::matiere_p(int R1, QString R2, QString R3,QString R4, int R5, int R6)
    {
        identifiant=R1;
        libelle=R2;
        reference=R3;
        description=R4;
        prix=R5;
        quantite=R6;

    }


    int matiere_p::get_identifiant(){return identifiant;}
    QString matiere_p::get_libelle(){ return libelle; }
    QString matiere_p::get_reference(){return reference;}
    QString matiere_p::get_description(){ return description;}
    int matiere_p::get_quantite(){return quantite;}
    int matiere_p::get_prix(){return prix;}


    void matiere_p::setID(int n){identifiant=n;}
    void matiere_p::setNom(QString n){libelle=n;}
    void matiere_p::setReference(QString n){reference=n;}
    void matiere_p::setDescription(QString n){description=n;}
    void matiere_p::setQuantite(int n){quantite=n;}
    void matiere_p::setPrix(int n){prix=n;}



    bool matiere_p::ajouter()
    {
    QSqlQuery query;
    QString res= QString::number(identifiant);
    query.prepare("INSERT INTO MATIERE_PREMIERE(IDENFIANTMP, LIBELLE, REFERENCE,DESCRIPTION, PRIXHORSTAXE, QUANTITE)"
                  "VALUES (:identifiant, :libelle, :reference, :description, :prix, :quantite)");
    query.bindValue(":identifiant", identifiant);
    query.bindValue(":libelle", libelle);
    query.bindValue(":reference", reference);
    query.bindValue(":description", description);
    query.bindValue(":prix", prix);
    query.bindValue(":quantite", quantite);


    return    query.exec();
    }

    QSqlQueryModel * matiere_p::afficher()
    {
        QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from MATIERE_PREMIERE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDENFIANTMP"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("LIBELLE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("REFERENCE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DESCRIPTION"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("PRIXHORSTAXE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("QUANTITE"));

        return model;
    }


    bool matiere_p::supprimer(int nom)
    {
    QSqlQuery query;
    query.prepare("Delete from MATIERE_PREMIERE where IDENFIANTMP=:identifiant");
    query.bindValue(":identifiant", nom);
    return    query.exec();
    }



    bool matiere_p::miseAjour(int idd)
    {

        QSqlQuery query;
        QString res= QString::number(idd);
        query.prepare("UPDATE MATIERE_PREMIERE  SET LIBELLE=:libelle,DESCRIPTION=:description,PRIXHORSTAXE=:prix,QUANTITE=:quantite WHERE IDENFIANTMP=:identifiant");
        query.bindValue(":identifiant", res);
        query.bindValue(":libelle", libelle);
        query.bindValue(":description", description);
        query.bindValue(":prix", prix);
        query.bindValue(":quantite", quantite);
        return    query.exec();
    }

    QSqlQueryModel * matiere_p::chercher(int name)

    {
        QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select * from MATIERE_PREMIERE where IDENFIANTMP=:identifiant");
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

    QSqlQueryModel * matiere_p::chercherL(QString name)

    {
        QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select * from MATIERE_PREMIERE where LIBELLE=:libelle");
    query.bindValue(":libelle", name);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDENFIANTMP"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("LIBELLE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("REFERENCE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DESCRIPTION"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("PRIXHORSTAXE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("QUANTITE"));

        return model;
    }

    QSqlQueryModel * matiere_p::chercherP(int prixh)

    {
        QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("select * from MATIERE_PREMIERE where PRIXHORSTAXE=:prix");
    query.bindValue(":prix", prixh);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDENFIANTMP"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("LIBELLE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("REFERENCE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DESCRIPTION"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("PRIXHORSTAXE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("QUANTITE"));

        return model;
    }


    QSqlQueryModel * matiere_p::trier_nom()
    {
        // trier nom
        QSqlQueryModel * model=new QSqlQueryModel() ;
        model->setQuery("select * from MATIERE_PREMIERE order by libelle ASC");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDENFIANTMP"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("LIBELLE"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("REFERENCE"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("DESCRIPTION"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("PRIXHORSTAXE"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("QUANTITE"));

            return model;
    }

    QSqlQueryModel * matiere_p::trier_quantite()
    {
        // trier nom
        QSqlQueryModel * model=new QSqlQueryModel() ;
        model->setQuery("select * from MATIERE_PREMIERE order by quantite ASC");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDENFIANTMP"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("LIBELLE"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("REFERENCE"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("DESCRIPTION"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("PRIXHORSTAXE"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("QUANTITE"));

            return model;
    }

    QSqlQueryModel * matiere_p::trier_prix()
    {
        // trier prix
        QSqlQueryModel * model=new QSqlQueryModel() ;
        model->setQuery("select * from MATIERE_PREMIERE order by prix ASC");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("IDENFIANTMP"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("LIBELLE"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("REFERENCE"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("DESCRIPTION"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("PRIXHORSTAXE"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("QUANTITE"));

            return model;
    }


    int matiere_p::verificationMp()
    {
        QSqlQuery query;

        query.prepare("select * from MATIERE_PREMIERE where IDENFIANTMP=:identifiant");
        query.bindValue(":identifiant",this->identifiant);
        query.exec();

        int count_user = 0;
        while (query.next())
        {
            identifiant=(query.value(0).toInt());
            libelle=(query.value(1).toString());
            reference=(query.value(2).toString());
            description=(query.value(3).toString());
            prix=(query.value(4).toInt());
            quantite=(query.value(5).toInt());
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


    int matiere_p::verificationMpN()
    {
        QSqlQuery query;

        query.prepare("select * from MATIERE_PREMIERE where LIBELLE=:libelle");
        query.bindValue(":libelle",this->libelle);
        query.exec();

        int count_user = 0;
        while (query.next())
        {
            identifiant=(query.value(0).toInt());
            libelle=(query.value(1).toString());
            reference=(query.value(2).toString());
            description=(query.value(3).toString());
            prix=(query.value(4).toInt());
            quantite=(query.value(5).toInt());
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

    int matiere_p::verificationMpP()
    {
        QSqlQuery query;

        query.prepare("select * from MATIERE_PREMIERE where PRIXHORSTAXE=:prix");
        query.bindValue(":prix",this->prix);
        query.exec();

        int count_user = 0;
        while (query.next())
        {
            identifiant=(query.value(0).toInt());
            libelle=(query.value(1).toString());
            reference=(query.value(2).toString());
            description=(query.value(3).toString());
            prix=(query.value(4).toInt());
            quantite=(query.value(5).toInt());
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
