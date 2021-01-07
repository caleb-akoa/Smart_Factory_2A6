#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include<revenues.h>
#include<smtp.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView_Revenues->setModel(rev.afficherRevenues());
    QString NomProduit = ui->lineEdit_RechRevN->text();
    ui->tableView_RechRev->setModel(rev.chercherRevenuesN(NomProduit));
    int ID_Revenue = ui->lineEdit_RechRevIDR->text().toInt();
    ui->tableView_RechRev->setModel(rev.chercherRevenues(ID_Revenue));
    ui->tableView_Factures->setModel(fac.afficherFactures());
    int ID_Client = ui->lineEdit_RechRevIDC->text().toInt();
    ui->tableView_RechRev->setModel(rev.chercherRevenuesC(ID_Client));
    int ID_Facture = ui->lineEdit_RechFacIDF->text().toInt();
    ui->tableView_RechFactures->setModel(fac.chercherFactures(ID_Facture));
    QString Designation = ui->lineEdit_RechFacIDF->text();
    ui->tableView_RechFactures->setModel(fac.chercherFacturesN(Designation));
    QString NomFournisseur = ui->lineEdit_RechFacIDF->text();
    ui->tableView_RechFactures->setModel(fac.chercherFacturesC(NomFournisseur));
    ui->comboBox_mailEmploye->setModel(e.afficher_email());
    ui->mail_client->setModel(client.afficher_mail_client());


    ////////////////Arduino
    ///
    int ret=arduinow.connect_arduino();
         switch(ret){
         case(0):qDebug()<< "arduino is availble and connected to :"<< arduinow.getarduino_port_name();
             break;
         case(1):qDebug()<< "arduino is availble but not connected to :"<< arduinow.getarduino_port_name();
             break;
         case(-1):qDebug()<< "arduino is not availble";
         }
         QObject::connect(arduinow.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));



    /*statistique Rania*/
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from machine where prix <500 ");
    float prixx=model->rowCount();
    model->setQuery("select * from machine where prix between 700 and 800 ");
    float prixxx=model->rowCount();
    model->setQuery("select * from machine where prix >850 ");
    float prixxxx=model->rowCount();
    float total=prixx+prixxx+prixxxx;
    QString a=QString("machine moins de 500 prix"+ QString::number((prixx*100)/total,'f',2)+"%");
    QString b=QString("machine entre 700 et 800 prix"+ QString::number((prixxx*100)/total,'f',2)+"%");
    QString c=QString("machine plus de 850 prix"+ QString::number((prixxxx*100)/total,'f',2)+"%");
    QPieSeries *series = new QPieSeries();
    series->append(a,prixx);
    series->append(b,prixxx);
    series->append(c,prixxxx);
    if (prixx!=0)
    {
        QPieSlice *slice = series->slices().at(0);
        slice->setLabelVisible();
        slice->setPen(QPen());
    }
    if (prixxx!=0)
    {
        QPieSlice *slice1 = series->slices().at(1);
        slice1->setLabelVisible();
        //slice1->setPen(QPen());
    }
    if (prixxxx!=0)
    {
        QPieSlice *slice2 = series->slices().at(2);
        slice2->setLabelVisible();
        //slice1->setPen(QPen());
    }
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Le Prix Des Machines");
    QChartView *chartview = new QChartView(chart);
    chartview->setParent(ui->horizontalFrame);

    /*statistique Zied*/

    QSqlQueryModel * modelz= new QSqlQueryModel();
    modelz->setQuery("select * from FACTURE where VALEUR <20 ");
    float valeurss=modelz->rowCount();
    modelz->setQuery("select * from FACTURE where VALEUR between 50 and 90 ");
    float valeursss=modelz->rowCount();
    modelz->setQuery("select * from FACTURE where VALEUR >90 ");
    float valeurssss=modelz->rowCount();
    float totale=valeurss+valeursss+valeurssss;
    QString aa=QString("FACTURE moins de 50 VALEUR"+ QString::number((valeurss*100)/totale,'f',2)+"%");
    QString bb=QString("FACTURE entre 50 et 90 VALEUR"+ QString::number((valeursss*100)/totale,'f',2)+"%");
    QString cc=QString("FACTURE plus de 90 VALEUR"+ QString::number((valeurssss*100)/totale,'f',2)+"%");
    QPieSeries *seriess = new QPieSeries();
    seriess->append(aa,prixx);
    seriess->append(bb,prixxx);
    seriess->append(cc,prixxxx);
    if (prixx!=0)
    {
        QPieSlice *slice = seriess->slices().at(0);
        slice->setLabelVisible();
        slice->setPen(QPen());
    }
    if (prixxx!=0)
    {
        QPieSlice *slice1 = seriess->slices().at(1);
        slice1->setLabelVisible();
        slice1->setPen(QPen());
    }
    if (prixxxx!=0)
    {
        QPieSlice *slice2 = seriess->slices().at(2);
        slice2->setLabelVisible();
        slice2->setPen(QPen());
    }

/*statistique Wajih*/
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

        ui->mail_client->setModel(client.afficher_mail_client());
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


/*                                           commande                                                                       */
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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



void MainWindow::on_comboBox_activated(const QString &arg1)// tri combobox
{
    if(arg1=="ID")
        ui->tableView->setModel(client.tri());
    else if (arg1=="Nom")

        ui->tableView->setModel(client.tri_nom());
    else if (arg1=="Prenom")

        ui->tableView->setModel(client.tri_prenom());
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//    RANIA !!


void MainWindow::on_pushButton_ajouterEmploye_3_clicked()
{
    QString nom= ui->lineEdit_nom->text();
    QString prenom= ui->lineEdit_prenom->text();
    int idEmploye= ui->lineEdit_identifiant->text().toInt();
    QString naissance= ui->dateEdit_naissance->text();
    QString poste= ui->lineEdit_poste->text();
    int salaire= ui->lineEdit_salaire->text().toInt();
    int telephone= ui->lineEdit_telephone->text().toInt();
    QString mail= ui->lineEdit_mail->text();
    QString domicile= ui->lineEdit_domicile->text();
    int cin= ui->lineEdit_cin->text().toInt();
    QString sexe= ui->lineEdit_sexe->text();

    employe e(nom,prenom,idEmploye,naissance,poste,salaire,telephone,mail,domicile,cin,sexe);

    if (nom!=NULL && prenom!=NULL && idEmploye!=NULL && naissance!=NULL && poste!=NULL && salaire!=NULL && telephone!=NULL && mail!=NULL && domicile!=NULL && sexe!=NULL)
    {
        bool test=e.ajouterEmploye();
        if (test)
        {ui->comboBox_mailEmploye->setModel(e.afficher_email());
            ui->tabEmploye->setModel(e.afficherEmploye());
            QMessageBox::information(nullptr, QObject::tr("ok"),
                                     QObject::tr("Ajout Employe effectue \n"
                                                 "click cancel to exit."), QMessageBox::Cancel);
            ui->lineEdit_nom->clear();
            ui->lineEdit_prenom->clear();
            ui->lineEdit_identifiant->clear();
            ui->dateEdit_naissance->clear();
            ui->lineEdit_poste->clear();
            ui->lineEdit_salaire->clear();
            ui->lineEdit_telephone->clear();
            ui->lineEdit_mail->clear();
            ui->lineEdit_domicile->clear();
            ui->lineEdit_cin->clear();
            ui->lineEdit_sexe->clear();
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("ok"),
                                  QObject::tr("Ajout Employe non effectue \n"
                                              "click cancel to exit."), QMessageBox::Cancel);
        }
    }
    else
    {
        QMessageBox::warning(this,"echec","Remplissez tous les champs!");
    }
}


void MainWindow::on_pushButton_modifierEmploye_4_clicked()
{
    QString nom=ui->lineEdit_nom_2->text();
    QString prenom=ui->lineEdit_prenom_2->text();
    QString idEmploye= ui->lineEdit_identifiant_2->text();
    QString naissance= ui->dateEdit_naissance_2->text();
    QString poste= ui->lineEdit_poste_2->text();
    QString salaire= ui->lineEdit_salaire_2->text();
    QString telephone= ui->lineEdit_telephone_2->text();
    QString mail= ui->lineEdit_mail_2->text();
    QString domicile= ui->lineEdit_domicile_2->text();
    QString cin= ui->lineEdit_cin_2->text();
    QString sexe= ui->lineEdit_sexe_2->text();

    e.SetNom(nom);
    e.SetPrenom(prenom);
    e.SetIdentifiant(idEmploye.toInt());
    e.SetNaissance(naissance);
    e.SetPoste(poste);
    e.SetSalaire(salaire.toInt());
    e.SetTelephone(telephone.toInt());
    e.SetMail(mail);
    e.SetDomicile(domicile);
    e.SetCin(cin.toInt());
    e.SetSexe(sexe);

    // employe e(nom,prenom,idEmploye,naissance,poste,salaire,telephone,mail,domicile,cin,sexe);

    bool test=e.modifierEmploye();
    if(test)
    {
        ui->tabEmploye->setModel(e.afficherEmploye());
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("modification Employe effectuee \n"
                                             "click cancel to exit."), QMessageBox::Cancel);
        ui->lineEdit_nom_2->clear();
        ui->lineEdit_prenom_2->clear();
        ui->lineEdit_identifiant_2->clear();
        ui->dateEdit_naissance_2->clear();
        ui->lineEdit_poste_2->clear();
        ui->lineEdit_salaire_2->clear();
        ui->lineEdit_telephone_2->clear();
        ui->lineEdit_mail_2->clear();
        ui->lineEdit_domicile_2->clear();
        ui->lineEdit_cin_2->clear();
        ui->lineEdit_sexe_2->clear();
        ui->lineEdit_idModifierE->clear();
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("ok"),
                              QObject::tr("modification Employe non effectue \n"
                                          "click cancel to exit."), QMessageBox::Cancel);
    }

}


