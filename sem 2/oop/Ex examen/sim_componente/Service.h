//
// Created by Ale on 05/20/2024.
//

#ifndef SIM_COMPONENTE_SERVICE_H
#define SIM_COMPONENTE_SERVICE_H
#include "RepoPlaca.h"
#include "RepoProcesoare.h"

class Service{
private:
    RepoPlaca placa;
    RepoProcesoare proces;
public:
    Service(RepoProcesoare& procese, RepoPlaca& placa) : proces(procese), placa(placa){};

    /**
     * Get all placa
     * @return : all placa
     */
    const vector<Placa>& get_allPlaca() {
        return placa.get_all();
    }

    /**
     * Get all procesor
     * @return : all procesor
     */
    const vector<Procesor>& get_allProcese() {
        return proces.get_all();
    }

    /**
     * adauga placa
     * @param nume : nume placa
     * @param soclu : nr soclu
     * @param pret : pret
     */
    void addPlaca(string nume, int soclu, int pret);

    /**
     *
     * @return : nr placi
     */
    int nrPlaci();

    /**
     *
     * @return : nr procesoare
     */
    int nrProcese();

    /**
     * Total proc + placa
     */
    int total(const Procesor& proc, const Placa& placa);

    /**
     * filtrare
     * @param p
     * @return
     */
    const vector<Placa> filter(const Procesor& p);
};
#endif //SIM_COMPONENTE_SERVICE_H
