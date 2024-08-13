//
// Created by Ale on 05/19/2024.
//

#ifndef SIM_APARTAMENTE_APARTAMENT_H
#define SIM_APARTAMENTE_APARTAMENT_H
#include <string>
using std::string;
class Apartamente{
private:
    int sup;
    string str;
    int pret;
public:
    /**
     * Constructor
     * @param str : strada
     * @param sup : suprafata
     * @param pret : pretul
     */
    Apartamente(string str, int sup, int pret) : str{str}, sup{sup}, pret{pret}{};

    Apartamente() = default;

    /**
     * Getter pt strada
     * @return : strada
     */
    string get_str() const;


    /**
     * Getter pt supratafa
     * @return : suprafata
     */
    int get_sup() const;

    /**
     * Getter pt pret
     * @return : pret
     */
    int get_pret() const;
};
#endif //SIM_APARTAMENTE_APARTAMENT_H
