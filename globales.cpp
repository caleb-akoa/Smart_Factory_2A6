
#include "globales.h"

// DATABSAE ::

QSqlDatabase connect_to_database(){
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("factware");
    db.setUserName("zied");
    db.setPassword("zied");
    db.open();
    return db;
}

QSqlDatabase database = connect_to_database();
