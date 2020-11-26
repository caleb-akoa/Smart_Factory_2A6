#include "mainwindow.h"
#include<QDebug>
#include <QApplication>
#include "cnx.h"
#include <QMessageBox>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
      MainWindow w;


    if (database.isOpen())// c bon !
    {
                 w.show();
return a.exec();
//        QMessageBox::information(nullptr, QObject::tr("database is open"),
//                                 QObject::tr("connection successful.\n"
//                                             "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        //  {w.show();
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                              QObject::tr("connecion failed.\n"
                                          "click cancel to exit"), QMessageBox::Cancel);



}

