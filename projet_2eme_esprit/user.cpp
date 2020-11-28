#include "user.h"



User::User()
{

}

User::User(QString username,QString password)
{
    this->id = 0;
    this->username = username;
    this->password = password;
}

User::User(int id,QString username,QString password)
{
    this->id = id;
    this->username = username;
    this->password = password;
}

int User::login()
{

    QSqlQuery query;

    query.prepare("select * from users where username = :username and password= :password");
    query.bindValue(":username",this->username);
    query.bindValue(":password",this->password);

    query.exec();

    int count_user = 0;
    while (query.next()) {
        count_user++;
    }

    if (count_user == 1) {
        return 0;
    }
    else if (count_user > 1 ) {
        return 1;
    }
    else{
        return 2;
    }
}
