//
// Created by Ale on 05/19/2024.
//

#ifndef SIM_APARTAMENTE_SERVICE_H
#define SIM_APARTAMENTE_SERVICE_H
#include "Repo.h"

class Service {
private:
    Repo& rep;
public:
    Service(Repo &rep): rep{rep}{};

    /**
     * Adauga un apartament
     * @param str : strada
     * @param sup : suprafta
     * @param pret : pretul
     */
    void add(string str, int sup, int pret);

    /**
     * Sterge apartamenul
     * @param a : apartamenul pe care vrem sa il stergem
     */
    void del(const Apartamente& a);

    /**
     * Filtreaza apartamentele care sunt intre doua suprafte
     * @param sup1 : suprafata unu
     * @param sup2 : suprafta 2
     * @param fil : vectorul de apartamente
     */
    void filter_sup(int sup1, int sup2, vector<Apartamente>& fil);

    /**
     * Filtreaz ap care sunt intre doua preturi
     * @param pret1 : pret 1
     * @param pret2 : pret 2
     * @param fil : vectorul de ap
     */
    void filter_pret(int pret1, int pret2, vector<Apartamente>& fil);

    const vector<Apartamente>& get_all(){
        return rep.get_all();
    }
};
#endif //SIM_APARTAMENTE_SERVICE_H
