#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "fournisseur.h"
#include "matierep.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();


private slots:
    void on_fournisseur_clicked();
    void on_matiereP_clicked();




private:
    Ui::Dialog *ui;
   fournisseur *fenetre;
   matiereP  *fenetre1;
};

#endif // DIALOG_H
