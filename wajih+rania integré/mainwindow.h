#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMessageBox>
#include <QMainWindow>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <client.h>
#include <user.h>
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QLineSeries>
#include <commande.h>
#include <employe.h>
#include <machine.h>



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


    void on_tabWidget_currentChanged(int index);

    void on_suivantmodifier_clicked();




    void on_tabWidget_3_tabBarClicked(int index);


    void on_ajoutercmd_clicked();

    void on_tabWidget_2_tabBarClicked(int index);



    void on_cherchermodifiercmd_clicked();

    void on_suivantcmd_clicked();



    void on_validermodifiercmd_clicked();

    void on_chercherdeletecmd_clicked();

    void on_deletecmd_clicked();

    void on_tabWidget_2_currentChanged(int index);



    void on_radioButton_2_clicked();

    void on_radioButton_clicked();

    void on_cherchernom_clicked();



    void on_comboBox_activated(const QString &arg1);

    void on_ajouterclient_2_clicked();



    void on_pushButton_ajouterEmploye_3_clicked();

    void on_pushButton_modifierEmploye_4_clicked();

    void on_pushButton_rechercherME_clicked();

    void on_pushButton_triEmploye_clicked();

    void on_pushButton_rechercherSE_clicked();

    void on_pushButton_supprimerE_clicked();

    void on_pushButton_chercherEmploye_clicked();

    void on_pushButton_chercherEmploye_2_clicked();

    void on_pushButton_chercherEmploye_3_clicked();

    void on_pushButton_ajouterMachine_3_clicked();

    void on_pushButton_chercherMachine_8_clicked();

    void on_pushButton_chercherMachine_9_clicked();

    void on_pushButton_chercherMachine_10_clicked();

    void on_tabWidget_9_currentChanged(int index);

    void on_tabWidget_9_tabBarClicked(int index);

    void on_pushButton_rechercherSM_clicked();

    void on_pushButton_supprimerM_clicked();

    void on_pushButton_triMachine_clicked();

    void on_pushButton_rechercherModM_clicked();

    void on_pushButton_modifierMachine_4_clicked();

private:
    Ui::MainWindow *ui;
    Client client;
    User user;
    Commande commande;
    employe e;
    machine m;
};
#endif // MAINWINDOW_H
