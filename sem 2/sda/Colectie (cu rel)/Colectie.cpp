#include "Colectie.h"
#include "IteratorColectie.h"
#include <iostream>

using namespace std;
/*
 * Best case, Worst case, Average case : theta(1)
 */
Nod::Nod(TElem e, int frec, PNod urm) {
    this->e = e;
    this->frec = frec;
    this->urm = urm;
}

/*
 * Best case, Worst case, Average case : theta(1)
 */
TElem Nod::element() {
    return e;
}

/*
 * Best case, Worst case, Average case : theta(1)
 */
int Nod::frecventa() {
    return frec;
}

/*
 * Best case, Worst case, Average case : theta(1)
 */
PNod Nod::urmator() {
    return urm;
}


/*
 * Best case, Worst case, Average case : theta(1)
 */
bool rel(TElem e1, TElem e2) {
	if ( e1 < e2) return true;
	return false;
}

/*
 * Best case, Worst case, Average case : theta(1)
 */
Colectie::Colectie() {
	prim = nullptr;
    dimensiune = 0;
}

/*
 * Best case : theta(1) - se insereaza la inceput
 * Worst case : theta(n) - se adauga la finalul listei
 * Average case : O(n) - n este nr elem din lista
 */
void Colectie::adauga(TElem e) {
    PNod nou = new Nod(e, 1, nullptr);

    if (prim == nullptr || rel(e, prim->e)) {
        this->dimensiune++;
        nou->urm = prim;
        prim = nou;
    }

    else {

        PNod q = prim;
        while (q->urm != nullptr && !rel(e, q->urm->e))
            q = q->urm;

        if (q->urm != nullptr && q->urm->e == e) {
            q->urm->frec++;
            this->dimensiune++;
            delete nou;
        }

        else {
            if(e == q->e){
                q->frec++;
                this->dimensiune++;
            }
            else {
                this->dimensiune++;
                nou->urm = q->urm;
                q->urm = nou;

            }
        }
    }
}

/*
 * Best case : theta(1) - elemnetul pe care dorim sa il stergem este primul
 * Worst case : theta(n) - elementul pe care dorin sa il stergem este ultimul
 * Average case : O(n) - n este nr elem din lista
 */
bool Colectie::sterge(TElem e) {
    if (prim == nullptr)
        return false;
    if (e == prim->e) {
        if (prim->frec > 1) {
            prim->frec--;
        }
        else {
            PNod nou = prim;
            prim = prim->urm;
            delete nou;
        }
        this->dimensiune--;
        return true;
    }
    else {
        PNod p = prim;
        while (p->urm != nullptr && p->urm->e != e)
            p = p->urm;
        if(p->urm != nullptr && p->urm->e == e){
            if(p->urm->frec > 1)
                p->urm->frec--;
            else {
                PNod nou = p->urm;
                p->urm = p->urm->urm;
                delete nou;
            }
            this->dimensiune--;
            return true;
        }
    }
    return false;
}

/*
 * Best case : theta(1) - elementu pe care il cautam este la inceput
 * Worst case : theta(n) - elementul pe care il cautam este ultimul
 * Average case : O(n) - n este nr elem din lista
 */
bool Colectie::cauta(TElem elem) const {
    PNod p = prim;
    while (p != nullptr) {
        if (p->e == elem)
            return true;
        p = p->urm;
    }
    return false;
}

/*
 * Best case : theta(1) - elementu a carui frecventa o cautam este la inceput
 * Worst case : theta(n) - elementul a carui frecventa o cautam este ultimul
 * Average case : O(n) - n este nr elem din lista
 */
int Colectie::nrAparitii(TElem elem) const {
    PNod p = prim;
    while (p != nullptr) {
        if (p->e == elem)
            return p->frec;
        p = p->urm;
    }
    return 0;
}

/*
 * Best case : theta(1) - elemnetul pe care dorim sa il stergem este primul
 * Worst case : theta(n) - elementul pe care dorin sa il stergem este ultimul
 * Average case : O(n) - n este nr elem din lista
 */
int Colectie::eliminaToateAparitiile(TElem elem) {
    int tot_elim = 0;
    if(elem == prim->e)
    {
        PNod nou = prim;
        prim = prim->urm;
        tot_elim = nou->frec;
        delete nou;
        dimensiune = dimensiune -tot_elim;
        return tot_elim;

    }
    else {
        PNod p = prim;
        while(p->urm != nullptr && p->urm->e != elem)
            p = p->urm;
        if( p->urm->e == elem){
            PNod nou = p->urm;
            p->urm = p->urm->urm;
            tot_elim = nou->frec;
            delete nou;
            dimensiune = dimensiune - tot_elim;
            return tot_elim;
        }
    }

}

/*
 * Pseudocod eliminaToateAparitiile(TElem elem)
 *
 * tot_elim <- 0
 * daca elem = [prim].e atunci
 *      aloca nou
 *      nou <- prim
 *      prim <- [prim].urm
 *      tot_elim <- [nou].frec
 *      sterge nou
 *      eliminaToateAparitiile <- tot_elim
 * altfel
 *      aloca p
 *      p <- prim
 *      cat timp [p].urm != NIL && [[p].urm].e != elem
 *          p <- [p].urm
 *      sf_cat_timp
 *      daca ( [[p].urm].e == elem)
 *          aloca nou
 *          nou <- [p].urm
 *          [p].urm <- [[p].urm].urm
 *          tot_elim <- [nou].frec
 *          sterge nou
 *          dimesiune <- dimensiune - tot_elim
 *          eliminaToateAparitiile <- tot_elim
 *      sf_daca
 * sf_daca
 */

/*
 * Best case, Worst case, Average case : theta(1)
 */
int Colectie::dim() const {
    return this->dimensiune;
}


/*
 * Best case, Worst case, Average case : theta(1)
 */
bool Colectie::vida() const {
    return prim == nullptr;
}


/*
 * Best case, Worst case, Average case : theta(1)
 */
IteratorColectie Colectie::iterator() const {
	return  IteratorColectie(*this);
}

/*
 * Best case, Worst case, Average case : theta(n) , n - nr elemente
 */
Colectie::~Colectie() {
	while( prim != nullptr){
        PNod p = prim;
        prim = prim->urm;
        delete p;
    }
}



