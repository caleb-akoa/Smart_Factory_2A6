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
void MainWindow::on_modifierclient_clicked(){ui->stackedWidget->setCurrentIndex(2);ui->tabWidget->setCurrentIndex(1);
                                             /*hide modier champs */ ui->label_36->hide(); ui->label_55->hide();ui->label_54->hide();ui->label_53->hide();ui->label_52->hide();ui->label_51->hide();ui->label_50->hide();ui->suivantmodifier->hide();ui->label_36->hide();ui->label_37->hide(); ui->lineEdit_9->hide();ui->lineEdit_10->hide();ui->lineEdit_11->hide();ui->lineEdit_12->hide();ui->lineEdit_13->hide();ui->lineEdit_14->hide();ui->lineEdit_15->hide();ui->lineEdit_17->hide();ui->validermodification->hide();}
void MainWindow::on_supprimerclient_clicked(){
    ui->lineEdit->hide();ui->lineEdit_2->hide();ui->lineEdit_3->hide();ui->lineEdit_4->hide();ui->lineEdit_5->hide();ui->lineEdit_6->hide(); ui->lineEdit_7->hide();    ui->lineEdit_8->hide();    ui->label_59->hide();    ui->label_60->hide();    ui->deleteclient->hide();    ui->label_34->hide();ui->label_35->hide();ui->stackedWidget->setCurrentIndex(2);ui->tabWidget->setCurrentIndex(2);}
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
void MainWindow::on_ajoutercl_clicked()//ajouter client
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


void MainWindow::on_tabWidget_tabBarClicked(int index)//afficher clients
{ ui->tableView->setModel(client.list());}


