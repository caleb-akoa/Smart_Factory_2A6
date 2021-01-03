#include "dialogproduit.h"
#include "ui_dialogproduit.h"
#include "produit.h"
#include <QMessageBox>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>
#include <QDialog>
#include <QtSql>
#include <QtDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QMainWindow>
#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include "dialogentrepot.h"
#include <QPrinter>
#include <QPrintDialog>

dialogproduit::dialogproduit(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::dialogproduit)
{
    ui->setupUi(this);
    ui->editOk->hide();
    ui->label_4->hide();
    ui->label_5->hide();
    ui->label_6->hide();
    ui->label_7->hide();
    ui->nouv_mar->hide();
    ui->nouv_nom->hide();
    ui->nouv_nombre->hide();
     ui->nouv_prix->hide();
     ui->nouv_ref->hide();
     ui->label_14->hide();
     ui->id->setValidator(new QRegExpValidator(QRegExp("[0-9]*")));
     ui->prix->setValidator(new QRegExpValidator(QRegExp("[0-9]*")));
     ui->nombre->setValidator(new QRegExpValidator(QRegExp("[0-9]*")));
     ui->ref->setValidator(new QRegExpValidator(QRegExp("[0-9]*")));
     ui->txt_id->setValidator(new QRegExpValidator(QRegExp("[0-9]*")));
     ui->txt_prix->setValidator(new QRegExpValidator(QRegExp("[0-9]*")));
     ui->txt_nombre->setValidator(new QRegExpValidator(QRegExp("[0-9]*")));
     ui->txt_ref->setValidator(new QRegExpValidator(QRegExp("[0-9]*")));
     ui->deleteLine->setValidator(new QRegExpValidator(QRegExp("[0-9]*")));
     ui->nouv_nombre->setValidator(new QRegExpValidator(QRegExp("[0-9]*")));
     ui->nouv_ref->setValidator(new QRegExpValidator(QRegExp("[0-9]*")));
     ui->nouv_prix->setValidator(new QRegExpValidator(QRegExp("[0-9]*")));

}

dialogproduit::~dialogproduit()
{
    delete ui;
}


