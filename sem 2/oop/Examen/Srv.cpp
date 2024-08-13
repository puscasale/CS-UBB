//
// Created by Ale on 06/25/2024.
//

#include <algorithm>
#include <iostream>
#include "Srv.h"
#include "assert.h"

vector<Masina> Srv::sort_nr(vector<Masina> lst) {
    std::sort(lst.begin(),lst.end(),[](Masina m1, Masina m2){
        return m1.get_nr() > m2.get_nr();
    });
    return lst;
}

void Srv::del(Masina m) {
    rep.del(m);

}

void Srv::modify(const string& op) {
    if(op == "-"){
        for(auto& e : rep.get_all()){
            int an = e.get_an()-1;
            e.set_an(an);
        }
    }
    if(op=="+"){
        for(auto& e : rep.get_all()){
            e.set_an(e.get_an()+1);
        }
    }
}



void test_srv(){
    Repo rep(R"(C:\Users\Ale\Desktop\untitled1\test.txt)");
    vector<Masina> aux = rep.get_all();
    Srv srv(rep);
    srv.modify("+");
    assert(srv.get_all()[0].get_an() == 2003);
    srv.modify("-");
    assert(srv.get_all()[0].get_an() == 2002);
    Masina m("nr1","audi",2002,"van");
    srv.del(m);
    assert(srv.get_all().size() == 0);
    rep.write_to_file(aux);
}