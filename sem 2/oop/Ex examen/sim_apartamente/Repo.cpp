//
// Created by Ale on 05/19/2024.
//

#include <algorithm>
#include <fstream>
#include "Repo.h"

void Repo::store(const Apartamente &a) {
    ap.push_back(a);
}

void Repo::remove(const Apartamente &a) {
    auto it = std::remove_if(ap.begin(), ap.end(), [a](const Apartamente & a_cmp){
        return a.get_pret() == a_cmp.get_pret() and a.get_str() == a_cmp.get_str() and a.get_sup() == a_cmp.get_sup();
    });
    ap.erase(it);
}

void RepoInFile::read_from_file() {
    std::ifstream file;
    file.open(file_name);
    string line, word;

    while(!file.eof()){
        getline(file, line);

        if(line.size()){
            vector<string> ap_info;

            auto found = line.find(',');
            while(found != -1){
                word = line.substr(0,found);
                line.erase(0,found+ 1);
                ap_info.push_back(word);
                found = line.find(',');
            }
            const Apartamente& a{ap_info.at(0),stoi(line),stoi(line)};
            Repo::store(a);
            ap_info.clear();
        }
    }
    file.close();
}
