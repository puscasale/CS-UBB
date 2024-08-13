#ifndef LAB2_4_DINAMIC_FUNCTIONS_H
#define LAB2_4_DINAMIC_FUNCTIONS_H
#include <crtdbg.h>
#include "list.h"
/*
 * Adauga un medicamnet in lista, daca deja exista un medicamnet cu acest id se updateaza stocul
 * param l: lista
 * param id: id ul medicamnetului (int)
 * param name: numele medicamnetului (char)
 * param concentration: concentratia medicamnetului (int)
 * param stock: stocul medicamnetului (int)
 * return: 0 - date invalide
 *         1 - s a efectuat adaugarea, modificarea stocului
 */
int add_med(List *l, int id, char *name, int concentration, int stock);

/*
 * Sterge un medicamnet de pe o pozitie
 * param poz: pozitia medicamnetului pe care vrem sa il stergem
 * return: 0 - stergerea s a efectuat
 *         1 - pozitie invalida
 */
int delete_med(List *l, int poz);

/*
 * Modifica numele si concentratia unui medicament
 * param l: lista
 * param poz: pozitai medicamentului (int)
 * param new_name: noul nume ( char)
 * param new_concentration: noua concentratie (int)
 * return: 0 - modificarea sa efectuat
 *         1 - pozitie invalida
 */
int modify_med(List *l, int poz, char *new_name, int new_concentration);

/*
* Filtreaza lista de medicamente dupa stoc
* param l: lista
* param stock: stoc (int)
* return: lista filtrata care contine elemente care au stocul mai mic decat stocul dat
*/
List filter_stock(List *l, int stock);

/*
* Filtreaza lista de medicamente dupa nume
* param l: lista
* param letter: o listera (char)
* return: lista filtrata care contine elemente a caror nume incepe cu litera data
*/
List filter_name(List *l, char letter);



int cmpName(Med* m1, Med* m2);

int cmpStock(Med* m1, Med *m2);

List sortNAme(List *l);

List sortStock(List *l);

#endif //LAB2_4_DINAMIC_FUNCTIONS_H
