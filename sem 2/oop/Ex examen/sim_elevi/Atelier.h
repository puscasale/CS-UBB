//
// Created by Ale on 05/21/2024.
//

#ifndef SIM_ELEVI_ATELIER_H
#define SIM_ELEVI_ATELIER_H
#include "Elevi.h"
#include <vector>
using std::vector;
class Atelier {
private:
    Elevi e;
    string a;
public:
    Atelier(Elevi& e, string & a) : e(e), a(a) {};

    vector<Atelier>& get_ateliere(Elevi& e);
};
#endif //SIM_ELEVI_ATELIER_H
