//
// Created by Ale on 05/21/2024.
//

#ifndef SIM_ROCHII_ROCHIE_H
#define SIM_ROCHII_ROCHIE_H
#include <string>
using std::string;
class Rochie{
private:
    int cod;
    string nume;
    string marime;
    int pret;
    bool disponibil;
public:
    Rochie(int cod, string nume, string marime, int pret, bool disponibil) : cod(cod), nume(nume), marime(marime), pret(pret), disponibil(disponibil){};

    //gettere
    int get_cod() const;

    string get_nume() const;

    string get_marime() const;

    int get_pret() const;

    bool get_dis() const;

    void set_dis(bool dis1) ;
};
#endif //SIM_ROCHII_ROCHIE_H
