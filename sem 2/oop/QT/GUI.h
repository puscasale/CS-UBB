//
// Created by Ale on 05/16/2024.
//

#ifndef QT_GUI_H
#define QT_GUI_H
#include <QtWidgets>
#include <qdebug.h>
#include <qmessagebox.h>
#include <vector>
#include <string>
#include "Service.h"
#include "Repo.h"
#include "Sort.h"
#include "Raport.h"
#include "Filter.h"
#include "CartQ.h"
#include "QPainter"
#include "MyListModel.h"
using std::vector;
using std::string;

class GUI: public QWidget, public Observable{
public:
    explicit GUI(Service& service) : service(service) {
        initGUI();
        loadData();
        initConnect();
    }

private:
    Service& service;
    Activity selected_act;


    Sort sort {service};
    Filter filter{service};
    Raport raport{service};

    QListView* lst_view = new QListView;
    QListWidget* list = new QListWidget;
    QTableView* tabel = new QTableView;
    MyListModel* model = new MyListModel(service.get_all());
    //QTableWidget* table = new QTableWidget(0,4,this);

    QPushButton* btnExit = new QPushButton(" &Exit ");
    QPushButton* btnCart = new QPushButton(" &Cart ");

    QPushButton* btnCosCrud = new QPushButton(" Cart Crud ");
    QPushButton* btnCosRead = new QPushButton (" Cart Read Only ");

    QPushButton* btnAdd = new QPushButton(" &Add ");
    QPushButton* btnModify = new QPushButton(" &Modify ");
    QPushButton* btnDelete = new QPushButton(" &Delete ");
    QPushButton* btnUndo = new QPushButton(" &Undo ");

    QPushButton* btnFind = new QPushButton(" &Find ");
    QPushButton* btnFilter = new QPushButton(" &Filter ");
    QPushButton* btnSort = new QPushButton(" &Sort ");
    QPushButton* btnRaport = new QPushButton(" &Raport ");

    QPushButton* btnAddCos = new QPushButton(" Add in Cart ");
    QPushButton* btnGolireCos = new QPushButton(" Empty Cart ");
    QPushButton* btnRandomCos = new QPushButton(" Random Cart ");

    QLineEdit* txtName = new QLineEdit;
    QLineEdit* txtDescription = new QLineEdit;
    QLineEdit* txtType = new QLineEdit;
    QLineEdit* txtTime = new QLineEdit;
    QLineEdit* nrAct = new QLineEdit;

    Cart cart;

    void initGUI() {

        setWindowTitle("Activities");
        tabel->setModel(model);
        auto* lyMain = new QHBoxLayout{};
        setLayout(lyMain);
        lst_view->setUniformItemSizes(true);;
        //Layout pt tabel
/*
        QStringList headers;
        headers << "Name" << "Description" << "Type" <<"Time";
        table->setHorizontalHeaderLabels(headers);
*/
        lyMain->addWidget(tabel);

        //Layout pt lista

        auto layout = new QVBoxLayout;

        auto label = new QLabel{ "List"};

        auto hlayout = new QHBoxLayout;
        hlayout->addStretch();
        hlayout->addWidget(label);
        hlayout->addStretch();

        layout->addLayout(hlayout);
        layout->addWidget(list);

        lyMain->addLayout(layout);

        //Layout pt butoanele de add,sergete, modifica si undo

        auto layout_btn = new QVBoxLayout;

        layout_btn->addWidget(btnAdd);
        layout_btn->addWidget(btnModify);
        layout_btn->addWidget(btnDelete);
        layout_btn->addWidget(btnUndo);

        lyMain->addLayout(layout_btn);

        //Layout pt campurile name, descr, type, time

        auto layout_right = new QVBoxLayout;

        auto layout_fields = new QFormLayout;

        layout_fields->addRow("Name", txtName);
        layout_fields->addRow("Description",txtDescription);
        layout_fields->addRow("Type",txtType);
        layout_fields->addRow("Time",txtTime);
        layout_fields->addRow("Number Act Random", nrAct);

        layout_right->addLayout(layout_fields);

        auto aux = new QHBoxLayout;

        aux->addWidget(btnFind);
        aux->addWidget(btnFilter);
        aux->addWidget(btnSort);
        aux->addWidget(btnRaport);

        layout_right->addLayout(aux);

        auto ly_btn_cart = new QHBoxLayout;
        ly_btn_cart->addWidget(btnAddCos);
        ly_btn_cart->addWidget(btnGolireCos);
        ly_btn_cart->addWidget(btnRandomCos);

        layout_right->addLayout(ly_btn_cart);

        layout_right->addWidget(btnCart);
        layout_right->addWidget(btnCosCrud);
        layout_right->addWidget(btnCosRead);
        layout_right->addWidget(btnExit);

        lyMain->addLayout(layout_right);
    }

