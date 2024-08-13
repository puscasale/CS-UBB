//
// Created by Ale on 05/24/2024.
//

#ifndef QT_MYLISTMODEL_H
#define QT_MYLISTMODEL_H
#include <vector>
#include <QAbstractListModel>
#include "activity.h"
using std::vector;

class MyListModel:public QAbstractListModel{
private:
    vector<Activity> act;
public:
    MyListModel(vector<Activity> act) : act{act}{};

    int rowCount(const QModelIndex& parent = QModelIndex()) const override{
        return act.size();
    }
    int columnCount(const QModelIndex& parent = QModelIndex()) const override{
        return 4;
    }
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override{
        Activity activity = act[index.row()];
        if(role == Qt::DisplayRole){
            if(index.column() == 0)
                return QString::fromStdString(activity.get_name());
            if(index.column() == 1)
                return QString::fromStdString(activity.get_description());
            if(index.column() == 2)
                return QString::fromStdString(activity.get_type());
            if(index.column() == 3)
                return QString::number(activity.get_time());
        }
        return QVariant{};
    }

    void setAct(const vector<Activity> activities)
    {
        beginResetModel();
        this->act = activities;
        endResetModel();
    }



};
#endif //QT_MYLISTMODEL_H
