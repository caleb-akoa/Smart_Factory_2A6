#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "produit.h"
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

    void on_pushButton_Produit_clicked();

    void on_pushButton_39_clicked();

    void on_pushButton_entrepot_clicked();

    void on_pushButton_26_clicked();

    void on_supprimer_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Produit Etmp;
};
#endif // MAINWINDOW_H
