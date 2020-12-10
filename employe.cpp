#include "employe.h"
using namespace std;

employe::employe(QString nom,QString prenom, int idEmploye,QString naissance,QString poste,int salaire,int telephone,QString mail,QString domicile,int cin,QString sexe)
{
    this->nom=nom;
    this->prenom=prenom;
    this->idEmploye=idEmploye;
    this->naissance=naissance;
    this->poste=poste;
    this->salaire=salaire;
    this->telephone=telephone;
    this->mail=mail;
    this->domicile=domicile;
    this->cin=cin;
    this->sexe=sexe;
}

bool employe::ajouterEmploye()
{
    QSqlQuery query;
    QString id=QString::number(idEmploye);
    QString sl=QString::number(salaire);
    QString tel=QString::number(telephone);
    QString cn=QString::number(cin);

    //la requete
    query.prepare("insert into employe (nom,prenom,identifiant,naissance,poste,salaire,telephone,mail,domicile,cin,sexe)" "values(:nom,:prenom,:id,:naissance,:poste,:sl,:tel,:mail,:domicile,:cn,:sexe)");

    //creation des variables
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":id",id);
    query.bindValue(":naissance",naissance);
    query.bindValue(":poste",poste);
    query.bindValue(":sl",sl);
    query.bindValue(":tel",tel);
    query.bindValue(":mail",mail);
    query.bindValue(":domicile",domicile);
    query.bindValue(":cn",cn);
    query.bindValue(":sexe",sexe);

    return query.exec();
}

QSqlQueryModel * employe::afficherEmploye()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from employe");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("identifiant"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("naissance"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("poste"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("salaire"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("telephone"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("mail"));
    model->setHeaderData(8,Qt::Horizontal,QObject::tr("domicile"));
    model->setHeaderData(9,Qt::Horizontal,QObject::tr("cin"));
    model->setHeaderData(10,Qt::Horizontal,QObject::tr("sexe"));

    return model;
}

bool employe::supprimerEmploye()
{
    QSqlQuery query;
    QString id=QString::number(idEmploye);

    query.prepare("Delete from employe where identifiant= :idEmploye");
    query.bindValue(":idEmploye", id);

    return query.exec();
}

