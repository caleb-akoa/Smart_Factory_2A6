#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "machine.h"
#include "employe.h"
#include "smtp.h"
#include "arduino.h"

#include<QtWidgets/QMainWindow>
#include<QtCharts/QChartView>
#include<QtCharts/QBarSeries>
#include<QtCharts/QBarSet>
#include<QtCharts/QLegend>
#include<QtCharts/QBarCategoryAxis>
#include<QtCharts/QHorizontalStackedBarSeries>
#include<QtCharts/QLineSeries>
#include<QtCharts/QCategoryAxis>
#include<QtCharts/QPieSeries>
#include<QtCharts/QPieSlice>

#include<QLineSeries>
#include<QtCharts>
#include<QChartView>
#include<QPieSeries>
#include<QPieSlice>
#include "connexion.h"

#include <QMessageBox>
#include <QDebug>
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
    bool envoie =false;
    void update_label();

private slots:
    void on_pushButton_employes_clicked();

    void on_pushButton_machines_clicked();

    void on_pushButton_machines_2_clicked();

    void on_pushButton_ajouterEmploye_clicked();

    void on_pushButton_modifierEmploye_clicked();

    void on_pushButton_afficherEmploye_clicked();

    void on_pushButton_supprimerEmploye_clicked();

    void on_pushButton_modifierEmploye_2_clicked();

    void on_pushButton_afficherEmploye_2_clicked();

    void on_pushButton_supprimerEmploye_2_clicked();

    void on_pushButton_retour_clicked();

    void on_pushButton_ajouterEmploye_4_clicked();

    void on_pushButton_afficherEmploye_3_clicked();

    void on_pushButton_supprimerEmploye_3_clicked();

    void on_pushButton_retour_2_clicked();

    void on_pushButton_ajouterEmploye_5_clicked();

    void on_pushButton_modifierEmploye_5_clicked();

    void on_pushButton_supprimerEmploye_4_clicked();

    void on_pushButton_retour_3_clicked();

    void on_pushButton_ajouterEmploye_6_clicked();

    void on_pushButton_modifierEmploye_6_clicked();

    void on_pushButton_afficherEmploye_5_clicked();

    void on_pushButton_retour_9_clicked();

    void on_pushButton_employes_3_clicked();

    void on_pushButton_ajouterMachine_clicked();

    void on_pushButton_modifierMachine_clicked();

    void on_pushButton_afficherMachine_clicked();

    void on_pushButton_supprimerMachine_clicked();

    void on_pushButton_statistiques_clicked();

    void on_pushButton_modifierMachine_2_clicked();

    void on_pushButton_afficherMachine_2_clicked();

    void on_pushButton_supprimerMachine_2_clicked();

    void on_pushButton_statistiques_2_clicked();

    void on_pushButton_retour_4_clicked();

    void on_pushButton_ajouterMachine_4_clicked();

    void on_pushButton_afficherMachine_3_clicked();

    void on_pushButton_supprimerMachine_3_clicked();

    void on_pushButton_statistiques_3_clicked();

    void on_pushButton_ajouterMachine_5_clicked();

    void on_pushButton_modifierMachine_5_clicked();

    void on_pushButton_supprimerMachine_4_clicked();

    void on_pushButton_statistiques_4_clicked();

    void on_pushButton_ajouterMachine_6_clicked();

    void on_pushButton_modifierMachine_6_clicked();

    void on_pushButton_afficherMachine_5_clicked();

    void on_pushButton_statistiques_5_clicked();

    void on_pushButton_retour_6_clicked();

    void on_pushButton_retour_7_clicked();

    void on_pushButton_ajouterMachine_7_clicked();

    void on_pushButton_modifierMachine_7_clicked();

    void on_pushButton_afficherMachine_6_clicked();

    void on_pushButton_supprimerMachine_6_clicked();

    void on_pushButton_retour_8_clicked();

    void on_pushButton_retour_5_clicked();

    void on_pushButton_ajouterMachine_3_clicked();

    void on_pushButton_supprimerM_clicked();

    void on_pushButton_modifierMachine_4_clicked();

    void on_pushButton_rechercherModM_clicked();

    void on_pushButton_ajouterEmploye_3_clicked();

    void on_pushButton_supprimerE_clicked();

    void on_pushButton_rechercherME_clicked();

    void on_pushButton_modifierEmploye_4_clicked();

    void on_pushButton_rechercherSE_clicked();

    void on_pushButton_triEmploye_clicked();

    void on_pushButton_rechercherSM_clicked();

    void on_pushButton_triMachine_clicked();

    void on_pushButton_supprimerEmploye_5_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_retour_10_clicked();

    void on_pushButton_supprimerEmploye_6_clicked();

    void on_pushButton_afficherEmploye_6_clicked();

    void on_pushButton_modifierEmploye_7_clicked();

    void on_pushButton_ajouterEmploye_7_clicked();

    void on_pushButton_chercherMachine_clicked();

    void on_pushButton_chercherMachine_2_clicked();

    void on_pushButton_chercherMachine_3_clicked();

    void on_pushButton_chercherMachine_4_clicked();

    void on_pushButton_chercherMachine_5_clicked();

    void on_pushButton_chercherMachine_6_clicked();

    void on_pushButton_retour_11_clicked();

    void on_pushButton_ajouterMachine_8_clicked();

    void on_pushButton_modifierMachine_8_clicked();

    void on_pushButton_afficherMachine_7_clicked();

    void on_pushButton_supprimerMachine_7_clicked();

    void on_pushButton_statistiques_7_clicked();

    void on_pushButton_chercherEmploye_clicked();

    void on_pushButton_aide_clicked();

    void on_pushButton_retour_12_clicked();

    void on_pushButton_chercherMachine_8_clicked();

    void on_pushButton_chercherEmploye_2_clicked();

    void on_pushButton_chercherEmploye_3_clicked();

    void on_pushButton_chercherMachine_9_clicked();

    void on_pushButton_chercherMachine_10_clicked();

    void on_pushButton_envoyer_clicked();

    void on_pushButton_envoyerMail_clicked();

    void on_pushButton_envoyerMail_2_clicked();

    void on_pushButton_envoyerMail_3_clicked();

    void on_pushButton_envoyerMail_4_clicked();

    void on_pushButton_envoyerMail_5_clicked();

    void on_pushButton_envoyerMail_6_clicked();

    void on_pushButton_ajouterEmploye_8_clicked();

    void on_pushButton_modifierEmploye_8_clicked();

    void on_pushButton_afficherEmploye_7_clicked();

    void on_pushButton_supprimerEmploye_7_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_retour_13_clicked();

    void on_pushButton_quitter_clicked();

    void on_pushButton_on_clicked();

    void on_pushButton_off_clicked();

    void on_pushButton_sup_clicked();

    void on_pushButton_inf_clicked();

    void on_pushButton_retour_14_clicked();

    void on_pushButton_pointer_clicked();

    void on_pushButton_imprimer_clicked();

private:
    Ui::MainWindow *ui;
    machine m;
    employe e;
    QByteArray data;
    arduino a;
};
bool envoie_Retour(bool msg);
#endif // MAINWINDOW_H
