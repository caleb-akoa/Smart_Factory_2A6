#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_client_0_clicked(){ui->stackedWidget->setCurrentIndex(1);}
void MainWindow::on_commande_0_clicked(){ui->stackedWidget->setCurrentIndex(3);}
void MainWindow::on_client_3_clicked(){ui->stackedWidget->setCurrentIndex(1);}
void MainWindow::on_commande_1_clicked(){ui->stackedWidget->setCurrentIndex(3);}
//////////////////////////////////////////////////  crouds clients clicked !!
void MainWindow::on_ajouterclient_clicked(){ui->stackedWidget->setCurrentIndex(2);ui->tabWidget->setCurrentIndex(0);}
void MainWindow::on_modifierclient_clicked(){ui->stackedWidget->setCurrentIndex(2);ui->tabWidget->setCurrentIndex(1);}
void MainWindow::on_supprimerclient_clicked(){ui->stackedWidget->setCurrentIndex(2);ui->tabWidget->setCurrentIndex(2);}
void MainWindow::on_afficherclient_clicked(){ ui->stackedWidget->setCurrentIndex(2);ui->tabWidget->setCurrentIndex(3);}
void MainWindow::on_chercherclient_clicked(){ui->stackedWidget->setCurrentIndex(2);ui->tabWidget->setCurrentIndex(4);}
//////////////////////////////////////////////// les retours client clicked !!!
void MainWindow::on_retour_clicked(){ui->stackedWidget->setCurrentIndex(1);}
void MainWindow::on_retour_2_clicked(){ui->stackedWidget->setCurrentIndex(1);}
void MainWindow::on_retour_3_clicked(){ui->stackedWidget->setCurrentIndex(1);}
void MainWindow::on_retour_4_clicked(){ui->stackedWidget->setCurrentIndex(1);}
void MainWindow::on_retour_5_clicked(){ui->stackedWidget->setCurrentIndex(1);}
///////////////////////////////////// crouds commande clicked !!
void MainWindow::on_ajouter_2_clicked(){ui->stackedWidget->setCurrentIndex(4);ui->tabWidget_2->setCurrentIndex(0);}
void MainWindow::on_modifier_2_clicked(){ui->stackedWidget->setCurrentIndex(4);ui->tabWidget_2->setCurrentIndex(1);}
void MainWindow::on_supprimer_2_clicked(){ui->stackedWidget->setCurrentIndex(4);ui->tabWidget_2->setCurrentIndex(2);}
void MainWindow::on_afficher_2_clicked(){ ui->stackedWidget->setCurrentIndex(4);ui->tabWidget_2->setCurrentIndex(3);}
void MainWindow::on_chercher_2_clicked(){ui->stackedWidget->setCurrentIndex(4);ui->tabWidget_2->setCurrentIndex(4);}
/////////////////////////////////// les retours commandes cllicked !!
void MainWindow::on_retour_6_clicked(){ui->stackedWidget->setCurrentIndex(3);}
void MainWindow::on_retour_7_clicked(){ui->stackedWidget->setCurrentIndex(3);}
void MainWindow::on_retour_8_clicked(){ui->stackedWidget->setCurrentIndex(3);}
void MainWindow::on_retour_9_clicked(){ui->stackedWidget->setCurrentIndex(3);}
void MainWindow::on_retour_10_clicked(){ui->stackedWidget->setCurrentIndex(3);}

/*                                           CLIENT                                                                       */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::on_ajoutercl_clicked()
{
    QString ID = ui->ID->text();
    QString NOM = ui->NOM->text();
    QString PRENOM = ui->PRENOM->text();
    QString MAIL = ui->MAIL->text();
    QString VILLE = ui->ADRESSE->text();
    QString BOITE = ui->BOITE->text();
    QString TELE = ui->TEL->text();

    if (ID.toInt()==0)
    {
        QMessageBox::critical(this, "failure !", "Verify");
        return;
    }

    QSqlQuery query;
    client.setId(ID.toInt());
    client.setFirstName(NOM);
    client.setLastName(PRENOM);
    client.setEmail(MAIL);
    client.setCity(VILLE);
    client.setAdress(BOITE);
    client.setNumTel(TELE);

    if (client.add())
    {
        QMessageBox::information(this, "success ", "ajouter avec success");
        ui->ID->setText("");
        ui->NOM->setText("");
        ui->PRENOM->setText("");
        ui->MAIL->setText("");
        ui->ADRESSE->setText("");
        ui->BOITE->setText("");
        ui->TEL->setText("");
    }
    else
    {
        QMessageBox::critical(this, "failure !", "completer les champs!");
    }
}

