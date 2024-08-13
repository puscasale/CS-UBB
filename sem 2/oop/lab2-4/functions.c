#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "functions.h"

/*
 * Creeaza o lista goala de medicamnete
 * return: lista
 */
Medicament_list create_list(){
    Medicament_list medicamente;
    medicamente.lungime = 0;
    return medicamente;
}

int get_size(Medicament_list *medicamente){
    return medicamente->lungime;
}

/*
 * Gaseste un medicamnetu dupa codul dat
 * medicamente: lista de medicamente
 * cod: codul dat
 * return: medicamentul daca exista, medicament neexistent daca nu exista un medicamnet cu acest cod
 */
Medicament get_medicament(Medicament_list *medicamente, int cod) {
    for (int i = 0; i < medicamente->lungime; i++) {
        if (medicamente->nr[i].cod == cod) {
            return medicamente->nr[i];
        }
    }
    Medicament medicamentNeexistent = {-1, "", 0, 0};
    return medicamentNeexistent;
}

/*
 * Settere
 */
void set_cod(Medicament *medicament, int cod){
    medicament->cod = cod;
}

void set_nume(Medicament *medicament, char nume[]){
    strcpy(medicament->nume, nume);
}

void set_concentratie(Medicament *medicament, int concentratie){
    medicament->concentratie = concentratie;
}

void set_cantitate(Medicament *medicament, int cantitate){
    medicament->cantitate = cantitate;
}

/*
 * Gettere
 */
int get_cod(Medicament *medicament){
    return medicament->cod;
}

char* get_nume(Medicament *medicament){
    return medicament->nume;
}

int get_concentratie(Medicament *medicament){
    return medicament->concentratie;
}

int get_cantitate(Medicament *medicament){
    return medicament->cantitate;
}




/*
 * Creaza un medicamet nou
 * cod: codul unic al medicamentului
 * nume: numele medicamentului
 * concentratie: concentratia medicamentului
 * cantitate: cantitatea de medicament
 */
Medicament create_medicament(int cod, char nume[], int concentratie, int cantitate){
    Medicament new_medicamet;
    set_cod(&new_medicamet, cod);
    set_nume(&new_medicamet, nume);
    set_concentratie(&new_medicamet, concentratie);
    set_cantitate(&new_medicamet, cantitate);
    return new_medicamet;
}

/*
 * Verificada daca doua coduri sunt identice
 * cod1: un cod
 * cod2: un cod
 * return: true daca doua coduri sunt identice, fals in caz contrar
 */
/*
bool equal_cod(int cod1, int cod2){
    if(cod1 == cod2)
        return true;
    return false;
}
*/
/*
 * Validare medicament
 * medicamente: lista de medicamente
 * medicament: un medicament
 * err: lisat de erori
 */
bool valid(Medicament_list *medicamente, Medicament new_medicamnet, char err[5][100], int *len){
    (*len) = 0;
    int ok =0;
    int cod = get_cod(&new_medicamnet);
    for( int i = 0; i< medicamente->lungime; i++){
        if(medicamente->nr[i].cod == cod){
            ok = 1;
            break;
        }
    }
    if(ok == 1){
        strcpy(err[*len], "Exista deja un medicamnet cu acest cod\n");
        (*len)++;
    }
    if(cod < 1){
        strcpy(err[*len], "Codul trebuei sa fie un numar mai mare sau egal cu 1\n");
        (*len)++;
    }


    char* nume = get_nume(&new_medicamnet);
    for( int i =0; i < strlen(nume); i++)
        if(isalpha(nume[i]) == 0){
            strcpy(err[*len], "Numele trebuie sa contina doar litere\n");
            (*len)++;
            break;
        }

    if(get_concentratie(&new_medicamnet) <=0 || get_concentratie(&new_medicamnet) >= 100){
        strcpy(err[*len], "Concentratia trebuie sa fie un numar intre 1 si 100\n");
        (*len)++;
    }
    if(get_cantitate(&new_medicamnet)<0){
        strcpy(err[*len], "Cantitatea nu poate sa fie mai mica decat 0\n");
        (*len)++;
    }
    if(*len)
        return false;
    return true;
}
bool valid_new_name(char* nume, char err[5][100], int *len){
    (*len) = 0;
    for( int i =0; i < strlen(nume); i++)
        if(isalpha(nume[i]) == 0){
            strcpy(err[*len], "Numele trebuie sa contina doar litere");
            (*len)++;
            break;
        }
    if(*len)
        return false;
    return true;
}

