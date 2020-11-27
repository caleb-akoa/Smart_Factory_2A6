#include "connexion.h"
#include <iostream>
#include<QSqlQuery>
#include<QSqlDatabase>
#include <QtSql>

using namespace std;
connexion::connexion(){}
bool connexion::ouvrirConnexion()
{    bool test=false;
     QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
     db.setDatabaseName("projet 2A6");
     db.setUserName("CALEB");//inserer nom de l'utilisateur
     db.setPassword("caleb");//inserer mot de passe de cet utilisateur

     if (db.open())
     {
        test=true;
        cout<< "connecter!";

      }
     return test;
}
 void connexion::fermerConnexion()
{
    db.close();
}

