#include <stdio.h>
#include <stdbool.h>

/*
     desc: verifica daca un numar este sau nu prim
     param: num (int): numarul care este verificat
     precond: numarul trebuie sa fie unul intreg
     postcond: functia returneaza 1 daca numarul este prim, 0 in caz contrar
     */
int prim(int num){

    if (num <= 1){
        return 0;
    }
    for (int i = 2; i*i <= num; i++){
        if (num % i == 0){
            return 0;
        }
    }
    return 1;
}
int cmmd(int a, int b) {
    while (b != 0) {
        int r = b;
        b = a % b;
        a = r;
    }
    return a;
}

/*
     desc: afiseaza primele n numere prime
     param: n (int): numarul de numere
     precond: n trebuei sa fie intreg pozitiv
     postcond: primele n numere prime sunt afisate pe ecran
     */

void afisprimele(int n){
    int contor = 0;
    int nr_curr = 2;
    printf("Primele %d numele prime sunt:",n);
    while(contor < n){
        if(prim(nr_curr)){
            printf("%d ", nr_curr);
            contor ++;
        }
        nr_curr++;
    }
    printf("\n");

}

void afis_zece(){
    int cnt = 0;
    int nr = 3;
    while(cnt<8
    ){
        int is_special = 1;
        for(int i = 2; i < nr; i++)
            if(cmmd(i,nr)==1){
                if(!prim(i)){
                    is_special = 0;
                }
            }
        if(is_special==1){
            printf("%d ", nr);
            cnt++;
        }
        nr++;
    }
}

void print_menu(){
    /*
     desc: afisarea meniului
     */
    printf("\n1. Generare primele n nr prime\n");
    printf("2. Nr relative mai mici ca si n\n");
    printf("3. Iesire\n");
}

int main() {
    int cmd;
    int n;
    while (true){
        print_menu();
        printf("Alege optiunea:");
        scanf("%d", &cmd);
        switch(cmd){
            case 1:
                printf("Introdu n:");
                scanf("%d", &n);
                afisprimele(n);
                break;
            case 2:
                afis_zece();
                break;
            case 3:
                return 0;
            default:
                printf("Comanda invalida");

        }

    }

}
