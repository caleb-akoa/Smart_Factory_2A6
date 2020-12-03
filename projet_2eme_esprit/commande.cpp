#include "commande.h"

Commande::Commande()
{

}
Commande::Commande(const QString &id, const QString &idClient, const QString &idProduit, const QString &quantite,
                   const QString &datelivri) : ID(id), Id_CLIENT(idClient), ID_PRODUIT(idProduit), QUANTITE(quantite),
                                              DATELIVRI(datelivri) {}
const QString &Commande::getId() const {
    return ID;
}

void Commande::setId(const QString &id) {
    ID = id;
}

const QString &Commande::getIdClient() const {
    return Id_CLIENT;
}

void Commande::setIdClient(const QString &idClient) {
    Id_CLIENT = idClient;
}

const QString &Commande::getIdProduit() const {
    return ID_PRODUIT;
}

void Commande::setIdProduit(const QString &idProduit) {
    ID_PRODUIT = idProduit;
}

const QString &Commande::getQuantite() const {
    return QUANTITE;
}

void Commande::setQuantite(const QString &quantite) {
    QUANTITE = quantite;
}

const QString &Commande::getDatelivri() const {
    return DATELIVRI;
}

void Commande::setDatelivri(const QString &datelivri) {
    DATELIVRI = datelivri;
}
bool Commande::add()
{

    QSqlQuery query;

    query.prepare("INSERT INTO commande (ID,Id_CLIENT, ID_PRODUIT, QUANTITE, DATELIVRI) "
                  "VALUES (?, ?, ?, ?, ?)");
    query.bindValue(0, this->ID);
    query.bindValue(1, this->Id_CLIENT);
    query.bindValue(2, this->ID_PRODUIT);
    query.bindValue(3, this->QUANTITE);
    query.bindValue(4, this->DATELIVRI);


    if (query.exec())
    {
        return true;

    }
    else
    {
        return false;
    }

}

int Commande::check() // check if it exsits or not
{

    QSqlQuery query;

    query.prepare("select * from commande where ID = :id ");
    query.bindValue(":id",ID);


    query.exec();

    int count_user = 0;
    while (query.next()) {
        count_user++;
    }

    if (count_user == 1) {
        return 0;
    }
    else if (count_user > 1 ) {
        return 1;
    }
    else{
        return 2;
    }}

bool Commande::cherchermodifier()
{

    QSqlQuery query;
    query.prepare("Select * from commande where ID=:id");
    query.bindValue(":id", ID);

    query.exec();

    if(query.next())
    {
        ID=query.value(0).toString();
        Id_CLIENT=query.value(1).toString();
        ID_PRODUIT=query.value(2).toString();
        QUANTITE=query.value(3).toString();
        DATELIVRI=query.value(4).toString();

    }
    return query.exec();

}
bool Commande::validermodification()
{


    QSqlQuery query;

    query.prepare("update COMMANDE set Id_CLIENT=:idclient,ID_PRODUIT=:idproduit,QUANTITE=:quantite,DATELIVRI=:datelivri where ID=:toupdate");

    query.bindValue(":toupdate",ID);
    query.bindValue(":idclient",Id_CLIENT);
    query.bindValue(":idproduit",ID_PRODUIT);
    query.bindValue(":quantite",QUANTITE);
    query.bindValue(":datelivri",DATELIVRI);

    return query.exec();

}

bool Commande::deletecmd()
{

    QSqlQuery query;
    query.prepare("delete from commande where ID=:todelete");
    query.bindValue(":todelete",ID);
    return query.exec();

}
QSqlQueryModel *Commande::list()
{
QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery("select * from commande");
return model;
}




