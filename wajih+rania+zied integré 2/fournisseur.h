#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class fournisseur
{
public:
    fournisseur();
    fournisseur(int, QString, QString, int, QString);


        int get_identifiant();
        QString get_nom();
        QString get_adresse();
        int get_telephone();
        QString get_email();

        void setID(int n);
        void setNom(QString n);
        void setAdresse(QString n);
        void setTelephone(int n);
        void setEmail(QString n);

        bool ajouter();
        bool modifier(int idd);
        QSqlQueryModel * afficher();
        bool supprimer(int);
        QSqlQueryModel * trier_nom();
        QSqlQueryModel * trier_ID();
        QSqlQueryModel * chercher(int);

private:
    int identifiant, telephone;
    QString nom, email, adresse;

};

#endif // FOURNISSEUR_H
