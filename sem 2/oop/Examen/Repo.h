//
// Created by Ale on 06/25/2024.
//

#ifndef UNTITLED1_REPO_H
#define UNTITLED1_REPO_H
#include "domain.h"
#include "vector"

class Repo{
private:
    vector<Masina> masini;
    string file_name;
public:
    //Constructor
    Repo(string file_name):file_name(file_name){
        load_from_file();
    }
    /**
     * Ia datele din fisier
     */
    void load_from_file();

    /**
     * Scrie datele in fisier
     * @param lst : lista de scris in fisier
     */
    void write_to_file(vector<Masina> lst);

    /**
     * Sterge Masina
     * @param m : masina de sters
     */
    void del(Masina m);

    /**
     * GEt all
     * @return: toate masinile
     */
    vector<Masina>& get_all() { return masini;}


};

void test_repo();
#endif //UNTITLED1_REPO_H
