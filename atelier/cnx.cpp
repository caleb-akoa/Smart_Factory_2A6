#include "cnx.h"
// test tutoriel git
QSqlDatabase connectdatabase()
{   QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("factware");
    db.setUserName("factware");
    db.setPassword("0123");
    db.open();
    return db;
}

QSqlDatabase database=connectdatabase();
