//
// Created by Ale on 05/22/2024.
//

#ifndef TEST_OOP_ECHIPE_H
#define TEST_OOP_ECHIPE_H
#include "string"
using std::string;
class Echipe{
private:
    string nume;
    string tara;
    int coef;
    int urna;
public:
    Echipe(string nume, string tara, int coef, int urna): nume(nume), tara(tara), coef(coef), urna(urna){};

    //Getterre pt campuri
    const string get_nume() const;

    string get_tara()const;

    int get_coef() const;

    int get_urna() const;
};
#endif //TEST_OOP_ECHIPE_H
