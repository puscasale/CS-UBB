#include "med.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
 * Creeaza o entitate de tipul Med
 * param id: idul entitatii (int)
 * param name: numele entitatii (char)
 * param concentration: concentratia entitatii (int)
 * param stock: stocul (int)
 * return: Med
 */
Med create(int id, char *name, int concentration, int stock){
    Med new;
    new.id = id;

    int nr = strlen(name) + 1;
    new.name = malloc(nr);
    strcpy(new.name, name);

    new.concentration = concentration;
    new.stock = stock;

    return new;
}

/*
 * Dealoca memoria ocupata de o entitate Med
 */
void destroy(Med *m){
    m->id = -1;
    free(m->name);
    m->concentration = -1;
    m->stock = -1;
}


int containsOnlyLetters(const char *str) {
    while (*str) {
        if (!isalpha(*str)) {
            return 0; // Not a letter
        }
        str++;
    }
    return 1; // Only contains letters
}

/*
 * Valideaza entitatea Med
 * return: 1 - id invalid
 *         2 - nume invalid
 *         3 - concentratie invalida
 *         4 - stock ivalid
 *         0 - entitate valida
 */
int validate(Med m){
    if(m.id < 0)
        return 1;
    if(containsOnlyLetters(m.name) == 0)
        return 2;
    if(m.concentration < 0)
        return 3;
    if(m.stock < 0)
        return 4;
    return 0;
}
