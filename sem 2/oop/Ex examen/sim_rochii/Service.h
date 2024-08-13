//
// Created by Ale on 05/21/2024.
//

#ifndef SIM_ROCHII_SERVICE_H
#define SIM_ROCHII_SERVICE_H
#include "Repo.h"

class Service{
private:
    Repo& rep;
public:
    explicit Service(Repo& rep) : rep{rep}{};
    /**
     * Get all
     * @return : all
     */
    vector<Rochie>& get_all() {
        return rep.get_all();
    }
    /**
     * Sorteada lisat dupa marime
     * @param copy : lista sortata
     */

    void sort_marime(vector<Rochie>& copy);
    /**
     * Sorteada lisat dupa pret
     * @param copy : lista sortata
     */
    void sort_pret(vector<Rochie>& copy);

    /**
     * Schimba disponibilitatea la fals daca a fost inchiriata rochia respectiva
     * @param r : rochia care se vrea inchiriata
     */
    void inchiriere( Rochie& r);
};
#endif //SIM_ROCHII_SERVICE_H
