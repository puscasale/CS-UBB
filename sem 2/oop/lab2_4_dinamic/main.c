#include <stdio.h>
#include "functions.h"
#include "med.h"
#include "list.h"
#include "tests.h"
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <stdlib.h>
#include <stdbool.h>


void run(){
    List l = create_list();
    while(true){
        printf("\n1. Vizualizare\n2. Adaugare\n3. Stergere\n4. Modificare\n5. Filtrate\n6. Sortare\n7. Iesire\n");
        int option = 0;
        printf("\nIntroduceti optiunea:");
        scanf("%d", &option);
        switch (option) {
            case 1: {
                if(size(&l) == 0)
                    printf("\nNu exista medicamente");
                else {
                    for( int i = 0; i < size(&l); i++){
                        Med m = get(&l, i);
                        printf("\nId:%d Nume:%s Concentratie:%d Stoc:%d",m.id, m.name, m.concentration, m.stock);
                    }
                }
                break;
            }
            case 2: {
                int id, stock, concentration;
                char name[50];

                printf("Introduceti id-ul:");
                scanf("%d", &id);

                printf("Intrdouceti numele:");
                scanf("%s", &name);

                printf("Introduceti concentratia:");
                scanf("%d", &concentration);

                printf("Introduceti stocul:");
                scanf("%d", &stock);

                int error = add_med(&l, id, name, concentration, stock);
                if(error != 0)
                    printf("Medicament invalid");
                else
                    printf("Medicament adaugat");
                break;
            }
            case 3: {
                int poz = 0;

                printf("Introduceti pozitia:");
                scanf("%d", &poz);

                poz = poz-1;
                int error = delete_med(&l, poz);
                if(error != 0)
                    printf("Medicamentul nu exista");
                else
                    printf("Medicament sters");
                break;
            }
            case 4: {
                int  new_concentration;
                char new_name[50];
                int poz = 0;

                printf("Introduceti pozitia:");
                scanf("%d", &poz);

                poz = poz - 1;
                printf("Introduceti noul nume:");
                scanf("%s", &new_name);

                printf("Introduceti noua concentratie:");
                scanf("%d", &new_concentration);

                int error = modify_med(&l, poz, new_name, new_concentration);
                if(error != 0)
                    printf("Medicament invalid");
                else
                    printf("Medicament modificat");
                break;
            }
            case 5: {
                char letter;
                int number;
                int crt;

                printf("1. Stoc\n2. Nume");
                printf("\nIntroduceti criteriul de filtrare:");

                scanf("%d", &crt);

                if(crt == 1){
                    printf("Introduceti un numar:");
                    scanf("%d", &number);
                    List rez = filter_stock(&l, number);

                    if(size(&rez) == 0){
                        printf("Nu exisat medicamente care sa aiba stocul mai mic decat numarul dat");
                    }
                    else {
                        for( int i = 0; i < size(&rez); i++){
                            Med m = get(&rez, i);
                            printf("\nId:%d Nume:%s Concentratie:%d Stoc:%d",m.id, m.name, m.concentration, m.stock);
                        }
                    }
                }

                else {
                    getchar();
                    printf("Introduceti o litera:");
                    scanf("%c", &letter);
                    List rez = filter_name(&l, letter);

                    if(size(&rez) == 0){
                        printf("Nu exista medicamente a caror nume sa inceapa cu aceasta litera");
                    }
                    else{
                        for( int i = 0; i < size(&rez); i++){
                            Med m = get(&rez, i);
                            printf("\nId:%d Nume:%s Concentratie:%d Stoc:%d",m.id, m.name, m.concentration, m.stock);
                        }
                    }
                }
                break;
            }
            case 6: {
                int mod;
                printf("1. Nume\n2. Stoc");
                printf("\nIntroduceti modeul de sortare:");
                scanf("%d", &mod);

                if(mod == 1) {
                    List sorted = sortNAme(&l);
                    for( int i = 0; i < size(&sorted); i++){
                        Med m = get(&sorted, i);
                        printf("\nId:%d Nume:%s Concentratie:%d Stoc:%d",m.id, m.name, m.concentration, m.stock);
                    }
                    free(sorted.elements);
                }
                else{
                    List sorted = sortStock(&l);
                    for( int i = 0; i < size(&sorted); i++){
                        Med m = get(&sorted, i);
                        printf("\nId:%d Nume:%s Concentratie:%d Stoc:%d",m.id, m.name, m.concentration, m.stock);
                    }
                    free(sorted.elements);
                }
                break;

            }
            case 7: {
                destroy_list(&l);
                exit(0);
            }
            default: {
                printf("\nOptiune invalida");
                break;
            }
        }
    }
}

void tests(){
    test_resize();
    test_add();
    test_set();
    test_get();
    test_Modify();
    test_delete();
    test_CopyList();
    test_CreateList();
    test_validate();
    test_add_med();
    test_delete_med();
    test_modify_med();
    test_filter_stock();
    test_filter_name();
    test_sortStock();
    test_sortName();

}

int main() {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    tests();
    run();
    return 0;
}
