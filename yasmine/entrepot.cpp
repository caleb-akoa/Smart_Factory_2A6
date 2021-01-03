#include "entrepot.h"
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
entrepot::entrepot()
{

}
entrepot::entrepot(int id,int num,int nbP,QString lieu)
{
    this->id=id;
    this->num=num;
    this->nbP=nbP;
    this->lieu=lieu;

}

bool entrepot::ajouter()
{
    QSqlQuery query;
  //  QString res = QString::number(id);
    query.prepare("insert into Tableentrepot"
                  " (id,num,nbP,lieu)""values (:id,:num,:nbP,:lieu)" );

    query.bindValue(":id",this->id);
    query.bindValue(":num",this->num);
    query.bindValue(":nbP",this->nbP);
      query.bindValue(":lieu",this->lieu);
    return query.exec();
}
bool entrepot:: supprimer(int id)
{
    QSqlQuery query;

    query.prepare("Delete from tableentrepot where ID=:id");
    query.bindValue(":id",id);
    return query.exec();
}


QString entrepot:: get_lieu()
{
   return lieu;
}
int entrepot::get_nbP()
{
    return  nbP;

}
int entrepot::get_num()
{
    return num;


}
int entrepot::get_id()
{
    return  id;

}



bool entrepot::modifier(int id)
{
    QSqlQuery query;
 query.prepare("update Tableentrepot set id=:id,num=:num,nbP=:nbP,lieu=:lieu where id=:id");
 query.bindValue(":id",id);
 query.bindValue(":num",num);
 query.bindValue(":nbP",nbP);
 query.bindValue(":lieu",lieu);

   return    query.exec();
}
QSqlQueryModel *entrepot::affichertri()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * FROM Tableentrepot ORDER BY id ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NUM "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("NBP"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("LIEU"));



        return model;
}
