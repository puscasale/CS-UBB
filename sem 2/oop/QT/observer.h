//
// Created by Ale on 05/24/2024.
//

#ifndef QT_OBSERVER_H
#define QT_OBSERVER_H

#include <cstdio>
#include <algorithm>
#include "vector"
using std::vector;
class Observer{
public:
    virtual void update()=0;
};

class Observable{
private:
    vector<Observer*> obs;
public:
    void addObs(Observer* ob){
        obs.push_back(ob);
    }

    void rmObs(Observer* ob){
        obs.erase(remove(obs.begin(), obs.end(), ob), obs.end());
    }

    void notify(){
        for (auto it:obs) {
            it->update();

        }
    }
};
#endif //QT_OBSERVER_H
