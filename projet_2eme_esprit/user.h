#ifndef USER_H
#define USER_H
#include <QString>
#include <QSql>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlQueryModel>

class User
{

public :
    int id;
    QString username;
    QString password;

public:
    User();
    User(QString username,QString password);
    User(int id,QString username,QString password);

    int login();

};

#endif // USER_H
