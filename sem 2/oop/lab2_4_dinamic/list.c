#include "list.h"
#include <stdlib.h>

/*
* Creeaza o lista goala
* return: lista
*/
List create_list() {
    List rez;
    rez.lung = 0;
    rez.capacitate = 2;
    rez.elements = malloc(rez.capacitate * sizeof(TElem ));
    return rez;
}


/*
 * Distruge o lista
 * param: l (lista)
*/
void destroy_list(List *l) {

    for(int i = 0; i < l->lung; i++)
    {
        destroy(&l->elements[i]);
    }
    l->lung = 0;
    free(l->elements);
}

/*
 * Realoca spatiul pentru lista
 * param: l (lista)
 */
void resize(List *l){
    int new_capacitate =  2 * l->capacitate;
    TElem *new_elements = malloc(new_capacitate * sizeof(TElem));
    for(int i = 0; i < l->lung; i++)
    {
        new_elements[i] = l->elements[i];
    }
    free(l->elements);
    l->elements = new_elements;
    l->capacitate = new_capacitate;
}

/*
  Returneaza elementul din lista de pe pozitia data
  param: poz - pozitia elementului
  return: elementul de pe pozitia poz
*/
TElem get(List *l, int poz) {
    return l->elements[poz];
}

/*
 * Seteaza elementul din lista de pe pozitia data
 * param poz: pozitia elementului
 * param new_m: noul element
 */
void set(List *l, int poz, Med new_m){
    l->elements[poz] = new_m;
}

/*
  Returneaza lungimea unei liste
  param: l (list)
  return: lungimea listei l
*/
int size(List *l) {
    return l->lung;
}

/*
 * Adauga in lista l elementul el
 * param: l (lista)
 * param: el - elementul care se adauga in lista (TElem)
 */
void add(List *l, TElem el) {
    if(l->lung == l->capacitate){
        resize(l);
    }
    l->elements[l->lung] = el;
    l->lung++;
}

/*
 * Sterge elementul de pe o pozitie
 * param: l (list)
 * param: poz - pozitia de pe care se sterge elementul (int)
 */
void delete(List *l, int poz) {
    for (int i = poz; i < l->lung - 1; i++) {
        l->elements[i] = l->elements[i + 1];
    }
    l->lung--;
}

/*
 * Modifica elementul de pe o anumita pozitie
 * param l: lista
 * param poz: pozitia de pe care se modifica elementul
 * param new_name: numele entitatii (char)
 * param new_concentration: concentratia  entitatii (int)
 */
void modify(List *l, int poz, char *new_name, int new_concentration) {
    int id = l->elements[poz].id;
    int stock = l->elements[poz].stock;
    destroy(&l->elements[poz]);
    Med new_m = create(id, new_name, new_concentration, stock);
    l->elements[poz] = new_m;
}

/*
 * Returneaza o copie a unei liste
 * param: l (list)
 * return: lista
 */
List copy_list(List* l) {
    List rez = create_list();
    for (int i = 0; i < size(l); i++) {
        TElem o = get(l, i);
        add(&rez, o);
    }

    return rez;
}
