#include "dialog.h"
#include "ui_dialog.h"
#include "fournisseur.h"
#include "matierep.h"


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
     QObject::connect(ui->pushButton, SIGNAL(clicked()), qApp, SLOT(quit()));
}

Dialog::~Dialog()
{
    delete ui;
}




void Dialog::on_fournisseur_clicked()
{
    fenetre = new fournisseur(this);
    fenetre->show();

}

void Dialog::on_matiereP_clicked()
{
    fenetre1 = new matiereP(this);
    fenetre1->show();
}
