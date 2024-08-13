//
// Created by Ale on 05/21/2024.
//

#ifndef SIM_ROCHII_GUI_H
#define SIM_ROCHII_GUI_H

#include <QWidget>
#include <QPushButton>
#include <QListWidget>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QTableWidget>
#include <QComboBox>
#include <QSpinBox>
#include <QRadioButton>
#include "Service.h"

class GUI : public QWidget {
public:
    GUI(Service& srv) : srv{srv} {
        initGUI();
        loadData();
        initConnect();
    };
private:
    Service& srv;
    int cod, pret;
    string nume, marime;
    bool dis;

    QListWidget* list = new QListWidget;
    QComboBox* combobox = new QComboBox;
    QSlider* slider = new QSlider;
    QSpinBox* spin = new QSpinBox;
    QRadioButton* radio = new QRadioButton;

    QPushButton* btnInchiriere = new QPushButton(" Inchiriere ");
    QPushButton* btnSortMarime = new QPushButton(" Sort marime ");
    QPushButton* btnSortPret = new QPushButton(" Sort pret ");
    QPushButton* btnNesort = new QPushButton(" Nesortat ");

    void initGUI() {
        auto* lyMain = new QHBoxLayout{};
        setLayout(lyMain);
        lyMain->addWidget(list);
        auto* ly = new QVBoxLayout;
        ly->addWidget(btnInchiriere);
        ly->addWidget(btnNesort);
        ly->addWidget(btnSortMarime);
        ly->addWidget(btnSortPret);
        ly->addWidget(radio);
        lyMain->addLayout(ly);

    }

    void loadData() {
        list->clear();


        for(const auto& el : srv.get_all()){
            QString data = "";
            data += el.get_nume();
            data += " | ";
            data += el.get_marime();
            data += " | ";
            data += QString::number(el.get_pret());

            QListWidgetItem* it = new QListWidgetItem(data);
            it->setData(Qt::UserRole, el.get_cod());
            it->setData(Qt::UserRole, el.get_dis());

            if (el.get_dis()) {
                it->setBackground(Qt::green);
            } else {
                it->setBackground(Qt::red);
            }
            list->addItem(it);
        }
    }

    void initConnect() {
        QObject::connect(list, &QListWidget::itemSelectionChanged, [&]() {
            auto sel = list->selectedItems();
            if (!sel.empty()) {
                QListWidgetItem* selectedItem = sel.at(0);

                // Retrieve data stored with UserRole
                cod = selectedItem->data(Qt::UserRole + 1).toInt();
                dis = selectedItem->data(Qt::UserRole + 2).toBool();

                // Parse the remaining information from the text
                QString info = selectedItem->text();
                QStringList parts = info.split(" | ");

                if (parts.size() == 3) {
                    nume = parts[0].toStdString();
                    marime = parts[1].toStdString();
                    pret = parts[2].toInt();
                }
            }
        });


        QObject::connect(btnSortMarime, &QPushButton::clicked, [&](){
            vector<Rochie> sorted;
            srv.sort_marime(sorted);
            list->clear();
            for(const auto& el : sorted){
                QString data = "";
                data += el.get_nume();
                data += " | ";
                data += el.get_marime();
                data += " | ";
                data += QString::number(el.get_pret());

                QListWidgetItem* it = new QListWidgetItem(data);
                it->setData(Qt::UserRole, el.get_cod());
                it->setData(Qt::UserRole, el.get_dis());
                if (el.get_dis()) {
                    it->setBackground(Qt::green);
                } else {
                    it->setBackground(Qt::red);
                }

                list->addItem(it);
            }
        });

        QObject::connect(btnSortPret, &QPushButton::clicked, [&](){
            vector<Rochie> sorted;
            srv.sort_pret(sorted);
            list->clear();
            for(const auto& el : sorted){
                QString data = "";
                data += el.get_nume();
                data += " | ";
                data += el.get_marime();
                data += " | ";
                data += QString::number(el.get_pret());

                QListWidgetItem* it = new QListWidgetItem(data);
                it->setData(Qt::UserRole, el.get_cod());
                it->setData(Qt::UserRole, el.get_dis());
                if (el.get_dis()) {
                    it->setBackground(Qt::green);
                } else {
                    it->setBackground(Qt::red);
                }

                list->addItem(it);
            }
        });

        QObject::connect(btnNesort, &QPushButton::clicked, [&](){
            list->clear();
            for(const auto& el : srv.get_all()){
                QString data = "";
                data += el.get_nume();
                data += " | ";
                data += el.get_marime();
                data += " | ";
                data += QString::number(el.get_pret());

                QListWidgetItem* it = new QListWidgetItem(data);
                it->setData(Qt::UserRole, el.get_cod());
                it->setData(Qt::UserRole, el.get_dis());
                if (el.get_dis()) {
                    it->setBackground(Qt::green);
                } else {
                    it->setBackground(Qt::red);
                }

                list->addItem(it);
            }
        });

        QObject::connect(btnInchiriere, &QPushButton::clicked, [&](){
            auto sel = list->selectedItems();
            if(!sel.empty()){
                QListWidgetItem* item = sel.at(0);
                bool diss = item->data(Qt::UserRole).toBool();
                if(diss){
                    item->setData(Qt::UserRole, false);
                    item->setBackground(Qt::red);

                    Rochie r(cod,nume,marime,pret, diss);
                    r.set_dis(false);
                }
                else {
                    QMessageBox::critical(this, "Error", "Nu");
                }
            }
        });
    }

};
#endif //SIM_ROCHII_GUI_H
