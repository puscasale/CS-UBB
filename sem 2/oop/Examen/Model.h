//
// Created by Ale on 06/25/2024.
//

#ifndef UNTITLED1_MODEL_H
#define UNTITLED1_MODEL_H

#include <QAbstractTableModel>
#include <QBrush>
#include "Srv.h"

class Model : public QAbstractTableModel{
private:
    vector<Masina> all;
public:
    Model(vector<Masina> all):all(all){};

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override{
        if(role == Qt::BackgroundRole){
            auto m = all[index.row()];
            string tp = m.get_tip();
            if(tp == "sedan"){
                QBrush b(Qt::darkGray);
                return b;
            }
            if(tp == "hatch"){
                QBrush b(Qt::darkCyan);
                return b;
            }
            if(tp == "suv"){
                QBrush b(Qt::darkBlue);
                return b;
            }
            if(tp == "van"){
                QBrush b(Qt::darkMagenta);
                return b;
            }

        }

        if(role == Qt::DisplayRole){
            auto m = all[index.row()];
            if(index.column() == 0)
                return QString::fromStdString(m.get_nr());
            if(index.column() == 1)
                return QString::fromStdString(m.get_den());
            if(index.column() == 2)
                return QString::number(m.get_an());
            if(index.column() == 3)
                return QString::fromStdString(m.get_tip());
        }
        return QVariant{};
    }

    int rowCount(const QModelIndex& index = QModelIndex()) const override{
        return all.size();
    }

    int columnCount(const QModelIndex& index = QModelIndex()) const override{
        return 4;
    }

    void set(vector<Masina> alln){
        beginResetModel();
        all=alln;
        endResetModel();
    }

};
#endif //UNTITLED1_MODEL_H

