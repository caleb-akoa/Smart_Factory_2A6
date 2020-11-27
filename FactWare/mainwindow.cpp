#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
#include "gestion.h"
#include "Dialog.h"
#include "echec.h"

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

void MainWindow::on_pushButton_clicked()
{
  Gestion g;
  g.NomUtilisateur = ui->nomUtilisateur->text();
  g.MotDePasse = ui->motDePasse->text().toULong();

  if(g.NomUtilisateur == "caleb" && g.MotDePasse == 1234 )
  {
              fenetre = new Dialog(this);
              fenetre->show();
              this->hide();


  }

  else
  {
      fenetre2 = new Echec(this);
             fenetre2->show();
  }
}

