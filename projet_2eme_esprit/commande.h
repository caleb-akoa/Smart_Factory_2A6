#ifndef COMMANDE_H
#define COMMANDE_H
#include <QString>
#include <QSql>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlQueryModel>
class Commande
{
public:
    QString ID;
    QString Id_CLIENT;
    QString ID_PRODUIT;
    QString QUANTITE;
    QString DATELIVRI;
    Commande();
    Commande(const QString &id, const QString &idClient, const QString &idProduit, const QString &quantite,
             const QString &datelivri);
    const QString &getId() const;

    void setId(const QString &id);

    const QString &getIdClient() const;

    void setIdClient(const QString &idClient);

    const QString &getIdProduit() const;

    void setIdProduit(const QString &idProduit);

    const QString &getQuantite() const;

    void setQuantite(const QString &quantite);

    const QString &getDatelivri() const;

    void setDatelivri(const QString &datelivri);

    bool add();
};

#endif // COMMANDE_H
