//
// Created by Ale on 03/20/2024.
//
#include "list.h"
#ifndef LAB2_4_DINAMIC_CUSTOMSORT_H
#define LAB2_4_DINAMIC_CUSTOMSORT_H

typedef int (*CompareFct)(TElem * m1,TElem * m2);
void sort(List *l, CompareFct cmpF);
#endif //LAB2_4_DINAMIC_CUSTOMSORT_H
