//
// Created by Ale on 06/25/2024.
//

#include <fstream>
#include <algorithm>
#include <iostream>
#include "Repo.h"
#include "assert.h"

void Repo::load_from_file() {
    ifstream file(file_name);
    while(!file.eof()){
        string nrmat,den,tip;
        int an;
        file>>nrmat>>den>>an>>tip;
        if(!nrmat.empty() && !den.empty() && !tip.empty())
            masini.push_back(Masina(nrmat,den,an,tip));
    }
    file.close();

}

void Repo::write_to_file(vector<Masina> lst) {
    ofstream g(file_name);
    for(Masina e:lst){
        g<<e.get_nr()<<endl;
        g<<e.get_den()<<endl;
        g<<e.get_an()<<endl;
        g<<e.get_tip()<<endl;
    }

}

void Repo::del(Masina m) {
    auto it = remove_if(masini.begin(),masini.end(),[m](Masina m_c){
        return m.get_nr() == m_c.get_nr() && m.get_tip() == m_c.get_tip() && m.get_an() == m_c.get_an() && m.get_den() == m_c.get_den();
    });
    masini.erase(it);
    write_to_file(get_all());

}



void test_repo(){
    Repo rep(R"(C:\Users\Ale\Desktop\untitled1\test.txt)");
    vector<Masina> aux = rep.get_all();

    Masina m("nr1","audi",2002,"van");
    rep.del(m);
    assert(rep.get_all().size() == 0);
    rep.write_to_file(aux);
}
