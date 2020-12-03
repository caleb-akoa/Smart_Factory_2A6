#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMessageBox>
#include <QDebug>
#include <fournisseur.h>
#include <matiere_p.h>
#include <QSound>

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_3_clicked();

    void on_fournisseur_clicked();

    void on_pushButton_1_clicked();



    void on_matiereP_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_clicked();

    void on_ajouter_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_M_clicked();

    void on_pushButton_supprimer_2_clicked();

    void on_recherche_textChanged(const QString &arg1);

    void on__ajoute_mp_clicked();

    void on_pushButton_12_clicked();

    void on_lineEdit_7_textChanged(const QString &arg1);

    void on_pushButton_13_clicked();

    void on_actionSon_triggered();

private:
    Ui::MainWindow *ui;
    QSound *son;
    fournisseur tb;
    matiere_P mp;
};
#endif // MAINWINDOW_H
