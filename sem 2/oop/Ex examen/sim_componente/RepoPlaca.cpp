//
// Created by Ale on 05/20/2024.
//

#include <fstream>
#include "RepoPlaca.h"

void RepoPlaca::addPlaca(const Placa &p) {
    placi.push_back(p);

}

void RepoPlaca::load_from_file() {
    std::ifstream file(file_name);
    while(!file.eof()){
        string nume;
        int soclu, pret;
        file >> nume >> soclu >> pret;

        if(!nume.empty())
            placi.push_back(Placa(nume, soclu,pret));
    }
    file.close();
}
