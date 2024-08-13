#ifndef LAB2_4_DINAMIC_MED_H
#define LAB2_4_DINAMIC_MED_H
#include <crtdbg.h>
typedef struct {
    int id;
    char* name;
    int concentration;
    int stock;
}Med;

/*
 * Creeaza o entitate de tipul Med
 * param id: idul entitatii (int)
 * param name: numele entitatii (char)
 * param concentration: concentratia entitatii (int)
 * param stock: stocul (int)
 * return: Med
 */
Med create(int id, char *name, int concentration, int stock);

/*
 * Dealoca memoria ocupata de o entitate Med
 */
void destroy(Med *m);

int containsOnlyLetters(const char *str);

/*
 * Valideaza entitatea Med
 * return: 1 - id invalid
 *         2 - nume invalid
 *         3 - concentratie invalida
 *         4 - stock ivalid
 *         0 - entitate valida
 */
        int validate(Med m);
#endif //LAB2_4_DINAMIC_MED_H
