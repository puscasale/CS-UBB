//
// Created by Ale on 05/19/2024.
//

#include <algorithm>
#include "Service.h"

void Service::add(string str, int sup, int pret) {
    const Apartamente& a{str, sup, pret};
    rep.store(a);

}

void Service::del(const Apartamente &a) {
    rep.remove(a);
}

void Service::filter_sup(int sup1, int sup2, vector<Apartamente> &fil) {
    const vector<Apartamente>& all = rep.get_all();
    std::copy_if(all.begin(), all.end(), back_inserter(fil), [sup1,sup2](const Apartamente& a){
        return a.get_sup() >= sup1 and a.get_sup() <= sup2;
    });
}

void Service::filter_pret(int pret1, int pret2, vector<Apartamente> &fil) {
    const vector<Apartamente>& all = rep.get_all();
    std::copy_if(all.begin(), all.end(), back_inserter(fil), [pret1,pret2](const Apartamente& a){
        return a.get_pret() >= pret1 and a.get_pret() <= pret2;
    });
}
