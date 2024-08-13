//
// Created by Ale on 05/22/2024.
//

#ifndef TEST_OOP_GUI_H
#define TEST_OOP_GUI_H

#include <QTableWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QFormLayout>
#include <iostream>
#include <QCheckBox>
#include "QLineEdit"
#include "Service.h"
#include "QMessageBox"
#include "QLabel"

class GUI : public QWidget{
public:
    GUI(Service& srv): srv{srv}{
        initGUI();
        loadData();
        initConnect();
    };
private:
    Service& srv;

    QTableWidget* tabel = new QTableWidget(0,4, this);

    QPushButton* btnFil = new QPushButton(" &Filter ");
    QPushButton* btnRes = new QPushButton(" &Resetare ");
    QPushButton* btnV = new QPushButton(" &Verificare distribuire ");
    QLabel* label = new QLabel("Numar: 0");
    QSlider* slider = new QSlider(Qt::Horizontal, this);

    QLineEdit* txtcoef = new QLineEdit;
    QCheckBox* ch = new QCheckBox(" Cu modificare");

    string const nume, tara;
    int coef, urna;

    void initGUI() {
        auto* lyMain = new QHBoxLayout{};
        setLayout(lyMain);

        lyMain->addWidget(tabel);
        auto lyb = new QVBoxLayout;
        lyb->addWidget(btnFil);
        lyb->addWidget(btnRes);
        lyb->addWidget(btnV);
        lyb->addWidget(ch);
        auto ly = new QVBoxLayout;
        auto dataly = new QFormLayout;

        dataly->addRow("Coef", txtcoef);

        ly->addLayout(dataly);
        slider->setRange(0,100);
        slider->setValue(0);
        lyb->addWidget(label);
        lyb->addWidget(slider);


        lyMain->addLayout(lyb);
        lyMain->addLayout(ly);

    }

    void loadData(){
        QString nume, tara, coef, urna;
        int row = 0;
        if(tabel->rowCount() == 0)
            tabel->insertRow(row);
        for(const auto& el: srv.get_all()) {

            nume = (QString::fromStdString(el.get_nume()));
            tara = (QString::fromStdString(el.get_tara()));
            coef = (QString::number(el.get_coef()));
            urna = (QString::number(el.get_urna()));

            if(tabel->rowCount() <= row)
                tabel->insertRow(row);

            auto* name_table = new QTableWidgetItem(nume);
            auto* tara_table = new QTableWidgetItem(tara);
            auto* coef_table = new QTableWidgetItem(coef);
            auto* uran_table = new QTableWidgetItem(urna);

            tabel->setItem(row, 0, name_table);
            tabel->setItem(row, 1, tara_table);
            tabel->setItem(row, 2, coef_table);
            tabel->setItem(row, 3, uran_table);

            QTableWidgetItem* itn = new QTableWidgetItem(QString::fromStdString(el.get_nume()));
            QTableWidgetItem* itt = new QTableWidgetItem(QString::fromStdString(el.get_tara()));
            QTableWidgetItem* itc = new QTableWidgetItem(QString::number(el.get_coef()));
            QTableWidgetItem* itu = new QTableWidgetItem(QString::number(el.get_urna()));

            if(el.get_tara() == "Anglia"){
                itn->setBackground(Qt::blue);
                itt->setBackground(Qt::blue);
                itc->setBackground(Qt::blue);
                itu->setBackground(Qt::blue);
            }
            else if(el.get_tara() == "Spania") {
                itn->setBackground(Qt::red);
                itt->setBackground(Qt::red);
                itc->setBackground(Qt::red);
                itu->setBackground(Qt::red);
            }


            row++;
        }

        if(row < tabel->rowCount()) {
            for(int i = tabel->rowCount(); i >= row; i--)
                tabel->removeRow(i);
        }
    }

    void initConnect() {
        QObject::connect(btnRes, &QPushButton::clicked, [&](){
            loadData();
        });

        QObject::connect(btnFil, &QPushButton::clicked, [&](){
            vector<Echipe> fil;
            int coeff = txtcoef->text().toInt();
            srv.filter(coeff,fil);
            QString nume, tara, coef, urna;
            int row = 0;
            if(tabel->rowCount() == 0)
                tabel->insertRow(row);
            for(const auto& el: fil) {
                QString e;

                nume = (QString::fromStdString(el.get_nume()));
                tara = (QString::fromStdString(el.get_tara()));
                coef = (QString::number(el.get_coef()));
                urna = (QString::number(el.get_urna()));

                e = nume + " | " + tara + " | " + coef + " | " + urna;


                if(tabel->rowCount() <= row)
                    tabel->insertRow(row);

                auto* name_table = new QTableWidgetItem(nume);
                auto* tara_table = new QTableWidgetItem(tara);
                auto* coef_table = new QTableWidgetItem(coef);
                auto* uran_table = new QTableWidgetItem(urna);

                tabel->setItem(row, 0, name_table);
                tabel->setItem(row, 1, tara_table);
                tabel->setItem(row, 2, coef_table);
                tabel->setItem(row, 3, uran_table);

                QTableWidgetItem* itn = new QTableWidgetItem(QString::fromStdString(el.get_nume()));
                QTableWidgetItem* itt = new QTableWidgetItem(QString::fromStdString(el.get_tara()));
                QTableWidgetItem* itc = new QTableWidgetItem(QString::number(el.get_coef()));
                QTableWidgetItem* itu = new QTableWidgetItem(QString::number(el.get_urna()));

                if(el.get_tara() == "Anglia"){
                    itn->setBackground(Qt::blue);
                    itt->setBackground(Qt::blue);
                    itc->setBackground(Qt::blue);
                    itu->setBackground(Qt::blue);
                }
                else if(el.get_tara() == "Spania") {
                    itn->setBackground(Qt::red);
                    itt->setBackground(Qt::red);
                    itc->setBackground(Qt::red);
                    itu->setBackground(Qt::red);
                }
                row++;
            }

            if(row < tabel->rowCount()) {
                for(int i = tabel->rowCount(); i >= row; i--)
                    tabel->removeRow(i);
            }
            txtcoef->clear();

        });

        QObject::connect(btnV, &QPushButton::clicked, [&](){
            QMessageBox::information(this,"Info", "Nr de echipe asociate gresit: ");
        });





    }
};





#endif //TEST_OOP_GUI_H