    void loadData() {
        list->clear();

        QString name, description, type, time;

        /*
        int row = 0;
        if(table->rowCount() == 0)
            table->insertRow(row);
        */
        vector<Activity> elems = service.get_all();
        for(const auto& act: elems) {
            QString e;

            name = (QString::fromStdString(act.get_name()));
            description = (QString::fromStdString(act.get_description()));
            type = (QString::fromStdString(act.get_type()));
            time = (QString::number(act.get_time()));

            e = name + " | " + description + " | " + type + " | " + time;
            list->addItem(e);
/*
            if(table->rowCount() <= row)
                table->insertRow(row);

            auto* name_table = new QTableWidgetItem(name);
            auto* description_table = new QTableWidgetItem(description);
            auto* type_table = new QTableWidgetItem(type);
            auto* time_table = new QTableWidgetItem(time);

            table->setItem(row, 0, name_table);
            table->setItem(row, 1, description_table);
            table->setItem(row, 2, type_table);
            table->setItem(row, 3, time_table);

            row++;
            */
        }
/*
        if(row < table->rowCount()) {
            for(int i = table->rowCount(); i >= row; i--)
                table->removeRow(i);
        }*/
        model->setAct(service.get_all());
    }

    void initConnect() {


        QObject::connect(list, &QListWidget::itemClicked, [&](QListWidgetItem* item){
            QString text = item->text();
            QStringList elems = text.split(" | ");

            txtName->setText(elems[0]);
            txtDescription->setText(elems[1]);
            txtType->setText(elems[2]);
            txtTime->setText(elems[3]);

            auto name = elems[0].toStdString();
            auto description = elems[1].toStdString();
            auto type = elems[2].toStdString();
            auto time = elems[3].toInt();

            selected_act = Activity(name, description, type, time);

        });

        QObject::connect(tabel->selectionModel(), &QItemSelectionModel::selectionChanged, [this](const QItemSelection& selected){
            if(!selected.indexes().isEmpty()){
                QModelIndex index = selected.indexes().first();
                int line = index.row();

                auto nameind = tabel->model()->index(line, 0);
                auto descind = tabel->model()->index(line, 1);
                auto typeind = tabel->model()->index(line, 2);
                auto timeind = tabel->model()->index(line, 3);

                QString name = tabel->model()->data(nameind, Qt::DisplayRole).toString();
                QString description = tabel->model()->data(descind, Qt::DisplayRole).toString();
                QString type = tabel->model()->data(typeind, Qt::DisplayRole).toString();
                QString time = tabel->model()->data(timeind, Qt::DisplayRole).toString();

                txtName->setText(name);
                txtDescription->setText(description);
                txtType->setText(type);
                txtTime->setText(time);

                selected_act = Activity(name.toStdString(), description.toStdString(), type.toStdString(), time.toInt());
            }
        });

        /*
        QObject::connect(table, &QTableWidget::cellClicked, [&](int row, int collum){
            table->selectRow(row);

            QTableWidgetItem* item_name = table->item(row,0);
            QTableWidgetItem* item_descr = table->item(row,1);
            QTableWidgetItem* item_type = table->item(row,2);
            QTableWidgetItem* item_time = table->item(row,3);

            txtName->setText(item_name->text());
            txtDescription->setText(item_descr->text());
            txtType->setText(item_type->text());
            txtTime->setText(item_time->text());

            selected_act = Activity(item_name->text().toStdString(), item_descr->text().toStdString(), item_type->text().toStdString(), item_time->text().toInt());

        });
*/
        QObject::connect(btnExit, &QPushButton::clicked, [&](){
            close();
        });

        QObject::connect(btnAdd, &QPushButton::clicked, [&]() {
            auto name = txtName->text();
            auto description = txtDescription->text();
            auto type = txtType->text();
            auto time = txtTime->text();

            auto act_name = name.toStdString();
            auto act_descrtiption = description.toStdString();
            auto act_type = type.toStdString();
            auto act_time = time.toInt();

            Activity act(act_name, act_descrtiption,act_type,act_time);

            try {
                service.add(act_name,act_descrtiption,act_type,act_time);
            }catch (Exception& ex){
                QString msg = QString::fromStdString(ex.getMessage());
                QMessageBox::critical(this, "Error",msg);
            }

            loadData();
            txtName->clear();
            txtDescription->clear();
            txtType->clear();
            txtTime->clear();
        });

        QObject::connect(btnModify, &QPushButton::clicked, [&](){
            if(txtName->text().isEmpty() or txtDescription->text().isEmpty() or txtType->text().isEmpty() or txtTime->text().isEmpty()) {
                QMessageBox::critical(this, "Error", "Invalid data");
                return;
            }

            else {
                auto name = txtName->text().toStdString();
                auto descr = txtDescription->text().toStdString();
                auto type = txtType->text().toStdString();
                auto time = txtTime->text().toInt();
                Activity new_act(name, descr, type, time);

                try {
                    service.modify(selected_act,new_act);
                }catch (Exception& ex) {
                    QString msg = QString::fromStdString(ex.getMessage());
                    QMessageBox::critical(this, "Error", msg);
                }
                loadData();

                txtName->clear();
                txtDescription->clear();
                txtType->clear();
                txtTime->clear();

                selected_act =  Activity();

            }

        });

        QObject::connect(btnDelete, &QPushButton::clicked, [&](){
            if(txtName->text().isEmpty() or txtDescription->text().isEmpty() or txtType->text().isEmpty() or txtTime->text().isEmpty()) {
                QMessageBox::critical(this, "Error", "Invalid data");
                return;
            }

            else{
                try{
                    service.del(selected_act);
                }catch(Exception& ex){
                    QString msg = QString::fromStdString(ex.getMessage());
                    QMessageBox::critical(this, "Error", msg);
                }
                loadData();

                txtName->clear();
                txtDescription->clear();
                txtType->clear();
                txtTime->clear();

                selected_act = Activity();

            }
        });

        QObject::connect(btnUndo, &QPushButton::clicked, [&](){
            if(service.Undo() == -1){
                QMessageBox::information(this, "Info", "Cant do Undo");
            }
            else {
                loadData();
            }
        });

        QObject::connect(btnFind, &QPushButton::clicked, [&](){
            if(txtName->text().isEmpty() or txtDescription->text().isEmpty() or txtType->text().isEmpty() or txtTime->text().isEmpty()) {
                QMessageBox::critical(this, "Error", "Invalid data");
                return;
            }

            else {
                auto find_name = txtName->text().toStdString();
                auto find_descr = txtDescription->text().toStdString();
                auto find_type = txtType->text().toStdString();
                auto find_time = txtTime->text().toInt();

                if(service.get_activity(find_name, find_descr, find_type, find_time)){
                    QString name = QString::fromStdString(find_name);
                    QString description = QString::fromStdString(find_descr);
                    QString type = QString::fromStdString(find_type);
                    QString time = QString::number(find_time);

                    QString msg = "Name: " + name + '\n' + "Description: " + description + '\n' + "Type: " + type + '\n' + "Time " + time;

                    QMessageBox::information(this, "Activity found", msg);
                }
                else {
                    QMessageBox::information(this, "Info", "Activity does not exist");

                }
            }
            txtName->clear();
            txtDescription->clear();
            txtType->clear();
            txtTime->clear();
        });

        QObject::connect(btnSort, &QPushButton::clicked, [&](){
            sort.show();
        });

        QObject::connect(btnFilter, &QPushButton::clicked, [&](){
            filter.show();
        });

        QObject::connect(btnCart, &QPushButton::clicked, [&](){
            auto* cart_main = new CartQ(service,cart);
            addObs(cart_main);
            cart.addObs(cart_main);
            cart_main->show();
        });

        QObject::connect(btnCosRead, &QPushButton::clicked, [&](){
            auto* cart_main = new Cartread(service,cart);
            addObs(cart_main);
            cart.addObs(cart_main);
            cart_main->show();
        });

        QObject::connect(btnCosCrud, &QPushButton::clicked, [&](){
            auto* cart_crud = new CartCrud(service,cart);
            addObs(cart_crud);
            cart.addObs(cart_crud);
            cart_crud->show();
        });

        QObject::connect(btnAddCos, &QPushButton::clicked, [&](){
            auto name = txtName->text().toStdString();
            auto descr = txtDescription->text().toStdString();
            auto type = txtType->text().toStdString();
            auto time = txtTime->text().toInt();

            if(service.get_activity(name, descr,type,time)){
                Activity act(name, descr, type, time);
                cart.add_cart(act);

                vector<Activity> activities = cart.get_all_cart();

                notify();
            }

            else{
                QMessageBox::critical(this, "Error", "The activity does not exist");
            }
            txtTime->clear();
            txtType->clear();
            txtDescription->clear();
            txtName->clear();
        });

        QObject::connect(btnGolireCos, &QPushButton::clicked, [&](){
            cart.empty();
            notify();
        });

        QObject::connect(btnRandomCos, &QPushButton::clicked, [&](){
            if(nrAct->text().isEmpty()){
                QMessageBox::critical(this, "Error", "The number cant be empty");
                return;
            }
            cart.empty();
            int nr = nrAct->text().toInt();
            cart.random_activity(nr, service.get_all());

            vector<Activity> activities = cart.get_all_cart();
            loadData();
            nrAct->clear();

            notify();
        });

        QObject::connect(btnRaport, &QPushButton::clicked, [&](){
            raport.show();
        });
    }

};

#endif //QT_GUI_H
