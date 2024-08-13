//
// Created by Ale on 06/24/2024.
//

#ifndef TRACTOARE_GUI_H
#define TRACTOARE_GUI_H

#include <QTableView>
#include <QPushButton>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QComboBox>
#include <QMessageBox>
#include <iostream>
#include <QRadioButton>
#include <QSpinBox>
#include <QPainter>
#include "Model.h"
#include "Srv.h"
#include "QWidget"
#include "QLineEdit"
#include "QLabel"
#include "domain.h"

class Painter : public QWidget{
private:
    int nr;
public:
    Painter(int nr):nr{nr}{
        this->repaint();
    }
    void paintEvent(QPaintEvent* ev) override{
        QPainter p{this};
        QPen pen(Qt::darkYellow,3);
        p.setPen(pen);
        int radius = 20;
        int spacing = 20;
        int x = spacing;
        int y = height() / 2;

        for (int i = 0; i < nr; ++i) {
            p.drawEllipse(QPoint(x, y), radius, radius);
            x += 2 * radius + spacing;
        }

    }
    void mousePressEvent(QMouseEvent* event) override {
        nr=nr-2;
        this->repaint();
    }

    void set_nr(int nrr){
        nr = nrr;
    }
};

class GUI : public QWidget{
public:
    explicit GUI(Srv& srv):srv{srv}{
        initgui();
        loadData();
        initconnect();
    }
private:
    Srv& srv;

    QTableView* tabel = new QTableView;
    Model* model = new Model(srv.sortare(srv.get_all()),srv.get_tpuri(),"");
    QPushButton* btnAdd = new QPushButton("Add");
    QLineEdit* txtid = new QLineEdit;
    QLineEdit* txtden = new QLineEdit;
    QLineEdit* txttip = new QLineEdit;
    QLineEdit* txtnrR = new QLineEdit;
    QComboBox* cmb = new QComboBox;
    //QLabel* l = new QLabel("");

    QRadioButton* btn1 = new QRadioButton;
    QLabel* l1 = new QLabel("2");

    QSpinBox* spin = new QSpinBox;
    Tractor sel_tr;

    Painter* paint = new Painter(0);


    void initgui(){
        tabel->setModel(model);
        auto* lymain = new QHBoxLayout{};
        setLayout(lymain);
        lymain->addWidget(tabel);

        auto lydr = new QVBoxLayout;
        auto lyf = new QFormLayout;
        lyf->addRow("id",txtid);
        lyf->addRow("denumire",txtden);
        lyf->addRow("tip",txttip);
        lyf->addRow("nr roti",txtnrR);
        lydr->addLayout(lyf);
        lydr->addWidget(paint);
        lydr->addWidget(l1);
        lydr->addWidget(btn1);
        spin->setSingleStep(2);
        spin->setRange(2,16);
        lydr->addWidget(spin);
        lydr->addWidget(btnAdd);
        lydr->addWidget(cmb);
        //lydr->addWidget(l);
        QStringList lst;
        for(auto& e :srv.get_tpuri()){
            QString tipp = QString::fromStdString(e.first);
            lst.push_back(tipp);
        }
        cmb->addItems(lst);
        lymain->addLayout(lydr);

    }

    void loadData(){
        string tip = cmb->currentText().toStdString();
        this->repaint();
        model->set(srv.sortare(srv.get_all()),srv.get_tpuri(),tip);
    }

    void initconnect(){


        QObject::connect(tabel->selectionModel(),&QItemSelectionModel::selectionChanged,[this](const QItemSelection& selcted){
            if(!selcted.indexes().isEmpty()){
                QModelIndex index = selcted.indexes().first();
                int line = index.row();

                auto id_ind = tabel->model()->index(line,0);
                auto den_ind = tabel->model()->index(line,1);
                auto tip_ind = tabel->model()->index(line,2);
                auto nr_ind = tabel->model()->index(line,3);

                QString id = tabel->model()->data(id_ind,Qt::DisplayRole).toString();
                QString den = tabel->model()->data(den_ind,Qt::DisplayRole).toString();
                QString tip = tabel->model()->data(tip_ind,Qt::DisplayRole).toString();
                QString nr = tabel->model()->data(nr_ind,Qt::DisplayRole).toString();

                txtid->setText(id);
                txtden->setText(den);
                txttip->setText(tip);
                txtnrR->setText(nr);

                sel_tr=Tractor(id.toInt(),den.toStdString(),tip.toStdString(),nr.toInt());
                paint->set_nr(nr.toInt());
                this->repaint();

            }
        });
        QObject::connect(btnAdd, &QPushButton::clicked, [&](){
           auto id = txtid->text().toInt();
           auto den = txtden->text().toStdString();
           auto tip = txttip->text().toStdString();
           auto nr = txtnrR->text().toInt();

           try{
               srv.add(id,den,tip,nr);
               loadData();

           }catch (SrvEx&){
               QMessageBox::critical(this,"Error","Date invalide");
           }
           sel_tr=Tractor();
        });

        QObject::connect(cmb,&QComboBox::currentTextChanged,[&](){
            //string tip = cmb->currentText().toStdString();
            //l->setText(QString::fromStdString(tip));

            loadData();
        });

        QObject::connect(btn1,&QRadioButton::clicked, [&](){
            QString label1 = l1->text();
            txtnrR->setText(label1);
        } );

        QObject::connect(spin, &QSpinBox::valueChanged, [&](){
            QString val = spin->text();
            txtnrR->setText(val);
        });
    }



};
#endif //TRACTOARE_GUI_H
