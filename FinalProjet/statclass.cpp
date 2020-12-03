#include "statclass.h"

statClass::statClass()
{

}

vector <QString> statClass::GetVectStat()
{
    vector <QString> vectStat;
    QSqlQuery query;
    query.prepare("select * from machine");
    query.exec();

    while (query.next())
    {
        vectStat.push_back(query.value(4).toString());
    }
    return vectStat;
}
