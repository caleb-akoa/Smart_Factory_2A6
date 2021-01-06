#ifndef MATIERE_P_H
#define MATIERE_P_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class matiere_p
{
public:
    matiere_p();
    matiere_p(int,QString,QString,QString, int, int);
    matiere_p(int,QString,QString, int, int);

      int get_identifiant();
      QString get_libelle();
      QString get_reference();
      QString get_description();
      int get_quantite();
       int get_prix();


      void setID(int n);
      void setNom(QString n);
      void setReference(QString n);
      void setDescription(QString n);
      void setQuantite(int n);
      void setPrix(int n);



         bool ajouter();
         bool verifie(int);
         bool miseAjour(int);
         QSqlQueryModel * afficher();

         bool supprimer(int);
         QSqlQueryModel * trier_nom();
         QSqlQueryModel * trier_prix();
         QSqlQueryModel * trier_quantite();
         QSqlQueryModel * chercher(int);
         QSqlQueryModel * chercherL(QString);
         QSqlQueryModel * chercherP(int);
         int verificationMp();
         int verificationMpN();
         int verificationMpP();




     private:
         int identifiant,prix,quantite;
         QString libelle,reference,description;
};

#endif // MATIERE_P_H
