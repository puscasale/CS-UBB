#include "IteratorMultime.h"
#include "Multime.h"
#include <stdexcept>

/*
 * Best case, Worst case, Average case: theta(1)
 */
IteratorMultime::IteratorMultime(const Multime& m) : multime(m){
	curent = 0;
}

/*
 * Best case, Worst case, Average case: theta(1)
 */
void IteratorMultime::prim() {
	curent = 0;
}

/*
 * Best case, Worst case, Average case: theta(1)
 */
void IteratorMultime::urmator() {
	curent++;
}

/*
 * Best case, Worst case, Average case: theta(1)
 */
TElem IteratorMultime::element() const {
    if (!valid()) {
        throw std::exception();

    }
    return multime.e[curent];
}

/*
 * Best case, Worst case, Average case: theta(1)
 */
bool IteratorMultime::valid() const {
    return curent < multime.dim();
}
