//
// Created by Ale on 06/25/2024.
//

#ifndef UNTITLED1_GUI_H
#define UNTITLED1_GUI_H

#include <QTableView>
#include <QPushButton>
#include <QHBoxLayout>
#include "Model.h"
#include "Srv.h"
#include "QWidget"

class GUI : public QWidget{
public:
    explicit GUI(Srv& srv):srv(srv){
        initgui();
        initconnect();
        reload();
    }
private:
    Srv& srv;
    QTableView* tabel = new QTableView;
    Model* model = new Model(srv.sort_nr(srv.get_all()));
    Masina sel_m;
    vector<string> undo;
    vector<string> redo;

    QPushButton* btndel = new QPushButton("del");
    QPushButton* btnplus = new QPushButton("+");
    QPushButton* btnminus = new QPushButton("-");
    QPushButton* btnundo = new QPushButton("undo");
    QPushButton* btnredo = new QPushButton("redo");

    void initgui(){
        tabel->setModel(model);
        auto* lymain = new QHBoxLayout{};
        setLayout(lymain);
        lymain->addWidget(tabel);

        auto ly_dr = new QVBoxLayout;
        ly_dr->addWidget(btndel);
        ly_dr->addWidget(btnminus);
        ly_dr->addWidget(btnplus);
        ly_dr->addWidget(btnundo);
        ly_dr->addWidget(btnredo);

        lymain->addLayout(ly_dr);
    }

    void reload(){
        model->set(srv.sort_nr(srv.get_all()));
    }

    void initconnect(){

        QObject::connect(tabel->selectionModel(),&QItemSelectionModel::selectionChanged,[this](const QItemSelection& selcted){
            if(!selcted.indexes().isEmpty()){
                QModelIndex index = selcted.indexes().first();
                int line = index.row();

                auto nr_ind = tabel->model()->index(line,0);
                auto den_ind = tabel->model()->index(line,1);
                auto an_ind = tabel->model()->index(line,2);
                auto tip_ind = tabel->model()->index(line,3);

                QString nr = tabel->model()->data(nr_ind,Qt::DisplayRole).toString();
                QString den = tabel->model()->data(den_ind,Qt::DisplayRole).toString();
                QString an = tabel->model()->data(an_ind,Qt::DisplayRole).toString();
                QString tip = tabel->model()->data(tip_ind,Qt::DisplayRole).toString();

                sel_m=Masina(nr.toStdString(),den.toStdString(),an.toInt(),tip.toStdString());

            }
        });

        QObject::connect(btndel, &QPushButton::clicked, [&](){
            if(tabel->selectionModel()->selectedIndexes().isEmpty()){
                return;
            }
            undo.push_back("del");
            srv.del(sel_m);
            sel_m = Masina();
            reload();
        });

        QObject::connect(btnminus, &QPushButton::clicked,[&](){
            undo.push_back("-");
            redo.push_back("-");
            srv.modify("-");
            reload();
        });

        QObject::connect(btnplus, &QPushButton::clicked, [&](){
            undo.push_back("+");
            redo.push_back("+");
            srv.modify("+");
            reload();
        });

        QObject::connect(btnundo,&QPushButton::clicked,[&](){
                string ultim = undo[undo.size()-1];
                if(ultim == "-"){
                    srv.modify("+");
                    reload();
                }
                else if(ultim == "+"){
                    srv.modify("-");
                    reload();
                }
        });

        QObject::connect(btnredo, &QPushButton::clicked, [&](){
            string ultim = redo[redo.size()-1];
            if(ultim == "-"){
                srv.modify("-");
                reload();
            }
            else if(ultim == "+"){
                srv.modify("+");
                reload();
            }
        });

    }
};
#endif //UNTITLED1_GUI_H
