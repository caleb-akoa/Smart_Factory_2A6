#include "connection.h"

connection::connection()
{

}
bool connection::ouvrirConnect()
{bool test=false;

QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Source_Projet2A");
db.setUserName("factware");
db.setPassword("0123");

if(db.open())
    test=true;
return test;
}

void connection::fermerConnect()
{ db.close();}
