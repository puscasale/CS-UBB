#include <stdio.h>
#include "functions.h"
#include "functions_test.h"
#include <stdbool.h>

void print_menu(){
    printf("1.%s\n2.%s\n3.%s\n4.%s\n5.%s\n6.%s\n7.%s\n", "Afisare medicamente", "Adaugare", "Stergere", "Modificare", "Soartare", "Filtrare", "Iesire");

}

/*
 * Printeaza un medicament dat
 */
void print_medicament(Medicament medicament){
    printf("cod: %d | nume: %s | concentratie: %d | cantitate: %d", get_cod(&medicament), get_nume(&medicament),
           get_concentratie(&medicament), get_cantitate(&medicament));
}

void print_errs(char err[5][100], int len){
    for(int l = 0; l < len; l++){
        printf("%s", err[l]);
    }
}

void print_medicamente(Medicament_list medicamente){
    if(get_size(&medicamente) > 0)
        for( int i = 0; i < get_size(&medicamente); i++)
            printf("cod: %d | nume: %s | concentratie: %d | cantitate: %d\n", get_cod(&medicamente.nr[i]), get_nume(&medicamente.nr[i]),
                   get_concentratie(&medicamente.nr[i]), get_cantitate(&medicamente.nr[i]));
    else printf("Nu exista medicamenete\n");
}

void add_medicament_ui(Medicament_list *medicamente){
    int cod, concentractie, cantitate, len;
    char nume[30], err[5][100];

    printf("Introduceti codul:");
    scanf("%d", &cod);

    printf("Introduceti numele:");
    scanf("%s", nume);

    printf("Introduceti concentratia:");
    scanf("%d", &concentractie);

    printf("Introduceti cantitatea:");
    scanf("%d", &cantitate);

    add_medicament(medicamente, cod, nume, concentractie, cantitate, err, &len);
    if(len)
        print_errs(err, len);
}

void delete_medicament_ui(Medicament_list *medicamente){
    int cod, len;
    char  err[5][100];

    printf("Introduceti codul:");
    scanf("%d", &cod);
    delete_medicament(medicamente, cod, err, &len);
    if(len)
        print_errs(err, len);
}

void update_medicament_ui(Medicament_list *medicamente){
    int cod, new_concentratie, len;
    char new_name[30], err[5][100];

    printf("Introduceti codul:");
    scanf("%d", &cod);

    printf("Introduceti noul nume:");
    scanf("%s", new_name);

    printf("Introduceti noua concentratie:");
    scanf("%d", &new_concentratie);

    modificare_medicament(medicamente, cod, new_name, new_concentratie, err, &len);
    if(len)
        print_errs(err, len);
}

void test_functions(){
    test_create_list();
    test_create_medicament();
    test_valid();
    test_add();
    test_delete();
    test_add_medicament();
    test_delete_medicament();
    test_valid_new_concentratie();
    test_valid_new_name();
    test_modificare_medicament();
}

int main() {
    Medicament_list medicamente = create_list();
    test_functions();
    int option;
    while(true)
    {
        print_menu();
        printf("Introduceti optiunea:");
        scanf("%d", &option);
        switch (option) {
            case 1:
                print_medicamente(medicamente);
                break;
            case 2:
                add_medicament_ui(&medicamente);
                break;
            case 3:
                delete_medicament_ui(&medicamente);
                break;
            case 4:
                update_medicament_ui(&medicamente);
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                return 0;
            default:
                printf("Optiune invaida\n");
                break;
        }
        printf("\n");
    }
}
