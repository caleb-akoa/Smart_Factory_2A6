#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
