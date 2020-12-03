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
void MainWindow::on_ajouterclient_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);ui->tabWidget->setCurrentIndex(5);
}
//////////////////////////////////////////////// les retours client clicked !!!
void MainWindow::on_retour_clicked(){ui->stackedWidget->setCurrentIndex(1);}
void MainWindow::on_retour_2_clicked(){ui->stackedWidget->setCurrentIndex(1);}
void MainWindow::on_retour_3_clicked(){ui->stackedWidget->setCurrentIndex(1);}
void MainWindow::on_retour_4_clicked(){ui->stackedWidget->setCurrentIndex(1);}
void MainWindow::on_retour_5_clicked(){ui->stackedWidget->setCurrentIndex(1);}
///////////////////////////////////// crouds commande clicked !!
void MainWindow::on_ajouter_2_clicked(){ui->stackedWidget->setCurrentIndex(4);ui->tabWidget_2->setCurrentIndex(0);}
void MainWindow::on_modifier_2_clicked(){ui->lineEdit_20->hide();ui->lineEdit_21->hide();ui->lineEdit_22->hide();ui->lineEdit_23->hide(); ui->lineEdit_24->hide(); ui->lineEdit_25->hide();ui->label_64->hide(); ui->label_65->hide();ui->validermodifiercmd->hide(); ui->suivantcmd->hide();ui->stackedWidget->setCurrentIndex(4);ui->tabWidget_2->setCurrentIndex(1);}
void MainWindow::on_supprimer_2_clicked(){ui->deletecmd->hide();ui->label_68->hide();ui->label_70->hide();ui->lineEdit_26->hide();ui->lineEdit_27->hide();ui->lineEdit_28->hide();ui->lineEdit_29->hide();ui->lineEdit_30->hide();ui->lineEdit_31->hide();ui->stackedWidget->setCurrentIndex(4);ui->tabWidget_2->setCurrentIndex(2);}
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
     ui->label_73->hide();
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



    ui->tochercher->hide();
    ui->chercher->hide();
    ui->tocherchernom->hide();
    ui->cherchernom->hide();






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

    else {QMessageBox::critical (this, "Error", "cette ID n'existe pas");}


}
void MainWindow::on_suivantmodifier_clicked()//modifier2
{
    ui->lineEdit_17->show();
    ui->label_37->show();
     ui->label_73->show();
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

            ui->lineEdit_17->setText("");
            ui->lineEdit_9->setText("");
            ui->lineEdit_10->setText("");
            ui->lineEdit_11->setText("");
            ui->lineEdit_12->setText("");
            ui->lineEdit_13->setText("");
            ui->lineEdit_14->setText("");
            ui->lineEdit_15->setText("");
        }
    }

    else {QMessageBox::critical (this, "Error", "mot de passe incorrect!");}
}


void MainWindow::on_chercher_clicked()// chercher client
{



    QString tochercher=ui->tochercher->text();
    client.setId( tochercher.toInt());


    if (tochercher!="" && client.check()==0)

    {
        client.chercher();
        QString a = QString::number(client.getId());
        ui->tochercher0->setText(a);
        ui->tochercher1->setText(client.getFirstName());
        ui->tochercher2->setText(client.getLastName());
        ui->tochercher3->setText(client.getEmail());
        ui->tochercher4->setText(client.getAdress());
        ui->tochercher5->setText(client.getCity());
        ui->tochercher6->setText(client.getNumTel());

    }
    else {QMessageBox::critical (this, "Error", "ID n'existe pas!");}
}




void MainWindow::on_tabWidget_3_tabBarClicked(int index)//line chart
{if (index==0)
    {
    QPieSeries *series = new QPieSeries();
    series->append("janvier",80);
    series->append("fevrier",70);
    series->append("mars",60);
    series->append("juin",50);
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("les clients inscrit dans 4 mois");
    QChartView *chartview=new QChartView(chart);
    chartview->setParent(ui->horizontalFrame);
    }
    else if(index==1)
    {
        QLineSeries *series = new QLineSeries();
        series->append(0,8);
        series->append(8,7);
        series->append(7,6);
        series->append(6,5);
        *series << QPoint(11,1)<<QPoint(13,3)<<QPoint(17,6)<<QPoint(18,3)<<QPoint(20,2);
        QChart *chart = new QChart();
        chart->legend()->hide();
        chart->addSeries(series);
        chart->createDefaultAxes();
        chart->setTitle("les clients inscrit dans 4 mois");
        QChartView *chartview=new QChartView(chart);
        chartview->setRenderHint(QPainter::Antialiasing);
        chartview->setParent(ui->horizontalFrame0);


    }

}


void MainWindow::on_ajoutercmd_clicked() //ajouter cmd
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

void MainWindow::on_tabWidget_2_tabBarClicked(int index) // hide
{
    ui->lineEdit_20->hide();
    ui->lineEdit_21->hide();
    ui->lineEdit_22->hide();
    ui->lineEdit_23->hide();
    ui->lineEdit_24->hide();
    ui->lineEdit_25->hide();
    ui->label_64->hide();
    ui->label_46->hide();
    ui->label_65->hide();
    ui->validermodifiercmd->hide();
    ui->suivantcmd->hide();

    //////////////////////
    ui->deletecmd->hide();
    ui->label_68->hide();
    ui->label_70->hide();
    ui->lineEdit_26->hide();
    ui->lineEdit_27->hide();
    ui->lineEdit_28->hide();
    ui->lineEdit_29->hide();
    ui->lineEdit_30->hide();
    ui->lineEdit_31->hide();
     ui->label_72->hide();


}




