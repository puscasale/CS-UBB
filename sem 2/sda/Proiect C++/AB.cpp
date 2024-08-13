#include "AB.h"
#include "IteratorAB.h"
#include <exception>
#include <string>

//Theta (1)
AB::AB() {
    rad = NULL;
}

//CF: Theta(1) CD: Theta(n) OC: O(n)
AB::AB(const AB& ab) {
    rad = copiere(ab.rad);
}

//Theta (1)
AB::AB(TElem e){
	rad = new Nod(e,NULL,NULL);
}

//CF: Theta(1) CD: Theta(n) OC: O(n)
AB::AB(const AB& st, TElem e, const AB& dr){
    	rad = new Nod(e,copiere(st.rad),copiere(dr.rad));
}

//CF: Theta(1) CD: Theta(n) OC: O(n)
void AB::distruge(PNod p){
    if(p != NULL){
        distruge(p->st);
        distruge(p->dr);
        delete p;
    }
}

//CF: Theta(1) CD: Theta(n) OC: O(n)
void AB::disSub(PNod p){
    if(p != NULL){
        distruge(p->st);
        distruge(p->dr);
    }
}

//CF: Theta(1) CD: Theta(n) OC: O(n)
PNod AB::copiere(PNod p) const {
    if(p != NULL){
        PNod pnew = new Nod(p->elem,NULL,NULL);
        pnew->st = copiere(p->st);
        pnew->dr = copiere(p->dr);
        return pnew;
    }
    return NULL;
}

//CF: Theta(1) CD: Theta(n) OC: O(n)
void AB::adaugaSubSt(const AB& st){
 	if(vid())
        throw std::exception();
    disSub(rad->st);
    rad->st = copiere(st.rad);
}

//CF: Theta(1) CD: Theta(n) OC: O(n)
void AB::adaugaSubDr(const AB& dr){
	if(vid())
        throw std::exception();
    disSub(rad->dr);
    rad->dr = copiere(dr.rad);
}

//Theta (1)
TElem AB::element() const{
 	if(vid())
        throw std::exception();
    return rad->elem;
}

//Theta (1)
AB AB::stang() const{
 	if(vid())
        throw std::exception();
    AB ab;
    ab.rad = copiere(rad->st);
    return ab;
}

//Theta (1)
AB AB::drept() const{
    if(vid())
        throw std::exception();
    AB ab;
    ab.rad = copiere(rad->dr);
    return ab;
}

//CF: Theta(1) CD: Theta(n) OC: O(n)
AB::~AB() {
	distruge(rad);
}

//Theta (1)
bool AB::vid() const{
	return rad == NULL;
}

//Theta(n)
int AB::valoareMinima() const {
    if (vid()) {
        return NULL_TVALOARE;
    }

    IteratorPreordine it(*this);
    int minVal = it.element();

    it.urmator();
    while (it.valid()) {
        int current = it.element();
        if (current < minVal) {
            minVal = current;
        }
        it.urmator();
    }

    return minVal;
}

/*
 * subalg valoareMinima
 * daca @vid() atunci
 *      valoareMinima<-NULL_TVALOARE
 * sf_daca
 *
 * creeazaIterator
 * minVal<-it.element()
 *
 * cat timp it este valid executa
 *  current<-it.element()
 *
 *  daca current < minVal atunci
 *      minVal <- current
 *  sf_daca
 *
 *  it.urmator()
 * sf_cat_timp
 *
 * valoareMinima<-minVal
 */

//Theta (1)
IteratorAB* AB::iterator(string s) const {
	if (s=="preordine")
		return new IteratorPreordine(*this);
	if (s=="inordine")
		return new IteratorInordine(*this);
	if (s=="postordine")
		return new IteratorPostordine(*this);
	if (s=="latime")
		return new IteratorLatime(*this);
	return nullptr;
};
