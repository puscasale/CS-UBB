//
// Created by Ale on 05/16/2024.
//

#ifndef QT_CARTQ_H
#define QT_CARTQ_H
#include <QtWidgets>
#include <QTileRules>
#include "cstdlib"
#include "Cart.h"
#include "Service.h"
#include "observer.h"

class CartQ : public QWidget,public Observer{
public:
    explicit CartQ(Service& srv, Cart& cart) : srv(srv), cart(cart) {
        initCart();
        initConnect();
    };
private:
    Service& srv;

    Cart& cart;

    QListWidget* list = new QListWidget;

    QPushButton* btnAdd = new QPushButton(" &Add ");
    QPushButton* btnEmpty = new QPushButton(" &Empty ");
    QPushButton* btnRandom = new QPushButton(" &Random ");
    QPushButton* btnExport = new QPushButton(" &Export ");

    QLineEdit* txtName = new QLineEdit;
    QLineEdit* txtDescription = new QLineEdit;
    QLineEdit* txtType = new QLineEdit;
    QLineEdit* txtTime = new QLineEdit;
    QLineEdit* nrAct = new QLineEdit;

    void initCart() {
        setWindowTitle(" Cart Activities ");

        auto* lyMain = new QHBoxLayout;
        setLayout(lyMain);

        auto* lyButton = new QHBoxLayout;

        lyButton->addWidget(btnAdd);
        lyButton->addWidget(btnEmpty);
        lyButton->addWidget(btnRandom);

        auto lyFields = new QFormLayout;

        lyFields->addRow("Name", txtName);
        lyFields->addRow("Description", txtDescription);
        lyFields->addRow("Type", txtType);
        lyFields->addRow("Time", txtTime);
        lyFields->addRow("Nr random act: ", nrAct);

        auto* lyRight = new QVBoxLayout;

        lyRight->addLayout(lyFields);
        lyRight->addLayout(lyButton);
        lyRight->addWidget(btnExport);

        lyMain->addWidget(list);
        lyMain->addLayout(lyRight);
    }

    void loadlist(const vector<Activity>& act) {
        list->clear();
        QString name, descr, type, time;

        for(const auto& a: act){
            QString e;
            name = (QString::fromStdString(a.get_name()));
            descr = (QString::fromStdString(a.get_description()));
            type = (QString::fromStdString(a.get_type()));
            time = (QString::number(a.get_time()));

            e = name + " | " + descr + " | " + type + " | " + time;
            list->addItem(e);
        }
    }

    void initConnect() {
        QObject::connect(btnAdd, &QPushButton::clicked, [&] (){
            auto name = txtName->text().toStdString();
            auto descr = txtDescription->text().toStdString();
            auto type = txtType->text().toStdString();
            auto time = txtTime->text().toInt();

            if(srv.get_activity(name, descr, type, time)){
                Activity act(name, descr, type, time);
                cart.add_cart(act);

                vector<Activity> activities = cart.get_all_cart();
                loadlist(activities);
            }
            else {
                QMessageBox::critical(this, "Error", "Activity does not exist");
            }

            txtName->clear();
            txtDescription->clear();
            txtType->clear();
            txtTime->clear();
        });

        QObject::connect(btnEmpty, &QPushButton::clicked, [&](){
            cart.empty();
            list->clear();
        });

        QObject::connect(btnRandom, &QPushButton::clicked, [&](){
            if(nrAct->text().isEmpty()){
                QMessageBox::critical(this, "Error", "The number cant be empty");
                return;
            }

            cart.empty();
            int nr = nrAct->text().toInt();
            cart.random_activity(nr, srv.get_all());

            vector<Activity> act = cart.get_all_cart();
            loadlist(act);

            nrAct->clear();
        });

        QObject::connect(btnExport, &QPushButton::clicked, [&](){
            string file_name = R"(C:\Users\Ale\Desktop\QT\exp.html)";
            srv.export_html(file_name);
            system(("start "+file_name).c_str());
        });
    }

    void update() override{
        loadlist(cart.get_all_cart());
    }
};

class Cartread: public QWidget, public Observer{
private:
    Cart& cart;
    Service& srv;
public:
    Cartread(Service& srv,Cart& cart): srv(srv) ,cart(cart){
        initGUI();
        cart.addObs(this);
    }

