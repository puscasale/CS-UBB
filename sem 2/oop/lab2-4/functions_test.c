#include "functions.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>

void test_create_list(){

    Medicament_list medicamente = create_list();
    assert(get_size(&medicamente) == 0);
}

void test_create_medicament(){
    Medicament medicament;
    medicament = create_medicament(1, "nume", 2, 12);
    assert(get_cod(&medicament) == 1);
    assert(strcmp(get_nume(&medicament), "nume") == 0);
    assert(get_concentratie(&medicament) == 2);
    assert(get_cantitate(&medicament) == 12);
}

void test_valid(){
    Medicament_list medicamente = create_list();
    Medicament medicament, medicament1, medicament2;
    char err[5][100];
    int len;

    medicament = create_medicament(1, "nume", 2, 12);
    assert(valid(&medicamente,medicament, err, &len));
    assert(len == 0);

    add(&medicamente, medicament);
    medicament1 = create_medicament(1, "23", -3, -5);
    valid(&medicamente, medicament1, err, &len);
    assert(len != 0);
    add(&medicamente, medicament);
    int cod = -2;

    medicament2 = create_medicament(cod, "numee", 3, 5);
    valid(&medicamente, medicament2, err, &len);
    assert(len != 0);


}
void test_valid_new_concentratie(){
    char err[5][100];
    int len = 0;
    assert(valid_new_concentratie( 6, err, &len));
    assert(len == 0);
    int concentratie = -2;
    valid_new_concentratie( concentratie, err, &len);
    assert(len != 0);
}

void test_valid_new_name(){
    char err[5][100];
    int len = 0;
    valid_new_name("paracetamol", err, &len);
    assert(len == 0);
    valid_new_name("23", err, &len);
    assert(len != 0);
}

void test_delete(){
    Medicament_list  medicamente = create_list();
    Medicament medicament1, medicament2, medicament3;
    medicament1 = create_medicament(1, "nume1", 2, 3);
    medicament2 = create_medicament(2, "nume2", 3, 4);
    medicament3 = create_medicament(3, "nume3", 4, 5);
    add(&medicamente, medicament1);
    add(&medicamente, medicament2);
    add(&medicamente, medicament3);
    assert(get_size(&medicamente) == 3);
    delete(&medicamente, 1);
    assert(get_size(&medicamente) == 2);
    delete(&medicamente, 2);
    assert(get_size(&medicamente) == 1);
}

void test_add(){
    Medicament_list medicamente = create_list();
    Medicament medicament1, medicament2, medicament3, medicament4;
    medicament1 = create_medicament(1, "nume1", 2, 3);
    medicament2 = create_medicament(2, "nume2", 3, 4);
    medicament3 = create_medicament(3, "nume3", 4, 5);
    add(&medicamente, medicament1);
    add(&medicamente, medicament2);
    add(&medicamente, medicament3);
    assert(get_size(&medicamente) == 3);
    medicament4 = create_medicament(4, "nume4", 5, 6);
    add(&medicamente, medicament4);
    assert(get_size(&medicamente) == 4);

}

void test_add_medicament(){
    Medicament_list medicamente = create_list();
    char err[5][100];
    int len;
    add_medicament(&medicamente, 1, "nume", 2, 4, err, &len);
    assert(get_size(&medicamente) == 1);
    add_medicament(&medicamente, 2, "nume2", 3, 4, err, &len);

}

void test_delete_medicament(){
    Medicament_list medicamente = create_list();
    char err[5][100];
    int len;

    add_medicament(&medicamente, 1, "nume", 2, 3, err, &len);
    assert(get_size(&medicamente) == 1);
    add_medicament(&medicamente, 2, "nume2", 5, 7, err, &len);
    delete_medicament(&medicamente, 10, err, &len);
    assert(len != 0);
    delete_medicament(&medicamente, 1, err, &len);
    assert(get_size(&medicamente) == 0);
    delete_medicament(&medicamente, 6, err, &len);
    assert(len != 0);

}

void test_modificare_medicament(){
    Medicament_list medicamente = create_list();
    Medicament medicament;
    char err[5][100];
    int len;
    medicament = create_medicament(1, "nume", 2, 3);
    add(&medicamente, medicament);
    modificare_medicament(&medicamente,1,"nume2",22,err, &len);
    int concentratie = 22;
    printf("%d",get_concentratie(&medicamente.nr[0]));
    //assert(get_concentratie(&medicamente.nr[0]) == concentratie);
}