void MainWindow::on_pushButton_rechercherME_clicked()
{
    QString idEmploye= ui->lineEdit_idModifierE->text();
    e.SetIdentifiant(idEmploye.toInt());

    //    bool test =e.verifEmploye();
    if(e.verifEmploye()==0)
    {
        if (e.rechercherEmploye())
        {
            QSqlQuery query;

            QString id=QString::number((e.GetIdentifiant()));
            QString sl=QString::number(e.GetSalaire());
            QString cn=QString::number(e.GetCin());
            QString tel=QString::number(e.GetTelephone());

            ui->lineEdit_nom_2->setText(e.GetNom());
            ui->lineEdit_prenom_2->setText(e.GetPrenom());
            ui->lineEdit_identifiant_2->setText(id);
            ui->dateEdit_naissance_2->setDate(QDate::fromString(e.GetNaissance(),"dd/MM/yyyy"));
            ui->lineEdit_poste_2->setText(e.GetPoste());
            ui->lineEdit_salaire_2->setText(sl);
            ui->lineEdit_telephone_2->setText(tel);
            ui->lineEdit_mail_2->setText(e.GetMail());
            ui->lineEdit_domicile_2->setText(e.GetDomicile());
            ui->lineEdit_cin_2->setText(cn);
            ui->lineEdit_sexe_2->setText(e.GetSexe());

            //            QMessageBox::information(nullptr, QObject::tr("ok"),
            //                                     QObject::tr("Employe existe \n"
            //                                                 "click cancel to exit."), QMessageBox::Cancel);
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("ok"),
                                  QObject::tr("Employe n'existe pas \n"
                                              "click cancel to exit."), QMessageBox::Cancel);
            ui->lineEdit_idModifierE->clear();
        }
    }
    else
    {
        QMessageBox::warning(this,"echec","Employe n'existe pas!");
    }
}

void MainWindow::on_pushButton_triEmploye_clicked()
{
    QString test = ui->comboBox_tri->currentText();
    if(test == "Nom")
    {
        ui->tabEmploye->setModel(e.trierEmployeParNom());
    }
    else if(test =="Identifiant")
    {
        ui->tabEmploye->setModel(e.trierEmployeParID());
    }
    else if(test == "Cin")
    {
        ui->tabEmploye->setModel(e.trierEmployeParCin());
    }
}



void MainWindow::on_pushButton_rechercherSE_clicked()
{
    QString idS=ui->lineEdit_idSupprimerE->text();
    e.SetIdentifiant(idS.toInt());

    if(e.verifEmploye()==0)
    {
        //        QMessageBox::information(nullptr, QObject::tr("ok"),
        //                                 QObject::tr("l'identifiant existe \n"
        //                                             "click cancel to exit."), QMessageBox::Cancel);

        ui->lineEdit_nom_5->show();
        ui->lineEdit_prenom_3->show();
        ui->lineEdit_identifiant_3->show();
        ui->dateEdit_naissance_3->show();
        ui->lineEdit_poste_3->show();
        ui->lineEdit_salaire_3->show();
        ui->lineEdit_telephone_3->show();
        ui->lineEdit_mail_3->show();
        ui->lineEdit_domicile_3->show();
        ui->lineEdit_cin_3->show();
        ui->lineEdit_sexe_3->show();
        ui->pushButton_supprimerE->show();

        QString id=QString::number((e.GetIdentifiant()));
        QString sl=QString::number(e.GetSalaire());
        QString cn=QString::number(e.GetCin());
        QString tel=QString::number(e.GetTelephone());
        ui->lineEdit_nom_5->setText(e.GetNom());
        ui->lineEdit_prenom_3->setText(e.GetPrenom());
        ui->lineEdit_identifiant_3->setText(id);
        ui->dateEdit_naissance_3->setDate(QDate::fromString(e.GetNaissance(),"dd/MM/yyyy"));
        ui->lineEdit_poste_3->setText(e.GetPoste());
        ui->lineEdit_salaire_3->setText(sl);
        ui->lineEdit_telephone_3->setText(tel);
        ui->lineEdit_mail_3->setText(e.GetMail());
        ui->lineEdit_domicile_3->setText(e.GetDomicile());
        ui->lineEdit_cin_3->setText(cn);
        ui->lineEdit_sexe_3->setText(e.GetSexe());


    }
    else
    {
        QMessageBox::warning(this,"echec","Employe n'existe pas!");
    }
}

