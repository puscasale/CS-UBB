//
// Created by Ale on 05/22/2024.
//

#include <fstream>
#include "Repo.h"

void Repo::load_from_file() {
    std::ifstream file(file_name);
    while(!file.eof()){
        string nume, tara;
        int coef,urna;
        file >> nume>>tara>>coef>>urna;
        if(!nume.empty() or !tara.empty())
            echipe.push_back(Echipe(nume,tara,coef,urna));
    }
    file.close();

}
