//
// Created by Ale on 05/21/2024.
//

#include "tests.h"
#include "assert.h"
void test_set() {
    Rochie r{1,"a","e",2,true};
    r.set_dis(false);
    assert(r.get_dis() == false);
}

void test_srv() {
    Repo rep(R"(C:\Users\Ale\Desktop\sim_rochii\file.txt)");
    Service srv(rep);
    vector<Rochie> sorted;
    srv.sort_marime(sorted);
    assert(sorted[0].get_marime() == "L");
    srv.sort_pret(sorted);
    assert(sorted[0].get_pret() == 30);
}

void test_all() {
    test_set();
    test_srv();
}