void MainWindow::on_pushButton_supprimerE_clicked()
{
    bool test= e.supprimerEmploye();

    if (test)
    {
        //refresh
        ui->tabEmploye->setModel(e.afficherEmploye());

        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("suppression Employe effectuee \n"
                                             "click cancel to exit."), QMessageBox::Cancel);
        ui->lineEdit_nom_5->clear();
        ui->lineEdit_prenom_3->clear();
        ui->lineEdit_identifiant_3->clear();
        ui->dateEdit_naissance_3->clear();
        ui->lineEdit_poste_3->clear();
        ui->lineEdit_salaire_3->clear();
        ui->lineEdit_telephone_3->clear();
        ui->lineEdit_mail_3->clear();
        ui->lineEdit_domicile_3->clear();
        ui->lineEdit_cin_3->clear();
        ui->lineEdit_sexe_3->clear();
        ui->lineEdit_idSupprimerE->clear();

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("ok"),
                              QObject::tr("suppression Employe non effectue \n"
                                          "click cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_chercherEmploye_clicked()
{
    QString idEmploye= ui->lineEdit_chercherIdentifiant->text();
    e.SetIdentifiant(idEmploye.toInt());

    if (e.verifEmploye()==0)
    {
        if (e.rechercherEmploye())
        {
            ui->lineEdit_nom_7->show();
            ui->lineEdit_prenom_4->show();
            ui->lineEdit_identifiant_4->show();
            ui->dateEdit_naissance_4->show();
            ui->lineEdit_poste_4->show();
            ui->lineEdit_salaire_4->show();
            ui->lineEdit_telephone_4->show();
            ui->lineEdit_mail_4->show();
            ui->lineEdit_domicile_4->show();
            ui->lineEdit_cin_4->show();
            ui->lineEdit_sexe_4->show();

            QSqlQuery query;

            QString id=QString::number(e.GetIdentifiant());
            QString sl=QString::number(e.GetSalaire());
            QString cn=QString::number(e.GetCin());
            QString tel=QString::number(e.GetTelephone());

            ui->lineEdit_nom_7->setText(e.GetNom());
            ui->lineEdit_prenom_4->setText(e.GetPrenom());
            ui->lineEdit_identifiant_4->setText(id);
            ui->dateEdit_naissance_4->setDate(QDate::fromString(e.GetNaissance(),"dd/MM/yyyy"));
            ui->lineEdit_poste_4->setText(e.GetPoste());
            ui->lineEdit_salaire_4->setText(sl);
            ui->lineEdit_telephone_4->setText(tel);
            ui->lineEdit_mail_4->setText(e.GetMail());
            ui->lineEdit_domicile_4->setText(e.GetDomicile());
            ui->lineEdit_cin_4->setText(cn);
            ui->lineEdit_sexe_4->setText(e.GetSexe());
            QMessageBox::information(nullptr, QObject::tr("ok"),
                                     QObject::tr("Employe trouve par identifiant \n"
                                                 "click cancel to exit."), QMessageBox::Cancel);
            ui->lineEdit_nom_7->clear();
            ui->lineEdit_prenom_4->clear();
            ui->lineEdit_identifiant_4->clear();
            ui->dateEdit_naissance_4->clear();
            ui->lineEdit_poste_4->clear();
            ui->lineEdit_salaire_4->clear();
            ui->lineEdit_telephone_4->clear();
            ui->lineEdit_mail_4->clear();
            ui->lineEdit_domicile_4->clear();
            ui->lineEdit_cin_4->clear();
            ui->lineEdit_sexe_4->clear();
            ui->lineEdit_chercherIdentifiant->clear();
            ui->lineEdit_chercherNom->clear();
            ui->lineEdit_chercherCIN->clear();

        }
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("ok"),
                              QObject::tr("Employe non trouve \n"
                                          "click cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_chercherEmploye_2_clicked()
{
    QString nom= ui->lineEdit_chercherNom->text();
    e.SetNom(nom);

    if (e.verifEmployeParNom()==0)
    {
        if (e.chercherParNom())
        {
            ui->lineEdit_nom_7->show();
            ui->lineEdit_prenom_4->show();
            ui->lineEdit_identifiant_4->show();
            ui->dateEdit_naissance_4->show();
            ui->lineEdit_poste_4->show();
            ui->lineEdit_salaire_4->show();
            ui->lineEdit_telephone_4->show();
            ui->lineEdit_mail_4->show();
            ui->lineEdit_domicile_4->show();
            ui->lineEdit_cin_4->show();
            ui->lineEdit_sexe_4->show();

            QSqlQuery query;

            QString id=QString::number(e.GetIdentifiant());
            QString sl=QString::number(e.GetSalaire());
            QString cn=QString::number(e.GetCin());
            QString tel=QString::number(e.GetTelephone());

            ui->lineEdit_nom_7->setText(e.GetNom());
            ui->lineEdit_prenom_4->setText(e.GetPrenom());
            ui->lineEdit_identifiant_4->setText(id);
            ui->dateEdit_naissance_4->setDate(QDate::fromString(e.GetNaissance(),"dd/MM/yyyy"));
            ui->lineEdit_poste_4->setText(e.GetPoste());
            ui->lineEdit_salaire_4->setText(sl);
            ui->lineEdit_telephone_4->setText(tel);
            ui->lineEdit_mail_4->setText(e.GetMail());
            ui->lineEdit_domicile_4->setText(e.GetDomicile());
            ui->lineEdit_cin_4->setText(cn);
            ui->lineEdit_sexe_4->setText(e.GetSexe());
            QMessageBox::information(nullptr, QObject::tr("ok"),
                                     QObject::tr("Employe trouve par nom \n"
                                                 "click cancel to exit."), QMessageBox::Cancel);
            ui->lineEdit_nom_7->clear();
            ui->lineEdit_prenom_4->clear();
            ui->lineEdit_identifiant_4->clear();
            ui->dateEdit_naissance_4->clear();
            ui->lineEdit_poste_4->clear();
            ui->lineEdit_salaire_4->clear();
            ui->lineEdit_telephone_4->clear();
            ui->lineEdit_mail_4->clear();
            ui->lineEdit_domicile_4->clear();
            ui->lineEdit_cin_4->clear();
            ui->lineEdit_sexe_4->clear();
            ui->lineEdit_chercherNom->clear();
            ui->lineEdit_chercherIdentifiant->clear();
            ui->lineEdit_chercherCIN->clear();

        }
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("ok"),
                              QObject::tr("Employe non trouve \n"
                                          "click cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_chercherEmploye_3_clicked()
{
    QString cin= ui->lineEdit_chercherCIN->text();
    e.SetCin(cin.toInt());

    if (e.verifEmployeParCin()==0)
    {
        if (e.chercherParCin())
        {
            ui->lineEdit_nom_7->show();
            ui->lineEdit_prenom_4->show();
            ui->lineEdit_identifiant_4->show();
            ui->dateEdit_naissance_4->show();
            ui->lineEdit_poste_4->show();
            ui->lineEdit_salaire_4->show();
            ui->lineEdit_telephone_4->show();
            ui->lineEdit_mail_4->show();
            ui->lineEdit_domicile_4->show();
            ui->lineEdit_cin_4->show();
            ui->lineEdit_sexe_4->show();

            QSqlQuery query;

            QString id=QString::number(e.GetIdentifiant());
            QString sl=QString::number(e.GetSalaire());
            QString cn=QString::number(e.GetCin());
            QString tel=QString::number(e.GetTelephone());

            ui->lineEdit_nom_7->setText(e.GetNom());
            ui->lineEdit_prenom_4->setText(e.GetPrenom());
            ui->lineEdit_identifiant_4->setText(id);
            ui->dateEdit_naissance_4->setDate(QDate::fromString(e.GetNaissance(),"dd/MM/yyyy"));
            ui->lineEdit_poste_4->setText(e.GetPoste());
            ui->lineEdit_salaire_4->setText(sl);
            ui->lineEdit_telephone_4->setText(tel);
            ui->lineEdit_mail_4->setText(e.GetMail());
            ui->lineEdit_domicile_4->setText(e.GetDomicile());
            ui->lineEdit_cin_4->setText(cn);
            ui->lineEdit_sexe_4->setText(e.GetSexe());
            QMessageBox::information(nullptr, QObject::tr("ok"),
                                     QObject::tr("Employe trouve par cin \n"
                                                 "click cancel to exit."), QMessageBox::Cancel);
            ui->lineEdit_nom_7->clear();
            ui->lineEdit_prenom_4->clear();
            ui->lineEdit_identifiant_4->clear();
            ui->dateEdit_naissance_4->clear();
            ui->lineEdit_poste_4->clear();
            ui->lineEdit_salaire_4->clear();
            ui->lineEdit_telephone_4->clear();
            ui->lineEdit_mail_4->clear();
            ui->lineEdit_domicile_4->clear();
            ui->lineEdit_cin_4->clear();
            ui->lineEdit_sexe_4->clear();
            ui->lineEdit_chercherIdentifiant->clear();
            ui->lineEdit_chercherNom->clear();
            ui->lineEdit_chercherCIN->clear();

        }
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("ok"),
                              QObject::tr("Employe non trouve \n"
                                          "click cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_ajouterMachine_3_clicked()
{
    int idMachine= ui->lineEdit_idMachine->text().toInt();
    float prix= ui->lineEdit_prix->text().toFloat();
    QString nom= ui->lineEdit_nom_3->text();
    QString reference= ui->lineEdit_reference->text();
    QString categorie= ui->lineEdit_categorie->text();

    machine m(idMachine, prix, nom, reference, categorie);

    if (idMachine!=NULL && prix!=NULL && nom!=NULL && reference!=NULL && categorie!=NULL)
    {
        bool test=m.ajouterMachine();
        if (test)
        {
            //refresh
            ui->tabMachine->setModel(m.afficherMachine());
            QMessageBox::information(nullptr, QObject::tr("ok"),
                                     QObject::tr("Ajout Machine effectue \n"
                                                 "click cancel to exit."), QMessageBox::Cancel);
            ui->lineEdit_idMachine->clear();
            ui->lineEdit_prix->clear();
            ui->lineEdit_nom_3->clear();
            ui->lineEdit_reference->clear();
            ui->lineEdit_categorie->clear();
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("not ok"),
                                  QObject::tr("Ajout Machine non effectue \n"
                                              "click cancel to exit."), QMessageBox::Cancel);
        }
    }
    else
    {
        QMessageBox::warning(this, "echec","Remplissez tous les champs!");
    }
}

void MainWindow::on_pushButton_chercherMachine_8_clicked()
{
    QString idMachine= ui->lineEdit_chercherID->text();
    m.SetIdMachine(idMachine.toInt());

    if (m.verifMachine()==0)
    {
        if (m.rechercherModifierMachine())
        {
            ui->lineEdit_idMachine_3->show();
            ui->lineEdit_prix_4->show();
            ui->lineEdit_nom_8->show();
            ui->lineEdit_reference_4->show();
            ui->lineEdit_categorie_4->show();

            QSqlQuery query;

            QString id=QString::number(m.GetIdMachine());
            QString pr=QString::number(m.GetPrix());

            ui->lineEdit_idMachine_3->setText(id);
            ui->lineEdit_prix_4->setText(pr);
            ui->lineEdit_nom_8->setText(m.GetNom());
            ui->lineEdit_reference_4->setText(m.GetReference());
            ui->lineEdit_categorie_4->setText(m.GetCategorie());
            QMessageBox::information(nullptr, QObject::tr("ok"),
                                     QObject::tr("Machine trouve par identifiant \n"
                                                 "click cancel to exit."), QMessageBox::Cancel);
            ui->lineEdit_idMachine_3->clear();
            ui->lineEdit_prix_4->clear();
            ui->lineEdit_nom_8->clear();
            ui->lineEdit_reference_4->clear();
            ui->lineEdit_categorie_4->clear();
            ui->lineEdit_chercherID->clear();
            ui->lineEdit_chercherNom_2->clear();
            ui->lineEdit_chercherReference->clear();
        }
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("ok"),
                              QObject::tr("Machine non trouve \n"
                                          "click cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_chercherMachine_9_clicked()
{
    QString nom= ui->lineEdit_chercherNom_2->text();
    m.SetNom(nom);

    if (m.verifMachineParNom()==0)
    {
        if (m.chercherParNom())
        {
            ui->lineEdit_idMachine_3->show();
            ui->lineEdit_prix_4->show();
            ui->lineEdit_nom_8->show();
            ui->lineEdit_reference_4->show();
            ui->lineEdit_categorie_4->show();

            QSqlQuery query;

            QString id=QString::number(m.GetIdMachine());
            QString pr=QString::number(m.GetPrix());

            ui->lineEdit_idMachine_3->setText(id);
            ui->lineEdit_prix_4->setText(pr);
            ui->lineEdit_nom_8->setText(m.GetNom());
            ui->lineEdit_reference_4->setText(m.GetReference());
            ui->lineEdit_categorie_4->setText(m.GetCategorie());
            QMessageBox::information(nullptr, QObject::tr("ok"),
                                     QObject::tr("Machine trouve par nom \n"
                                                 "click cancel to exit."), QMessageBox::Cancel);
            ui->lineEdit_idMachine_3->clear();
            ui->lineEdit_prix_4->clear();
            ui->lineEdit_nom_8->clear();
            ui->lineEdit_reference_4->clear();
            ui->lineEdit_categorie_4->clear();
            ui->lineEdit_chercherID->clear();
            ui->lineEdit_chercherID->clear();
            ui->lineEdit_chercherNom_2->clear();
            ui->lineEdit_chercherReference->clear();
        }
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("ok"),
                              QObject::tr("Machine non trouve \n"
                                          "click cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_chercherMachine_10_clicked()
{
    QString reference= ui->lineEdit_chercherReference->text();
    m.SetReference(reference);

    if (m.verifMachineParReference()==0)
    {
        if (m.chercherParReference())
        {
            ui->lineEdit_idMachine_3->show();
            ui->lineEdit_prix_4->show();
            ui->lineEdit_nom_8->show();
            ui->lineEdit_reference_4->show();
            ui->lineEdit_categorie_4->show();

            QSqlQuery query;

            QString id=QString::number(m.GetIdMachine());
            QString pr=QString::number(m.GetPrix());

            ui->lineEdit_idMachine_3->setText(id);
            ui->lineEdit_prix_4->setText(pr);
            ui->lineEdit_nom_8->setText(m.GetNom());
            ui->lineEdit_reference_4->setText(m.GetReference());
            ui->lineEdit_categorie_4->setText(m.GetCategorie());
            QMessageBox::information(nullptr, QObject::tr("ok"),
                                     QObject::tr("Machine trouve par reference \n"
                                                 "click cancel to exit."), QMessageBox::Cancel);
            ui->lineEdit_idMachine_3->clear();
            ui->lineEdit_prix_4->clear();
            ui->lineEdit_nom_8->clear();
            ui->lineEdit_reference_4->clear();
            ui->lineEdit_categorie_4->clear();
            ui->lineEdit_chercherID->clear();
            ui->lineEdit_chercherID->clear();
            ui->lineEdit_chercherNom_2->clear();
            ui->lineEdit_chercherReference->clear();

        }
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("ok"),
                              QObject::tr("Machine non trouve \n"
                                          "click cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_tabWidget_9_currentChanged(int index)
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
    chart->setTitle("Rendement de Machines");
    QChartView *chartview=new QChartView(chart);
    chartview->setRenderHint(QPainter::Antialiasing);
    chartview->setParent(ui->horizontalFrame1);
}

void MainWindow::on_tabWidget_9_tabBarClicked(int index)
{
    QPieSeries *series =new QPieSeries();
    series->append("Decembre",80);
    series->append("Novembre",70);
    series->append("Janvier",50);
    series->append("Octobre",40);
    series->append("Septembre",30);

    QPieSlice *slice = series->slices().at(1);
    slice->setExploded(true);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Le Rendement Des Machines Pendant l'Hiver");

    QChartView *chartview = new QChartView(chart);
    chartview->setParent(ui->horizontalFrame);
}

void MainWindow::on_pushButton_rechercherSM_clicked()
{
    QString ids=ui->lineEdit_idSupprimerM->text();
    m.SetIdMachine(ids.toInt());

    if(m.verifMachine()==0)
    {
        ui->lineEdit_idMachine_2->show();
        ui->lineEdit_prix_3->show();
        ui->lineEdit_nom_6->show();
        ui->lineEdit_reference_3->show();
        ui->lineEdit_categorie_3->show();
        ui->pushButton_supprimerM->show();

        QString id=QString::number(m.GetIdMachine());
        QString pr=QString::number(m.GetPrix());

        ui->lineEdit_idMachine_2->setText(id);
        ui->lineEdit_prix_3->setText(pr);
        ui->lineEdit_nom_6->setText(m.GetNom());
        ui->lineEdit_reference_3->setText(m.GetReference());
        ui->lineEdit_categorie_3->setText(m.GetCategorie());
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("ok"),
                              QObject::tr("l'identifiant n'existe pas \n"
                                          "click cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_supprimerM_clicked()
{
    bool test=m.supprimerMachine();

    if (test)
    {
        //refresh
        ui->tabMachine->setModel(m.afficherMachine());
        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("suppression Machine effectuee \n"
                                             "click cancel to exit."), QMessageBox::Cancel);
        ui->lineEdit_idMachine_2->clear();
        ui->lineEdit_prix_3->clear();
        ui->lineEdit_nom_6->clear();
        ui->lineEdit_reference_3->clear();
        ui->lineEdit_categorie_3->clear();
        ui->lineEdit_idSupprimerM->clear();
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("ok"),
                              QObject::tr("suppression Machine non effectue \n"
                                          "click cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_triMachine_clicked()
{
    QString test = ui->comboBox_triMachine->currentText();
    if(test == "Identifiant")
    {
        ui->tabMachine->setModel(m.trierMachineParID());
    }
    else if(test =="Nom")
    {
        ui->tabMachine->setModel(m.trierMachineParNom());
    }
    else if(test == "Reference")
    {
        ui->tabMachine->setModel(m.trierMachineParReference());
    }
}

void MainWindow::on_pushButton_rechercherModM_clicked()
{
    QString idMachine= ui->lineEdit_idModifierM->text();
    m.SetIdMachine(idMachine.toInt());

    if(m.verifMachine()==0)
    {
        if(m.rechercherModifierMachine())
        {
            QString id=QString::number(m.GetIdMachine());
            QString pr=QString::number(m.GetPrix());

            ui->lineEdit_id_2->setText(id);
            ui->lineEdit_prix_2->setText(pr);
            ui->lineEdit_nom_4->setText(m.GetNom());
            ui->lineEdit_reference_2->setText(m.GetReference());
            ui->lineEdit_categorie_2->setText(m.GetCategorie());

            //            QMessageBox::information(nullptr, QObject::tr("ok"),
            //                                     QObject::tr("Machine existe \n"
            //                                                 "click cancel to exit."), QMessageBox::Cancel);
        }
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                              QObject::tr("Machine n'existe pas \n"
                                          "click cancel to exit."), QMessageBox::Cancel);
        ui->lineEdit_idModifierM->clear();
    }
}

void MainWindow::on_pushButton_modifierMachine_4_clicked()
{
    QString idMachine= ui->lineEdit_id_2->text();
    QString prix=ui->lineEdit_prix_2->text();
    QString nom=ui->lineEdit_nom_4->text();
    QString reference=ui->lineEdit_reference_2->text();
    QString categorie=ui->lineEdit_categorie_2->text();

    m.SetIdMachine(idMachine.toInt());
    m.SetPrix(prix.toInt());
    m.SetNom(nom);
    m.SetReference(reference);
    m.SetCategorie(categorie);


    bool test=m.modifierMachine();
    if (test)
    {
        //refresh
        ui->tabMachine->setModel(m.afficherMachine());

        QMessageBox::information(nullptr, QObject::tr("ok"),
                                 QObject::tr("modification Machine effectue \n"
                                             "click cancel to exit."), QMessageBox::Cancel);

        ui->lineEdit_id_2->clear();
        ui->lineEdit_prix_2->clear();
        ui->lineEdit_nom_4->clear();
        ui->lineEdit_reference_2->clear();
        ui->lineEdit_categorie_2->clear();
        ui->lineEdit_idModifierM->clear();
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("not ok"),
                              QObject::tr("modification Machine non effectue \n"
                                          "click cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_ajouter_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
    ui->tabWidget_8->setCurrentIndex(0);
}

void MainWindow::on_ValidezRevenues_clicked() //AFFICHER REVENUES
{

    //if (verifNomProduits())
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

void MainWindow::on_Validez_Mod_Rev_clicked() //MODIFIER REVENUES
{
    int ID_Revenue=ui->lineEdit_22->text().toInt();
    QString NomProduit=ui->lineEdit_13->text();
    int QuantiteVendue=ui->lineEdit_14->text().toInt();
    int ValeursUnitaire=ui->lineEdit_15->text().toInt();
    int ID_Client=ui->lineEdit_12->text().toInt();
    QString DateVente=ui->dateEditRev->text();

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

void MainWindow::on_pushButton_SupprimerRevenues_clicked() //SUPPRIMER REVENUES
{
    int ID_Revenue=ui->lineEdit_SID_Revenue->text().toInt();


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



void MainWindow::on_pushButton_RechRevN_clicked()
{
    QString NomProduit = ui->lineEdit_RechRevN->text();
    ui->tableView_RechRev->setModel(rev.chercherRevenuesN(NomProduit));
}

void MainWindow::on_pushButton_RechRevIDR_clicked()
{
    int ID_Revenue = ui->lineEdit_RechRevIDR->text().toInt();
    ui->tableView_RechRev->setModel(rev.chercherRevenues(ID_Revenue));
}

void MainWindow::on_pushButton_RechRevIDC_clicked()
{
    int ID_Client = ui->lineEdit_RechRevIDC->text().toInt();
    ui->tableView_RechRev->setModel(rev.chercherRevenuesC(ID_Client));
}

void MainWindow::on_pushButton_AjouterFacture_clicked()
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


void MainWindow::on_pushButton_ModifierFacture_clicked()
{
    int ID_Facture=ui->lineEdit_ModRefFac->text().toInt();
    QString NomFournisseur=ui->lineEdit_ModNomF->text();
    QString Designation=ui->lineEdit_ModType->text();
    int Valeur=ui->lineEdit_ModVal->text().toInt();


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

void MainWindow::on_pushButton_TrierNom_clicked()
{
    ui->tableView_TrierFactures->setModel(fac.trierFacturesOrdre());
}

void MainWindow::on_pushButton_TrierDesignation_clicked()
{
    ui->tableView_TrierFactures->setModel(fac.trierFacturesOrdreD());
}

void MainWindow::on_pushButton_42_clicked()
{
    ui->tableView_TrierFactures->setModel(fac.trierFacturesQuantite());
}

void MainWindow::on_pushButton_30_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_pushButton_29_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}

void MainWindow::on_pushButton_56_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}

void MainWindow::on_pushButton_64_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}

void MainWindow::on_pushButton_91_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}

void MainWindow::on_pushButton_109_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}

void MainWindow::on_pushButton_151_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}

void MainWindow::on_pushButton_57_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_pushButton_65_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_pushButton_92_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_pushButton_110_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_pushButton_162_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_retour_28_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_retour_27_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_retour_51_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_retour_50_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_retour_26_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_retour_33_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}

void MainWindow::on_retour_32_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}

void MainWindow::on_retour_31_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}

void MainWindow::on_retour_53_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}

void MainWindow::on_retour_52_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}

void MainWindow::on_retour_30_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}

void MainWindow::on_pushButton_RechFactIDF_clicked()
{
    int ID_Facture = ui->lineEdit_RechFacIDF->text().toInt();
    ui->tableView_RechFactures->setModel(fac.chercherFactures(ID_Facture));
}

void MainWindow::on_pushButton_RechFacD_clicked()
{
    QString Designation = ui->lineEdit_RechFacIDF->text();
    ui->tableView_RechFactures->setModel(fac.chercherFacturesN(Designation));
}

void MainWindow::on_pushButton_RechFacN_clicked()
{
    QString NomFournisseur = ui->lineEdit_RechFacN->text();
    ui->tableView_RechFactures->setModel(fac.chercherFacturesC(NomFournisseur));
}

void MainWindow::on_pushButton_26_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_27_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_client_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_93_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_client_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_111_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_148_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_149_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_client_10_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_153_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_158_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_159_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_client_11_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_161_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}

void MainWindow::on_pushButton_163_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_61_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_62_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_pushButton_52_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_53_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_pushButton_89_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_pushButton_106_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_ajouter_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
    ui->tabWidget_19->setCurrentIndex(0);
}

void MainWindow::on_modifier_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
    ui->tabWidget_19->setCurrentIndex(1);
}

void MainWindow::on_supprimer_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
    ui->tabWidget_19->setCurrentIndex(2);
}

void MainWindow::on_afficher_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
    ui->tabWidget_19->setCurrentIndex(3);
}

void MainWindow::on_supprimer_10_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
    ui->tabWidget_19->setCurrentIndex(4);
}

void MainWindow::on_ajouter_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(12);
    ui->tabWidget_20->setCurrentIndex(0);
}

void MainWindow::on_modifier_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
    ui->tabWidget_20->setCurrentIndex(1);
}

void MainWindow::on_supprimer_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
    ui->tabWidget_20->setCurrentIndex(2);
}

void MainWindow::on_afficher_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
    ui->tabWidget_20->setCurrentIndex(3);
}

void MainWindow::on_afficher_11_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
    ui->tabWidget_20->setCurrentIndex(4);
}

void MainWindow::on_afficher_10_clicked()
{
    ui->stackedWidget->setCurrentIndex(10);
    ui->tabWidget_20->setCurrentIndex(5);
}

void MainWindow::on_ajouter_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
    ui->tabWidget_7->setCurrentIndex(0);
}

void MainWindow::on_modifier_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
    ui->tabWidget_7->setCurrentIndex(1);
}

void MainWindow::on_supprimer_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
    ui->tabWidget_7->setCurrentIndex(2);
}

void MainWindow::on_afficher_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
    ui->tabWidget_7->setCurrentIndex(3);
}

void MainWindow::on_modifier_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
    ui->tabWidget_8->setCurrentIndex(1);
}

