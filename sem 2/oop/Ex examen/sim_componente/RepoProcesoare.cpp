//
// Created by Ale on 05/20/2024.
//

#include <fstream>
#include "RepoProcesoare.h"

void RepoProcesoare::load_from_file() {
    std::ifstream file(file_name);
    while(!file.eof()){
        string nume;
        int nrT, soclu, pret;
        file >> nume >> nrT >> soclu >> pret;
        if(!nume.empty())
            procesoare.push_back(Procesor(nume,nrT,soclu,pret));

    }
    file.close();
}
