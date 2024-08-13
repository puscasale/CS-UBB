//
// Created by Ale on 05/19/2024.
//

#ifndef SIM_APARTAMENTE_REPO_H
#define SIM_APARTAMENTE_REPO_H
#include "Apartament.h"
#include <vector>
using std::vector;

class Repo {
private:
    vector<Apartamente> ap;
public:
    Repo(const Repo& ot) = delete;
    Repo() = default;

    /**
     * Adauga un ap in lista
     * @param a : apartamentul de adaugat
     */
    virtual void store(const Apartamente& a);

    /**
     * Sterge un ap din lista
     * @param a : apartamentul de sters
     */
    virtual void remove(const Apartamente& a);

    /**
     * Get all
     * @return: all ap
     */
    vector<Apartamente>& get_all(){
        return ap;
    }

};


class RepoInFile : public Repo {
private:
    string file_name;
    void read_from_file();

public:
    explicit RepoInFile(string file_name) : Repo(), file_name(file_name) {
        read_from_file();
    }

    void store(const Apartamente& a) override {
        Repo::store(a);
    }

    void remove(const Apartamente& a) override {
        Repo::remove(a);
    }
};


#endif //SIM_APARTAMENTE_REPO_H
