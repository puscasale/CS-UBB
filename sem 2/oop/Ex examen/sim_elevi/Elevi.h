//
// Created by Ale on 05/20/2024.
//

#ifndef SIM_ELEVI_ELEVI_H
#define SIM_ELEVI_ELEVI_H
#include <string>
using std::string;
class Elevi{
private:
    int nrmat;
    string nume;
    string scoala;
public:
    Elevi(int nrmat, string nume, string scoala): nrmat{nrmat}, nume{nume}, scoala{scoala}{};

    Elevi() = default;

    /**
     * Getter
     * @return nrmat
     */
    int get_nrmat() const;

    /**
     * Getter
     * @return nume
     */
    string get_nume() const;

    /**
     * Getter
     * @return scoala
     */
    string get_scoala() const;

};
#endif //SIM_ELEVI_ELEVI_H
