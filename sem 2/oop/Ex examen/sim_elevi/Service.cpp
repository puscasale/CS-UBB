//
// Created by Ale on 05/20/2024.
//

#include <algorithm>
#include "Service.h"
#include "Elevi.h"
bool cmp(const Elevi& e1, const Elevi& e2){
    return e1.get_nume() < e2.get_nume();
}

void Service::sort_name(vector<Elevi> &copy) {
    copy = rep.get_all();
    std::sort(copy.begin(), copy.end(), cmp);
}

void Service::get_all_ateliere(string at, vector<Elevi> &copy) {
    vector<Elevi>& all = rep.get_all();
    std::copy_if(all.begin(),all.end(),back_inserter(copy), [at](const Elevi& e){
        return e.get_atelier() == at;
    });
}
