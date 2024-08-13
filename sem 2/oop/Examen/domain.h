//
// Created by Ale on 06/25/2024.
//

#ifndef UNTITLED1_DOMAIN_H
#define UNTITLED1_DOMAIN_H
#include <string>

using namespace std;

class Masina{
private:
    string nrinmat;
    string denumire;
    int an;
    string tip;
public:
    //Constructor
    Masina(string nrinmat, string denumire, int an, string tip):nrinmat(nrinmat),denumire(denumire),an(an),tip(tip){};
    Masina()=default;
    /**
     * Gettere si setere
     */
    string get_nr() const {return nrinmat;}
    string get_den() const {return denumire;}
    int get_an() const {return an;}
    string get_tip() const {return tip;}
    void set_an(int an_nou){an=an_nou;}
};
void test_domain();
#endif //UNTITLED1_DOMAIN_H
