//
// Created by Ale on 05/19/2024.
//

#ifndef SIM_APARTAMENTE_GUI_H
#define SIM_APARTAMENTE_GUI_H
#include <QtWidgets>
#include <qdebug.h>
#include <qmessagebox.h>
#include <vector>
#include <string>
#include "Service.h"
#include "Apartament.h"
#include "Repo.h"

class GUI: public QWidget {
public:
    explicit GUI(Service& srv) : srv(srv) {
        initGUI();
        loadData();
        initConnect();
    }
private:
    Service& srv;
    Apartamente sel_ap;

    QListWidget* list = new QListWidget;

    QPushButton* btnAdd = new QPushButton(" &Add ");
    QPushButton* btnDel = new QPushButton(" &Delete ");
    QPushButton* btnFsup = new QPushButton(" &Filter sup ");
    QPushButton* btnFpret = new QPushButton(" &Filter price ");
    QPushButton* btnExit = new QPushButton(" &Exit ");

    QLineEdit* txtSup = new QLineEdit;
    QLineEdit* txtStr = new QLineEdit;
    QLineEdit* txtPret = new QLineEdit;
    QLineEdit* MinSup = new QLineEdit;
    QLineEdit* MaxSup = new QLineEdit;
    QLineEdit* MinPret = new QLineEdit;
    QLineEdit* MaxPret = new QLineEdit;

    void initGUI() {
        setWindowTitle("Apartamente");

        auto* lyMain = new QHBoxLayout{};
        setLayout(lyMain);

        //layot lista

        auto layout = new QVBoxLayout;
        /*
        auto label = new QLabel{"List"};
        auto hlayout = new QHBoxLayout;
        hlayout->addStretch();
        hlayout->addWidget(label);
        hlayout->addStretch();

        layout->addLayout(hlayout);
         */
        layout->addWidget(list);

        lyMain->addLayout(layout);

        //layout btn
        auto lyBtn = new QVBoxLayout;

        lyBtn->addWidget(btnAdd);
        lyBtn->addWidget(btnDel);
        lyBtn->addWidget(btnExit);

        lyMain->addLayout(lyBtn);

        //layout campuri
        auto lyR = new QVBoxLayout;
        auto lyF = new QFormLayout;

        lyF->addRow("Strada",txtStr);
        lyF->addRow("Suprafa",txtSup);
        lyF->addRow("Pret",txtPret);

        lyR->addLayout(lyF);

        auto aux = new QHBoxLayout;
        aux->addWidget(btnFsup);
        aux->addWidget(btnFpret);

        lyR->addLayout(aux);

        auto lyf = new QFormLayout;
        lyf->addRow("Sup min", MinSup);
        lyf->addRow("Sup max",MaxSup);
        lyf->addRow("Pret min",MinPret);
        lyf->addRow("Pret max",MaxPret);

        lyR->addLayout(lyf);

        lyMain->addLayout(lyR);
    }

    void loadData() {
        list->clear();
        QString str,sup,pret;

        vector<Apartamente> elems = srv.get_all();
        for(const auto& ap: elems) {
            QString e;
            str = (QString::fromStdString(ap.get_str()));
            sup = (QString::number(ap.get_sup()));
            pret = (QString::number(ap.get_pret()));

            e = str + " | " + sup + " | " + pret;
            list->addItem(e);
        }
    }

    void initConnect() {

        QObject::connect(list, &QListWidget::itemClicked, [&](QListWidgetItem* item){
            QString text = item->text();
            QStringList elems = text.split(" | ");

            txtStr->setText(elems[0]);
            txtSup->setText(elems[1]);
            txtPret->setText(elems[2]);

            auto str = elems[0].toStdString();
            auto sup = elems[1].toInt();
            auto pret = elems[2].toInt();

            sel_ap = Apartamente(str,sup,pret);
        });

        QObject::connect(btnExit, &QPushButton::clicked, [&](){
            close();
        });

        QObject::connect(btnAdd, &QPushButton::clicked, [&](){
            auto str = txtStr->text().toStdString();
            auto sup = txtSup->text().toInt();
            auto pret = txtPret->text().toInt();

            srv.add(str,sup,pret);

            loadData();
            txtPret->clear();
            txtSup->clear();
            txtStr->clear();
        });

        QObject::connect(btnDel, &QPushButton::clicked, [&](){
            srv.del(sel_ap);
            loadData();
            sel_ap = Apartamente();
        });

        QObject::connect(btnFsup, &QPushButton::clicked, [&](){
            int min = MinSup->text().toInt();
            int max = MaxSup->text().toInt();
            vector<Apartamente> fil;
            srv.filter_sup(min, max,fil);

            auto* d = new QDialog;
            auto* ly = new QVBoxLayout(d);
            auto* fill = new QListWidget(d);

            for(const auto& ap: fil) {
                QString e;
                QString str = (QString::fromStdString(ap.get_str()));
                QString sup = (QString::number(ap.get_sup()));
                QString pret = (QString::number(ap.get_pret()));

                e = str + " | " + sup + " | " + pret;
                fill->addItem(e);
            }
            ly->addWidget(fill);
            d->exec();
        });

        QObject::connect(btnFpret, &QPushButton::clicked, [&](){
            int min = MinPret->text().toInt();
            int max = MaxPret->text().toInt();
            vector<Apartamente> fil;
            srv.filter_pret(min, max,fil);

            auto* d = new QDialog;
            auto* ly = new QVBoxLayout(d);
            auto* fill = new QListWidget(d);

            for(const auto& ap: fil) {
                QString e;
                QString str = (QString::fromStdString(ap.get_str()));
                QString sup = (QString::number(ap.get_sup()));
                QString pret = (QString::number(ap.get_pret()));

                e = str + " | " + sup + " | " + pret;
                fill->addItem(e);
            }
            ly->addWidget(fill);
            d->exec();
        });
    }
};
#endif //SIM_APARTAMENTE_GUI_H
