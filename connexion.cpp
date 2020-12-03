#include "connexion.h"

//connexion::connexion()
//{

//}
QSqlDatabase ouvrirConnexion()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("chafai");
    db.setPassword("123");
    db.open();
    return db;
}
QSqlDatabase database=ouvrirConnexion();
