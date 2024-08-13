//
// Created by Ale on 05/22/2024.
//

#ifndef TEST_OOP_REPO_H
#define TEST_OOP_REPO_H
#include "Echipe.h"
#include "vector"
using std::vector;

class Repo{
private:
    string file_name;
    vector<Echipe> echipe;
public:
    Repo(string file_name) : file_name(file_name){
        load_from_file();
    }
    /**
     * Citeste datele fin fisier
     */
    void load_from_file();

    /**
     * Returenaza lista cu toate echipele
     * @return
     */
    vector<Echipe>& get_all(){
        return echipe;
    }
};
#endif //TEST_OOP_REPO_H
