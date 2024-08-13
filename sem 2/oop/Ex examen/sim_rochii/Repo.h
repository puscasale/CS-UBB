//
// Created by Ale on 05/21/2024.
//

#ifndef SIM_ROCHII_REPO_H
#define SIM_ROCHII_REPO_H
#include "Rochie.h"
#include <vector>
using std::vector;

class Repo{
private:
    vector<Rochie> rochii;
    string file_name;
public:
    explicit Repo(const string& file_name) : file_name(file_name){
        load_from_file();
    };
    /**
     * incarca din fis
     */
    void load_from_file();

    /**
     * Get all
     * @return: all
     */
    vector<Rochie>& get_all() {
        return rochii;
    }


};
#endif //SIM_ROCHII_REPO_H