int employe::verifEmploye()
{
    QSqlQuery query;

    employe e;

    query.prepare("select * from employe where identifiant= :idEmploye");
    query.bindValue(":idEmploye",this->idEmploye);
    query.exec();

    int count_user = 0;
    while (query.next())
    {nom=(query.value(0).toString());
        prenom=(query.value(1).toString());
        idEmploye=(query.value(2).toInt());
        naissance=(query.value(3).toString());
        poste=(query.value(4).toString());
        salaire=(query.value(5).toInt());
        telephone=(query.value(6).toInt());
        mail=(query.value(7).toString());
        domicile=(query.value(8).toString());
        cin=(query.value(9).toInt());
        sexe=(query.value(10).toString());

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

bool employe::modifierEmploye()
{
    QSqlQuery query;
    QString idm=QString::number(idEmploye);

    query.prepare("Update employe set nom=:nom,prenom=:prenom,naissance=:naissance,poste=:poste,salaire=:salaire,telephone=:telephone,mail=:mail,domicile=:domicile,cin=:cin,sexe=:sexe where identifiant=:idEmploye");
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":idEmploye",idm);
    query.bindValue(":naissance",naissance);
    query.bindValue(":poste",poste);
    query.bindValue(":salaire",salaire);
    query.bindValue(":telephone",telephone);
    query.bindValue(":mail",mail);
    query.bindValue(":domicile",domicile);
    query.bindValue(":cin",cin);
    query.bindValue(":sexe",sexe);

    return query.exec();
}

bool employe::rechercherEmploye()//recherche modification
{
    QSqlQuery query;
    query.prepare("Select * from employe where identifiant=:idEmploye");
    query.bindValue(":idEmploye",idEmploye);
    query.exec();

    if (query.next())
    {
        nom=(query.value(0).toString());
        prenom=(query.value(1).toString());
        idEmploye=(query.value(2).toInt());
        naissance=(query.value(3).toString());
        poste=(query.value(4).toString());
        salaire=(query.value(5).toInt());
        telephone=(query.value(6).toInt());
        mail=(query.value(7).toString());
        domicile=(query.value(8).toString());
        cin=(query.value(9).toInt());
        sexe=(query.value(10).toString());
    }
    return query.exec();
}

QSqlQueryModel * employe::trierEmployeParNom()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from employe order by nom ASC ");

        model->setHeaderData(0,Qt::Horizontal,QObject::tr("nom"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("prenom"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("identifiant"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("naissance"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("poste"));
        model->setHeaderData(5,Qt::Horizontal,QObject::tr("salaire"));
        model->setHeaderData(6,Qt::Horizontal,QObject::tr("telephone"));
        model->setHeaderData(7,Qt::Horizontal,QObject::tr("mail"));
        model->setHeaderData(8,Qt::Horizontal,QObject::tr("domicile"));
        model->setHeaderData(9,Qt::Horizontal,QObject::tr("cin"));
        model->setHeaderData(10,Qt::Horizontal,QObject::tr("sexe"));

    return model;
}

QSqlQueryModel * employe::trierEmployeParID()
{

    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from employe order by identifiant ASC ");

        model->setHeaderData(0,Qt::Horizontal,QObject::tr("nom"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("prenom"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("identifiant"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("naissance"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("poste"));
        model->setHeaderData(5,Qt::Horizontal,QObject::tr("salaire"));
        model->setHeaderData(6,Qt::Horizontal,QObject::tr("telephone"));
        model->setHeaderData(7,Qt::Horizontal,QObject::tr("mail"));
        model->setHeaderData(8,Qt::Horizontal,QObject::tr("domicile"));
        model->setHeaderData(9,Qt::Horizontal,QObject::tr("cin"));
        model->setHeaderData(10,Qt::Horizontal,QObject::tr("sexe"));

    return model;
}

QSqlQueryModel * employe::trierEmployeParCin()
{

    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("Select * from employe order by cin ASC ");

        model->setHeaderData(0,Qt::Horizontal,QObject::tr("nom"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("prenom"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("identifiant"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("naissance"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("poste"));
        model->setHeaderData(5,Qt::Horizontal,QObject::tr("salaire"));
        model->setHeaderData(6,Qt::Horizontal,QObject::tr("telephone"));
        model->setHeaderData(7,Qt::Horizontal,QObject::tr("mail"));
        model->setHeaderData(8,Qt::Horizontal,QObject::tr("domicile"));
        model->setHeaderData(9,Qt::Horizontal,QObject::tr("cin"));
        model->setHeaderData(10,Qt::Horizontal,QObject::tr("sexe"));

    return model;
}

bool employe::rechercherSupprimer()
{
    QSqlQuery query;
    //QString id=QString::number(idEmploye);
    query.prepare("Select * from employe where identifiant=:idEmploye");
    query.bindValue(":idEmploye",idEmploye);
    query.exec();
    return query.exec();
}

bool employe::chercherParNom()
{

    QSqlQuery query;
    query.prepare("Select * from employe where nom=:nom");
    query.bindValue(":nom",nom);
    query.exec();

    if (query.next())
    {
        nom=(query.value(0).toString());
        prenom=(query.value(1).toString());
        idEmploye=(query.value(2).toInt());
        naissance=(query.value(3).toString());
        poste=(query.value(4).toString());
        salaire=(query.value(5).toInt());
        telephone=(query.value(6).toInt());
        mail=(query.value(7).toString());
        domicile=(query.value(8).toString());
        cin=(query.value(9).toInt());
        sexe=(query.value(10).toString());
    }
    return query.exec();
}

int employe::verifEmployeParNom()
{
    QSqlQuery query;

    employe e;

    query.prepare("select * from employe where nom= :nom");
    query.bindValue(":nom",this->nom);
    query.exec();

    int count_user = 0;
    while (query.next())
    {nom=(query.value(0).toString());
        prenom=(query.value(1).toString());
        idEmploye=(query.value(2).toInt());
        naissance=(query.value(3).toString());
        poste=(query.value(4).toString());
        salaire=(query.value(5).toInt());
        telephone=(query.value(6).toInt());
        mail=(query.value(7).toString());
        domicile=(query.value(8).toString());
        cin=(query.value(9).toInt());
        sexe=(query.value(10).toString());

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

bool employe::chercherParCin()
{
    QSqlQuery query;
    query.prepare("Select * from employe where cin=:cin");
    query.bindValue(":cin",cin);
    query.exec();

    if (query.next())
    {
        nom=(query.value(0).toString());
        prenom=(query.value(1).toString());
        idEmploye=(query.value(2).toInt());
        naissance=(query.value(3).toString());
        poste=(query.value(4).toString());
        salaire=(query.value(5).toInt());
        telephone=(query.value(6).toInt());
        mail=(query.value(7).toString());
        domicile=(query.value(8).toString());
        cin=(query.value(9).toInt());
        sexe=(query.value(10).toString());
    }
    return query.exec();
}

int employe::verifEmployeParCin()
{
    QSqlQuery query;

    employe e;

    query.prepare("select * from employe where cin= :cin");
    query.bindValue(":cin",this->cin);
    query.exec();

    int count_user = 0;
    while (query.next())
    {nom=(query.value(0).toString());
        prenom=(query.value(1).toString());
        idEmploye=(query.value(2).toInt());
        naissance=(query.value(3).toString());
        poste=(query.value(4).toString());
        salaire=(query.value(5).toInt());
        telephone=(query.value(6).toInt());
        mail=(query.value(7).toString());
        domicile=(query.value(8).toString());
        cin=(query.value(9).toInt());
        sexe=(query.value(10).toString());

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
