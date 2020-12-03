#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "revenues.h"
#include "factures.h"
#include <QMessageBox>
#include <QChar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView_Revenues->setModel(rev.afficherRevenues());
    QString NomProduit = ui->lineEdit->text();
       ui->tableView_2->setModel(rev.chercherRevenuesN(NomProduit));
    int ID_Revenue = ui->lineEdit_2->text().toInt();
    ui->tableView_2->setModel(rev.chercherRevenues(ID_Revenue));
    ui->tableView_Factures->setModel(fac.afficherFactures());
    int ID_Client = ui->lineEdit_5->text().toInt();
    ui->tableView_2->setModel(rev.chercherRevenuesC(ID_Client));

}


MainWindow::~MainWindow()
{
    delete ui;
}

/*bool check_number(QString str)
{
   for (int i = 0; i < str.length(); i++)
   if (isdigit(str[i]) == false)
      return false;
      else return true;
}*/
bool MainWindow::verifNomProduits()
{


    if (ui->lineEdit_NomProduits->text().contains(QRegExp("[^a-zA-Z ]") ) || ui->lineEdit_NomProduits->text().isEmpty()
            ||ui->lineEdit_ID_Revenues->text().contains(QRegExp("[^0-9 ]") ) || ui->lineEdit_ID_Revenues->text().isEmpty())
    {
        ui->lineEdit_NomProduits->clear();

        QMessageBox::critical(nullptr,QObject::tr("OK"),
                             QObject::tr("contient que des caracteres!!!! \n"
                             "Click Cancel to exit."), QMessageBox::Cancel);

        return false;
    }
else return true;

}


