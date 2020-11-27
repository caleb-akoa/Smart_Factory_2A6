#ifndef CONNEXION_H
#define CONNEXION_H

#include <QMainWindow>
#include<QSqlDatabase>
#include<QSqlQuery>
#include <QtSql>

class connexion
{
private:
     QSqlDatabase db;


public:
    connexion();
    bool ouvrirConnexion();
    void fermerConnexion();

};

#endif // CONNEXION_H
