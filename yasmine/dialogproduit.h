#ifndef DIALOGPRODUIT_H
#define DIALOGPRODUIT_H
#include "produit.h"
#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class dialogproduit; }
QT_END_NAMESPACE

class dialogproduit : public QDialog
{
    Q_OBJECT

public:
    dialogproduit(QWidget *parent = nullptr);
    ~dialogproduit();

private slots:
    void on_ajouter_clicked();

    void on_tabprod_activated(const QModelIndex &index);

    void on_close_clicked();

    void on_del_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_edi_clicked();

    void on_edit_clicked();

    void on_editOk_clicked();

    void on_delete_btn_clicked();

    void on_back_clicked();

    void on_nextcrud_clicked();

    void on_pushButton_clicked();

    void on_search_cursorPositionChanged(int arg1, int arg2);

    void on_search_textChanged(const QString &arg1);

private:
    Ui::dialogproduit *ui;
    produit tmpprod;
};
#endif // DIALOGPRODUIT_H
