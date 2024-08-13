//
// Created by Ale on 05/21/2024.
//

#include <iostream>
#include "tests.h"
#include "assert.h"
void testproc(){
    Procesor pr("n", 1, 11, 2);
    assert(pr.getNume() == "n");
    assert(pr.get_nrT() == 1);
    assert(pr.get_soclu() == 11);
    assert(pr.getPret() == 2);
}

void test_repo_srv() {
    RepoPlaca placa{R"(C:\Users\Ale\Desktop\sim_componente\test.txt)"};
    RepoProcesoare proc {R"(C:\Users\Ale\Desktop\sim_componente\test.txt)"};

    Service srv(proc,placa);
    srv.addPlaca("a",2,3);
    assert(placa.get_all()[0].get_nume() == "a");
    assert(proc.sizeProc() == 1);
    assert(srv.nrPlaci()== 3);
    assert(srv.nrProcese() == 1);
    int nr = srv.total(Procesor("a",2,3,4),Placa("a",2,3));
    assert(nr == 7);
    vector<Placa> fil;
    fil = srv.filter(Procesor("a",2,3,4));
    assert(fil.size() == 0);

}



void test_all(){
    testproc();
    test_repo_srv();
}
