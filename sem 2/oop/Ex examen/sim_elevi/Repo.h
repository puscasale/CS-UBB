//
// Created by Ale on 05/20/2024.
//

#ifndef SIM_ELEVI_REPO_H
#define SIM_ELEVI_REPO_H
#include "Elevi.h"
#include <vector>
using std::vector;

class Repo {
private:
    vector<Elevi> elevi;
    string file_name;
public:

    Repo(string file_name) : file_name(file_name){
        load_from_file();
    };
    Repo(const Repo& ot) = delete;

    Repo() = default;

    virtual void add(const Elevi& e);

    vector<Elevi>& get_all(){
        return elevi;
    };

    void load_from_file();
};
#endif //SIM_ELEVI_REPO_H
