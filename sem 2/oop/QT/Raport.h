//
// Created by Ale on 05/16/2024.
//

#ifndef QT_RAPORT_H
#define QT_RAPORT_H
#include "service.h"
#include <QtWidgets>

class Raport : public QWidget {
public:
    explicit Raport(Service& service): service(service){
            initRaport();
    };
private:
    Service& service;
    QListWidget* list = new QListWidget;

    void initRaport() {
        setWindowTitle("Raport");
        auto* lyMain = new QHBoxLayout;
        setLayout(lyMain);

        lyMain->addWidget(list);

        unordered_map<string, ActivityCount> raport = service.raport();

        for(const auto& e: raport){
            auto type = (QString::fromStdString(e.first));
            auto nr = (QString::number(e.second.get_count()));
            QString el = "Type: " + type + " Number: " + nr + '\n';
            list->addItem(el);
        }

    }
};
#endif //QT_RAPORT_H
