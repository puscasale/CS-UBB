//
// Created by Ale on 06/24/2024.
//

#ifndef TRACTOARE_SRV_H
#define TRACTOARE_SRV_H

#include <map>
#include "Repo.h"

class SrvEx:public exception{

};

class Srv{
private:
    Repo& rep;
public:
    Srv(Repo& rep):rep{rep}{};
    void add(int id, string& denumire, string& tip, int nrR);
    void validare(int id, string& denumire, string& tip, int nrR);
    vector<Tractor> sortare(vector<Tractor> lst);
    map<string,int> get_tpuri();
    vector<Tractor> filtrare(string tip);
    vector<Tractor>& get_all(){
        return rep.get_all();
    }
};
#endif //TRACTOARE_SRV_H
