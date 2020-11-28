#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QSql>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlQueryModel>


class Client
{
public:
    int id;
    QString firstName;
    QString lastName;
    QString email;
    QString city;
    QString adress;
    QString numTel;

public:
    Client();
    Client(QString firstName,QString lastName,QString email,QString city,QString adress,QString numTel);
    Client(int id,QString firstName,QString lastName,QString email,QString city,QString adress,QString numTel);

    int getId() const;
    void setId(int id);
    const QString &getFirstName() const;
    void setFirstName(const QString &firstName);
    const QString &getLastName() const;
    void setLastName(const QString &lastName);
    const QString &getEmail() const;
    void setEmail(const QString &email);
    const QString &getCity() const;
    void setCity(const QString &city);
    const QString &getAdress() const;
    void setAdress(const QString &adress);
    const QString &getNumTel() const;
    void setNumTel(const QString &numTel);

    bool add();
    bool edit();
    int check();

    QSqlQueryModel *list();
};

#endif // CLIENT_H
