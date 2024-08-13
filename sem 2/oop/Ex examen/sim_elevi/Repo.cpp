//
// Created by Ale on 05/20/2024.
//
#include <fstream>
#include "Repo.h"


void Repo::add(const Elevi &e) {
    elevi.push_back(e);
}

void Repo::load_from_file() {
    std::ifstream file(file_name);
    while(!file.eof())
    {
        string nume, scaola;
        int nrmat;
        file >>nrmat >> nume >>scaola;
        if(!nume.empty() or !scaola.empty()){
            elevi.push_back(Elevi(nrmat,nume,scaola));
        }
    }
    file.close();
}
