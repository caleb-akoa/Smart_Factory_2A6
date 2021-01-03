#include "produit.h"


produit::produit()
{
 int id=0;
 QString nom ="" ;
 QString marque="";
 int prix=0;
 int nombre=0;
 int ref=0;
}
produit::produit(int id,QString nom,QString marque,int prix,int nombre ,int ref)
{
    this->id=id;
    this->nom=nom;
    this->marque=marque;
    this->prix=prix;
    this->nombre=nombre;
    this->ref=ref;
}
int produit::get_id(){return id;}
QString produit::get_nom(){return nom;}
QString produit::get_marque(){return marque;}
int produit::get_prix(){return prix;}
int produit::get_nombre(){return nombre;}
int produit::get_ref(){return ref;}

bool produit::ajouter(){
    QSqlQuery query;
    query.prepare("INSERT INTO PRODUITS (id,nom,marque,prix,nombre,ref)"
                "Values(:id,:nom,:marque,:prix,:nombre,:ref)");
    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":marque",marque);
    query.bindValue(":prix",prix);
    query.bindValue(":nombre",nombre);
    query.bindValue(":ref",ref);
   return  query.exec();
}
QSqlQueryModel * produit::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM PRODUITS order by ID ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Produit"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom Produit"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Marque Produit"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Prix Produit"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Nombre Produits"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Ref Produit"));
    return model;
}
bool produit::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("Delete from produits where id=:id ");
    query.bindValue(":id",id);
    return query.exec();
}
bool produit::modifier(int id)
{
    QSqlQuery query;
    query.prepare("UPDATE produits set nom=:nom,prix=:prix,marque=:marque,nombre=:nombre,id=:id,ref=:ref where id=:id");
     query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":marque",marque);
    query.bindValue(":prix",prix);
    query.bindValue(":nombre",nombre);
    query.bindValue(":ref",ref);
      return query.exec();
}
