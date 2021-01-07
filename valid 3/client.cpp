#include "client.h"
#include<QDebug>
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "user.h"



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

    query.prepare("INSERT INTO client (ID, NOM, PRENOM, MAIL, BOITE, TELE, VILLE) "
                  "VALUES (?, ?, ?, ?, ?, ?, ?)");
    query.bindValue(0, this->id);
    query.bindValue(1, this->firstName);
    query.bindValue(2, this->lastName);
    query.bindValue(3, this->email);
    query.bindValue(4, this->adress);
    query.bindValue(5, this->numTel);
    query.bindValue(6, this->city);

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
int Client::check() // check if it exsits or not  par id
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
QSqlQueryModel *Client::tri()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from client order by ID");


    return model;

}
QSqlQueryModel *Client::tri_nom()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from client order by nom");


    return model;

}
QSqlQueryModel *Client::tri_prenom()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from client order by prenom");


    return model;

}
bool Client::chercherdelet()
{
    QSqlQuery query;
    query.prepare("Select * from client where ID=:id");
    query.bindValue(":id", id);

    query.exec();

    if(query.next())
    {
        id=query.value(0).toInt();
        firstName=query.value(1).toString();
        lastName=query.value(2).toString();
        email=query.value(3).toString();
        city=query.value(4).toString();
        adress=query.value(5).toString();
        numTel=query.value(6).toString();
    }
    return query.exec();
}

bool Client::deleteclient()
{

    QSqlQuery query;
    query.prepare("delete from client where ID=:todelete");
    query.bindValue(":todelete",id);
    return query.exec();

}

bool Client::cherchermodifier()
{

    QSqlQuery query;
    query.prepare("Select * from client where ID=:id");
    query.bindValue(":id", id);

    query.exec();

    if(query.next())
    {
        id=query.value(0).toInt();
        firstName=query.value(1).toString();
        lastName=query.value(2).toString();
        email=query.value(3).toString();
        city=query.value(4).toString();
        adress=query.value(5).toString();
        numTel=query.value(6).toString();
    }
    return query.exec();

}
bool Client::validermodification()
{


    QSqlQuery query;

    query.prepare("update client set NOM=:nom,PRENOM=:prenom,MAIL=:email,BOITE=:boite,TELE=:telephone,VILLE=:adresse where ID=:toupdate");

    query.bindValue(":toupdate",id);
    query.bindValue(":nom",firstName);
    query.bindValue(":prenom",lastName);
    query.bindValue(":email",email);
    query.bindValue(":boite",adress);
    query.bindValue(":telephone",numTel);
    query.bindValue(":adresse",city);
    return query.exec();

}

bool Client::chercher()
{
    QSqlQuery query;
    query.prepare("Select * from client where ID=:id");
    query.bindValue(":id", id);

    query.exec();

    while(query.next())
    {
        id=query.value(0).toInt();
        firstName=query.value(1).toString();
        lastName=query.value(2).toString();
        email=query.value(3).toString();
        city=query.value(4).toString();
        adress=query.value(5).toString();
        numTel=query.value(6).toString();
    }
    return query.exec();


}


int Client::check_nom() // check if it exsits or not  par id
{

    QSqlQuery query;

    query.prepare("select * from client where nom = :id ");
    query.bindValue(":id",firstName);


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
bool Client::chercher_nom()
{
    QSqlQuery query;
    query.prepare("Select * from client where nom=:id");
    query.bindValue(":id", firstName);

    query.exec();

    while(query.next())
    {
        id=query.value(0).toInt();
        firstName=query.value(1).toString();
        lastName=query.value(2).toString();
        email=query.value(3).toString();
        city=query.value(4).toString();
        adress=query.value(5).toString();
        numTel=query.value(6).toString();
    }
    return query.exec();


}
QSqlQueryModel *Client::afficher_mail_client()
{

        QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select mail from client");
    //    model->setHeaderData(0,Qt::Horizontal,QObject::tr("nom"));
    //    model->setHeaderData(1,Qt::Horizontal,QObject::tr("prenom"));
    //    model->setHeaderData(2,Qt::Horizontal,QObject::tr("identifiant"));
    //    model->setHeaderData(3,Qt::Horizontal,QObject::tr("naissance"));
    //    model->setHeaderData(4,Qt::Horizontal,QObject::tr("poste"));
    //    model
    return model;


}
