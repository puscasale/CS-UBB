//
// Created by Ale on 06/25/2024.
//

#include "domain.h"
#include "iostream"
#include "assert.h"

void test_domain(){
    Masina m("nr1","a",2022,"van");
    assert(m.get_an() == 2022);
    assert(m.get_tip() == "van");
    assert(m.get_den() == "a");
    assert(m.get_nr() == "nr1");
    m.set_an(2000);
    assert(m.get_an() == 2000);
}