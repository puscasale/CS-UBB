//
// Created by Ale on 05/22/2024.
//

#include "tests.h"

#include "assert.h"

void test_echipe(){
    Echipe e("a","a",2,3);
    assert(e.get_nume() == "a");
    assert(e.get_tara() == "a");
    assert(e.get_urna() == 3);
    assert(e.get_coef() == 2);
}

void test_srv(){
    Repo rep(R"(C:\Users\Ale\Desktop\test_oop\file.txt)");
    Service srv(rep);
    assert(srv.get_all().size() == 10);
    vector<Echipe> fil;
    srv.filter(2,fil);
    assert(fil.empty());
}

void test_all() {
    test_srv();
    test_echipe();
}
