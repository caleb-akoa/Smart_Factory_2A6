#ifndef STATCLASS_H
#define STATCLASS_H
#include <QString>
#include <vector>
#include <QSqlQuery>
#include <QSqlQueryModel>
using namespace std;



class statClass
{
public:
    statClass();
    vector <QString> GetVectStat();
};

#endif // STATCLASS_H
