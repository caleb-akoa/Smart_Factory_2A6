#ifndef MACHINE_H
#define MACHINE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class machine
{
public:
    QString nom, reference,categorie;
    int idMachine;
    int prix;
public:
    //constructeurs
    machine(){};
    machine(int, int, QString, QString, QString);

    //getters
    QString GetNom(){return nom;}
    QString GetReference(){return reference;}
    QString GetCategorie(){return categorie;}
    int GetIdMachine(){return idMachine;}
    int GetPrix(){return prix;}

    //Setters
    void SetNom(QString n){nom=n;}
    void SetReference(QString ref){reference=ref;}
    void SetCategorie(QString ctg){categorie=ctg;}
    void SetIdMachine(int idM){idMachine=idM;}
    void SetPrix(int px){prix=px;}

    //Fonctions
    bool ajouterMachine();
    bool rechercherModifierMachine();
    bool supprimerMachine();
    int verifMachine();
    int verifMachineParNom();
    int verifMachineParReference();
    bool modifierMachine();

    QSqlQueryModel * trierMachineParNom();
    QSqlQueryModel * trierMachineParID();
    QSqlQueryModel * trierMachineParReference();
    QSqlQueryModel * afficherMachine();

     QSqlQueryModel * chercherParId(int );
     bool chercherParNom();
     bool chercherParReference();
};

#endif // MACHINE_H
