#include "produit.h"
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
Produit::Produit()
{

}
Produit::Produit(QString nom,float prix,int nb,int id)
{
    this->nom=nom;
    this->prix=prix;
    this->nb=nb;
    this->id=id;
}
QString Produit::get_Nom()
{
    return  nom;
}
float Produit::get_prix()
{
    return  prix;

}
int Produit::get_Nb()
{
    return nb;
}
int Produit::get_id()
{
    return id;
}
void Produit::setNom(QString nom)
{
    this->nom=nom;
}
void Produit::setPrix(float prix)
{
    this->prix=prix;
}
void Produit::setNb(int nb)
{
    this->nb=nb;
}
void Produit::set(int id)
{
    this->id=id;
}

bool Produit:: ajouter()
{
  QSqlQuery query;
//  QString res = QString::number(id);
  query.prepare("insert into table1"
                " (nom,prix,nb,id)""values (:nom,:prix,:nb,:id)" );
  query.bindValue(":nom",this->nom);
  query.bindValue(":prix",this->prix);
  query.bindValue(":nb",this->nb);
  query.bindValue(":id",this->id);
query.exec();
  return query.exec();
}
bool Produit:: supprimer()
{
    QSqlQuery query;
    QString res = QString::number(id);
    query.prepare("Delete from produit where ID=:id");
    query.bindValue(":id",res);
    return query.exec();
}

QSqlQueryModel *Produit:: afficher()
{
  QSqlQueryModel *model=new QSqlQueryModel();
  model->setQuery("select *from produit");
  model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
  model->setHeaderData(0,Qt::Horizontal,QObject::tr("Nom"));
  model->setHeaderData(0,Qt::Horizontal,QObject::tr("Prenom"));
  return  model;


}
int Produit:: calculer()
{

}
