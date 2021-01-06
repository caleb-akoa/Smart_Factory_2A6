#include "globales.h"

// DATABSAE ::

QSqlDatabase connect_to_database(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("FACTWARE_DATABASE");
    db.setUserName("projet");
    db.setPassword("1230");
    db.open();
    return db;
}

QSqlDatabase database = connect_to_database();