void MainWindow::on_pushButton_39_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_40_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_11_clicked()
{
  ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_12_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_13_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_14_clicked()
{
     ui->stackedWidget->setCurrentIndex(6);
}



void MainWindow::on_pushButton_17_clicked()
{
   ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_pushButton_48_clicked()
{
   ui->stackedWidget->setCurrentIndex(8);
}

void MainWindow::on_pushButton_47_clicked()
{
  ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_pushButton_49_clicked()
{
   ui->stackedWidget->setCurrentIndex(10);
}

void MainWindow::on_pushButton_18_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}

void MainWindow::on_pushButton_19_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
}

void MainWindow::on_pushButton_20_clicked()
{
  ui->stackedWidget->setCurrentIndex(13);
}

void MainWindow::on_pushButton_24_clicked()
{
 ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_25_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}



void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_10_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_23_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_ValidezRevenues_clicked()
{if (verifNomProduits())
    {
    int ID_Revenue=ui->lineEdit_ID_Revenues->text().toInt();
    QString NomProduit=ui->lineEdit_NomProduits->text();
    int QuantiteVendue=ui->lineEdit_QuantiteVendue->text().toInt();
    int ValeursUnitaire=ui->lineEdit_ValeursUnitaire->text().toInt();
    int ID_Client=ui->lineEdit_ID_Client->text().toInt();
    QString DateVente=ui->lineEdit_DateVente->text();

    Revenues R (NomProduit,QuantiteVendue,ValeursUnitaire,ID_Client,DateVente,ID_Revenue);

    bool test=R.ajouterRevenues();


    if(test)
    {
        int ID_Revenue = ui->lineEdit_2->text().toInt();
        ui->tableView_2->setModel(rev.chercherRevenues(ID_Revenue));
        ui->tableView_Revenues->setModel(rev.afficherRevenues());
        QString NomProduit = ui->lineEdit->text();
           ui->tableView_2->setModel(rev.chercherRevenuesN(NomProduit));
           int ID_Client = ui->lineEdit_5->text().toInt();
           ui->tableView_2->setModel(rev.chercherRevenuesC(ID_Client));
    QMessageBox::information(nullptr,QObject::tr("OK"),
                             QObject::tr("Ajout effectué \n"
                             "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else{
    QMessageBox::critical(nullptr,QObject::tr("OK"),
                             QObject::tr("Ajout non effectué!!!! \n"
                             "Click Cancel to exit."), QMessageBox::Cancel);
    }

}
}

void MainWindow::on_pushButton_36_clicked()//supprimer Revenues
{
 int ID_Revenue=ui->lineEdit_SID_Revenues->text().toInt();


 bool test=rev.supprimerRevenues(ID_Revenue);

 if(test)
 {
     int ID_Revenue = ui->lineEdit_2->text().toInt();
     ui->tableView_2->setModel(rev.chercherRevenues(ID_Revenue));
     ui->tableView_Revenues->setModel(rev.afficherRevenues());
     QString NomProduit = ui->lineEdit->text();
        ui->tableView_2->setModel(rev.chercherRevenuesN(NomProduit));
        int ID_Client = ui->lineEdit_5->text().toInt();
        ui->tableView_2->setModel(rev.chercherRevenuesC(ID_Client));
 QMessageBox::information(nullptr,QObject::tr("OK"),
                          QObject::tr("Suppression effectué \n"
                          "Click Cancel to exit."), QMessageBox::Cancel);
 }
 else{
 QMessageBox::critical(nullptr,QObject::tr("OK"),
                          QObject::tr("Suppression non effectué!!!! \n"
                          "Click Cancel to exit."), QMessageBox::Cancel);
 }


}





void MainWindow::on_pushButton_118_clicked()
{

    QString NomFournisseur=ui->lineEdit_NomFournisseur->text();
    QString Designation=ui->lineEdit_Designation->text();
    int Valeur=ui->lineEdit_Valeur->text().toInt();
    int ID_Facture=ui->lineEdit_ID_Facture->text().toInt();


    Factures F (NomFournisseur,Designation,Valeur,ID_Facture);

    bool test=F.ajouterFactures();
    if(test)
    {
        ui->tableView_Factures->setModel(fac.afficherFactures());
    QMessageBox::information(nullptr,QObject::tr("OK"),
                             QObject::tr("Ajout effectué \n"
                             "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else{
    QMessageBox::critical(nullptr,QObject::tr("OK"),
                             QObject::tr("Ajout non effectué!!!! \n"
                             "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_SuppFactures_clicked()
{
    int ID_Facture=ui->lineEdit_SIDFACT->text().toInt();


    bool test=fac.supprimerFactures(ID_Facture);

    if(test)
    {
        ui->tableView_Factures->setModel(fac.afficherFactures());
    QMessageBox::information(nullptr,QObject::tr("OK"),
                             QObject::tr("Suppression effectué \n"
                             "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else{
    QMessageBox::critical(nullptr,QObject::tr("OK"),
                             QObject::tr("Suppression non effectué!!!! \n"
                             "Click Cancel to exit."), QMessageBox::Cancel);
    }

}

void MainWindow::on_pushButton_35_clicked()
{
    int ID_Revenue=ui->lineEdit_22->text().toInt();
    QString NomProduit=ui->lineEdit_13->text();
    int QuantiteVendue=ui->lineEdit_14->text().toInt();
    int ValeursUnitaire=ui->lineEdit_15->text().toInt();
    int ID_Client=ui->lineEdit_12->text().toInt();
    QString DateVente=ui->dateEdit->text();

    Revenues R(NomProduit,QuantiteVendue,ValeursUnitaire,ID_Client,DateVente,ID_Revenue);


    bool test=R.modifierRevenues(ID_Revenue);

    if(test)
    {
        int ID_Revenue = ui->lineEdit_2->text().toInt();
        ui->tableView_2->setModel(rev.chercherRevenues(ID_Revenue));
        ui->tableView_Revenues->setModel(rev.afficherRevenues());
        QString NomProduit = ui->lineEdit->text();
           ui->tableView_2->setModel(rev.chercherRevenuesN(NomProduit));
           int ID_Client = ui->lineEdit_5->text().toInt();
           ui->tableView_2->setModel(rev.chercherRevenuesC(ID_Client));
    QMessageBox::information(nullptr,QObject::tr("OK"),
                             QObject::tr("Modifier effectué \n"
                             "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else{
    QMessageBox::critical(nullptr,QObject::tr("OK"),
                             QObject::tr("Modifier non effectué!!!! \n"
                             "Click Cancel to exit."), QMessageBox::Cancel);
    }

}




void MainWindow::on_pushButton_144_clicked()
{
  ui->stackedWidget->setCurrentIndex(14);
}

void MainWindow::on_pushButton_22_clicked()
{
    ui->tableView->setModel(fac.trierFacturesOrdre());
}

void MainWindow::on_pushButton_26_clicked()
{
    ui->tableView->setModel(fac.trierFacturesQuantite());
}

void MainWindow::on_pushButton_119_clicked()
{
    int ID_Facture=ui->lineEdit_85->text().toInt();
    QString NomFournisseur=ui->lineEdit_78->text();
    QString Designation=ui->lineEdit_81->text();
    int Valeur=ui->lineEdit_79->text().toInt();


    Factures F(NomFournisseur,Designation,Valeur,ID_Facture);


    bool test=F.modifierFactures(ID_Facture);

    if(test)
    {
         ui->tableView_Factures->setModel(fac.afficherFactures());;
    QMessageBox::information(nullptr,QObject::tr("OK"),
                             QObject::tr("Modifier effectué \n"
                             "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else{
    QMessageBox::critical(nullptr,QObject::tr("OK"),
                             QObject::tr("Modifier non effectué!!!! \n"
                             "Click Cancel to exit."), QMessageBox::Cancel);
    }

}

void MainWindow::on_pushButton_28_clicked()
{
  ui->tableView->setModel(fac.trierFacturesOrdreD());
}

void MainWindow::on_pushButton_16_clicked()
{
 ui->stackedWidget->setCurrentIndex(15);
}

void MainWindow::on_pushButton_29_clicked()
{
    int ID_Revenue = ui->lineEdit_2->text().toInt();
    ui->tableView_2->setModel(rev.chercherRevenues(ID_Revenue));
}

void MainWindow::on_pushButton_30_clicked()
{
        QString NomProduit = ui->lineEdit->text();
           ui->tableView_2->setModel(rev.chercherRevenuesN(NomProduit));
}




void MainWindow::on_pushButton_27_clicked()
{
    int ID_Client = ui->lineEdit_5->text().toInt();
    ui->tableView_2->setModel(rev.chercherRevenuesC(ID_Client));
}

void MainWindow::on_pushButton_31_clicked()
{
  ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_32_clicked()
{
  ui->stackedWidget->setCurrentIndex(2);
}
