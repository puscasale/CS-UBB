//
// Created by Ale on 06/24/2024.
//

#include <fstream>
#include "Repo.h"

void Repo::load_from_file() {
    ifstream file(file_name);
    while(!file.eof()){
        int id,nrR;
        string denumire,tip;
        file>>id>>denumire>>tip>>nrR;
        if(!denumire.empty() && !tip.empty())
            tractoare.push_back(Tractor(id,denumire,tip,nrR));
    }
    file.close();
}

void Repo::save_to_file(vector<Tractor> lst) {
    ofstream g(file_name);
    for(auto& t:lst){
        g<<t.get_id()<<endl;
        g<<t.get_denumire()<<endl;
        g<<t.get_tip()<<endl;
        g<<t.get_nrR()<<endl;
    }

}

void Repo::add(Tractor tr) {
    tractoare.push_back(tr);
    save_to_file(tractoare);

}
