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
#include <factures.h>
#include <revenues.h>
#include "fournisseur.h"
#include "matiere_p.h"
#include "produit.h"
#include "entrepot.h"
#include <QPrinter>
#include <QPrintDialog>

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

    void on_ajouter_5_clicked();

    void on_ValidezRevenues_clicked();

    void on_Validez_Mod_Rev_clicked();

    void on_pushButton_SupprimerRevenues_clicked();

    void on_pushButton_RechRevN_clicked();

    void on_pushButton_RechRevIDR_clicked();

    void on_pushButton_RechRevIDC_clicked();



    void on_pushButton_AjouterFacture_clicked();

    void on_pushButton_ModifierFacture_clicked();

    void on_pushButton_SuppFactures_clicked();

    void on_pushButton_TrierNom_clicked();

    void on_pushButton_TrierDesignation_clicked();

    void on_pushButton_42_clicked();

    void on_pushButton_30_clicked();

    void on_pushButton_29_clicked();

    void on_pushButton_56_clicked();

    void on_pushButton_64_clicked();

    void on_pushButton_91_clicked();

    void on_pushButton_109_clicked();

    void on_pushButton_151_clicked();

    void on_pushButton_57_clicked();

    void on_pushButton_65_clicked();

    void on_pushButton_92_clicked();

    void on_pushButton_110_clicked();

    void on_pushButton_162_clicked();

    void on_retour_28_clicked();

    void on_retour_27_clicked();

    void on_retour_51_clicked();

    void on_retour_50_clicked();

    void on_retour_26_clicked();

    void on_retour_33_clicked();

    void on_retour_32_clicked();

    void on_retour_31_clicked();

    void on_retour_53_clicked();

    void on_retour_52_clicked();

    void on_retour_30_clicked();

    void on_pushButton_RechFactIDF_clicked();

    void on_pushButton_RechFacD_clicked();

    void on_pushButton_RechFacN_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_27_clicked();

    void on_client_5_clicked();

    void on_pushButton_93_clicked();

    void on_client_7_clicked();

    void on_pushButton_111_clicked();

    void on_pushButton_148_clicked();

    void on_pushButton_149_clicked();

    void on_client_10_clicked();

    void on_pushButton_153_clicked();

    void on_pushButton_158_clicked();

    void on_pushButton_159_clicked();

    void on_client_11_clicked();

    void on_pushButton_161_clicked();

    void on_pushButton_163_clicked();

    void on_pushButton_61_clicked();

    void on_pushButton_62_clicked();

    void on_pushButton_52_clicked();

    void on_pushButton_53_clicked();

    void on_pushButton_89_clicked();

    void on_pushButton_106_clicked();

    void on_ajouter_8_clicked();

    void on_modifier_8_clicked();

    void on_supprimer_8_clicked();

    void on_afficher_8_clicked();

    void on_supprimer_10_clicked();

    void on_ajouter_9_clicked();

    void on_modifier_9_clicked();

    void on_supprimer_9_clicked();

    void on_afficher_9_clicked();

    void on_afficher_11_clicked();

    void on_afficher_10_clicked();

    void on_ajouter_3_clicked();

    void on_modifier_3_clicked();

    void on_supprimer_3_clicked();

    void on_afficher_3_clicked();

    void on_modifier_5_clicked();

    void on_supprimer_5_clicked();

    void on_afficher_5_clicked();

    void on_retour_19_clicked();

    void on_retour_20_clicked();

    void on_retour_21_clicked();

    void on_retour_22_clicked();

    void on_retour_23_clicked();

    void on_retour_24_clicked();

    void on_ajouter_clicked();

    void on_pushButton_M_clicked();

    void on_pushButton_supprimer_2_clicked();

    void on_pushButton_imprimer_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_28_clicked();

    void on_pushButton_51_clicked();

    void on_pushButton_54_clicked();

    void on_pushButton_58_clicked();

    void on_pushButton_63_clicked();

    void on_pushButton_87_clicked();

    void on_pushButton_90_clicked();

    void on_pushButton_105_clicked();

    void on_pushButton_108_clicked();

    void on_pushButton_147_clicked();

    void on_pushButton_150_clicked();

    void on_pushButton_157_clicked();

    void on_pushButton_160_clicked();

    void on_pushButton_132_clicked();

    void on_pushButton_135_clicked();

    void on_pushButton_123_clicked();

    void on_pushButton_126_clicked();

    void on_pushButton_292_clicked();

    void on_pushButton_293_clicked();

    void on_pushButton_294_clicked();

    void on_client_23_clicked();

    void on_pushButton_296_clicked();

    void on_pushButton_297_clicked();

    void on_pushButton_298_clicked();

    void on_pushButton_303_clicked();

    void on_pushButton_304_clicked();

    void on_pushButton_305_clicked();

    void on_client_24_clicked();

    void on_pushButton_306_clicked();

    void on_pushButton_307_clicked();

    void on_pushButton_308_clicked();

    void on_pushButton_309_clicked();

    void on_pushButton_310_clicked();

    void on_pushButton_94_clicked();

    void on_pushButton_95_clicked();

    void on_pushButton_112_clicked();

    void on_pushButton_113_clicked();

    void on_pushButton_154_clicked();

    void on_pushButton_155_clicked();

    void on_pushButton_164_clicked();

    void on_pushButton_165_clicked();

    void on_pushButton_299_clicked();

    void on_pushButton_300_clicked();

    void on_pushButton_31_clicked();

    void on_pushButton_32_clicked();

    void on_pushButton_67_clicked();

    void on_pushButton_68_clicked();

    void on_pushButton_131_clicked();

    void on_pushButton_129_clicked();

    void on_pushButton_128_clicked();

    void on_pushButton_127_clicked();

    void on_client_9_clicked();

    void on_pushButton_125_clicked();

    void on_pushButton_124_clicked();

    void on_pushButton_139_clicked();

    void on_pushButton_138_clicked();

    void on_pushButton_137_clicked();

    void on_pushButton_136_clicked();

    void on_client_12_clicked();

    void on_pushButton_134_clicked();

    void on_pushButton_133_clicked();

    void on_pushButton_59_clicked();

    void on_pushButton_60_clicked();

    void on_ajouter_25_clicked();

    void on_tabprod_activated(const QModelIndex &index);

    void on_del_2_clicked();

    void on_tabWidget_25_currentChanged(int index);

    void on_edi_2_clicked();

    void on_edit_2_clicked();

    void on_editOk_2_clicked();

    void on_delete_btn_2_clicked();

    void on_search_2_textChanged(const QString &arg1);

    void on_pushButton_311_clicked();

    void on_ajouter_23_clicked();

    void on_tabent_activated(const QModelIndex &index);

    void on_del_clicked();

    void on_tabWidget_99_currentChanged(int index);

    void on_edi_clicked();

    void on_edit_clicked();

    void on_editOk_clicked();

    void on_delete_btn_clicked();

    void on_search_textChanged(const QString &arg1);

    void on_pushButton_301_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_pushButton_chercherMachine_24_clicked();

    void on_pushButton_chercherMachine_22_clicked();

    void on_pushButton_chercherMachine_23_clicked();

    void on_pushButton_chercherMachine_20_clicked();

    void on_pushButton_chercherMachine_21_clicked();

private:
    Ui::MainWindow *ui;
    Client client;
    User user;
    Commande commande;
    employe e;
    machine m;
    Revenues rev;
    Factures fac;
    fournisseur tb;
    matiere_p mp;
    produit tmpprod;
    entrepot tmpent;
};
#endif // MAINWINDOW_H
