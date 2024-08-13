//
// Created by Ale on 05/20/2024.
//

#ifndef SIM_ELEVI_GUI_H
#define SIM_ELEVI_GUI_H
#include <QtWidgets>
#include <qdebug.h>
#include <qmessagebox.h>
#include <vector>
#include <string>
#include "Service.h"

class GUI : public QWidget {
public:
    GUI(Service& srv) : srv(srv) {
        initGUI();
        loadData();
        initConnect();
    }
private:
    Service& srv;
    Elevi sel;

    QListWidget* list = new QListWidget;
    QTableWidget* tabel = new QTableWidget(0,3, this);

    QPushButton* btnExit = new QPushButton(" &Exit ");
    QPushButton* btnSort = new QPushButton(" &Sort ");
    QPushButton* btnDP = new QPushButton(" &Desen+Pictura ");
    QPushButton* btnFoto = new QPushButton(" &Fotografie ");
    QPushButton* btnMuzica = new QPushButton(" &Muzica ");
    QPushButton* btnInfo = new QPushButton(" &Info ");
    QPushButton* btnJur = new QPushButton(" &Jurnalism ");

    QLineEdit* txtAt = new QLineEdit;

    void initGUI() {
        auto* lyMain = new QHBoxLayout{};
        setLayout(lyMain);

        auto ly = new QVBoxLayout;
        ly->addWidget(list);
        lyMain->addLayout(ly);
        auto ly_b = new QVBoxLayout;
        ly_b->addWidget(btnExit);
        ly_b->addWidget(btnSort);
        lyMain->addLayout(ly_b);
        auto ly_r = new QVBoxLayout;
        auto ly_f = new QFormLayout;
        ly_f->addRow("Atelier",txtAt);
        ly_r->addLayout(ly_f);
        auto aux = new QHBoxLayout;
        aux->addWidget(btnDP);
        aux->addWidget(btnFoto);
        aux->addWidget(btnInfo);
        aux->addWidget(btnMuzica);
        aux->addWidget(btnJur);
        ly_r->addLayout(aux);
        lyMain->addLayout(ly_r);
    }

    void loadData() {

    }

    void initConnect() {

    }
};
#endif //SIM_ELEVI_GUI_H
