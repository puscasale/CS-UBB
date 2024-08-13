//
// Created by Ale on 05/16/2024.
//

#ifndef QT_SORT_H
#define QT_SORT_H
#include "service.h"
#include <QtWidgets>

class Sort : public  QWidget{
public:
    explicit Sort(Service& service): service(service){
        initSort();
        initConnect();
    };
private:
    Service& service;

    QListWidget* list = new QListWidget;

    QPushButton* btnName = new QPushButton(" Sort Name ");
    QPushButton* btnDescription = new QPushButton(" Sort Description ");
    QPushButton* btnType_Time = new QPushButton(" Sort Type+Time");

    void initSort() {
        setWindowTitle("Sort Acvtivity");

        auto* lyMain = new QHBoxLayout{};
        setLayout(lyMain);

        auto* lyButton = new QVBoxLayout{};

        lyButton->addWidget(btnName);
        lyButton->addWidget(btnDescription);
        lyButton->addWidget(btnType_Time);

        lyMain->addWidget(list);
        lyMain->addLayout(lyButton);
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
        QObject::connect(btnName, &QPushButton::clicked, [&](){
            vector<Activity> copy;
            service.sort_name(copy);
            loadlist(copy);
        });

        QObject::connect(btnDescription, &QPushButton::clicked, [&](){
            vector<Activity> copy;
            service.sort_descr(copy);
            loadlist(copy);
        });

        QObject::connect(btnType_Time, &QPushButton::clicked, [&](){
            vector<Activity> copy;
            service.sort_type_time(copy);
            loadlist(copy);
        });
    }
};
#endif //QT_SORT_H
