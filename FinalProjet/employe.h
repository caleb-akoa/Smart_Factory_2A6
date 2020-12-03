#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>
#include <QSqlQueryModel>
#include <QFileDialog>
#include <QDebug>
#include <QBuffer>
#include <QSqlQuery>
#include <QRegExp>
#include <cstdlib>
#include <iostream>
#include <map>
#include <QStringListModel>
#include <QList>
#include <QListView>
using namespace std;

class employe
{
    QString nom, prenom,naissance,poste,mail,domicile,sexe;
    int idEmploye,telephone,cin,salaire;

public:
    //constructeurs
    employe(){};
    employe(QString, QString,int,QString,QString,int,int,QString,QString,int,QString);

    //getters
    QString GetNom(){return nom;}
    QString GetPrenom(){return prenom;}
    int GetIdentifiant(){return idEmploye;}
    QString GetNaissance(){return naissance;}
    QString GetPoste(){return poste;}
    int GetSalaire(){return salaire;}
    int GetTelephone(){return telephone;}
    QString GetMail(){return mail;}
    QString GetDomicile(){return domicile;}
    int GetCin(){return cin;}
    QString GetSexe(){return sexe;}

    //setters
    void SetNom(QString n){nom=n;}
    void SetPrenom(QString pr){prenom=pr;}
    void SetIdentifiant(int idE){idEmploye=idE;}
    void SetNaissance(QString ns){naissance=ns;}
    void SetPoste(QString pos){poste=pos;}
    void SetSalaire(int sal){salaire=sal;}
    void SetTelephone(int tel){telephone=tel;}
    void SetMail(QString m){mail=m;}
    void SetDomicile(QString dm){domicile=dm;}
    void SetCin(int c){cin=c;}
    void SetSexe(QString s){sexe=s;}

    //fonctions
    bool ajouterEmploye();
    bool rechercherSupprimer();
    bool supprimerEmploye();
    bool rechercherEmploye();
    bool modifierEmploye();
    int verifEmploye();
    int verifEmployeParNom();
    int verifEmployeParCin();

    QSqlQueryModel * afficherEmploye();
    QSqlQueryModel * trierEmployeParNom();
    QSqlQueryModel * trierEmployeParID();
    QSqlQueryModel * trierEmployeParCin();

    QSqlQueryModel * chercherParId(int );
    bool chercherParNom();
    bool chercherParCin();

};

#endif // EMPLOYE_H
