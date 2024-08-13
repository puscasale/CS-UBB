//
// Created by Ale on 05/20/2024.
//

#ifndef SIM_COMPONENTE_REPOPLACA_H
#define SIM_COMPONENTE_REPOPLACA_H
#include "Placa.h"
#include <vector>
using std::vector;

class RepoPlaca{
private:
    string file_name;
    vector<Placa> placi;
public:
    RepoPlaca(const string& file_name) : file_name{file_name}{
        load_from_file();
    }
    /**\
     * load data from file
     */
    void load_from_file();
    /**
     * Get all
     * @return : all
     */
    const vector<Placa>& get_all(){
        return placi;
    }
    /**
     * adauga o placa in lista de placi
     * @param p : placa de adaugat
     */
    void addPlaca(const Placa& p);

    int sizePlaca(){
        return placi.size();
    }
};
#endif //SIM_COMPONENTE_REPOPLACA_H
