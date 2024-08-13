//
// Created by Ale on 03/12/2024.
//

#ifndef LAB2_4_FUNCTIONS_H
#define LAB2_4_FUNCTIONS_H
#include <stdbool.h>
typedef struct {
    int cod;
    char nume[30];
    int concentratie;
    int cantitate;
}Medicament;

typedef struct{
    Medicament nr[100];
    int lungime;
}Medicament_list;

Medicament_list create_list();

int get_size(Medicament_list *medicamente);

Medicament get_medicament(Medicament_list *medicamente, int cod);

void set_cod(Medicament *medicament, int cod);

void set_nume(Medicament *medicament, char nume[]);

void set_concentratie(Medicament *medicament, int concentratie);

void set_cantitate(Medicament *medicament, int cantitate);

int get_cod(Medicament *medicament);

char* get_nume(Medicament *medicament);

int get_concentratie(Medicament *medicament);

int get_cantitate(Medicament *medicament);

void print_medicament(Medicament medicament);

void print_errs(char err[5][100], int len);

Medicament create_medicament(int cod, char nume[], int concentartie, int cantitate);

bool equal_cod(int cod1, int cod2);

bool valid(Medicament_list *medicamente, Medicament new_medicamnet, char err[5][100], int *len);

bool valid_new_name(char* nume, char err[5][100], int *len);

bool valid_new_concentratie(int concentratie, char err[5][100], int *len);

void add(Medicament_list *medicamente, Medicament new_medicamnet);

void delete(Medicament_list *medicamente, int cod);

void update(Medicament_list *medicamente, Medicament up_medicament, int cod);

void add_medicament(Medicament_list *medicamente, int cod, char nume[], int concentratie, int cantitate, char err[5][100], int *len);

void modificare_medicament(Medicament_list *medicamente, int cod, char new_name[], int new_concentratie, char err[5][100], int *len);

void delete_medicament(Medicament_list *medicamente, int cod, char err[5][100], int *len);

#endif //LAB2_4_FUNCTIONS_H