void MainWindow::on_supprimer_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
    ui->tabWidget_8->setCurrentIndex(2);
}

void MainWindow::on_afficher_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);
    ui->tabWidget_8->setCurrentIndex(3);
}

void MainWindow::on_retour_19_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_retour_20_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_retour_21_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_retour_22_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_retour_23_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_retour_24_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}


void MainWindow::on_pushButton_imprimer_clicked()
{
    //QDateTime datecreation = date.currentDateTime();
    //QString afficheDC = "Date de Creation PDF : " + datecreation.toString() ;
    QPdfWriter pdf("C:/Users/wajih/OneDrive/Desktop/rania/Pdf.pdf");
    QPainter painter(&pdf);
    int i = 4000;
    painter.setPen(Qt::blue);
    painter.setFont(QFont("Arial", 30));
    painter.drawText(1100,1200,"Liste des Employes ");
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 50));
    // painter.drawText(1100,2000,afficheDC);
    painter.drawRect(100,100,7300,2600);
    //painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/RH/Desktop/projecpp/image/logopdf.png"));
    painter.drawRect(0,3000,9600,500);
    painter.setFont(QFont("Arial", 9));
    painter.drawText(200,3300,"NOM");
    painter.drawText(1700,3300,"PRENOM");
    painter.drawText(3200,3300,"IDENTIFIANT");
    painter.drawText(4900,3300,"NAISSANCE");
    painter.drawText(6600,3300,"POSTE");
    painter.drawText(8100,3300,"SALAIRE");
    painter.drawText(9600,3300,"TELEPHONE");
    painter.drawText(11100,3300,"MAIL");
    painter.drawText(12600,3300,"DOMICILE");
    painter.drawText(14100,3300,"CIN");
    painter.drawText(15600,3300,"SEXE");
    QSqlQuery query;
    query.prepare("select * from EMPLOYE");
    query.exec();
    while (query.next())
    {
        painter.drawText(200,i,query.value(0).toString());
        painter.drawText(1700,i,query.value(1).toString());
        painter.drawText(3200,i,query.value(2).toString());
        painter.drawText(4900,i,query.value(3).toString());
        painter.drawText(6600,i,query.value(4).toString());
        painter.drawText(8100,i,query.value(5).toString());
        i = i + 500;
    }
    int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
    if (reponse == QMessageBox::Yes)
    {
        QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/wajih/OneDrive/Desktop/rania/Pdf.pdf"));
        painter.end();
    }
    if (reponse == QMessageBox::No)
    {
        painter.end();
    }
}

