#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include<revenues.h>
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
        {
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
