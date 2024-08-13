//
// Created by Ale on 05/19/2024.
//
#include <iostream>
#include "tests.h"
#include <assert.h>
void test_getter() {
    const Apartamente a("a",2,3);
    assert(a.get_pret() == 3);
    assert(a.get_sup() ==2);
    assert(a.get_str() == "a");
}

void test_store_del() {
    Repo rep;
    const Apartamente a("a",2,3);
    rep.store(a);
    assert(rep.get_all().size() == 1);
    rep.remove(a);
    assert(rep.get_all().empty());
}

void test_add_del() {
    Repo rep;
    Service srv{rep};
    srv.add("a",2,3);
    assert(srv.get_all().size() == 1);
    srv.del(Apartamente("a",2,3));
    assert(srv.get_all().empty());
}

void test_filter() {
    Repo rep;
    Service srv{rep};
    srv.add("a",2,3);
    srv.add("a",4,5);
    srv.add("w",6,8);
    vector<Apartamente> fil;
    srv.filter_pret(2,6,fil);
    assert(fil.size() ==2);
    vector<Apartamente> fil2;
    srv.filter_sup(3,9,fil2);
    assert(fil.size() == 2);
}

void test_all() {
    test_add_del();
    test_filter();
    test_getter();
    test_store_del();
}
