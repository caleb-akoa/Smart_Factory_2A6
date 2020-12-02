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
    float prix;
public:
    //constructeurs
    machine(){};
    machine(int, float, QString, QString, QString);

    //getters
    QString GetNom(){return nom;}
    QString GetReference(){return reference;}
    QString GetCategorie(){return categorie;}
    int GetIdMachine(){return idMachine;}
    float GetPrix(){return prix;}

    //Setters
    void SetNom(QString n){nom=n;}
    void SetReference(QString ref){reference=ref;}
    void SetCategorie(QString ctg){categorie=ctg;}
    void SetIdMachine(int idM){idMachine=idM;}
    void SetPrix(float px){prix=px;}

    //Fonctions
    bool ajouterMachine();//
    QSqlQueryModel * afficherMachine();
    bool supprimerMachine(int);
    int verifMachine();//
    bool modifierMachine();//
    QSqlQueryModel * trierMachineParNom();
    QSqlQueryModel * trierMachineParID();
    QSqlQueryModel * trierMachineParReference();
     bool rechercherModifier(int);
};

#endif // MACHINE_H
