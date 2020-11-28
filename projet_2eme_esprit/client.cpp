#include "client.h"
#include<QDebug>
#include "ui_mainwindow.h"
#include "mainwindow.h"



Client::Client()
{

}

Client::Client(QString firstName,QString lastName,QString email,QString city,QString adress,QString numTel)
{
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
    this->city = city;
    this->adress = adress;
    this->numTel = numTel;
}

Client::Client(int id,QString firstName,QString lastName,QString email,QString city,QString adress,QString numTel)
{

    this->id = id;
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
    this->city = city;
    this->adress = adress;
    this->numTel = numTel;
}

int Client::getId() const {
    return id;
}

void Client::setId(int id) {
    Client::id = id;
}

const QString &Client::getFirstName() const {
    return firstName;
}

void Client::setFirstName(const QString &firstName) {
    Client::firstName = firstName;
}

const QString &Client::getLastName() const {
    return lastName;
}

void Client::setLastName(const QString &lastName) {
    Client::lastName = lastName;
}

const QString &Client::getEmail() const {
    return email;
}

void Client::setEmail(const QString &email) {
    Client::email = email;
}

const QString &Client::getCity() const {
    return city;
}

void Client::setCity(const QString &city) {
    Client::city = city;
}

const QString &Client::getAdress() const {
    return adress;
}

void Client::setAdress(const QString &adress) {
    Client::adress = adress;
}

const QString &Client::getNumTel() const {
    return numTel;
}

void Client::setNumTel(const QString &numTel) {
    Client::numTel = numTel;
}

bool Client::add()
{

    QSqlQuery query;

    query.prepare("INSERT INTO client (ID, NOM, PRENOM, MAIL, VILLE, BOITE, TELE) "
                  "VALUES (?, ?, ?, ?, ?, ?, ?)");
    query.bindValue(0, this->id);
    query.bindValue(1, this->firstName);
    query.bindValue(2, this->lastName);
    query.bindValue(3, this->email);
    query.bindValue(4, this->city);
    query.bindValue(5, this->adress);
    query.bindValue(6, this->numTel);

    if (query.exec())
    {
        return true;

    }
    else
    {
        return false;
    }
}

QSqlQueryModel *Client::list()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from client");


    return model;

}
int Client::check() // check if it exsits or not
{

    QSqlQuery query;

    query.prepare("select * from client where ID = :id ");
    query.bindValue(":id",this->id);


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
    }}
