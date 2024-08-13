#include "customSort.h"

void sort(List *l, CompareFct cmpF){
    int i, j;
    for (i = 0; i < size(l); i++) {
        for (j = i + 1; j < size(l); j++) {
            TElem el1 = get(l,i);
            TElem el2 = get(l, j);
            if(cmpF(&el1, &el2) > 0){
                set(l,i,el2);
                set(l,j,el1);
            }
        }
    }
}