void MainWindow::on_tabWidget_tabBarClicked(int index)//afficher
{ ui->tableView->setModel(client.list());}

void MainWindow::on_deleteclient_clicked()
{
    QSqlQuery query;

    QString password = ui->lineEdit_8->text();
    query.prepare("select * from users where password= :password");
    query.bindValue(":password",password);
    query.exec();
    if(query.next())
    {QString todelete = ui->todelete->text();
        query.prepare("delete from client where ID=:todelete");
        query.bindValue(":todelete",todelete);
        query.exec();
        QMessageBox::information (this, "deleted", "client supprimé");
        ui->todelete->setText("");
        ui->lineEdit->setText("");
        ui->lineEdit_2->setText("");
        ui->lineEdit_3->setText("");
        ui->lineEdit_4->setText("");
        ui->lineEdit_5->setText("");
        ui->lineEdit_6->setText("");
        ui->lineEdit_7->setText("");
        ui->lineEdit_8->setText("");
    }

    else {QMessageBox::critical (this, "Error", "action not done");}

}

void MainWindow::on_cherchermodifier_clicked()
{  QString toupdate = ui->toupdate->text();
    client.setId( toupdate.toInt());

    int delet = client.check();
    if(delet == 0)

    {
        QSqlQuery query;
        query.prepare("Select * from client where ID=:id");
        query.bindValue(":id", toupdate);
        query.exec();
        if(query.next())
        {
            ui->lineEdit_9->setText(query.value(0).toString());
            ui->lineEdit_10->setText(query.value(1).toString());
            ui->lineEdit_11->setText(query.value(2).toString());
            ui->lineEdit_12->setText(query.value(3).toString());
            ui->lineEdit_13->setText(query.value(4).toString());
            ui->lineEdit_14->setText(query.value(5).toString());
            ui->lineEdit_15->setText(query.value(6).toString());
        }
    }

}

void MainWindow::on_chercher_clicked()
{
    QString tochercher=ui->tochercher->text();
    QSqlQuery query;

    if (tochercher!="")
    {
        query.prepare("Select * from client where NOM=:nom");
        query.bindValue(":nom", tochercher);
        query.exec();
        if(query.next())
        {
            ui->tochercher0->setText(query.value(0).toString());
            ui->tochercher1->setText(query.value(1).toString());
            ui->tochercher2->setText(query.value(2).toString());
            ui->tochercher3->setText(query.value(3).toString());
            ui->tochercher4->setText(query.value(4).toString());
            ui->tochercher5->setText(query.value(5).toString());
            ui->tochercher6->setText(query.value(6).toString());
        }
    }
}

void MainWindow::on_chercherdelete_clicked()
{
    QString todelete = ui->todelete->text();
    client.setId( todelete.toInt());

    int delet = client.check();
    if(delet == 0)

    {
        QSqlQuery query;
        query.prepare("Select * from client where ID=:id");
        query.bindValue(":id", todelete);
        query.exec();
        if(query.next())
        {
            ui->lineEdit->setText(query.value(0).toString());
            ui->lineEdit_2->setText(query.value(1).toString());
            ui->lineEdit_3->setText(query.value(2).toString());
            ui->lineEdit_4->setText(query.value(3).toString());
            ui->lineEdit_5->setText(query.value(4).toString());
            ui->lineEdit_6->setText(query.value(5).toString());
            ui->lineEdit_7->setText(query.value(6).toString());
        }
    }
}

void MainWindow::on_validermodification_clicked()
{

        QString  id= ui->lineEdit_9->text();
        QString   nom=ui->lineEdit_10->text();
        QString  prenom= ui->lineEdit_11->text();
        QString  email= ui->lineEdit_12->text();
        QString  boite =ui->lineEdit_13->text();
        QString telephone= ui->lineEdit_14->text();
        QString adresse=ui->lineEdit_15->text();
        QSqlQuery query;

        query.prepare("update client set NOM=:nom,PRENOM=:prenom,MAIL=:email,BOITE=:boite,TELE=:telephone,VILLE=:adresse where ID=:toupdate");

        query.bindValue(":toupdate",id);

        query.bindValue(":nom",nom);
        query.bindValue(":prenom",prenom);
        query.bindValue(":email",email);
        query.bindValue(":boite",boite);
        query.bindValue(":telephone",telephone);
        query.bindValue(":adresse",adresse);

        if(query.exec()){
        QMessageBox::information (this, "update", "client updated");
        ui->toupdate->setText("");
    }


    else {QMessageBox::critical (this, "Error", "unexpected error");}
}