void MainWindow::on_pushButton_25_clicked()
{
    ui->stackedWidget->setCurrentIndex(19);
}

void MainWindow::on_pushButton_28_clicked()
{
    ui->stackedWidget->setCurrentIndex(17);
}

void MainWindow::on_pushButton_51_clicked()
{
    ui->stackedWidget->setCurrentIndex(19);
}

void MainWindow::on_pushButton_54_clicked()
{ui->stackedWidget->setCurrentIndex(17);

}

void MainWindow::on_pushButton_58_clicked()
{
    ui->stackedWidget->setCurrentIndex(19);
}

void MainWindow::on_pushButton_63_clicked()
{
    ui->stackedWidget->setCurrentIndex(17);
}

void MainWindow::on_pushButton_87_clicked()
{
    ui->stackedWidget->setCurrentIndex(19);
}

void MainWindow::on_pushButton_90_clicked()
{
    ui->stackedWidget->setCurrentIndex(17);
}

void MainWindow::on_pushButton_105_clicked()
{
    ui->stackedWidget->setCurrentIndex(19);
}

void MainWindow::on_pushButton_108_clicked()
{
    ui->stackedWidget->setCurrentIndex(17);
}

void MainWindow::on_pushButton_147_clicked()
{
    ui->stackedWidget->setCurrentIndex(19);
}

