#include "MD.h"
#include "IteratorMD.h"
#include <exception>
#include <iostream>
#include <math.h>

using namespace std;
//tetha(m)
MD::MD() {
    m = 500000;
    e = new pair<int, int>[m];
    urm = new int[m];
    for (int i = 0; i < m; i++) {
        urm[i] = -1;
        e[i] = make_pair(NULL_TELEM, NULL_TELEM);
    }
    primLiber = 0;
}
//theta(1)
// Funcția de dispersie
int MD::d(TCheie c) const {
    return abs(c % m);
}

//Best case: theta(1), Worts case: theta(m), Overall: O(m)
// Metoda privată pentru actualizarea primului element liber
void MD::actPrimLiber() {
    primLiber++;
    while(primLiber < m && e[primLiber].first != NULL_TELEM)
        primLiber++;
}

void MD::redim() {
    auto* elemsRedim = new pair<TCheie , TValoare>[2 * m];
    int* urmRedim = new int[2 * m];

// Inițializează toate elementele noului vector cu valorile potrivite
    for (int i = 0; i < 2 * m; ++i) {
        urmRedim[i] = -1;
        elemsRedim[i] = make_pair(NULL_TELEM, NULL_TELEM);
    }
    delete[] urm; // Șterge vectorul vechi de următori

    urm = urmRedim; // Asociază noul vector de următori

    int mV = m;
    primLiber = 0;
    m *= 2;

// Actualizează valorile în noul vector de elemente și reconfigurează primLiber
    for (int i = 0; i < mV; ++i) {
        int j = d(e[i].first);
        if (elemsRedim[j].first == NULL_TELEM) {
            elemsRedim[j] = e[i];
            if (j == primLiber) {
                primLiber++;
                while (primLiber < m and elemsRedim[primLiber].first != NULL_TELEM)
                    primLiber++;
            }
        } else {
            int k = -1;
            while (j != -1 and elemsRedim[j] != e[i])
                k = j, j = urm[j];
            urm[k] = primLiber;
            elemsRedim[primLiber] = e[i];

            primLiber++;
            while (primLiber < m and elemsRedim[primLiber].first != NULL_TELEM)
                primLiber++;
        }
    }

    delete[] e; // Șterge vectorul vechi de elemente
    e = elemsRedim; // Asociază noul vector de elemente

}

//Best case:theta(1), Worst case: theta(m), Overall: O(m)
// Adăugarea unei perechi (cheie, valoare) în MD
void MD::adauga(TCheie c, TValoare v) {
    //if (primLiber == m)
        //redim();

    int i = d(c); // valoarea de dispersie a elementului

    if (e[i].first == NULL_TELEM) //
    {
        e[i] = make_pair(c,v);
        if (i == primLiber)
            actPrimLiber();
    }
    else
    {
        int j = -1;
        while (i != -1) {
            j = i;
            i = urm[i];
        }
        urm[j] = primLiber;
        e[primLiber] = make_pair(c,v);
        actPrimLiber();
    }
    dimensiune++;
}


//Best case:theta(1), Worst case: theta(m), Overall: O(m)
// Căutarea unei chei și returnarea vectorului de valori asociate
vector<TValoare> MD::cauta(TCheie c) const {
    vector<TValoare> rezultat;
    int i = d(c);
    while (i != -1) {
        if (e[i].first == c) {
            rezultat.push_back(e[i].second);
        }
        i = urm[i]; // Move to the next element in the linked list
    }
    return rezultat;
}

//Best case:theta(1), Worst case: theta(m), Overall: O(m)
// Ștergerea unei chei și a unei valori
// Returnează adevărat dacă s-a găsit cheia și valoarea de șters
bool MD::sterge(TCheie c, TValoare v) {
    int i = d(c);
    int j = -1;

    while(i != -1 and e[i] != make_pair(c,v))
        j = i, i = urm[i];
    if(i == -1)
        return false;
    else {
        bool gata = false;
        do {
            int p = urm[i], pp = i;
            while(p != -1 and d(e[p].first) != i)
            {
                pp = p;
                p = urm[p];
            }
            if(p == -1)
                gata = true;
            else {
                e[i] = e[p];
                i = p;
                j = pp;
            }
        } while(!gata);
        if(j == -1){
            int k = 0;
            while(k < m and urm[k] != i)
                k++;
            if(k < m)
                j = k;
        }
        if(j != -1)
            urm[j] = urm[i];
        e[i] = make_pair(NULL_TELEM,NULL_TELEM);
        urm[i] = -1;

        if(i < primLiber) primLiber = i;

    }
    dimensiune--;
    return true;
}
//theta(m)
vector<TValoare>MD:: coletiaValori() const
{
    IteratorMD it = iterator();
    vector<TValoare> elems;
    while(it.valid())
    {
        elems.push_back(it.element().second);
        it.urmator();
    }
    return elems;
}

/*
 * Subalg colectiaValori() const
 *  it <- ietaror()
 *  elems:vector<TValoare>
 *  cat timp it.valid executa
 *      @adauga in elems it.element().second
 *      it.urmator()
 *  SfCattimp
 *  colectiaValori<-elems
 */


//theta(1)
// Returnează numărul de perechi (cheie, valoare) din MD
int MD::dim() const {
    return dimensiune;
}

//theta(1)
// Verifică dacă MultiDictionarul e vid
bool MD::vid() const {
    return dimensiune == 0;
}

//theta(1)
// Returnează iterator pe MD
IteratorMD MD::iterator() const {
    return IteratorMD(*this);
}

//theta(1)
// Destructorul MultiDictionarului
MD::~MD() {
    delete[] e;
    delete[] urm;
}



