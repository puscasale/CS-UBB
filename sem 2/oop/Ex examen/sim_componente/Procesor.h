//
// Created by Ale on 05/20/2024.
//

#ifndef SIM_COMPONENTE_PROCESOR_H
#define SIM_COMPONENTE_PROCESOR_H
#include <string>
using std::string;
class Procesor{
private:
    string nume;
    int nrT;
    int socluProcesor;
    int pret;
public:
    Procesor(string nume, int nrT, int socluProcesor, int pret) : nume{nume}, nrT{nrT}, socluProcesor{socluProcesor}, pret{pret}{};

    string getNume() const;
    int get_nrT() const;
    int get_soclu() const;
    int getPret() const;
};
#endif //SIM_COMPONENTE_PROCESOR_H
