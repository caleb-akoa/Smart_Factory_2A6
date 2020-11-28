#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMessageBox>
#include <QMainWindow>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <client.h>


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
    void on_client_0_clicked();void on_commande_0_clicked();void on_client_3_clicked();void on_commande_1_clicked();
    //////////// crouds client !!
    void on_ajouterclient_clicked();void on_modifierclient_clicked();void on_supprimerclient_clicked();void on_afficherclient_clicked();void on_chercherclient_clicked();
    ////////////retours client !!
    void on_retour_clicked();void on_retour_2_clicked();void on_retour_3_clicked();void on_retour_4_clicked();void on_retour_5_clicked();
    /////////// crouds commandes clicked !!
    void on_ajouter_2_clicked();void on_modifier_2_clicked();void on_supprimer_2_clicked();void on_afficher_2_clicked();void on_chercher_2_clicked();
    ////////////// les retours commandes !!
    void on_retour_6_clicked();void on_retour_7_clicked();void on_retour_8_clicked();void on_retour_9_clicked();void on_retour_10_clicked();


    void on_ajoutercl_clicked();

    void on_tabWidget_tabBarClicked(int index);

    void on_deleteclient_clicked();



    void on_cherchermodifier_clicked();




    void on_chercher_clicked();

    void on_chercherdelete_clicked();

    void on_validermodification_clicked();

private:
    Ui::MainWindow *ui;
    Client client;

};
#endif // MAINWINDOW_H
