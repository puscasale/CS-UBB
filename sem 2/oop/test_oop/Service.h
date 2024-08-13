//
// Created by Ale on 05/22/2024.
//

#ifndef TEST_OOP_SERVICE_H
#define TEST_OOP_SERVICE_H
#include "Repo.h"

class Service{
private:
    Repo& repo;
public:
    Service(Repo& rep): repo{rep}{};

    /**
     * Returenaza lisat cu toate echipele
     * @return
     */
    vector<Echipe>& get_all(){
        return repo.get_all();
    }

    /**
     * Filtreaza lisat de echipe cu cele care au coef mai mic decat cel dat
     * @param coef : coeficientul dat
     * @param fil : lista filtrata
     */
    void filter(int coef, vector<Echipe>& fil);
};
#endif //TEST_OOP_SERVICE_H