void MainWindow::on_pushButton_150_clicked()
{
    ui->stackedWidget->setCurrentIndex(17);
}

void MainWindow::on_pushButton_157_clicked()
{
    ui->stackedWidget->setCurrentIndex(19);
}

void MainWindow::on_pushButton_160_clicked()
{
    ui->stackedWidget->setCurrentIndex(17);
}

void MainWindow::on_pushButton_132_clicked()
{
    ui->stackedWidget->setCurrentIndex(19);
}

void MainWindow::on_pushButton_135_clicked()
{
    ui->stackedWidget->setCurrentIndex(17);
}

void MainWindow::on_pushButton_123_clicked()
{
    ui->stackedWidget->setCurrentIndex(19);
}

void MainWindow::on_pushButton_126_clicked()
{
    ui->stackedWidget->setCurrentIndex(17);
}

void MainWindow::on_pushButton_292_clicked()
{
    ui->stackedWidget->setCurrentIndex(19);
}

void MainWindow::on_pushButton_293_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_294_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_client_23_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_296_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}

void MainWindow::on_pushButton_297_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_pushButton_298_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_303_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}


void MainWindow::on_pushButton_304_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_pushButton_305_clicked()
{
    ui->stackedWidget->setCurrentIndex(17);
}

void MainWindow::on_client_24_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_306_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}

void MainWindow::on_pushButton_307_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_pushButton_308_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_309_clicked()
{
    ui->stackedWidget->setCurrentIndex(15);
}

void MainWindow::on_pushButton_310_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
}

void MainWindow::on_pushButton_94_clicked()
{
    ui->stackedWidget->setCurrentIndex(15);
}

void MainWindow::on_pushButton_95_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
}

void MainWindow::on_pushButton_112_clicked()
{
    ui->stackedWidget->setCurrentIndex(15);
}

void MainWindow::on_pushButton_113_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
}

void MainWindow::on_pushButton_154_clicked()
{
    ui->stackedWidget->setCurrentIndex(15);
}

void MainWindow::on_pushButton_155_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
}

void MainWindow::on_pushButton_164_clicked()
{
    ui->stackedWidget->setCurrentIndex(15);
}

void MainWindow::on_pushButton_165_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
}

void MainWindow::on_pushButton_299_clicked()
{
    ui->stackedWidget->setCurrentIndex(15);
}

void MainWindow::on_pushButton_300_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
}

void MainWindow::on_pushButton_31_clicked()
{
    ui->stackedWidget->setCurrentIndex(15);
}

void MainWindow::on_pushButton_32_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
}

void MainWindow::on_pushButton_67_clicked()
{
    ui->stackedWidget->setCurrentIndex(15);
}

void MainWindow::on_pushButton_68_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
}

void MainWindow::on_pushButton_131_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
}

void MainWindow::on_pushButton_129_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_128_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_pushButton_127_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}

void MainWindow::on_client_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_125_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_pushButton_124_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_139_clicked()
{
    ui->stackedWidget->setCurrentIndex(15);
}

void MainWindow::on_pushButton_138_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_pushButton_137_clicked()
{
    ui->stackedWidget->setCurrentIndex(9);
}

void MainWindow::on_pushButton_136_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
}

void MainWindow::on_client_12_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_134_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);
}

void MainWindow::on_pushButton_133_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_59_clicked()
{
    ui->stackedWidget->setCurrentIndex(15);
}

void MainWindow::on_pushButton_60_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///
//   yesmine
void MainWindow::on_ajouter_25_clicked()
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
void MainWindow::on_tabprod_activated(const QModelIndex &index)
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


void MainWindow::on_del_2_clicked()
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

void MainWindow::on_tabWidget_25_currentChanged(int index)
{
    ui->tabprod->setModel(tmpprod.afficher());
}

void MainWindow::on_edi_2_clicked()
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

void MainWindow::on_edit_2_clicked()
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

void MainWindow::on_editOk_2_clicked()
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

void MainWindow::on_delete_btn_2_clicked()
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


void MainWindow::on_pushButton_311_clicked()
{
    QPrinter *imprimante;
    QPrintDialog pd(ui->tabprod);
    if(pd.exec()== QDialog::Accepted) return;
    imprimante=pd.printer();
    imprimante->setOutputFormat(QPrinter::PdfFormat);
    imprimante->setOutputFileName("C:/Users/ME/Desktop/pdf/doc.pdf");

}



void MainWindow::on_search_2_textChanged(const QString &arg1)
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
////////////////////// entrepot
void MainWindow::on_ajouter_23_clicked()
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

void MainWindow::on_tabent_activated(const QModelIndex &index)
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

void MainWindow::on_tabWidget_99_currentChanged(int index)
{
     ui->tabent->setModel(tmpent.affichertri());
}

void MainWindow::on_del_clicked()
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

void MainWindow::on_edi_clicked()
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

void MainWindow::on_edit_clicked()
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

void MainWindow::on_editOk_clicked()
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

void MainWindow::on_delete_btn_clicked()
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

void MainWindow::on_search_textChanged(const QString &arg1)
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

void MainWindow::on_pushButton_301_clicked()
{
    QPrinter *imprimante;
    QPrintDialog pd(ui->tabent);
    if(pd.exec()== QDialog::Accepted) return;
    imprimante=pd.printer();
    imprimante->setOutputFormat(QPrinter::PdfFormat);
    imprimante->setOutputFileName("C:/Users/ME/Desktop/pdf/doc.pdf");

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//    CALEB !!


////////////////////////
// Fournisseur !
void MainWindow::on_ajouter_clicked()
{
    tb.setID(ui->lineEdit_identifiantF->text().toInt());
    tb.setNom(ui->lineEdit_nomF->text());
    tb.setAdresse(ui->lineEdit_adresseF->text());
    tb.setTelephone(ui->lineEdit_telephoneF->text().toInt());
    tb.setEmail(ui->lineEdit_emailF->text());

    fournisseur f(tb.get_identifiant(), tb.get_nom(), tb.get_adresse(), tb.get_telephone(), tb.get_email());

    bool test = f.ajouter();
    if(test)
    {

        ui->table_F->setModel(tb.afficher());//actualiser
        QMessageBox::information(this, "Reussite", "Fournisseur ajouté !");
        ui->lineEdit_identifiantF->clear();
        ui->lineEdit_nomF->clear();
        ui->lineEdit_adresseF->clear();
        ui->lineEdit_telephoneF->clear();
        ui->lineEdit_emailF->clear();
    }
    else
    {
        QMessageBox::warning(this, "Echec", "Fournisseur non ajouté !");
        ui->lineEdit_identifiantF->clear();
        ui->lineEdit_nomF->clear();
        ui->lineEdit_adresseF->clear();
        ui->lineEdit_telephoneF->clear();
        ui->lineEdit_emailF->clear();
    }
}




void MainWindow::on_pushButton_M_clicked()
{
    tb.setID(ui->lineEdit_identifiantM->text().toInt());
    tb.setNom(ui->lineEdit_nom1->text());
    tb.setAdresse(ui->lineEdit_61->text());
    tb.setTelephone(ui->lineEdit_62->text().toInt());
    tb.setEmail(ui->lineEdit_63->text());

    fournisseur f(tb.get_identifiant(), tb.get_nom(), tb.get_adresse(), tb.get_telephone(), tb.get_email());


        bool test = f.modifier(f.get_identifiant());
        if(test)
        {
            ui->table_F->setModel(tb.afficher());
            qDebug()<<"Modification effectue"<<endl;

            QMessageBox::information(this, "Reussite", "Modification effectué !");
            ui->lineEdit_identifiantM->clear();
            ui->lineEdit_nom1->clear();
            ui->lineEdit_61->clear();
            ui->lineEdit_62->clear();
            ui->lineEdit_63->clear();
        }
        else
        {
            qDebug()<<"Envoi non effectue"<<endl;
            QMessageBox::information(this, "Echec", "Modification non effectué !");
            ui->lineEdit_identifiantM->clear();
            ui->lineEdit_nom1->clear();
            ui->lineEdit_61->clear();
            ui->lineEdit_62->clear();
            ui->lineEdit_63->clear();
        }
}

void MainWindow::on_pushButton_supprimer_2_clicked()
{
    tb.setID(ui->recherche->text().toInt());
    if(tb.get_identifiant()!=0)
    {
        if(tb.verificationFournisseur()==0)
        {
            bool test=tb.supprimer(tb.get_identifiant());
            if(test)
            {
                ui->table_F->setModel(tb.afficher());
                qDebug()<<"Suppression effectue"<<endl;
                QMessageBox::information(this, "Reussite", "Supression effectué !");
                ui->recherche->clear();

            }
            else
            {
                qDebug()<<"Suppression non effectue"<<endl;
                QMessageBox::warning(this, "Echec", "Supression non effectué !");
                ui->recherche->clear();
            }

        }

    }
    else
        QMessageBox::warning(this, "Echec", "Remplissez le champs !");
}




void MainWindow::on_pushButton_21_clicked()
{
    QString ids=ui->lineEdit_identifiantM->text();
    tb.setID(ids.toInt());
    if(tb.verificationFournisseur()==0)
    {
        ui->lineEdit_identifiantM->show();
        ui->lineEdit_nom1->show();
        ui->lineEdit_61->show();
        ui->lineEdit_62->show();
        ui->lineEdit_63->show();

        QString id=QString::number(tb.get_identifiant());
        QString pr=QString::number(m.GetPrix());

        ui->lineEdit_identifiantM->setText(id);
        ui->lineEdit_nom1->setText(tb.get_nom());;
        ui->lineEdit_61->setText(tb.get_adresse());
        ui->lineEdit_62->setText(pr);
        ui->lineEdit_63->setText(tb.get_email());

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("ok"),
                              QObject::tr("l'identifiant n'existe pas \n"
                                          "click cancel to exit."), QMessageBox::Cancel);
    }
}



