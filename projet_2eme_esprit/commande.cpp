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


QString ID;
QString Id_CLIENT;
QString ID_PRODUIT;
QString QUANTITE;
QString DATELIVRI;












