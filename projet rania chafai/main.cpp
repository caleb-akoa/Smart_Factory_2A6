#include "mainwindow.h"
#include "connexion.h"
#include <QApplication>
#include <QMessageBox>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
//    w.show();

    if (database.isOpen())// c bon!!!
    {
        w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                                  QObject::tr("connexion successful.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                                  QObject::tr("connexion failed.\n"
                                              "Click Cancel to exit."), QMessageBox::Cancel);
    }
    return a.exec();
}
