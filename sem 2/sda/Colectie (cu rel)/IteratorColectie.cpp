#include "IteratorColectie.h"
#include "Colectie.h"
#include <iostream>

/*
 * Best case, Worst case, Average case : theta(1)
 */
IteratorColectie::IteratorColectie(const Colectie& c): col(c) {
    prim();
}

/*
 * Best case, Worst case, Average case : theta(1)
 */
TElem IteratorColectie::element() const {
    if (!valid())
        throw std::exception();
    return curr->element();
}

/*
 * Best case, Worst case, Average case : theta(1)
 */
bool IteratorColectie::valid() const {
	return curr != nullptr;
}

/*
 * Best case, Worst case, Average case : theta(1)
 */
void IteratorColectie::urmator() {
	if(!valid())
        throw std::exception();

    if( index < curr->frecventa())
            index ++;

    else {
        curr = curr->urmator();
        index = 0;
    }



}

/*
 * Best case, Worst case, Average case : theta(1)
 */
void IteratorColectie::prim() {
	curr = col.prim;
}
