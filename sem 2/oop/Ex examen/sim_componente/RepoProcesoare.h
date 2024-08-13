//
// Created by Ale on 05/20/2024.
//

#ifndef SIM_COMPONENTE_REPOPROCESOARE_H
#define SIM_COMPONENTE_REPOPROCESOARE_H
#include "Procesor.h"
#include <vector>
using std::vector;

class RepoProcesoare{
private:
    string file_name;
    vector<Procesor> procesoare;
public:
    RepoProcesoare(const string& file_name) : file_name{file_name}{
        load_from_file();
    };

    void load_from_file();
    const vector<Procesor>& get_all(){
        return procesoare;
    }
    int sizeProc() {
        return procesoare.size();
    }
};
#endif //SIM_COMPONENTE_REPOPROCESOARE_H
