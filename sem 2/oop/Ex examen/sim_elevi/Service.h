//
// Created by Ale on 05/20/2024.
//

#ifndef SIM_ELEVI_SERVICE_H
#define SIM_ELEVI_SERVICE_H
#include "Repo.h"

class Service{
private:
    Repo& rep;
public:
    Service(Repo& rep) : rep{rep}{};
    /**
     * Sorteaza toti elevii dupa nume
     * @param copy : vectorul de e;evi sortati
     */
    void sort_name(vector<Elevi>& copy);

    /**
     * Get all
     * @return: all
     */
    const vector<Elevi>& get_all() {
        return rep.get_all();
    }

    /**
     * Vector cu toti elevii care au un anumit atelier
     * @param at : atelierul cautat
     * @param copy : vectoul de elevi cu acel atelier
     */
    void get_all_ateliere(string at, vector<Elevi>& copy);
};
#endif //SIM_ELEVI_SERVICE_H
