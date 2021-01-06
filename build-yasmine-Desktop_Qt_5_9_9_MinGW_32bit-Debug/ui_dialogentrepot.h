/********************************************************************************
** Form generated from reading UI file 'dialogentrepot.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGENTREPOT_H
#define UI_DIALOGENTREPOT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dialogentrepot
{
public:
    QPushButton *logout;
    QPushButton *close;
    QPushButton *back;
    QPushButton *nextmodule;
    QLabel *label_13;
    QTabWidget *tabWidget;
    QWidget *create;
    QPushButton *ajouter;
    QLineEdit *id;
    QLineEdit *num;
    QLineEdit *nbp;
    QLineEdit *lieu;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QWidget *read;
    QTableView *tabent;
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
    QPushButton *del;
    QPushButton *edi;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *txt_id;
    QLineEdit *txt_nom;
    QLineEdit *txt_marque;
    QLineEdit *txt_prix;
    QWidget *update;
    QLineEdit *id_2;
    QPushButton *edit;
    QLabel *label_3;
    QLineEdit *nouv_nom;
    QLineEdit *nouv_mar;
    QLineEdit *nouv_prix;
    QPushButton *editOk;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QWidget *deletee;
    QPushButton *delete_btn;
    QLabel *label_2;
    QLineEdit *deleteLine;
    QPushButton *prevcrud;
    QPushButton *previousmodule_2;
    QPushButton *nextcrud;

    void setupUi(QDialog *dialogentrepot)
    {
        if (dialogentrepot->objectName().isEmpty())
            dialogentrepot->setObjectName(QStringLiteral("dialogentrepot"));
        dialogentrepot->resize(652, 495);
        dialogentrepot->setStyleSheet(QLatin1String("QLabel {\n"
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
        logout = new QPushButton(dialogentrepot);
        logout->setObjectName(QStringLiteral("logout"));
        logout->setGeometry(QRect(560, 0, 61, 21));
        logout->setCursor(QCursor(Qt::PointingHandCursor));
        close = new QPushButton(dialogentrepot);
        close->setObjectName(QStringLiteral("close"));
        close->setGeometry(QRect(621, 0, 20, 20));
        back = new QPushButton(dialogentrepot);
        back->setObjectName(QStringLiteral("back"));
        back->setGeometry(QRect(40, 450, 581, 41));
        back->setCursor(QCursor(Qt::PointingHandCursor));
        nextmodule = new QPushButton(dialogentrepot);
        nextmodule->setObjectName(QStringLiteral("nextmodule"));
        nextmodule->setGeometry(QRect(620, 450, 20, 41));
        label_13 = new QLabel(dialogentrepot);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(230, 0, 151, 31));
        label_13->setStyleSheet(QLatin1String("font: 75 16pt \"MS Shell Dlg 2\";\n"
"color: white;\n"
"font-weight: none;\n"
"background-color: Black\n"
";"));
        tabWidget = new QTabWidget(dialogentrepot);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 30, 631, 411));
        create = new QWidget();
        create->setObjectName(QStringLiteral("create"));
        ajouter = new QPushButton(create);
        ajouter->setObjectName(QStringLiteral("ajouter"));
        ajouter->setGeometry(QRect(260, 270, 141, 16));
        ajouter->setCursor(QCursor(Qt::PointingHandCursor));
        id = new QLineEdit(create);
        id->setObjectName(QStringLiteral("id"));
        id->setGeometry(QRect(190, 40, 321, 20));
        num = new QLineEdit(create);
        num->setObjectName(QStringLiteral("num"));
        num->setGeometry(QRect(190, 80, 321, 20));
        nbp = new QLineEdit(create);
        nbp->setObjectName(QStringLiteral("nbp"));
        nbp->setGeometry(QRect(190, 120, 321, 20));
        lieu = new QLineEdit(create);
        lieu->setObjectName(QStringLiteral("lieu"));
        lieu->setGeometry(QRect(190, 160, 321, 20));
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
        tabWidget->addTab(create, QString());
        read = new QWidget();
        read->setObjectName(QStringLiteral("read"));
        tabent = new QTableView(read);
        tabent->setObjectName(QStringLiteral("tabent"));
        tabent->setGeometry(QRect(10, 40, 611, 251));
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
        del = new QPushButton(read);
        del->setObjectName(QStringLiteral("del"));
        del->setGeometry(QRect(140, 350, 75, 23));
        edi = new QPushButton(read);
        edi->setObjectName(QStringLiteral("edi"));
        edi->setGeometry(QRect(410, 350, 75, 23));
        horizontalLayoutWidget = new QWidget(read);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 300, 561, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        txt_id = new QLineEdit(horizontalLayoutWidget);
        txt_id->setObjectName(QStringLiteral("txt_id"));

        horizontalLayout->addWidget(txt_id);

        txt_nom = new QLineEdit(horizontalLayoutWidget);
        txt_nom->setObjectName(QStringLiteral("txt_nom"));

        horizontalLayout->addWidget(txt_nom);

        txt_marque = new QLineEdit(horizontalLayoutWidget);
        txt_marque->setObjectName(QStringLiteral("txt_marque"));

        horizontalLayout->addWidget(txt_marque);

        txt_prix = new QLineEdit(horizontalLayoutWidget);
        txt_prix->setObjectName(QStringLiteral("txt_prix"));

        horizontalLayout->addWidget(txt_prix);

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
        nouv_mar->setGeometry(QRect(380, 140, 113, 20));
        nouv_prix = new QLineEdit(update);
        nouv_prix->setObjectName(QStringLiteral("nouv_prix"));
        nouv_prix->setGeometry(QRect(170, 240, 301, 20));
        editOk = new QPushButton(update);
        editOk->setObjectName(QStringLiteral("editOk"));
        editOk->setGeometry(QRect(260, 340, 62, 21));
        editOk->setCursor(QCursor(Qt::PointingHandCursor));
        label_4 = new QLabel(update);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 120, 91, 61));
        label_5 = new QLabel(update);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(300, 130, 91, 41));
        label_6 = new QLabel(update);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(70, 240, 81, 20));
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
        prevcrud = new QPushButton(dialogentrepot);
        prevcrud->setObjectName(QStringLiteral("prevcrud"));
        prevcrud->setGeometry(QRect(220, 0, 21, 31));
        previousmodule_2 = new QPushButton(dialogentrepot);
        previousmodule_2->setObjectName(QStringLiteral("previousmodule_2"));
        previousmodule_2->setGeometry(QRect(20, 450, 21, 41));
        previousmodule_2->setStyleSheet(QStringLiteral(""));
        nextcrud = new QPushButton(dialogentrepot);
        nextcrud->setObjectName(QStringLiteral("nextcrud"));
        nextcrud->setGeometry(QRect(370, 0, 21, 31));

        retranslateUi(dialogentrepot);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(dialogentrepot);
    } // setupUi

    void retranslateUi(QDialog *dialogentrepot)
    {
        dialogentrepot->setWindowTitle(QApplication::translate("dialogentrepot", "Dialog", Q_NULLPTR));
        logout->setText(QApplication::translate("dialogentrepot", "LOGOUT", Q_NULLPTR));
        close->setText(QApplication::translate("dialogentrepot", "X", Q_NULLPTR));
        back->setText(QApplication::translate("dialogentrepot", "MAINMENU", Q_NULLPTR));
        nextmodule->setText(QApplication::translate("dialogentrepot", "\342\206\222", Q_NULLPTR));
        label_13->setText(QApplication::translate("dialogentrepot", "   ENTREPOTS", Q_NULLPTR));
        ajouter->setText(QApplication::translate("dialogentrepot", "Add", Q_NULLPTR));
        label_8->setText(QApplication::translate("dialogentrepot", "ID :", Q_NULLPTR));
        label_9->setText(QApplication::translate("dialogentrepot", "NUM :", Q_NULLPTR));
        label_10->setText(QApplication::translate("dialogentrepot", "NBP :", Q_NULLPTR));
        label_11->setText(QApplication::translate("dialogentrepot", "LIEU :", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(create), QApplication::translate("dialogentrepot", "CREATE", Q_NULLPTR));
        id_asc->setText(QApplication::translate("dialogentrepot", "           ^", Q_NULLPTR));
        id_desc->setText(QApplication::translate("dialogentrepot", "           v", Q_NULLPTR));
        num_asc->setText(QApplication::translate("dialogentrepot", "           ^", Q_NULLPTR));
        num_desc->setText(QApplication::translate("dialogentrepot", "           v", Q_NULLPTR));
        des_asc->setText(QApplication::translate("dialogentrepot", "           ^", Q_NULLPTR));
        des_desc->setText(QApplication::translate("dialogentrepot", "           v", Q_NULLPTR));
        montant_asc->setText(QApplication::translate("dialogentrepot", "           v", Q_NULLPTR));
        montant_desc->setText(QApplication::translate("dialogentrepot", "           ^", Q_NULLPTR));
        type_asc->setText(QApplication::translate("dialogentrepot", "  ^", Q_NULLPTR));
        type_desc->setText(QApplication::translate("dialogentrepot", "  v", Q_NULLPTR));
        previousmodule->setText(QApplication::translate("dialogentrepot", "\342\206\220", Q_NULLPTR));
        pushButton->setText(QApplication::translate("dialogentrepot", "PRINT", Q_NULLPTR));
        del->setText(QApplication::translate("dialogentrepot", "Delete", Q_NULLPTR));
        edi->setText(QApplication::translate("dialogentrepot", "Modify", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(read), QApplication::translate("dialogentrepot", "READ", Q_NULLPTR));
        edit->setText(QApplication::translate("dialogentrepot", "Select", Q_NULLPTR));
        label_3->setText(QApplication::translate("dialogentrepot", "ID :", Q_NULLPTR));
        editOk->setText(QApplication::translate("dialogentrepot", "Save", Q_NULLPTR));
        label_4->setText(QApplication::translate("dialogentrepot", "NEW  NUM :", Q_NULLPTR));
        label_5->setText(QApplication::translate("dialogentrepot", "NEW NBP :", Q_NULLPTR));
        label_6->setText(QApplication::translate("dialogentrepot", "NEW LIEU :", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(update), QApplication::translate("dialogentrepot", "UPDATE", Q_NULLPTR));
        delete_btn->setText(QApplication::translate("dialogentrepot", "Delete", Q_NULLPTR));
        label_2->setText(QApplication::translate("dialogentrepot", "ID :", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(deletee), QApplication::translate("dialogentrepot", "DELETE", Q_NULLPTR));
        prevcrud->setText(QApplication::translate("dialogentrepot", "\342\206\220", Q_NULLPTR));
        previousmodule_2->setText(QApplication::translate("dialogentrepot", "\342\206\220", Q_NULLPTR));
        nextcrud->setText(QApplication::translate("dialogentrepot", "\342\206\222", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class dialogentrepot: public Ui_dialogentrepot {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGENTREPOT_H
