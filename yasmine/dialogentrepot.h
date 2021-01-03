#ifndef DIALOGENTREPOT_H
#define DIALOGENTREPOT_H

#include <QDialog>
#include "entrepot.h"
namespace Ui {
class dialogentrepot;
}

class dialogentrepot : public QDialog
{
    Q_OBJECT

public:
    explicit dialogentrepot(QWidget *parent = nullptr);
    ~dialogentrepot();

private slots:
    void on_ajouter_clicked();

    void on_tabent_activated(const QModelIndex &index);

    void on_tabWidget_currentChanged(int index);

    void on_del_clicked();

    void on_edi_clicked();

    void on_edit_clicked();

    void on_editOk_clicked();

    void on_delete_btn_clicked();

    void on_search_textChanged(const QString &arg1);

    void on_pushButton_clicked();

    void on_prevcrud_clicked();

    void on_search_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::dialogentrepot *ui;
    entrepot tmpent;

};

#endif // DIALOGENTREPOT_H
