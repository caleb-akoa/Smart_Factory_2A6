#include "globals.h"

// DATABSAE ::

QSqlDatabase connect_to_database(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("FACTWARE_DATABASE");
    db.setUserName("factware");
    db.setPassword("factwaree");
    db.open();
    return db;
}

QSqlDatabase database = connect_to_database();
