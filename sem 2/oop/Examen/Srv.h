//
// Created by Ale on 06/25/2024.
//

#ifndef UNTITLED1_SRV_H
#define UNTITLED1_SRV_H
#include "Repo.h"

class Srv{
private:
    Repo& rep;
public:
    //Constructor
    Srv(Repo& rep):rep(rep){};

    /**
     * Sterge o masina din lista
     * @param m : masia pe o vom sterge
     */
    void del(Masina m);

    /**
     * Sorteaza o lista de masina dupa numarul de inmatriculare
     * @param lst : lista de sortat
     * @return : lista sortata
     */
    vector<Masina> sort_nr(vector<Masina> lst);

    /**
     * GEt all
     * @return: toate emels
     */
    vector<Masina>& get_all() { return rep.get_all();}

    /**
     * Modifica anul fabricatiei ficerai masini din lista in functie de parametrul op
     * @param op : "+" sau "-"
     */
    void modify(const string& op);


};

void test_srv();
#endif //UNTITLED1_SRV_H
