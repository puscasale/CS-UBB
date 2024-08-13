#include "Multime.h"
#include "IteratorMultime.h"

#include <iostream>
/*
 *  theta(n)
 */
void Multime::redim(){
    //alocam un spatiu de capacitate dubla
    TElem *eNou = new int[2 * cp];

    //copiem vechile val in noua zona
    for ( int i = 0; i < n; i++)
        eNou[i] = e[i];

    //dublam capacitatea
    cp = 2 * cp;

    //eliberam vechea zona
    delete[]e;

    //vectorul indica spre noua zona
    e = eNou;
}

/*
 * theta(1)
 */
Multime::Multime() {

    //setam capacitatea
    this->cp = cp;

    //alocam spatiu de memomrare pentru vector
    e = new TElem[cp];

    //setam numarul de elemnete
    this->n = 0;
}

/*
 * Best case: theta(1) - acel element mai exista in lista (primul)
 * Worst case: theta(n) - se adauga un elem in care se redim vectorul
 * Average case: O(n)
 */
bool Multime::adauga(TElem elem) {

    //cauta daca elem mai exista, daca da imi returneaza false
    for( int i = 0; i < n; i++){
        if(elem == e[i]){
            return false;
        }
    }

    // daca nu mai exista loc redimensionam vectorul
    if(n == cp)
        redim();

    // adaugam elem la final si returnam true
    this->e[n] = elem;
    n++;
    return true;
}

/*
 * Best case: theta(1) - elem pe care vrem sa il stergem este primul
 * Worst case: theta(n) - elem pe care vrem sa il stergem este ultimul
 * Average case: O(n)
 */
bool Multime::sterge(TElem elem) {
	for( int i = 0; i < n; i++){
        if(e[i] == elem){
            e[i] = e[n-1];
            n--;
            return true;
        }

    }
    return false;
}

/*
 * Best case: theta(1) - elem cautat este primul din multime
 * Worst case: theta(n) - elem cautat este ultimul din multime
 * Aearage case: O(n)
 */
bool Multime::cauta(TElem elem) const {

    //cauta daca un elem este in multime, return true daca este, altfel return false
    for( int i = 0; i < n; i++){
        if(e[i] == elem)
            return true;
    }
	return false;
}

/*
 * Best case: theta(1)
 * Worst case: theta(1)
 * Aearage case: theta(1)
 */
int Multime::dim() const {
  //returneaza dim
    return n;
}

/*
 * Best case: theta(1)
 * Worst case: theta(1)
 * Aearage case: theta(1)
 */
bool Multime::vida() const {
	if(n == 0) return true;
	return false;
}

/*
 * theta(n)
 */
Multime::~Multime() {
    //eliminam zona de memorie alocata vectorului
    delete[]e;
}

/*
 * Best case: theta(m.dim())
 * Worst case: theta(n*m.dim())
 * Aearage case: O(n*m.dim())
 */
bool Multime::submultime(Multime& m) const{
    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < m.dim(); j++) {
            if (e[i] == m.e[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            return false;
        }
    }
    return true;
}

/*
 * Pseudocod submultime(Multime &m)
 *
 *  pentru i <-0,n executa
 *      found <- false
 *      pentru j<-0, m.dim executa
 *          daca e[i] = m.e[j] atunci
 *              found <- true
 *              break
 *           sf daca
 *       sf pentru
 *       daca found != true atunci
 *          submultime <- false
 *       sf daca
 *  sf pentru
 *  submultime <- true
 * sf subprogram
 *
 */


/*
 * theta(1)
 */
IteratorMultime Multime::iterator() const {
	return IteratorMultime(*this);
}

