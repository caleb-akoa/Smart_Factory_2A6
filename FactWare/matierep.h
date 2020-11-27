#ifndef MATIEREP_H
#define MATIEREP_H
#include "info_mp.h"

#include <QDialog>

namespace Ui {
class matiereP;
}

class matiereP : public QDialog
{
    Q_OBJECT

public:
    explicit matiereP(QWidget *parent = nullptr);
    ~matiereP();




private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_lineEdit_7_textChanged(const QString &arg1);

    void on_pushButton_4_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::matiereP *ui;
    info_mp mp;
};

#endif // MATIEREP_H
