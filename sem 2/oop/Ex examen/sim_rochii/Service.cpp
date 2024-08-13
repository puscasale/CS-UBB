//
// Created by Ale on 05/21/2024.
//

#include <algorithm>
#include "Service.h"
#include "Rochie.h"
bool cmp_marime(const Rochie& r1, const Rochie& r2) {
    return r1.get_marime() < r2.get_marime();
}

bool cmp_pret(const Rochie& r1, const Rochie& r2) {
    return r1.get_pret() < r2.get_pret();
}

void Service::sort_marime(vector<Rochie> &copy) {
    copy = rep.get_all();
    std::sort(copy.begin(), copy.end(), cmp_marime);
}

void Service::sort_pret(vector<Rochie> &copy) {
    copy = rep.get_all();
    std::sort(copy.begin(), copy.end(), cmp_pret);
}

