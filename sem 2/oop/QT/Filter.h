//
// Created by Ale on 05/16/2024.
//

#ifndef QT_FILTER_H
#define QT_FILTER_H
#include <QtWidgets>
#include "service.h"

class Filter: public QWidget{
public:
    explicit Filter(Service& srv) : srv(srv){
        initFilter();
        initConnect();
    };
private:
    Service& srv;

    QListWidget* list = new QListWidget;

    QPushButton* btnDescription = new QPushButton(" Filter &Description ");
    QPushButton* btnType = new QPushButton(" Filter &Type ");

    QLineEdit* txtDescription = new QLineEdit;
    QLineEdit* txtType = new QLineEdit;

    void initFilter() {
        setWindowTitle("Filter activities");

        auto* lyMain = new QHBoxLayout;
        setLayout(lyMain);

        auto* lyButton = new QHBoxLayout;

        lyButton->addWidget(btnDescription);
        lyButton->addWidget(btnType);

        auto* lyFields = new QFormLayout;

        lyFields->addRow("Description: ",txtDescription);
        lyFields->addRow("Type: ",txtType);

        auto* lyRight = new QVBoxLayout;

        lyRight->addLayout(lyFields);
        lyRight->addLayout(lyButton);

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
        QObject::connect(btnDescription, &QPushButton::clicked, [&](){
            if(txtDescription->text().isEmpty()){
                QMessageBox::critical(this, "Error", "The description cant be empty");
                return;
            }
            vector<Activity> copy;
            string descr = txtDescription->text().toStdString();
            srv.filter_descr(descr,copy);

            loadlist(copy);

            txtDescription->clear();
            txtType->clear();
        });

        QObject::connect(btnType, &QPushButton::clicked, [&](){
            if(txtType->text().isEmpty()){
                QMessageBox::critical(this, "Error","The type cant be empty");
                return;
            }
            vector<Activity> copy;
            string type = txtType->text().toStdString();
            srv.filter_type(type, copy);

            loadlist(copy);

            txtType->clear();
            txtDescription->clear();
        });
    }
};
#endif //QT_FILTER_H