    void initGUI(){
        setWindowTitle("Cart Read Only");
    }

    void paintEvent(QPaintEvent*) override {
        QPainter painter{this};
        for (int i = 0; i < cart.get_all_cart().size(); ++i) {

            int x = QRandomGenerator::global()->bounded(width());
            int y = QRandomGenerator::global()->bounded(height());

            int diameter = 20;
            painter.setBrush(Qt::red);
            painter.drawEllipse(x, y, diameter, diameter);
        }
    }

    void update() override{
        repaint();
    }

};

class CartCrud: public QWidget, public Observer{
public:
    CartCrud(Service& srv, Cart& cart) : srv(srv), cart(cart){
        init();
        initConnect();
        loadData();
        cart.addObs(this);
    }
private:
    Service& srv;
    Cart& cart;
    QListWidget* list = new QListWidget;

    QPushButton* btnAdd = new QPushButton(" &Add ");
    QPushButton* btnEmpty = new QPushButton(" &Empty ");
    QPushButton* btnRandom = new QPushButton(" &Random ");
    QPushButton* btnExport = new QPushButton(" &Export ");

    QLineEdit* txtName = new QLineEdit;
    QLineEdit* txtDescription = new QLineEdit;
    QLineEdit* txtType = new QLineEdit;
    QLineEdit* txtTime = new QLineEdit;
    QLineEdit* nrAct = new QLineEdit;

    void init() {
        setWindowTitle(" Cart CRUD ");

        auto* lyMain = new QHBoxLayout;
        setLayout(lyMain);

        auto* lyButton = new QHBoxLayout;

        lyButton->addWidget(btnAdd);
        lyButton->addWidget(btnEmpty);
        lyButton->addWidget(btnRandom);

        auto lyFields = new QFormLayout;

        lyFields->addRow("Name", txtName);
        lyFields->addRow("Description", txtDescription);
        lyFields->addRow("Type", txtType);
        lyFields->addRow("Time", txtTime);
        lyFields->addRow("Nr random act: ", nrAct);

        auto* lyRight = new QVBoxLayout;

        lyRight->addLayout(lyFields);
        lyRight->addLayout(lyButton);
        lyRight->addWidget(btnExport);

        lyMain->addWidget(list);
        lyMain->addLayout(lyRight);
    }

    void loadData(){
        vector<Activity> act = cart.get_all_cart();
        list->clear();
        QString name, descr, type, time;

        for(const auto& a: act){
            QString e;
            name = (QString::fromStdString(a.get_name()));
            descr = (QString::fromStdString(a.get_description()));
            type = (QString::fromStdString(a.get_type()));
            time = (QString::number(a.get_time()));

            e = name + " | " + descr + " | " + type + " | " + time;
            list->addItem(e);
        }
    }

    void initConnect(){
        QObject::connect(btnAdd, &QPushButton::clicked, [&] (){
            auto name = txtName->text().toStdString();
            auto descr = txtDescription->text().toStdString();
            auto type = txtType->text().toStdString();
            auto time = txtTime->text().toInt();

            if(srv.get_activity(name, descr, type, time)){
                Activity act(name, descr, type, time);
                cart.add_cart(act);

                vector<Activity> activities = cart.get_all_cart();
                loadData();
            }
            else {
                QMessageBox::critical(this, "Error", "Activity does not exist");
            }

            txtName->clear();
            txtDescription->clear();
            txtType->clear();
            txtTime->clear();
        });

        QObject::connect(btnEmpty, &QPushButton::clicked, [&](){
            cart.empty();
            list->clear();
        });

        QObject::connect(btnRandom, &QPushButton::clicked, [&](){
            if(nrAct->text().isEmpty()){
                QMessageBox::critical(this, "Error", "The number cant be empty");
                return;
            }

            cart.empty();
            int nr = nrAct->text().toInt();
            cart.random_activity(nr, srv.get_all());

            vector<Activity> act = cart.get_all_cart();
            loadData();

            nrAct->clear();
        });

        QObject::connect(btnExport, &QPushButton::clicked, [&](){
            string file_name = R"(C:\Users\Ale\Desktop\QT\exp.html)";
            srv.export_html(file_name);
            system(("start "+file_name).c_str());
        });
    }

    void update() override{
        loadData();
    }

};


#endif //QT_CARTQ_H
