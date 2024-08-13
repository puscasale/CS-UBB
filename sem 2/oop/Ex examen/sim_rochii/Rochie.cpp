//
// Created by Ale on 05/21/2024.
//

#include "Rochie.h"

int Rochie::get_cod() const {
    return cod;
}

string Rochie::get_nume() const {
    return nume;
}

string Rochie::get_marime() const {
    return marime;
}

int Rochie::get_pret() const {
    return pret;
}

bool Rochie::get_dis() const {
    return disponibil;
}

void Rochie::set_dis(bool dis1) {
    this->disponibil = dis1;
}