void MainWindow::on_pushButton_clicked()
{
    //ui->table_F->setModel(tb.trier_nom());
}

void MainWindow::on_pushButton_5_clicked()
{
  //  ui->table_F->setModel(tb.trier_ID());
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->afficherMatierePremiere->setModel(mp.trier_nom());
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->afficherMatierePremiere->setModel(mp.trier_quantite());
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->afficherMatierePremiere->setModel(mp.trier_prix());
}



void MainWindow::on_pushButton_cherchern_clicked()
{
   // tb.setID(ui->lineEdit_chercherID_2->text());
    //ui->tableView_21->setModel(tb.chercher(tb.get_identifiant()));
}

void MainWindow::on_pushButton_cherhcerIDF_clicked()
{
    tb.setNom(ui->lineEdit_chercherNom_9->text());
    ui->tableView_21->setModel(tb.chercherN(tb.get_nom()));

}


////////////////////////////////////////////////////////////////////////////////
//Matiere Premiere

void MainWindow::on_pushButton_14_clicked()
{
    mp.setID(ui->lineEdit_69->text().toInt());
    mp.setNom(ui->lineEdit_292->text());
    mp.setReference(ui->lineEdit_70->text());
    mp.setDescription(ui->plainTextEdit_2->toPlainText());
    mp.setQuantite(ui->lineEdit_72->text().toInt());
    mp.setPrix(ui->lineEdit_71->text().toInt());





       matiere_p MP(mp.get_identifiant(),mp.get_libelle(),mp.get_reference(),mp.get_description(),mp.get_prix(),mp.get_quantite());

       if(MP.get_identifiant()!=0, MP.get_libelle()!=NULL, MP.get_reference()!=NULL, MP.get_description()!=NULL, MP.get_prix()!=0, mp.get_quantite()!=0)
       {

           bool test = MP.ajouter();

            if(test)
            {
                 ui->afficherMatierePremiere->setModel(mp.afficher());//actualiser
                  QMessageBox::information(this, "Reussite", "Matiere premiere ajouté !");
                 qDebug()<<"Envoi effectue"<<endl;
                 ui->lineEdit_69->clear();
                 ui->lineEdit_292->clear();
                 ui->lineEdit_70->clear();
                 ui->plainTextEdit_2->clear();
                 ui->lineEdit_71->clear();
                 ui->lineEdit_72->clear();
            }
           else
            {

                 qDebug()<<"Envoi non effectue"<<endl;
                 QMessageBox::information(this, "Reussite", "Matiere premiere non ajouté !");
                 ui->lineEdit_69->clear();
                 ui->lineEdit_292->clear();
                 ui->lineEdit_70->clear();
                 ui->plainTextEdit_2->clear();
                 ui->lineEdit_71->clear();
                 ui->lineEdit_72->clear();
            }

       }
       else
             QMessageBox::warning(this, "Echec", "Remplissez tout les champs !");
}



void MainWindow::on_pushButton_12_clicked()
{
    mp.setID(ui->lineEdit_64->text().toInt());
    mp.setNom(ui->lineEdit_Nom_3->text());
    mp.setReference(ui->lineEdit_65->text());
    mp.setDescription(ui->plainTextEdit->toPlainText());
    mp.setQuantite(ui->lineEdit_66->text().toInt());
    mp.setPrix(ui->lineEdit_67->text().toInt());


       matiere_p MP(mp.get_identifiant(),mp.get_libelle(),mp.get_reference(),mp.get_description(),mp.get_prix(),mp.get_quantite());


       if(MP.get_identifiant()!=0, MP.get_libelle()!=NULL, MP.get_reference()!=NULL, MP.get_description()!=NULL, MP.get_prix()!=0, mp.get_quantite()!=0)
       {
                 if(mp.verificationMp()==0)
                 {
                     bool test = MP.miseAjour(MP.get_identifiant());

                           if(test)
                           {
                                ui->afficherMatierePremiere->setModel(mp.afficher());//actualiser

                                qDebug()<<"Envoi effectue"<<endl;
                                QMessageBox::information(this, "Reussite", "Modification effectue !");
                                ui->lineEdit_64->clear();
                                ui->lineEdit_65->clear();
                                ui->lineEdit_Nom_3->clear();
                                ui->plainTextEdit->clear();
                                ui->lineEdit_66->clear();
                                ui->lineEdit_67->clear();
                           }
                          else
                           {
                                 qDebug()<<"Envoi non effectue"<<endl;
                                  QMessageBox::information(this, "Reussite", "Modification non effectue !");
                                  ui->lineEdit_64->clear();
                                  ui->lineEdit_65->clear();
                                  ui->lineEdit_Nom_3->clear();
                                  ui->plainTextEdit->clear();
                                  ui->lineEdit_66->clear();
                                  ui->lineEdit_67->clear();

                           }
                 }

       }
       else
             QMessageBox::critical(this, "Echec", "Remplissez tout les champs !");

}



void MainWindow::on_pushButton_13_clicked()
{
    mp.setID(ui->lineEdit_68->text().toInt());
    if(mp.get_identifiant()!=0)
    {
         if(mp.verificationMp()==0)
         {

             bool test=mp.supprimer(mp.get_identifiant());
                     if(test)
                     {
                           ui->afficherMatierePremiere->setModel(mp.afficher());
                           QMessageBox::information(this, "Reussite", "Suppression effectue !");
                          ui->lineEdit_68->clear();

                     }
                    else
                        {

                         QMessageBox::information(this, "Reussite", "Suppression effectue !");
                         ui->lineEdit_68->clear();
                       }
         }

    }
    else
          QMessageBox::critical(this, "Echec", "Remplissez tout les champs !");

}

void MainWindow::on_pushButton_chercherP24_clicked()
{
    mp.setPrix(ui->lineEdit_291->text().toInt());
    if(mp.get_prix()!=0)
    {
         if(mp.verificationMpP()==0)
         {
                 ui->tableView_22->setModel(mp.chercherP(mp.get_prix()));
         }

}
}
void MainWindow::on_pushButton_chercheridm_clicked()
{
    mp.setID(ui->lineEdit_289->text().toInt());
    if(mp.get_identifiant()!=0)
    {
         if(mp.verificationMp()==0)
         {
                 ui->tableView_22->setModel(mp.chercher(mp.get_identifiant()));
         }
    }
}
void MainWindow::on_pushButton_c_clicked()
{
    mp.setNom(ui->lineEdit_289->text());
    if(mp.get_libelle()!=NULL)
    {
         if(mp.verificationMpN()==0)
         {
                 ui->tableView_22->setModel(mp.chercherL(mp.get_libelle()));
         }
    }
}



void MainWindow::on_pushButton_4_clicked()
{
    QString data=arduinow.read_from_arduino();

         qDebug()<< data.length();
         qDebug()<< data;
     if (data[data.length()-1]=="1" )
         ui->label_444->setText("on");
     else if ( data[data.length()-1]=="0")
          ui->label_444->setText("off");


}

