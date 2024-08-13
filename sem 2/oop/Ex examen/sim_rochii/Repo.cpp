//
// Created by Ale on 05/21/2024.
//

#include <fstream>
#include "Repo.h"

void Repo::load_from_file() {
    std::ifstream file(file_name);
    while(!file.eof()){
        int cod;
        string nume, marime;
        int pret;
        bool dis;
        file>>cod>>nume>>marime>>pret>>dis;
        if(!nume.empty() or !marime.empty())
            rochii.push_back(Rochie(cod,nume,marime,pret,dis));
    }
    file.close();

}