void dialogproduit::on_ajouter_clicked()
{
    int id=ui->id->text().toInt();
    QString nom=ui->nom->text();
    QString marque=ui->marque->text();
    int prix=ui->prix->text().toInt();
     int nombre=ui->nombre->text().toInt();
      int ref=ui->ref->text().toInt();
      produit e(id,nom,marque,prix,nombre,ref);
      bool test=e.ajouter();
      if(test)
      {
        ui->tabprod->setModel(tmpprod.afficher());
        ui->id->clear();
        ui->nom->clear();
        ui->marque->clear();
        ui->prix->clear();
        ui->nombre->clear();
        ui->ref->clear();
        QMessageBox::information(nullptr, QObject::tr("Ajouter produit"),
                              QObject::tr("Produit Ajouté ! ! .\n"
                                          "Click Close to exit."), QMessageBox::Close);
       }             else
            QMessageBox::critical(nullptr, QObject::tr("Ajouter Produit"),
                        QObject::tr("Erreur ! Remplir les informations.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


}





void dialogproduit::on_tabprod_activated(const QModelIndex &index)
{
    QString val=ui->tabprod->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("Select * from produits where id='"+val+"'");
    if(qry.exec())
    {
        while(qry.next())
        {
            ui->txt_id->setText(qry.value(0).toString());
            ui->txt_nom->setText(qry.value(1).toString());
            ui->txt_marque->setText(qry.value(2).toString());
            ui->txt_prix->setText(qry.value(3).toString());
            ui->txt_nombre->setText(qry.value(4).toString());
            ui->txt_ref->setText(qry.value(4).toString());
            ui->txt_id ->show();
            ui-> txt_nom->show();
            ui->txt_marque ->show();
            ui->txt_nombre->show();
            ui->txt_ref ->show();
            ui->del ->show();
            ui->edi ->show();

        }
    }
}

void dialogproduit::on_close_clicked()
{
    this->close();
}

void dialogproduit::on_del_clicked()
{
    int id = ui->txt_id->text().toInt();
    QSqlQuery query;
    query.prepare("Select * from produits where id = ?");
    query.addBindValue(id);
    query.exec();
    if(query.next()) {
    bool test=tmpprod.supprimer(id);
    if(test)
    {
        ui->tabprod->setModel(tmpprod.afficher());
        QMessageBox::information(nullptr, QObject::tr("Supprimer un Produit"),
                    QObject::tr("Produt supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Close);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un Produit"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel); }

}

void dialogproduit::on_tabWidget_currentChanged(int index)
{
     ui->tabprod->setModel(tmpprod.afficher());
}

void dialogproduit::on_edi_clicked()
{
    int id=ui->txt_id->text().toInt();
    QString nom=ui->txt_nom->text();
    QString marque=ui->txt_marque->text();
     int prix=ui->txt_prix->text().toInt();
    int nombre=ui->txt_nombre->text().toInt();
        int ref=ui->txt_ref->text().toInt();
    produit e(id,nom,marque,prix,nombre,ref);
    bool test=e.modifier(id);
    if(test)
    {
        ui->tabprod->setModel(tmpprod.afficher());
        QMessageBox::information(nullptr, QObject::tr("Modifier Produit"),
                              QObject::tr("Porduit Modifié ! ! .\n"
                                          "Click Close to exit."), QMessageBox::Close);
}
}

void dialogproduit::on_edit_clicked()
{
    int id = ui->id_2 ->text().toInt();
    QSqlQuery query;
    query.prepare("Select * from produits where id=?");
    query.addBindValue(id);
    query.exec();
    if(query.next()){
     ui->editOk->show();
     ui->label_4->show();
     ui->label_5->show();
     ui->label_6->show();
     ui->label_7->show();
     ui->nouv_mar->show();
     ui->nouv_nom->show();
     ui->nouv_nombre->show();
      ui->nouv_prix->show();
      ui->nouv_ref->show();
    ui->label_14->show();}
            else
    {
        QMessageBox::critical(nullptr, QObject::tr("EDIT"),
         QObject::tr("\n ID not Found !\n"), QMessageBox::Cancel);

    }
}

void dialogproduit::on_editOk_clicked()
{
    int id=ui->id_2->text().toInt();
    QString nom=ui->nouv_nom->text();
    QString marque=ui->nouv_mar->text();
    int prix=ui->nouv_prix->text().toInt();
    int nombre=ui->nouv_nombre->text().toInt();
    int ref=ui->nouv_ref->text().toInt();
    produit e(id,nom,marque,prix,nombre,ref);
    bool test=e.modifier(id);
    if(test)
    {

        ui->tabprod->setModel(tmpprod.afficher());
        QMessageBox::information(nullptr, QObject::tr("Modifier Produit"),
                              QObject::tr("Porduit Modifié ! ! .\n"
                                          "Click Close to exit."), QMessageBox::Close);
        ui->editOk->hide();
        ui->label_4->hide();
        ui->label_5->hide();
        ui->label_6->hide();
        ui->label_7->hide();
        ui->nouv_mar->hide();
        ui->nouv_nom->hide();
        ui->nouv_nombre->hide();
        ui->nouv_prix->hide();
        ui->nouv_ref->hide();
        ui->label_14->hide();
    }
    else { QMessageBox::critical(nullptr, QObject::tr("TRY AGAIN ! "),
                                    QObject::tr("something went wrong try again ! ! .\n"
                                                "Click Close to exit."), QMessageBox::Close);
             }

}

void dialogproduit::on_delete_btn_clicked()
{
    int id = ui->deleteLine->text().toInt();
    QSqlQuery query;
    query.prepare("SELECT * from produits where id = ?");
    query.addBindValue(id);
    query.exec();
    if(query.next()) {
    bool test=tmpprod.supprimer(id);
    if(test)
    {
        ui->tabprod->setModel(tmpprod.afficher());
        QMessageBox::information(nullptr, QObject::tr("Supprimer un Produit"),
                    QObject::tr("Produit supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Close);

    }
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un Produit"),
                    QObject::tr("Erreur ID NOT FOUND !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel); }


}



void dialogproduit::on_nextcrud_clicked()
{
    this->hide();
    dialogentrepot c;
    c.exec();
}

void dialogproduit::on_pushButton_clicked()
{
    QPrinter *imprimante;
    QPrintDialog pd(ui->tabprod);
    if(pd.exec()== QDialog::Accepted) return;
    imprimante=pd.printer();
    imprimante->setOutputFormat(QPrinter::PdfFormat);
    imprimante->setOutputFileName("C:/Users/ME/Desktop/pdf/doc.pdf");

}



void dialogproduit::on_search_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery   *query= new QSqlQuery();
    query->prepare("SELECT * from produits WHERE id LIKE'"+arg1+"%' or nom  LIKE'"+arg1+"%' or marque LIKE'"+arg1+"%' or prix  like'"+arg1+"%' or  nombre  like'"+arg1+"%' or ref  like'"+arg1+"%' ");
     query->exec();
    if(query->next())
    {
     model->setQuery(*query);
     ui->tabprod->setModel(model); }
    else {
        QMessageBox::critical(nullptr, QObject::tr("ENTREPOT"),
                        QObject::tr("NO MATCH FOUND !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        ui->search->clear();

    }
}