void MainWindow::on_chercherdelete_clicked()//delete 0
{   ui->lineEdit->show();
    ui->lineEdit_2->show();
    ui->lineEdit_3->show();
    ui->lineEdit_4->show();
    ui->lineEdit_5->show();
    ui->lineEdit_6->show();
    ui->lineEdit_7->show();
    ui->lineEdit_8->show();
    ui->label_59->show();
    ui->label_60->show();
    ui->deleteclient->show();
    ui->label_34->show();
    ui->label_35->show();
    QString todelete = ui->todelete->text();
    client.setId( todelete.toInt());

    int delet = client.check();
    if(delet == 0)
    {
        if(client.chercherdelet())
        {
            QString a = QString::number(client.getId());
            ui->lineEdit->setText(a);
            ui->lineEdit_2->setText(client.getFirstName());
            ui->lineEdit_3->setText(client.getLastName());
            ui->lineEdit_4->setText(client.getEmail());
            ui->lineEdit_5->setText(client.getAdress());
            ui->lineEdit_6->setText(client.getCity());
            ui->lineEdit_7->setText(client.getNumTel());
        }
    }
}
void MainWindow::on_deleteclient_clicked()//delete 1
{
    QSqlQuery query;

    QString password = ui->lineEdit_8->text();

    user.password=password;
    if(user.passwordcheck())

    {
        QString todelete = ui->todelete->text();
        client.setId(todelete.toInt());
        if(client.deleteclient())
        {

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
    }

    else {QMessageBox::critical (this, "Error", "action not done");}

}


void MainWindow::on_tabWidget_currentChanged(int index)/// ki tickliki ala modifier fel tab bar0
{
    ui->lineEdit->hide();
    ui->lineEdit_2->hide();
    ui->lineEdit_3->hide();
    ui->lineEdit_4->hide();
    ui->lineEdit_5->hide();
    ui->lineEdit_6->hide();
    ui->lineEdit_7->hide();
    ui->lineEdit_8->hide();
    ui->label_59->hide();
    ui->label_60->hide();
    ui->deleteclient->hide();
    ui->label_34->hide();
    ui->label_35->hide();
    ui->lineEdit_9->hide();
    ui->lineEdit_10->hide();
    ui->lineEdit_11->hide();
    ui->lineEdit_12->hide();
    ui->lineEdit_13->hide();
    ui->lineEdit_14->hide();
    ui->lineEdit_15->hide();
    ui->lineEdit_17->hide();
    ui->validermodification->hide();
    ui->label_55->hide();
    ui->label_54->hide();
    ui->label_53->hide();
    ui->label_52->hide();
    ui->label_51->hide();
    ui->label_50->hide();
    ui->label_36->hide();
    ui->label_37->hide();
    ui->suivantmodifier->hide();
}
void MainWindow::on_cherchermodifier_clicked()//modfier1
{  QString toupdate = ui->toupdate->text();
    client.setId( toupdate.toInt());

    int delet = client.check();
    if(delet == 0)

    {
        ui->lineEdit_9->show();
        ui->lineEdit_10->show();
        ui->lineEdit_11->show();
        ui->lineEdit_12->show();
        ui->lineEdit_13->show();
        ui->lineEdit_14->show();
        ui->lineEdit_15->show();
        ui->label_36->show();
        ui->suivantmodifier->show();
        ui->label_55->show();
        ui->label_54->show();
        ui->label_53->show();
        ui->label_52->show();
        ui->label_51->show();
        ui->label_50->show();
        if(client.cherchermodifier())
        {
            QString a = QString::number(client.getId());
            ui->lineEdit_9->setText(a);
            ui->lineEdit_10->setText(client.getFirstName());
            ui->lineEdit_11->setText(client.getLastName());
            ui->lineEdit_12->setText(client.getEmail());
            ui->lineEdit_13->setText(client.getAdress());
            ui->lineEdit_14->setText(client.getCity());
            ui->lineEdit_15->setText(client.getNumTel());


        }
    }

    else {QMessageBox::critical (this, "Error", "cette ID n'existe pas");

    }


}
void MainWindow::on_suivantmodifier_clicked()//modifier2
{
    ui->lineEdit_17->show();
    ui->label_37->show();
    ui->validermodification->show();
}
void MainWindow::on_validermodification_clicked() // ki bch taaamil il modifcation etape finale 3
{

    QString  id= ui->lineEdit_9->text();
    QString   nom=ui->lineEdit_10->text();
    QString  prenom= ui->lineEdit_11->text();
    QString  email= ui->lineEdit_12->text();
    QString  boite =ui->lineEdit_15->text();
    QString telephone= ui->lineEdit_13->text();
    QString adresse=ui->lineEdit_14->text();
    QString password=ui->lineEdit_17->text();

    user.password=password;

    client.setId(id.toInt());
    client.setFirstName(nom);
    client.setLastName(prenom);
    client.setEmail(email);
    client.setCity(adresse);
    client.setAdress(boite);
    client.setNumTel(telephone);
    if(user.passwordcheck())
    {

        if( client.validermodification())
        {
            QMessageBox::information (this, "update", "client updated");
            ui->toupdate->setText("");
        }
    }

    else {QMessageBox::critical (this, "Error", "unexpected error");}
}


void MainWindow::on_chercher_clicked()// chercher
{
    QString tochercher=ui->tochercher->text();
    client.setId( tochercher.toInt());


    if (tochercher!="" && client.chercher())
    {
        QString a = QString::number(client.getId());
        ui->tochercher0->setText(a);
        ui->tochercher1->setText(client.getFirstName());
        ui->tochercher2->setText(client.getLastName());
        ui->tochercher3->setText(client.getEmail());
        ui->tochercher4->setText(client.getAdress());
        ui->tochercher5->setText(client.getCity());
        ui->tochercher6->setText(client.getNumTel());

    }
}


void MainWindow::on_pushButton_clicked()// tri
{
    ui->tableView->setModel(client.tri());
}

void MainWindow::on_tabWidget_3_tabBarClicked(int index)//line chart
{
    QPieSeries *series = new QPieSeries();
    series->append("c++",80);
    series->append("python",70);
    series->append("wajih+",60);
    series->append("rania",50);
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("titre");
    QChartView *chartview=new QChartView(chart);
    chartview->setParent(ui->horizontalFrame);

}
void MainWindow::on_tabWidget_3_currentChanged(int index)//pie chart
{


    QLineSeries *series = new QLineSeries();
    series->append(0,6);
    series->append(2,4);
    series->append(3,8);
    series->append(10,5);
    *series << QPoint(11,1)<<QPoint(13,3)<<QPoint(17,6)<<QPoint(18,3)<<QPoint(20,2);
    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->setTitle("titre");
    QChartView *chartview=new QChartView(chart);
    chartview->setRenderHint(QPainter::Antialiasing);
    chartview->setParent(ui->horizontalFrame0);
}

void MainWindow::on_ajoutercmd_clicked()
{
    QString ID = ui->IDcmd->text();
    QString idclient = ui->ID_client->text();
    QString idproduit = ui->ID_produit->text();
    QString quantite = ui->quantite->text();
    QString datelivri = ui->datelivri->text();


    if (ID.toInt()==0)
    {
        QMessageBox::critical(this, "failure !", "Verify");
        return;
    }


    commande.setId(ID);
    commande.setIdClient(idclient);
    commande.setIdProduit(idproduit);
    commande.setQuantite(quantite);
    commande.setDatelivri(datelivri);


    if (commande.add())
    {
        QMessageBox::information(this, "success ", "ajouter avec success");
        ui->IDcmd->setText("");
        ui->ID_client->setText("");
        ui->ID_produit->setText("");
        ui->quantite->setText("");
        ui->datelivri->setText("");

    }
    else
    {
        QMessageBox::critical(this, "failure !", "completer les champs!");
    }
}