bool valid_new_concentratie(int concentratie, char err[5][100], int *len){
    (*len) = 0;
    if(concentratie <=0 || concentratie >= 100) {
        strcpy(err[*len], "Concentratia trebuie sa fie un numar intre 1 si 100");
        (*len)++;
    }
    if(*len)
        return false;
    return true;
}

//Repo

/*
 * Adauga un medicamnet in lista
 * medicamnete: lisat de medicamente
 * new_medicamnet: noul medicamnet pe care vrem sa il adaugam
 */
void add(Medicament_list *medicamente, Medicament new_medicamnet){
    medicamente->nr[medicamente->lungime] = new_medicamnet;
    medicamente->lungime++;
}

/*
 * Sterge un medicamnet dupa codul dat
 * medicamente: lista de medicamente
 * cod: codul unic al medicamentului
 */
void delete(Medicament_list *medicamente, int cod){
    for( int i = 0; i< medicamente->lungime; i++){
        if(medicamente->nr[i].cod == cod){
            for( int j = i; j < medicamente->lungime - 1; j++){
                medicamente->nr[i] = medicamente->nr[i+1];
            }
            medicamente->lungime--;
        }
    }
}

/*
void update(Medicament_list *medicamente, Medicament up_medicament, int cod){
    for( int i =0; i < medicamente->lungime; i++){
        if(medicamente->nr[i].cod == cod){
            medicamente->nr[i] = up_medicament;
        }
    }
}
*/


//Service


/*
 * Adauga un medicamnet valid in lista
 * medicamente: lista de medicamente
 * cod: codul medicamnetului
 * nume: numele medicamentului
 * concentratie: concentratia medicamentului
 * cantitate: cantitatea medicamentului
 * err: lista de erori
 * len: lungimea listei de erori
 */
void add_medicament(Medicament_list *medicamente, int cod, char nume[], int concentratie, int cantitate, char err[5][100], int *len){
    Medicament new_medicamnet = create_medicament(cod, nume, concentratie, cantitate);
    if(valid(medicamente, new_medicamnet, err, len))
        add(medicamente, new_medicamnet);
}

/*
void modificare_medicament(Medicament_list *medicamente, int cod, char new_name[], int new_concentratie, char err[5][100], int *len){
    Medicament medicament = get_medicament(medicamente, cod);
    if(medicament.cod == -1){
        strcpy(err[*len], "Nu exista acest medicament");
        (*len)++;
    }
    else{
        if(valid_new_name(new_name, err, len) && valid_new_concentratie(new_concentratie, err, len)){
            set_nume(&medicament, new_name);
            set_concentratie(&medicament, new_concentratie);
        }
    }
}
 */
/*
* Modifica numele si concentaria unui medicamnet dat dupa cod
* medicamente: lista de medicamente
* cod: codul medicamnetului pe care vrem sa il modificam
* new_name: noul nume
* new_concentartie: noua concentratie
*/

void modificare_medicament(Medicament_list *medicamente, int cod, char new_name[], int new_concentratie, char err[5][100], int *len) {
    Medicament *medicament = NULL;
    for (int i = 0; i < medicamente->lungime; i++) {
        if (medicamente->nr[i].cod == cod) {
            medicament = &medicamente->nr[i];
            break;
        }
    }
    if(medicament != NULL)
        if (valid_new_name(new_name, err, len) && valid_new_concentratie(new_concentratie, err, len)) {
            set_nume(medicament, new_name);
            set_concentratie(medicament, new_concentratie);
        }

}


/*
 * Sterge un medicament din lista dupa codul dat
 * medicamenete: lista de medicamente
 * cod: codul dat
 * err: lista de erori
 * len: lungimea listei de erori
 */
void delete_medicament(Medicament_list *medicamente, int cod, char err[5][100], int *len){
    Medicament medicament;
    medicament = get_medicament(medicamente, cod);
    if(get_size(medicamente) == 0){
        strcpy(err[*len], "Nu exista niciun medicament");
        (*len)++;
    }
    else if(medicament.cod == -1){
        strcpy(err[*len], "Nu exista acest medicament");
        (*len)++;
    }
    else
        delete(medicamente, cod);
}