void MainWindow::on_cherchermodifiercmd_clicked()// chercher modifier cmd
{ QString toupdate = ui->lineEdit_16->text();
    commande.setId( toupdate);

    int delet = commande.check();
    if(delet == 0)
    {
        ui->lineEdit_20->show();
        ui->lineEdit_21->show();
        ui->lineEdit_22->show();
        ui->lineEdit_23->show();
        ui->lineEdit_24->show();
        ui->suivantcmd->show();
        ui->label_65->show();
        if (commande.cherchermodifier())
        {
            ui->lineEdit_20->setText(commande.getId());
            ui->lineEdit_21->setText(commande.getIdClient());
            ui->lineEdit_22->setText(commande.getIdProduit());
            ui->lineEdit_23->setText(commande.getQuantite());
            ui->lineEdit_24->setText(commande.getDatelivri());

        }

    }
    else {QMessageBox::critical (this, "Error", "cette ID n'existe pas");}
}

void MainWindow::on_suivantcmd_clicked() //suivant cmd
{
    ui->label_64->show();
     ui->label_46->show();
    ui->validermodifiercmd->show();
    ui->lineEdit_25->show();
}


void MainWindow::on_validermodifiercmd_clicked()// valider modifier cmd
{
    QString  id= ui->lineEdit_20->text();
    QString   idclient=ui->lineEdit_21->text();
    QString  idproduit= ui->lineEdit_22->text();
    QString  quantite= ui->lineEdit_23->text();
    QString  datelivri =ui->lineEdit_24->text();
    QString  password =ui->lineEdit_25->text();
    user.password=password;
    commande.setId(id);
    commande.setIdClient(idclient);
    commande.setIdProduit(idproduit);
    commande.setQuantite(quantite);
    commande.setDatelivri(datelivri);
    if(user.passwordcheck())
    {

        if( commande.validermodification())
        {
            QMessageBox::information (this, "update", "commande updated");
            ui->lineEdit_16->setText("");
            ui->lineEdit_25->setText("");
            ui->lineEdit_24->setText("");
            ui->lineEdit_23->setText("");
            ui->lineEdit_22->setText("");
            ui->lineEdit_21->setText("");
            ui->lineEdit_20->setText("");
        }
    }

    else {QMessageBox::critical (this, "Error", "mot de passe incorrect!");}
}




void MainWindow::on_chercherdeletecmd_clicked()// chercher delete cmd
{
    QString todelete = ui->lineEdit_18->text();

    commande.setId( todelete);
    int delet = commande.check();

    if(delet==0)
    {

        ui->deletecmd->show();
        ui->label_68->show();
        ui->label_70->show();
        ui->label_72->show();
        ui->lineEdit_26->show();
        ui->lineEdit_27->show();
        ui->lineEdit_28->show();
        ui->lineEdit_29->show();
        ui->lineEdit_30->show();
        ui->lineEdit_31->show();
        if (commande.cherchermodifier())
        {
            ui->lineEdit_26->setText(commande.getId());
            ui->lineEdit_27->setText(commande.getIdClient());
            ui->lineEdit_28->setText(commande.getIdProduit());
            ui->lineEdit_29->setText(commande.getQuantite());
            ui->lineEdit_30->setText(commande.getDatelivri());

        }
    }
    else QMessageBox::critical(this, "failure !", "Verify");
}

void MainWindow::on_deletecmd_clicked()// delte cmd
{ QString password = ui->lineEdit_31->text();
    user.password=password;
    if(user.passwordcheck())
    {
        QString todelete = ui->lineEdit_18->text();
        commande.setId(todelete);
        if(commande.deletecmd())
        {

            QMessageBox::information (this, "deleted", "client supprimé");
            ui->lineEdit_18->setText("");
            ui->lineEdit_26->setText("");
            ui->lineEdit_27->setText("");
            ui->lineEdit_28->setText("");
            ui->lineEdit_29->setText("");
            ui->lineEdit_30->setText("");
            ui->lineEdit_31->setText("");

        }
    }

    else {QMessageBox::critical (this, "Error", "mot de passe incorrect!");}

}

void MainWindow::on_tabWidget_2_currentChanged(int index)// affiche cmd
{
    ui->tableView_2->setModel(commande.list());
}
void MainWindow::on_radioButton_clicked()// cherhcer parid
{
    ui->tocherchernom->hide();
    ui->cherchernom->hide();
    ui->tochercher->show();
    ui->chercher->show();
}


void MainWindow::on_radioButton_2_clicked()// chercher par nom
{

    ui->tochercher->hide();
    ui->chercher->hide();


    ui->tocherchernom->show();
    ui->cherchernom->show();

}


void MainWindow::on_cherchernom_clicked() // chercher par nom 2 button
{
    QString tocherchernom=ui->tocherchernom->text();
    client.setFirstName(tocherchernom);


    if (tocherchernom!="" && client.check_nom()==0)

    {
        client.chercher_nom();
        QString a = QString::number(client.getId());
        ui->tochercher0->setText(a);
        ui->tochercher1->setText(client.getFirstName());
        ui->tochercher2->setText(client.getLastName());
        ui->tochercher3->setText(client.getEmail());
        ui->tochercher4->setText(client.getAdress());
        ui->tochercher5->setText(client.getCity());
        ui->tochercher6->setText(client.getNumTel());

    }
    else {QMessageBox::critical (this, "Error", "ID n'existe pas!");}
}









void MainWindow::on_comboBox_activated(const QString &arg1)
{
     if(arg1=="ID")
     ui->tableView->setModel(client.tri());
     else if (arg1=="Nom")

 ui->tableView->setModel(client.tri_nom());
     else if (arg1=="Prenom")

ui->tableView->setModel(client.tri_prenom());
}







