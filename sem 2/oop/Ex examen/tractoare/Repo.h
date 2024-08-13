//
// Created by Ale on 06/24/2024.
//

#ifndef TRACTOARE_REPO_H
#define TRACTOARE_REPO_H
#include "domain.h"
#include "vector"

class Repo{
private:
    vector<Tractor> tractoare;
    string file_name;
public:
    Repo(string file_name):file_name(file_name){
        load_from_file();
    }
    void load_from_file();
    void save_to_file(vector<Tractor> lst);
    vector<Tractor>& get_all(){
        return tractoare;
    }
    void add(Tractor tr);

};
#endif //TRACTOARE_REPO_H
