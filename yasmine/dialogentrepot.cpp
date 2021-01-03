#include "dialogentrepot.h"
#include "ui_dialogentrepot.h"
#include "entrepot.h"
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
#include <QPrinter>
#include <QPrintDialog>
#include "dialogproduit.h"
dialogentrepot::dialogentrepot(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialogentrepot)
{
    ui->setupUi(this);
    ui->nouv_nom ->hide();
    ui->label_4 ->hide();
    ui->label_5->hide();
    ui->nouv_mar ->hide();
    ui->label_6 ->hide();
    ui->nouv_prix ->hide();
    ui->editOk->hide();
}

dialogentrepot::~dialogentrepot()
{
    delete ui;
}

void dialogentrepot::on_ajouter_clicked()
{
    int id=ui->id->text().toInt();
    int num=ui->num->text().toInt();
    int nbP=ui->nbp->text().toInt();
    QString lieu=ui->lieu->text();


    entrepot e(id,num,nbP,lieu);
    bool test=e.ajouter();
    if(test)
    {
        ui->tabent->setModel(tmpent.affichertri());
             ui->id->clear();
             ui->num ->clear();
             ui->nbp ->clear();
             ui->lieu->clear();


             QMessageBox::information(nullptr, QObject::tr("ENTREPOT"),
                                   QObject::tr("ENTREPOT ADDED! ! .\n"
                                               "Click Close to exit."), QMessageBox::Close);

}             else
                 QMessageBox::critical(nullptr, QObject::tr("ENTREPOT"),
                             QObject::tr("ERROR! FILL ALL THE DATA.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);


}

void dialogentrepot::on_tabent_activated(const QModelIndex &index)
{
    QString val=ui->tabent->model()->data(index).toString();
    QSqlQuery qry;
    qry.prepare("Select * from TABLEENTREPOT where id ='"+val+"'");
    if(qry.exec())
    {
        while(qry.next())
        {
            ui->txt_id->setText(qry.value(0).toString());
            ui->txt_nom->setText(qry.value(1).toString());
            ui->txt_marque->setText(qry.value(2).toString());
            ui->txt_prix->setText(qry.value(3).toString());


            ui-> txt_id->show();
            ui->txt_marque ->show();
            ui->txt_nom ->show();
            ui->txt_prix ->show();

            ui->del ->show();
            ui->edi ->show();

        }
    }
}

void dialogentrepot::on_tabWidget_currentChanged(int index)
{
     ui->tabent->setModel(tmpent.affichertri());
}

void dialogentrepot::on_del_clicked()
{
    int id = ui->txt_id->text().toInt();
    QSqlQuery query;
    query.prepare("Select * from TABLEENTREPOT where id = ?");
    query.addBindValue(id);
    query.exec();
    if(query.next()) {
    bool test=tmpent.supprimer(id);
    if(test)
    {
        ui->tabent->setModel(tmpent.affichertri());
        QMessageBox::information(nullptr, QObject::tr("Supprimer un Produit"),
                    QObject::tr("Produt supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Close);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un Produit"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel); }

}

void dialogentrepot::on_edi_clicked()
{
    int id= ui->txt_id->text().toInt();
    int num = ui->txt_nom->text().toInt();
    int nbP =ui->txt_marque->text().toInt();
    QString lieu =ui->txt_prix->text();


    entrepot e(id,num,nbP,lieu);
    bool test=e.modifier(id);
    if(test)
    {
        ui->tabent->setModel(tmpent.affichertri());
        QMessageBox::information(nullptr, QObject::tr("MODIFY ENTREPOT Produit"),
                              QObject::tr("ENTREPOT MODIFIED ! ! .\n"
                                          "Click Close to exit."), QMessageBox::Close);
}
}

void dialogentrepot::on_edit_clicked()
{
    int id =ui->id_2 ->text().toInt();
    QSqlQuery query;
    query.prepare("Select * from TABLEENTREPOT where id=?");
    query.addBindValue(id);
    query.exec();
    if(query.next()){
        ui->nouv_nom ->show();
        ui->label_4 ->show();
        ui->label_5->show();
        ui->nouv_mar ->show();
        ui->label_6 ->show();
        ui->nouv_prix ->show();
        ui->editOk->show();
    }
    else
{
QMessageBox::critical(nullptr, QObject::tr("EDIT"),
 QObject::tr("\n ID not Found !\n"), QMessageBox::Cancel);
ui->id_2->clear();
    }
}

void dialogentrepot::on_editOk_clicked()
{
    int id =ui->id_2 ->text().toInt();
    int num =ui->nouv_nom  ->text().toInt();
    int nbP =ui->nouv_mar  ->text().toInt();
    QString lieu=ui->nouv_prix ->text();
    entrepot e(id,num,nbP,lieu);
    bool test=e.modifier(id);
    if(test)
    {

        ui->tabent->setModel(tmpent.affichertri());
        QMessageBox::information(nullptr, QObject::tr("MODIFY ENTREPOT"),
                              QObject::tr("ENTREPOT MODIFIED ! ! .\n"
                                          "Click Close to exit."), QMessageBox::Close);

            ui->nouv_nom ->hide();
            ui->label_4 ->hide();
            ui->label_5->hide();
            ui->nouv_mar ->hide();
            ui->label_6 ->hide();
            ui->nouv_prix ->hide();
            ui->editOk->hide();
            ui->nouv_nom ->clear();
            ui->label_4 ->clear();
            ui->label_5->clear();
            ui->nouv_mar ->clear();
            ui->label_6 ->clear();
            ui->nouv_prix ->clear();

        }
    else { QMessageBox::critical(nullptr, QObject::tr("TRY AGAIN ! "),
                                    QObject::tr("something went wrong try again ! ! .\n"
                                                "Click Close to exit."), QMessageBox::Close);
             }


}

void dialogentrepot::on_delete_btn_clicked()
{
    int id = ui->deleteLine->text().toInt();
        QSqlQuery query;
        query.prepare("SELECT * from TABLEENTREPOT where id = ?");
        query.addBindValue(id);
        query.exec();
        if(query.next()) {
        bool test=tmpent.supprimer(id);
        if(test)
        {
            ui->tabent->setModel(tmpent.affichertri());
            QMessageBox::information(nullptr, QObject::tr("DELETE"),
                        QObject::tr("DELETED SUCCESSFULY !\n"
                                    "Click Cancel to exit."), QMessageBox::Close);

        ui->deleteLine->clear();
        }
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Supprimer un Produit"),
                        QObject::tr("Erreur ID NOT FOUND !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel); }


}

void dialogentrepot::on_search_textChanged(const QString &arg1)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery   *query= new QSqlQuery();
    query->prepare("SELECT * from TABLEENTREPOT WHERE id LIKE'"+arg1+"%' or num  LIKE'"+arg1+"%' or nbP LIKE'"+arg1+"%' or lieu  like'"+arg1+"%' ");
     query->exec();
    if(query->next())
    {
     model->setQuery(*query);
     ui->tabent->setModel(model); }
    else {
        QMessageBox::critical(nullptr, QObject::tr("ENTREPOT"),
                        QObject::tr("NO MATCH FOUND !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        ui->search->clear();

    }
}

void dialogentrepot::on_pushButton_clicked()
{
    QPrinter *imprimante;
    QPrintDialog pd(ui->tabent);
    if(pd.exec()== QDialog::Accepted) return;
    imprimante=pd.printer();
    imprimante->setOutputFormat(QPrinter::PdfFormat);
    imprimante->setOutputFileName("C:/Users/ME/Desktop/pdf/doc.pdf");

}

void dialogentrepot::on_prevcrud_clicked()
{
    this->hide();
    dialogproduit d;
    d.exec();
}


