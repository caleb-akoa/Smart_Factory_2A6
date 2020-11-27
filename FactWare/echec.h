#ifndef ECHEC_H
#define ECHEC_H

#include <QDialog>

namespace Ui {
class Echec;
}

class Echec : public QDialog
{
    Q_OBJECT

public:
    explicit Echec(QWidget *parent =  0);
    ~Echec();

private slots:

    void on_pushButton_4_clicked();


private:
    Ui::Echec *ui;
};

#endif // ECHEC_H
