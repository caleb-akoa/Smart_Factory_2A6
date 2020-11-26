
#include "globales.h"
#include <QMessageBox>
#include <QApplication>
#include "mainwindow.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if(database.isOpen()){

        QMessageBox::information(0, "Database connected !", " connect to the database ...");
MainWindow w ;
w.show();
        return a.exec();
    }else {
        QMessageBox::critical(0, "Database not connected !", "Cannot connect to the database ...");
        return a.exec();
    }
}
