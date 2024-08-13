//
// Created by Ale on 05/20/2024.
//

#ifndef SIM_COMPONENTE_GUI_H
#define SIM_COMPONENTE_GUI_H
#include "Service.h"
#include <qwidget.h>
#include <qlistwidget.h>
#include <qpushbutton.h>
#include <qlineedit.h>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QMessageBox>

class GUI : public QWidget{
public:
    GUI(Service& srv) : srv{srv}{
        initGUI();
        loadData();
        initConnect();
    }
private:
    Service& srv;
    QListWidget* lProc = new QListWidget;
    QListWidget* lPlaci = new QListWidget;

    QPushButton* btnadd = new QPushButton("&add placa");
    QPushButton* btntot = new QPushButton("&Calc total");
    QPushButton* btnfilter = new QPushButton("&Filtreaza");

    QLineEdit* txtNume = new QLineEdit;
    QLineEdit* txtSoclu = new QLineEdit;
    QLineEdit* txtpret = new QLineEdit;

    string numeProc;
    int socluProc;
    int pretProc;
    int nrTProc;

    string numePlaca;
    int socluPlaca;
    int pretPlaca;

    void initGUI() {
        auto* lyMain = new QHBoxLayout;
        setLayout(lyMain);

        lyMain->addWidget(lProc);
        lyMain->addWidget(lPlaci);

        auto ly = new QVBoxLayout;
        auto dataly = new QFormLayout;

        dataly->addRow("Nume", txtNume);
        dataly->addRow("Soclu Proc", txtSoclu);
        dataly->addRow("Pret", txtpret);

        ly->addLayout(dataly);
        ly->addWidget(btnadd);
        ly->addWidget(btnfilter);
        ly->addWidget(btntot);

        lyMain->addLayout(ly);
    }

    void loadData() {
        lProc->clear();
        lPlaci->clear();
        for(const auto& el: srv.get_allProcese()){
            QString data = "";
            data += el.getNume();
            data += " - ";
            data += QString::number(el.get_nrT());

            QListWidgetItem* it = new QListWidgetItem(data);
            it->setData(Qt::UserRole, el.getPret());
            it->setData(Qt::WhatsThisRole, el.get_soclu());

            lProc->addItem(it);
        }

        for(const auto& el: srv.get_allPlaca()){
            QString data = "";
            data += el.get_nume();

            QListWidgetItem* it = new QListWidgetItem(data);
            it->setData(Qt::UserRole, el.get_pret());
            it->setData(Qt::WhatsThisRole, el.get_soclu());

            lPlaci->addItem(it);
        }
    }

    void initConnect() {
        QObject::connect(btnadd, &QPushButton::clicked, [&](){
            string nume = txtNume->text().toStdString();
            int soclu = txtSoclu->text().toInt();
            int pret = txtpret->text().toInt();

            srv.addPlaca(nume, soclu,pret);
            loadData();
        });

        QObject::connect(lPlaci, &QListWidget::itemSelectionChanged, [&](){
            auto sel = lPlaci->selectedItems();
            if(!sel.empty()){
                numePlaca = sel.at(0)->text().toStdString();
                socluPlaca = sel.at(0)->data(Qt::WhatsThisRole).toInt();
                pretPlaca = sel.at(0)->data(Qt::UserRole).toInt();
            }
        });

        //??
        QObject::connect(lProc, &QListWidget::itemSelectionChanged, [&](){
            auto sel = lProc->selectedItems();
            if(!sel.empty()){
                string info = sel.at(0)->text().toStdString();
                socluProc = sel.at(0)->data(Qt::WhatsThisRole).toInt();
                pretProc = sel.at(0)->data(Qt::UserRole).toInt();

                int found = info.find('-');
                numeProc = info.substr(0,found -1);
                info.erase(info.begin(),info.begin() + found + 1);
                //pretProc = stoi(info);
            }
        });

        QObject::connect(btntot, &QPushButton::clicked, [&](){
            Placa placa(numePlaca, socluPlaca, pretPlaca);
            Procesor proc(numeProc,nrTProc, socluProc, pretProc);

            int tot = srv.total(proc, placa);

            QMessageBox::information(nullptr, "Total", QString::number(tot));
        });

        QObject::connect(btnfilter, &QPushButton::clicked, [&](){
            Procesor proc{numeProc, nrTProc, socluProc, pretProc};
            vector<Placa> lst = srv.filter(proc);

            lPlaci->clear();

            for(const auto& el : lst){
                QString data = "";
                data += el.get_nume();
                QListWidgetItem* it = new QListWidgetItem(data);
                it->setData(Qt::UserRole, el.get_pret());
                it->setData(Qt::WhatsThisRole, el.get_soclu());

                lPlaci->addItem(it);

            }
        });
    }

};

#endif //SIM_COMPONENTE_GUI_H
