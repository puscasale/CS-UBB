//
// Created by Ale on 05/20/2024.
//

#ifndef SIM_COMPONENTE_PLACA_H
#define SIM_COMPONENTE_PLACA_H
#include <string>
using std::string;

class Placa{
private:
    string nume;
    int socluProcesor;
    int pret;
public:
    Placa(string nume, int socluProcesor, int pret) : nume{nume}, socluProcesor{socluProcesor}, pret{pret}{};
    string get_nume() const;
    int get_soclu() const;
    int get_pret() const;
};
#endif //SIM_COMPONENTE_PLACA_H
