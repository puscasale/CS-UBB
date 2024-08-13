//
// Created by Ale on 06/24/2024.
//

#include <algorithm>
#include "Srv.h"

void Srv::validare(int id, string &denumire, string &tip, int nrR) {
    for(auto& e:get_all()){
        if(id == e.get_id())
            throw SrvEx();
    }
    if(denumire == "" || tip == "" || ( nrR %2 == 1 || nrR > 16 || nrR < 2))
        throw SrvEx();
}

void Srv::add(int id, string &denumire, string &tip, int nrR) {
    validare(id,denumire,tip,nrR);
    rep.add(Tractor(id,denumire,tip,nrR));

}

vector<Tractor> Srv::sortare(vector<Tractor> lst) {
    sort(lst.begin(),lst.end(),[](Tractor& t1,Tractor& t2){
        if(t1.get_denumire() == t2.get_denumire())
            return t1.get_nrR() > t2.get_nrR();
        return t1.get_denumire() > t2.get_denumire();
    });
    return lst;
}

vector<Tractor> Srv::filtrare(string tip) {
    vector<Tractor> rez;
    for(auto& e:get_all()){
        if(e.get_tip() == tip)
            rez.push_back(e);
    }
    return rez;
}

map<string, int> Srv::get_tpuri() {
    map<string,int> rez;
    for(auto& e:get_all()){
        rez[e.get_tip()]++;
    }
    return rez;
}
