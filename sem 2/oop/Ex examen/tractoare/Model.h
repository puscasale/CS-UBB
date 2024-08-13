//
// Created by Ale on 06/24/2024.
//

#ifndef TRACTOARE_MODEL_H
#define TRACTOARE_MODEL_H

#include <QAbstractTableModel>
#include <QBrush>
#include "Srv.h"

class Model : public QAbstractTableModel{
private:
    vector<Tractor> tr;
    map<string,int> tip;
    string t;
public:
    Model(vector<Tractor> tr, map<string,int> tip,string t):tr{tr},tip{tip},t{t}{};

    int rowCount(const QModelIndex& parent = QModelIndex()) const override{
        return tr.size();
    }
    int columnCount(const QModelIndex& parent = QModelIndex()) const override{
        return 5;
    }
    void set(vector<Tractor> trr, map<string,int> tipp,string tt){
        beginResetModel();
        tr = trr;
        tip = tipp;
        t = tt;
        endResetModel();
    }

    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override{
        if(role == Qt::BackgroundRole){
            auto tractor = tr[index.row()];
            string tp = tractor.get_tip();
            if(tp == t){
                QBrush b(Qt::darkMagenta);
                return b;
            }

        }

        if(role == Qt::DisplayRole){
            auto tract = tr[index.row()];
            if(index.column() == 0)
                return QString::number(tract.get_id());
            if(index.column() == 1)
                return QString::fromStdString(tract.get_denumire());
            if(index.column() == 2)
                return QString::fromStdString(tract.get_tip());
            if(index.column() == 3)
                return QString::number(tract.get_nrR());
            if(index.column() == 4)
                return QString::number(tip.at(tract.get_tip()));
        }
        return QVariant{};
    }
};
#endif //TRACTOARE_MODEL_H
