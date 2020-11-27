#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QtDebug>

#include "connexion.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    connexion c;

  bool test=c.ouvrirConnexion();
  MainWindow w;
  if(test==true)
  {
      w.show();
      QMessageBox::critical(nullptr, QObject::tr("database is  open"),
                  QObject::tr("connection avec succes.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

  }
  else
      QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                  QObject::tr("echec de la connection.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);




    return a.exec();
}
