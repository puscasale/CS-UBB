//
// Created by Ale on 05/22/2024.
//

#include <algorithm>
#include "Service.h"

void Service::filter(int coef, vector<Echipe> &fil) {
    vector<Echipe> all = repo.get_all();
    for(auto & e: all){
        if(e.get_coef() < coef)
            fil.push_back(e);
    }
}
