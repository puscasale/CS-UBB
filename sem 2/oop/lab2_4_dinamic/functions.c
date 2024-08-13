#include "functions.h"
#include "customSort.h"
#include <ctype.h>
#include <string.h>

/*
 * Adauga un medicamnet in lista, daca deja exista un medicamnet cu acest id se updateaza stocul
 * param l: lista
 * param id: id ul medicamnetului (int)
 * param name: numele medicamnetului (char)
 * param concentration: concentratia medicamnetului (int)
 * param stock: stocul medicamnetului (int)
 * return: 1 - date invalide
 *         0 - s a efectuat adaugarea, modificarea stocului
 */
int add_med(List *l, int id, char *name, int concentration, int stock) {
    for( int i = 0; i < size(l); i ++) {
        TElem med = get(l, i);
        if (id == med.id && concentration != med.concentration && strcmp(name, med.name) != 0) {
            return 1;
        }
    }

    Med m = create(id, name, concentration, stock);
    int valid = validate(m);
    if(valid != 0){
        destroy(&m);
        return valid;
    }
    for( int i = 0; i < size(l); i ++){
        TElem existing_med = get(l, i);
        if(existing_med.id == m.id && existing_med.concentration == m.concentration && strcmp(existing_med.name, m.name) == 0){
            existing_med.stock = m.stock + existing_med.stock;
            set(l, i, existing_med);
            destroy(&m);
            return 0;
        }
    }
    add(l, m);
    return 0;
}

/*
 * Sterge un medicamnet de pe o pozitie
 * param poz: pozitia medicamnetului pe care vrem sa il stergem
 * return: 0 - stergerea s a efectuat
 *         1 - pozitie invalida
 */
int delete_med(List *l, int poz){
    if( poz < 0 || poz >= l->lung)
        return 1;
    destroy(&l->elements[poz]);
    delete(l, poz);
    return 0;
}

/*
 * Modifica numele si concentratia unui medicament
 * param l: lista
 * param poz: pozitai medicamentului (int)
 * param new_name: noul nume ( char)
 * param new_concentration: noua concentratie (int)
 * return: 0 - modificarea sa efectuat
 *         1 - pozitie invalida
 */
int modify_med(List *l, int poz, char *new_name, int new_concentration){
    if (poz < 0 || poz >= l->lung)
        return 1;
    int id = l->elements[poz].id;
    int stock = l->elements[poz].stock;
    Med m = create(id, new_name, new_concentration, stock);
    int valid = validate(m);
    if(valid != 0){
        destroy(&m);
        return valid;
    }
    modify(l, poz, new_name, new_concentration);
    destroy(&m);
    return 0;
}

/*
* Filtreaza lista de medicamente dupa stoc
* param l: lista
* param stock: stoc (int)
* return: lista filtrata care contine elemente care au stocul mai mic decat stocul dat
*/
List filter_stock(List *l, int stock){
    List rez = create_list();
    for( int i = 0; i < size(l); i++){
        TElem elem = get(l, i);
        if(elem.stock < stock)
            add(&rez, elem);
    }
    return rez;
}

/*
* Filtreaza lista de medicamente dupa nume
* param l: lista
* param letter: o listera (char)
* return: lista filtrata care contine elemente a caror nume incepe cu litera data
*/
List filter_name(List *l, char letter){
    List rez = create_list();
    letter = tolower(letter);

    for( int i = 0; i < size(l); i++){
        TElem elem = get(l, i);
        char first_letter = +tolower(elem.name[0]);
        if(first_letter == letter)
            add(&rez, elem);
    }
    return rez;
}

int cmpName(Med* m1, Med* m2){
    return strcmp(m1->name, m2->name);
}

int cmpStock(Med* m1, Med *m2){
    if(m1->stock == m2->stock)
        return 0;
    if(m1->stock > m2->stock)
        return 1;
    else
        return -1;
}

List sortStock(List *l){
    List Stocklst = copy_list(l);
    sort(&Stocklst, cmpStock);
    return Stocklst;
}

List sortNAme(List *l){
    List Namelst = copy_list(l);
    sort(&Namelst, cmpName);
    return Namelst;
}



