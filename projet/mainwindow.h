#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMessageBox>
#include <QMainWindow>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>


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


    void on_connect_clicked();

    void on_ajoutercmd_clicked();

    void on_modifercmd_clicked();

    void on_suppcmd_clicked();

    void on_affcmd_clicked();

    void on_chercmd_clicked();

    void on_retour_clicked();

    void on_retour_2_clicked();

    void on_retour_3_clicked();

    void on_retour_4_clicked();

    void on_retour_5_clicked();

    void on_retour_6_clicked();

    void on_retour_7_clicked();

    void on_retour_8_clicked();

    void on_retour_9_clicked();

    void on_retour_10_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_45_clicked();

    void on_pushButton_58_clicked();

    void on_ajouter_clicked();

    void on_modifier_clicked();

    void on_supprimer_clicked();

    void on_afficher_clicked();

    void on_chercher_clicked();

    void on_pushButton_13_clicked();



    void on_ajoutercl_clicked();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
