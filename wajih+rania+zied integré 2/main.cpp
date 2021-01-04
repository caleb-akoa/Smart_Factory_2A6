  #include "login.h"
#include "globales.h"
#include <QMessageBox>
#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if(database.isOpen()){
        Login screenLogin;
        screenLogin.show();
        return a.exec();
    }else {
        QMessageBox::critical(0, "Database not connected !", "Cannot connect to the database ...");
        return a.exec();
    }
}
