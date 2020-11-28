#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H
#include "info_fournisseur.h"

#include <QDialog>

namespace Ui {
class fournisseur;
}

class fournisseur : public QDialog
{
    Q_OBJECT

public:
    explicit fournisseur(QWidget *parent = nullptr);
    ~fournisseur();


private slots:
    void on_ajouter_clicked();

    void on_pushButton_M_clicked();

    void on_pushButton_supprimer_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_recherche_textChanged(const QString &arg1);

private:
    Ui::fournisseur *ui;
    info_fournisseur tb;

};

#endif // FOURNISSEUR_H
