#include "connection.h"

connection::connection()
{

}
bool connection::ouvrirConnect()
{bool test=false;

QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("FACTWARE_DATABASE");
db.setUserName("projet");
db.setPassword("1230");

if(db.open())
    test=true;
return test;
}

void connection::fermerConnect()
{ db.close();}
