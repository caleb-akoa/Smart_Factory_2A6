#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "produit.h"
#include <QString>
#include "entrepot.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(Etmp.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_pushButton_Produit_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_39_clicked()
{
     ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_pushButton_entrepot_clicked()
{
     ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_pushButton_26_clicked()
{
     ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_buttonBox_7_accepted() // page 0;
{
    ui->stackedWidget->setCurrentIndex(1);
}
void MainWindow::on_supprimer_clicked()
{
    int id=ui->lineEdit_idSup->text().toInt();
    bool test=Etmp.supprimer();
    if(test)
    {
        QMessageBox::information(nullptr,QObject ::tr("ok"),
        QObject::tr("suppression effectuee \n click cancel to exit "),QMessageBox::Cancel);


    }
    else
        QMessageBox::critical(nullptr,QObject ::tr("Not ok"),QObject::tr("suppression non effectuee\n "
                                                                         "click cancel to exit"),QMessageBox::Cancel);

}

void MainWindow::on_pushButton_clicked()
{  ;
    int id=ui->lineEdit_idSup->text().toInt();
    QString nom=ui->lineEdit_nom->text();
    QString marque=ui->lineEdit_marque->text();
    int nb=ui->lineEdit_nombres->text().toInt();
    int prix=ui->lineEdit_prix->text().toInt();
    Produit p(nom,prix,nb,id);
    bool Stest=p.ajouter();
    if(Stest)
    {
QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("ajout effectuee\n" "click cancel to exit"),QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr,QObject ::tr("Not ok"),QObject::tr("ajout non effectuee\n "
                                                                         "click cancel to exit"),QMessageBox::Cancel);
}
// entrepot




void MainWindow::on_buttonBox_4_accepted()
{
    QString lieu=ui->lineEdit_lieu->text();
    int nbP=ui->lineEdit_nbP->text().toInt();
    int num=ui->lineEdit_numerp->text().toInt();
    int id=ui->lineEdit_id_2->text().toInt();

    entrepot e(lieu,nbP,num,id);
    bool Stest=e.ajouter();
    if(Stest)
    {
        //refresh (actualiser)
        ui->tableView->setModel(Etmp.afficher());

QMessageBox::information(nullptr,QObject::tr("ok"),QObject::tr("ajout effectuee\n" "click cancel to exit"),QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr,QObject ::tr("Not ok"),QObject::tr("ajout non effectuee\n "
                                                                         "click cancel to exit"),QMessageBox::Cancel);
}

void MainWindow::on_buttonBox_6_accepted() // tri entrepot
{
    ui->tableView->setModel(e.tri());
}

void MainWindow::on_pushButton_4_clicked() // afficher entrepot
{
     ui->tableView->setModel(e.afficher());
}


//produit
void MainWindow::on_pushButton_2_clicked() //modifier produit
{

       int id = ui->lineEdit_30->text().toInt();
         QString nom= ui->lineEdit_6->text();





     bool test=temp.modifier();
             if (test)
             {
                  ui->tableView_2->setModel(temp.afficher());
         }
  }


void MainWindow::on_pushButton_6_clicked() //rechercher produit
{

        int id = ui->lineEdit_4->text().toInt();
        ui->tableView_2->setModel(temp.rechercher());

}


//entrepot



void MainWindow::on_pushButton_14_clicked() // modifer entrepot

{
    int id = ui->lineEdit_7->text().toInt();
         QString lieu= ui->lineEdit_lieu->text();


         int num= ui->lineEdit_numerp->text().toInt();
         int nbP= ui->lineEdit_nbP->text().toInt();


     bool test=e.modifier();
             if (test)
             {
                  ui->tableView->setModel(e.afficher());
         }
}





void MainWindow::on_pushButton_16_clicked() //rechercher entrepot
{
    QString tochercher=ui->lineEdit_9->text();
        QSqlQuery query;

        if (tochercher!="")
        {
            query.prepare("Select * from entrepot where lieu=:lieu");
            query.bindValue(":lieu", tochercher);
            query.exec();
            if(query.next())
            {
                ui->lineEdit_9->setText(query.value(0).toString());

            }
        }

}

// le tri

void MainWindow::on_pushButton_5_clicked() // tri produit
{

        ui->tableView->setModel(temp.tri());
}



void MainWindow::on_buttonBox_5_accepted() // supprimer entrepot
{
    int id=ui->lineEdit_23->text().toInt();
    e.setid(id);
    bool test=e.supprimer();
    if(test)
    {
        //refresh (actualiser)
        ui->tableView->setModel(e.afficher());
        QMessageBox::information(nullptr,QObject ::tr("ok"),
        QObject::tr("suppression effectuee \n click cancel to exit "),QMessageBox::Cancel);


    }
    else
        QMessageBox::critical(nullptr,QObject ::tr("Not ok"),QObject::tr("suppression non effectuee\n "
                                                                         "click cancel to exit"),QMessageBox::Cancel);
}
