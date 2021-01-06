/********************************************************************************
** Form generated from reading UI file 'dialogproduit.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGPRODUIT_H
#define UI_DIALOGPRODUIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dialogproduit
{
public:
    QPushButton *back;
    QLabel *label_13;
    QPushButton *nextcrud;
    QPushButton *nextmodule;
    QPushButton *prevcrud;
    QPushButton *logout;
    QPushButton *previousmodule_2;
    QTabWidget *tabWidget;
    QWidget *create;
    QPushButton *ajouter;
    QLineEdit *id;
    QLineEdit *nom;
    QLineEdit *marque;
    QLineEdit *prix;
    QLineEdit *nombre;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label;
    QLineEdit *ref;
    QWidget *read;
    QTableView *tabprod;
    QLineEdit *search;
    QPushButton *id_asc;
    QPushButton *id_desc;
    QPushButton *num_asc;
    QPushButton *num_desc;
    QPushButton *des_asc;
    QPushButton *des_desc;
    QPushButton *montant_asc;
    QPushButton *montant_desc;
    QPushButton *type_asc;
    QPushButton *type_desc;
    QPushButton *previousmodule;
    QPushButton *pushButton;
    QLineEdit *txt_nombre;
    QLineEdit *txt_marque;
    QPushButton *del;
    QLineEdit *txt_id;
    QLineEdit *txt_nom;
    QPushButton *edi;
    QLineEdit *txt_prix;
    QLineEdit *txt_ref;
    QWidget *update;
    QLineEdit *id_2;
    QPushButton *edit;
    QLabel *label_3;
    QLineEdit *nouv_nom;
    QLineEdit *nouv_mar;
    QLineEdit *nouv_prix;
    QLineEdit *nouv_nombre;
    QPushButton *editOk;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *nouv_ref;
    QLabel *label_14;
    QWidget *deletee;
    QPushButton *delete_btn;
    QLabel *label_2;
    QLineEdit *deleteLine;
    QPushButton *close;

    void setupUi(QDialog *dialogproduit)
    {
        if (dialogproduit->objectName().isEmpty())
            dialogproduit->setObjectName(QStringLiteral("dialogproduit"));
        dialogproduit->resize(633, 525);
        dialogproduit->setStyleSheet(QLatin1String("QLabel {\n"
"font-weight: bold;\n"
"font-size: 10px;\n"
"}\n"
"QLineEdit {\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid gray;\n"
"border-radius: 8px;\n"
"}\n"
"\n"
"\n"
"QPushButton {\n"
"color: white;\n"
"font-weight: bold;\n"
"background-color: black;\n"
"border-width: 1px;\n"
"border-color: #339;\n"
"border-style: solid;\n"
"border-radius: 7;\n"
"padding: 3px;\n"
"font-size: 10px;\n"
"padding-left: 5px;\n"
"padding-right: 5px;\n"
"\n"
"}\n"
"QPushButton:hover { background-color: white;\n"
"color:black;\n"
"text-decoration: underline; }"));
        back = new QPushButton(dialogproduit);
        back->setObjectName(QStringLiteral("back"));
        back->setGeometry(QRect(29, 460, 581, 41));
        back->setCursor(QCursor(Qt::PointingHandCursor));
        label_13 = new QLabel(dialogproduit);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(219, 10, 151, 31));
        label_13->setStyleSheet(QLatin1String("font: 75 16pt \"MS Shell Dlg 2\";\n"
"color: white;\n"
"font-weight: none;\n"
"background-color: Black\n"
";"));
        nextcrud = new QPushButton(dialogproduit);
        nextcrud->setObjectName(QStringLiteral("nextcrud"));
        nextcrud->setGeometry(QRect(359, 10, 21, 31));
        nextmodule = new QPushButton(dialogproduit);
        nextmodule->setObjectName(QStringLiteral("nextmodule"));
        nextmodule->setGeometry(QRect(609, 460, 20, 41));
        prevcrud = new QPushButton(dialogproduit);
        prevcrud->setObjectName(QStringLiteral("prevcrud"));
        prevcrud->setGeometry(QRect(209, 10, 21, 31));
        logout = new QPushButton(dialogproduit);
        logout->setObjectName(QStringLiteral("logout"));
        logout->setGeometry(QRect(549, 10, 61, 21));
        logout->setCursor(QCursor(Qt::PointingHandCursor));
        previousmodule_2 = new QPushButton(dialogproduit);
        previousmodule_2->setObjectName(QStringLiteral("previousmodule_2"));
        previousmodule_2->setGeometry(QRect(9, 460, 21, 41));
        previousmodule_2->setStyleSheet(QStringLiteral(""));
        tabWidget = new QTabWidget(dialogproduit);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(-1, 40, 631, 411));
        create = new QWidget();
        create->setObjectName(QStringLiteral("create"));
        ajouter = new QPushButton(create);
        ajouter->setObjectName(QStringLiteral("ajouter"));
        ajouter->setGeometry(QRect(260, 270, 141, 16));
        ajouter->setCursor(QCursor(Qt::PointingHandCursor));
        id = new QLineEdit(create);
        id->setObjectName(QStringLiteral("id"));
        id->setGeometry(QRect(190, 40, 321, 20));
        nom = new QLineEdit(create);
        nom->setObjectName(QStringLiteral("nom"));
        nom->setGeometry(QRect(190, 80, 321, 20));
        marque = new QLineEdit(create);
        marque->setObjectName(QStringLiteral("marque"));
        marque->setGeometry(QRect(190, 120, 321, 20));
        prix = new QLineEdit(create);
        prix->setObjectName(QStringLiteral("prix"));
        prix->setGeometry(QRect(190, 160, 321, 20));
        nombre = new QLineEdit(create);
        nombre->setObjectName(QStringLiteral("nombre"));
        nombre->setGeometry(QRect(190, 200, 321, 20));
        label_8 = new QLabel(create);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(130, 40, 47, 13));
        label_9 = new QLabel(create);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(120, 80, 61, 16));
        label_10 = new QLabel(create);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(120, 120, 51, 20));
        label_11 = new QLabel(create);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(120, 160, 47, 16));
        label_12 = new QLabel(create);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(120, 200, 47, 13));
        label = new QLabel(create);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 240, 61, 16));
        ref = new QLineEdit(create);
        ref->setObjectName(QStringLiteral("ref"));
        ref->setGeometry(QRect(190, 240, 321, 20));
        tabWidget->addTab(create, QString());
        read = new QWidget();
        read->setObjectName(QStringLiteral("read"));
        tabprod = new QTableView(read);
        tabprod->setObjectName(QStringLiteral("tabprod"));
        tabprod->setGeometry(QRect(10, 40, 611, 251));
        search = new QLineEdit(read);
        search->setObjectName(QStringLiteral("search"));
        search->setGeometry(QRect(490, 10, 113, 20));
        id_asc = new QPushButton(read);
        id_asc->setObjectName(QStringLiteral("id_asc"));
        id_asc->setGeometry(QRect(20, 40, 141, 21));
        id_asc->setStyleSheet(QLatin1String("\n"
"QPushButton {\n"
"color: grey;\n"
"font-weight: none;\n"
"background-color: none;\n"
"border-width: none;\n"
"border-color: none;\n"
"border-style: none;\n"
"border-radius: none;\n"
"padding: none;\n"
"\n"
"\n"
"}\n"
"QPushButton:hover { background-color: none;\n"
"color:black;\n"
"text-decoration: none; }"));
        id_desc = new QPushButton(read);
        id_desc->setObjectName(QStringLiteral("id_desc"));
        id_desc->setGeometry(QRect(30, 40, 121, 21));
        id_desc->setStyleSheet(QLatin1String("\n"
"QPushButton {\n"
"color: grey;\n"
"font-weight: none;\n"
"background-color: none;\n"
"border-width: none;\n"
"border-color: none;\n"
"border-style: none;\n"
"border-radius: none;\n"
"padding: none;\n"
"\n"
"\n"
"}\n"
"QPushButton:hover { background-color: none;\n"
"color:black;\n"
"text-decoration: none; }"));
        num_asc = new QPushButton(read);
        num_asc->setObjectName(QStringLiteral("num_asc"));
        num_asc->setGeometry(QRect(130, 40, 121, 21));
        num_asc->setStyleSheet(QLatin1String("\n"
"QPushButton {\n"
"color: grey;\n"
"font-weight: none;\n"
"background-color: none;\n"
"border-width: none;\n"
"border-color: none;\n"
"border-style: none;\n"
"border-radius: none;\n"
"padding: none;\n"
"\n"
"\n"
"}\n"
"QPushButton:hover { background-color: none;\n"
"color:black;\n"
"text-decoration: none; }"));
        num_desc = new QPushButton(read);
        num_desc->setObjectName(QStringLiteral("num_desc"));
        num_desc->setGeometry(QRect(130, 40, 121, 21));
        num_desc->setStyleSheet(QLatin1String("\n"
"QPushButton {\n"
"color: grey;\n"
"font-weight: none;\n"
"background-color: none;\n"
"border-width: none;\n"
"border-color: none;\n"
"border-style: none;\n"
"border-radius: none;\n"
"padding: none;\n"
"\n"
"\n"
"}\n"
"QPushButton:hover { background-color: none;\n"
"color:black;\n"
"text-decoration: none; }"));
        des_asc = new QPushButton(read);
        des_asc->setObjectName(QStringLiteral("des_asc"));
        des_asc->setGeometry(QRect(240, 40, 121, 21));
        des_asc->setStyleSheet(QLatin1String("\n"
"QPushButton {\n"
"color: grey;\n"
"font-weight: none;\n"
"background-color: none;\n"
"border-width: none;\n"
"border-color: none;\n"
"border-style: none;\n"
"border-radius: none;\n"
"padding: none;\n"
"\n"
"\n"
"}\n"
"QPushButton:hover { background-color: none;\n"
"color:black;\n"
"text-decoration: none; }"));
        des_desc = new QPushButton(read);
        des_desc->setObjectName(QStringLiteral("des_desc"));
        des_desc->setGeometry(QRect(240, 40, 121, 21));
        des_desc->setStyleSheet(QLatin1String("\n"
"QPushButton {\n"
"color: grey;\n"
"font-weight: none;\n"
"background-color: none;\n"
"border-width: none;\n"
"border-color: none;\n"
"border-style: none;\n"
"border-radius: none;\n"
"padding: none;\n"
"\n"
"\n"
"}\n"
"QPushButton:hover { background-color: none;\n"
"color:black;\n"
"text-decoration: none; }"));
        montant_asc = new QPushButton(read);
        montant_asc->setObjectName(QStringLiteral("montant_asc"));
        montant_asc->setGeometry(QRect(340, 40, 131, 21));
        montant_asc->setStyleSheet(QLatin1String("\n"
"QPushButton {\n"
"color: grey;\n"
"font-weight: none;\n"
"background-color: none;\n"
"border-width: none;\n"
"border-color: none;\n"
"border-style: none;\n"
"border-radius: none;\n"
"padding: none;\n"
"\n"
"\n"
"}\n"
"QPushButton:hover { background-color: none;\n"
"color:black;\n"
"text-decoration: none; }"));
        montant_desc = new QPushButton(read);
        montant_desc->setObjectName(QStringLiteral("montant_desc"));
        montant_desc->setGeometry(QRect(340, 40, 131, 21));
        montant_desc->setStyleSheet(QLatin1String("\n"
"QPushButton {\n"
"color: grey;\n"
"font-weight: none;\n"
"background-color: none;\n"
"border-width: none;\n"
"border-color: none;\n"
"border-style: none;\n"
"border-radius: none;\n"
"padding: none;\n"
"\n"
"\n"
"}\n"
"QPushButton:hover { background-color: none;\n"
"color:black;\n"
"text-decoration: none; }"));
        type_asc = new QPushButton(read);
        type_asc->setObjectName(QStringLiteral("type_asc"));
        type_asc->setGeometry(QRect(470, 40, 91, 21));
        type_asc->setStyleSheet(QLatin1String("\n"
"QPushButton {\n"
"color: grey;\n"
"font-weight: none;\n"
"background-color: none;\n"
"border-width: none;\n"
"border-color: none;\n"
"border-style: none;\n"
"border-radius: none;\n"
"padding: none;\n"
"\n"
"\n"
"}\n"
"QPushButton:hover { background-color: none;\n"
"color:black;\n"
"text-decoration: none; }"));
        type_desc = new QPushButton(read);
        type_desc->setObjectName(QStringLiteral("type_desc"));
        type_desc->setGeometry(QRect(470, 40, 91, 21));
        type_desc->setStyleSheet(QLatin1String("\n"
"QPushButton {\n"
"color: grey;\n"
"font-weight: none;\n"
"background-color: none;\n"
"border-width: none;\n"
"border-color: none;\n"
"border-style: none;\n"
"border-radius: none;\n"
"padding: none;\n"
"\n"
"\n"
"}\n"
"QPushButton:hover { background-color: none;\n"
"color:black;\n"
"text-decoration: none; }"));
        previousmodule = new QPushButton(read);
        previousmodule->setObjectName(QStringLiteral("previousmodule"));
        previousmodule->setGeometry(QRect(320, 400, 21, 41));
        previousmodule->setStyleSheet(QStringLiteral(""));
        pushButton = new QPushButton(read);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 10, 61, 23));
        txt_nombre = new QLineEdit(read);
        txt_nombre->setObjectName(QStringLiteral("txt_nombre"));
        txt_nombre->setGeometry(QRect(420, 310, 91, 20));
        txt_marque = new QLineEdit(read);
        txt_marque->setObjectName(QStringLiteral("txt_marque"));
        txt_marque->setGeometry(QRect(210, 310, 91, 20));
        del = new QPushButton(read);
        del->setObjectName(QStringLiteral("del"));
        del->setGeometry(QRect(140, 350, 75, 23));
        txt_id = new QLineEdit(read);
        txt_id->setObjectName(QStringLiteral("txt_id"));
        txt_id->setGeometry(QRect(10, 310, 91, 20));
        txt_nom = new QLineEdit(read);
        txt_nom->setObjectName(QStringLiteral("txt_nom"));
        txt_nom->setGeometry(QRect(110, 310, 91, 20));
        edi = new QPushButton(read);
        edi->setObjectName(QStringLiteral("edi"));
        edi->setGeometry(QRect(410, 350, 75, 23));
        txt_prix = new QLineEdit(read);
        txt_prix->setObjectName(QStringLiteral("txt_prix"));
        txt_prix->setGeometry(QRect(310, 310, 91, 20));
        txt_ref = new QLineEdit(read);
        txt_ref->setObjectName(QStringLiteral("txt_ref"));
        txt_ref->setGeometry(QRect(520, 310, 91, 20));
        tabWidget->addTab(read, QString());
        update = new QWidget();
        update->setObjectName(QStringLiteral("update"));
        id_2 = new QLineEdit(update);
        id_2->setObjectName(QStringLiteral("id_2"));
        id_2->setGeometry(QRect(210, 50, 113, 20));
        edit = new QPushButton(update);
        edit->setObjectName(QStringLiteral("edit"));
        edit->setGeometry(QRect(430, 50, 62, 21));
        edit->setCursor(QCursor(Qt::PointingHandCursor));
        label_3 = new QLabel(update);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(120, 50, 61, 21));
        nouv_nom = new QLineEdit(update);
        nouv_nom->setObjectName(QStringLiteral("nouv_nom"));
        nouv_nom->setGeometry(QRect(130, 140, 113, 20));
        nouv_mar = new QLineEdit(update);
        nouv_mar->setObjectName(QStringLiteral("nouv_mar"));
        nouv_mar->setGeometry(QRect(390, 140, 113, 20));
        nouv_prix = new QLineEdit(update);
        nouv_prix->setObjectName(QStringLiteral("nouv_prix"));
        nouv_prix->setGeometry(QRect(130, 240, 113, 20));
        nouv_nombre = new QLineEdit(update);
        nouv_nombre->setObjectName(QStringLiteral("nouv_nombre"));
        nouv_nombre->setGeometry(QRect(390, 240, 113, 20));
        editOk = new QPushButton(update);
        editOk->setObjectName(QStringLiteral("editOk"));
        editOk->setGeometry(QRect(260, 340, 62, 21));
        editOk->setCursor(QCursor(Qt::PointingHandCursor));
        label_4 = new QLabel(update);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 130, 91, 51));
        label_5 = new QLabel(update);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(280, 130, 91, 31));
        label_6 = new QLabel(update);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(40, 240, 81, 20));
        label_7 = new QLabel(update);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(290, 240, 91, 21));
        nouv_ref = new QLineEdit(update);
        nouv_ref->setObjectName(QStringLiteral("nouv_ref"));
        nouv_ref->setGeometry(QRect(230, 300, 113, 20));
        label_14 = new QLabel(update);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(160, 300, 61, 16));
        tabWidget->addTab(update, QString());
        deletee = new QWidget();
        deletee->setObjectName(QStringLiteral("deletee"));
        delete_btn = new QPushButton(deletee);
        delete_btn->setObjectName(QStringLiteral("delete_btn"));
        delete_btn->setGeometry(QRect(260, 210, 62, 21));
        delete_btn->setCursor(QCursor(Qt::PointingHandCursor));
        label_2 = new QLabel(deletee);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(90, 130, 47, 21));
        deleteLine = new QLineEdit(deletee);
        deleteLine->setObjectName(QStringLiteral("deleteLine"));
        deleteLine->setGeometry(QRect(150, 130, 291, 20));
        tabWidget->addTab(deletee, QString());
        close = new QPushButton(dialogproduit);
        close->setObjectName(QStringLiteral("close"));
        close->setGeometry(QRect(610, 10, 20, 20));

        retranslateUi(dialogproduit);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(dialogproduit);
    } // setupUi

    void retranslateUi(QDialog *dialogproduit)
    {
        dialogproduit->setWindowTitle(QApplication::translate("dialogproduit", "dialogproduit", Q_NULLPTR));
        back->setText(QApplication::translate("dialogproduit", "MAINMENU", Q_NULLPTR));
        label_13->setText(QApplication::translate("dialogproduit", "    PRODUITS", Q_NULLPTR));
        nextcrud->setText(QApplication::translate("dialogproduit", "\342\206\222", Q_NULLPTR));
        nextmodule->setText(QApplication::translate("dialogproduit", "\342\206\222", Q_NULLPTR));
        prevcrud->setText(QApplication::translate("dialogproduit", "\342\206\220", Q_NULLPTR));
        logout->setText(QApplication::translate("dialogproduit", "LOGOUT", Q_NULLPTR));
        previousmodule_2->setText(QApplication::translate("dialogproduit", "\342\206\220", Q_NULLPTR));
        ajouter->setText(QApplication::translate("dialogproduit", "Add", Q_NULLPTR));
        label_8->setText(QApplication::translate("dialogproduit", "ID :", Q_NULLPTR));
        label_9->setText(QApplication::translate("dialogproduit", "Nom :", Q_NULLPTR));
        label_10->setText(QApplication::translate("dialogproduit", "Marque :", Q_NULLPTR));
        label_11->setText(QApplication::translate("dialogproduit", "Prix :", Q_NULLPTR));
        label_12->setText(QApplication::translate("dialogproduit", "Nombre :", Q_NULLPTR));
        label->setText(QApplication::translate("dialogproduit", "Reference:", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(create), QApplication::translate("dialogproduit", "CREATE", Q_NULLPTR));
        id_asc->setText(QApplication::translate("dialogproduit", "           ^", Q_NULLPTR));
        id_desc->setText(QApplication::translate("dialogproduit", "           v", Q_NULLPTR));
        num_asc->setText(QApplication::translate("dialogproduit", "           ^", Q_NULLPTR));
        num_desc->setText(QApplication::translate("dialogproduit", "           v", Q_NULLPTR));
        des_asc->setText(QApplication::translate("dialogproduit", "           ^", Q_NULLPTR));
        des_desc->setText(QApplication::translate("dialogproduit", "           v", Q_NULLPTR));
        montant_asc->setText(QApplication::translate("dialogproduit", "           v", Q_NULLPTR));
        montant_desc->setText(QApplication::translate("dialogproduit", "           ^", Q_NULLPTR));
        type_asc->setText(QApplication::translate("dialogproduit", "  ^", Q_NULLPTR));
        type_desc->setText(QApplication::translate("dialogproduit", "  v", Q_NULLPTR));
        previousmodule->setText(QApplication::translate("dialogproduit", "\342\206\220", Q_NULLPTR));
        pushButton->setText(QApplication::translate("dialogproduit", "PRINT", Q_NULLPTR));
        del->setText(QApplication::translate("dialogproduit", "Delete", Q_NULLPTR));
        edi->setText(QApplication::translate("dialogproduit", "Modify", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(read), QApplication::translate("dialogproduit", "READ", Q_NULLPTR));
        edit->setText(QApplication::translate("dialogproduit", "Select", Q_NULLPTR));
        label_3->setText(QApplication::translate("dialogproduit", "ID :", Q_NULLPTR));
        editOk->setText(QApplication::translate("dialogproduit", "Save", Q_NULLPTR));
        label_4->setText(QApplication::translate("dialogproduit", "Nouveau Nom", Q_NULLPTR));
        label_5->setText(QApplication::translate("dialogproduit", "Nouveau Marque", Q_NULLPTR));
        label_6->setText(QApplication::translate("dialogproduit", "Nouveau Prix", Q_NULLPTR));
        label_7->setText(QApplication::translate("dialogproduit", "Nouveau Nombre", Q_NULLPTR));
        label_14->setText(QApplication::translate("dialogproduit", "Nouvea Ref", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(update), QApplication::translate("dialogproduit", "UPDATE", Q_NULLPTR));
        delete_btn->setText(QApplication::translate("dialogproduit", "Delete", Q_NULLPTR));
        label_2->setText(QApplication::translate("dialogproduit", "ID :", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(deletee), QApplication::translate("dialogproduit", "DELETE", Q_NULLPTR));
        close->setText(QApplication::translate("dialogproduit", "X", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class dialogproduit: public Ui_dialogproduit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGPRODUIT_H
