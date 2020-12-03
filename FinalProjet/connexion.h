#ifndef CONNEXION_H
#define CONNEXION_H
#include<QSqlDatabase>
#include<QSqlQuery>
#include<QSql>

//class connexion
//{
//public:
//    connexion();
//};

    extern QSqlDatabase ouvrirConnexion();
    extern QSqlDatabase database;

#endif // CONNEXION_H