void MainWindow::on_pushButton_22_clicked()
{

    //QDateTime datecreation = date.currentDateTime();
    //QString afficheDC = "Date de Creation PDF : " + datecreation.toString() ;
    QPdfWriter pdf("C:/Users/ziedh/Desktop/impression/Pdf.pdf");
    QPainter painter(&pdf);
    int i = 4000;
    painter.setPen(Qt::blue);
    painter.setFont(QFont("Arial", 30));
    painter.drawText(1100,1200,"Liste des Revenues ");
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 50));
    // painter.drawText(1100,2000,afficheDC);
    painter.drawRect(100,100,7300,2600);
    //painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/RH/Desktop/projecpp/image/logopdf.png"));
    painter.drawRect(0,3000,9600,500);
    painter.setFont(QFont("Arial", 9));
    painter.drawText(200,3300,"NOMPRODUIT");
    painter.drawText(1700,3300,"IDENTIFIANTREVENU");
    painter.drawText(3200,3300,"QUANTITEVENDUE");
    painter.drawText(4900,3300,"VALEURSUNITAIRE");
    painter.drawText(6600,3300,"IDENTIFIANTCLIENT");
    painter.drawText(8100,3300,"DATEVENTE");

    QSqlQuery query;
    query.prepare("select * from REVENUE");
    query.exec();
    while (query.next())
    {
        painter.drawText(200,i,query.value(0).toString());
        painter.drawText(1700,i,query.value(1).toString());
        painter.drawText(3200,i,query.value(2).toString());
        painter.drawText(4900,i,query.value(3).toString());
        painter.drawText(6600,i,query.value(4).toString());
        painter.drawText(8100,i,query.value(5).toString());
        i = i + 500;
    }
    int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
    if (reponse == QMessageBox::Yes)
    {
        QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/ziedh/Desktop/impression/Pdf.pdf"));
        painter.end();
    }
    if (reponse == QMessageBox::No)
    {
        painter.end();
    }
}

void MainWindow::on_pushButton_23_clicked()
{
    //QDateTime datecreation = date.currentDateTime();
    //QString afficheDC = "Date de Creation PDF : " + datecreation.toString() ;
    QPdfWriter pdf("C:/Users/ziedh/Desktop/impression/Pdf.pdf");
    QPainter painter(&pdf);
    int i = 4000;
    painter.setPen(Qt::blue);
    painter.setFont(QFont("Arial", 30));
    painter.drawText(1100,1200,"Liste des Clients ");
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 50));
    // painter.drawText(1100,2000,afficheDC);
    painter.drawRect(100,100,7300,2600);
    //painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/RH/Desktop/projecpp/image/logopdf.png"));
    painter.drawRect(0,3000,9600,500);
    painter.setFont(QFont("Arial", 9));
    painter.drawText(200,3300,"ID");
    painter.drawText(1700,3300,"NOM");
    painter.drawText(3200,3300,"PRENOM");
    painter.drawText(4900,3300,"MAIL");
    painter.drawText(6600,3300,"BOITE");
    painter.drawText(8100,3300,"VILLE");
    painter.drawText(9800,3300,"TELE");
    QSqlQuery query;
    query.prepare("select * from CLIENT");
    query.exec();
    while (query.next())
    {
        painter.drawText(200,i,query.value(0).toString());
        painter.drawText(1700,i,query.value(1).toString());
        painter.drawText(3200,i,query.value(2).toString());
        painter.drawText(4900,i,query.value(3).toString());
        painter.drawText(6600,i,query.value(4).toString());
        painter.drawText(8100,i,query.value(5).toString());
        i = i + 500;
    }
    int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
    if (reponse == QMessageBox::Yes)
    {
        QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/ziedh/Desktop/impression/Pdf.pdf"));
        painter.end();
    }
    if (reponse == QMessageBox::No)
    {
        painter.end();
    }
}

void MainWindow::on_pushButton_mailEmploye_clicked()
{
    Smtp* smtp = new Smtp("raniacheffai@gmail.com","RC02072000","smtp.gmail.com",465);
       connect (smtp, SIGNAL (status (QString)), this, SLOT (mailSent(QString)));
       smtp->sendMail("raniacheffai@gmail.com", ui->comboBox_mailEmploye->currentText(), ui->mailEmploye->text(), ui->textEdit_msgEmploye->toPlainText());
}

void MainWindow::on_afficher_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(14);
    ui->tabWidget_11->setCurrentIndex(0);
}

void MainWindow::on_ajouter_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(14);
    ui->tabWidget_11->setCurrentIndex(1);
}

void MainWindow::on_modifier_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(14);
    ui->tabWidget_11->setCurrentIndex(2);
}

void MainWindow::on_ajouterclient_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(14);
    ui->tabWidget_11->setCurrentIndex(4);
}

void MainWindow::on_ajouter_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(16);
    ui->tabWidget_10->setCurrentIndex(1);
}

void MainWindow::on_afficher_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(16);
    ui->tabWidget_10->setCurrentIndex(0);
}

void MainWindow::on_supprimer_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(16);
    ui->tabWidget_10->setCurrentIndex(2);
}

void MainWindow::on_modifier_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(16);
    ui->tabWidget_10->setCurrentIndex(3);
}

void MainWindow::on_modifier_14_clicked()
{
    ui->stackedWidget->setCurrentIndex(16);
    ui->tabWidget_10->setCurrentIndex(4);
}

void MainWindow::on_ajouter_22_clicked()
{
    ui->stackedWidget->setCurrentIndex(18);
    ui->tabWidget_11->setCurrentIndex(0);
}

void MainWindow::on_afficher_21_clicked()
{
    ui->stackedWidget->setCurrentIndex(18);
    ui->tabWidget_11->setCurrentIndex(1);
}

void MainWindow::on_modifier_19_clicked()
{
    ui->stackedWidget->setCurrentIndex(18);
    ui->tabWidget_11->setCurrentIndex(2);
}

void MainWindow::on_supprimer_20_clicked()
{
    ui->stackedWidget->setCurrentIndex(18);
    ui->tabWidget_11->setCurrentIndex(3);
}

void MainWindow::on_pushButton_24_clicked()
{
 ui->stackedWidget->setCurrentIndex(17);
}

void MainWindow::on_ajouter_24_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);
    ui->tabWidget_25->setCurrentIndex(0);
}

void MainWindow::on_afficher_22_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);
    ui->tabWidget_25->setCurrentIndex(1);
}

void MainWindow::on_modifier_20_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);
    ui->tabWidget_25->setCurrentIndex(2);
}

void MainWindow::on_supprimer_21_clicked()
{
    ui->stackedWidget->setCurrentIndex(20);
    ui->tabWidget_25->setCurrentIndex(3);
}

void MainWindow::on_pushButton_204_clicked()
{
  ui->stackedWidget->setCurrentIndex(19);
}

void MainWindow::on_pushButton_205_clicked()
{
  ui->stackedWidget->setCurrentIndex(15);
}

void MainWindow::on_pushButton_206_clicked()
{
  ui->stackedWidget->setCurrentIndex(15);
}

void MainWindow::on_pushButton_207_clicked()
{
    ui->stackedWidget->setCurrentIndex(15);
}

void MainWindow::on_pushButton_208_clicked()
{
    ui->stackedWidget->setCurrentIndex(15);
}

void MainWindow::on_pushButton_209_clicked()
{
    ui->stackedWidget->setCurrentIndex(15);
}

void MainWindow::on_pushButton_211_clicked()
{
   ui->stackedWidget->setCurrentIndex(13);
}

void MainWindow::on_pushButton_212_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
}

void MainWindow::on_pushButton_213_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
}

void MainWindow::on_pushButton_210_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
}

void MainWindow::on_pushButton_214_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
}

void MainWindow::on_pushButton_215_clicked()
{
    ui->stackedWidget->setCurrentIndex(13);
}

void MainWindow::on_pushButton_temperateur_clicked()
{
    QString data=arduinow.read_from_arduino();

//        QStringRef subString(&data,data.length()-5 ,5 );
//     qDebug()<< subString;



          qDebug()<< data.length();
          qDebug()<< data;
      if (data[data.length()-1]=="1" )
          ui->temperateur->setText("surchauffe");
      else if ( data[data.length()-1]=="0")
           ui->temperateur->setText("etat normale");
}

void MainWindow::on_envoyer_mail_client_clicked()
{
    Smtp* smtp = new Smtp("raniacheffai@gmail.com","RC02072000","smtp.gmail.com",465);
        connect (smtp, SIGNAL (status (QString)), this, SLOT (mailSent(QString)));
        smtp->sendMail("raniacheffai@gmail.com", ui->mail_client->currentText(), ui->subject_client->text(), ui->message_client->toPlainText());
}

void MainWindow::on_envoyer_facture_clicked()
{
    Smtp* smtp = new Smtp("raniacheffai@gmail.com","RC02072000","smtp.gmail.com",465);
        connect (smtp, SIGNAL (status (QString)), this, SLOT (mailSent(QString)));
        smtp->sendMail("raniacheffai@gmail.com", ui->emailfacture->text(), ui->subject_facture->text(), ui->message_facture->toPlainText());
}

