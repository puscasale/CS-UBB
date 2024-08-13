//
// Created by Ale on 05/20/2024.
//

#include "Service.h"

void Service::addPlaca(string nume, int soclu, int pret) {
    Placa p(nume, soclu, pret);
    placa.addPlaca(p);

}

int Service::nrPlaci() {
    return placa.sizePlaca();
}

int Service::nrProcese() {
    return proces.sizeProc();
}

int Service::total(const Procesor &proc, const Placa &placa) {
    return proc.getPret() + placa.get_pret();
}

const vector<Placa> Service::filter(const Procesor &p) {
    static vector<Placa> fil;
    for(const auto& el: placa.get_all())
        if(el.get_soclu() == p.get_soclu())
            fil.push_back(el);

    return fil;
}




