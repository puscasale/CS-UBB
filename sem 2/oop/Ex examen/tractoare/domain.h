//
// Created by Ale on 06/24/2024.
//

#ifndef TRACTOARE_DOMAIN_H
#define TRACTOARE_DOMAIN_H
#include <string>
using namespace std;
class Tractor{
private:
    int id, nrR;
    string denumire, tip;
public:
    Tractor(int id, string denumire, string tip, int nrR): id{id},denumire{denumire},tip{tip},nrR{nrR}{};
    Tractor()=default;
    int get_id(){return id;}
    int get_nrR(){return nrR;}
    string get_denumire(){return denumire;}
    string get_tip(){return tip;}
};
#endif //TRACTOARE_DOMAIN_H
