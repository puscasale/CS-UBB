#include "tests.h"
#include "functions.h"
#include "med.h"
#include "list.h"
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <crtdbg.h>

//list tests
void test_CreateList(){
    List l = create_list();
    assert(size(&l) == 0);
    destroy_list(&l);
}

void test_get() {
    List l = create_list();
    add(&l,create(1,"nurofen",67,100));
    Med m;
    m = get(&l, 0);
    assert(m.id == 1);
    destroy_list(&l);
}

void test_set() {
    List l = create_list();
    add(&l, create(1, "nurofen", 67, 100));
    add(&l, create(2, "nuj", 7, 10));
    TElem original = get(&l, 1);
    set(&l, 1, create(3, "vitamine", 56, 8));
    assert(l.elements[1].id == 3);
    assert(size(&l) == 2);
    destroy(&original);
    destroy_list(&l);


}

void test_add() {
    List l = create_list();
    add(&l,create(1,"nurofen",67,100));
    assert(size(&l) == 1);
    add(&l,create(2,"nurofen",67,100));
    assert(l.capacitate == l.lung);
    add(&l,create(3,"nurofen",67,100));
    assert(l.capacitate != l.lung);
    destroy_list(&l);
}

void test_delete() {
    List l = create_list();
    Med m = create(1,"nurofen",67,100);
    add(&l, m);
    destroy(&m);
    assert(get(&l, 0).stock == 100);
    add(&l, create(2, "agocalmin",97, 87));
    delete(&l, 0);
    assert(size(&l) == 1);
    destroy_list(&l);
}

void test_Modify() {
    List l = create_list();
    add(&l,create(1,"nurofen",67,100));
    modify(&l, 0, "teraflu", 100);
    assert(strcmp(l.elements[0].name, "teraflu") == 0);
    assert(l.elements[0].concentration == 100);
    destroy_list(&l);
}

void test_CopyList(){
    List l = create_list();
    add(&l, create(1,"nurofen",67,100));
    add(&l, create(2, "agocalmin",97, 87));

    List l2 = copy_list(&l);
    assert(size(&l2) == 2);
    destroy_list(&l);
    free(l2.elements);
}

void test_resize() {
    List l = create_list();
    add(&l, create(1,"nurofen",67,100));
    add(&l, create(2,"nurofen",67,100));
    resize(&l);
    assert(l.capacitate == 4);
    destroy_list(&l);
}

//med tests

void test_validate(){
    Med m = create(-2, "nurofen", 3, 4);
    assert(validate(m) == 1);
    destroy(&m);

    Med m1 = create(1, "34", 3, 4);
    assert(validate(m1) == 2);
    destroy(&m1);

    Med m2 = create(1, "nurofen", -3, 7);
    assert(validate(m2) == 3);
    destroy(&m2);

    Med m3 = create(1, "nurofen", 3, -4);
    assert(validate(m3) == 4);
    destroy(&m3);

    Med m4 = create(1, "nurofen", 2, 3);
    assert(validate(m4) == 0);
    destroy(&m4);

}

void test_add_med() {
    List l = create_list();
    int error = add_med(&l, 1, "nuj", -4, 6);
    assert(error == 3);
    add_med(&l, 1, "nurofen", 3, 3);
    assert(size(&l) == 1);
    add_med(&l, 1, "nurofen", 3, 10);
    assert(l.elements[0].stock == 13);
     error = add_med(&l, 1, "fr", 4, 10);
    assert(error != 0);
    destroy_list(&l);
}

void test_delete_med() {
    List l = create_list();
    int error = delete_med(&l, 7);
    assert(error != 0);
    add_med(&l, 1, "nurofen", 2, 3);
    add_med(&l, 2, "nuj", 4, 5);
    delete_med(&l, 1);
    assert(size(&l) == 1);
    destroy_list(&l);
}

void test_modify_med() {
    List l = create_list();
    add_med(&l, 1, "nurofen", 2, 3);
    modify_med(&l, 0, "nume", 99);
    assert(l.elements[0].concentration == 99);
    int error = modify_med(&l, 9, "nuj", 8);
    assert(error != 0);
    error = modify_med(&l, 0, "87", -2);
    assert(error != 0);
    destroy_list(&l);

}

void test_filter_stock() {
    List l = create_list();
    add_med(&l, 1, "nurofen", 2, 3);
    add_med(&l, 2, "nuj", 5, 8);
    List rez = filter_stock(&l, 7);
    assert(size(&rez) == 1);
    free(rez.elements);
    destroy_list(&l);

}

void test_filter_name() {
    List l = create_list();
    add_med(&l, 1, "nurofen", 2, 3);
    add_med(&l, 2, "nuj", 5, 8);
    List rez = filter_name(&l, 'n');
    assert(size(&rez) == 2);
    free(rez.elements);
    destroy_list(&l);

}

void test_sortStock() {
    List l = create_list();
    add_med(&l, 1, "nurofen", 2, 3);
    add_med(&l, 2, "nuj", 5, 8);
    add_med(&l, 3, "nurofen", 5, 2);
    add_med(&l, 4, "urofen", 6, 2);
    List sorted = sortStock(&l);
    assert(sorted.elements[0].id == 3);
    destroy_list(&l);
    free(sorted.elements);
}

void test_sortName() {
    List l = create_list();
    add_med(&l, 1, "nurofen", 2, 9);
    add_med(&l, 2, "auj", 5, 9);
    add_med(&l, 3, "burofen", 5, 8);
    List sorted = sortNAme(&l);
    assert(sorted.elements[2].id == 1);
    destroy_list(&l);
    free(sorted.elements);
}
























































//list tests















