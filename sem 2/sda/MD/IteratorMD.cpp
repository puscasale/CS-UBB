#include "IteratorMD.h"
#include "MD.h"

using namespace std;

//Best case : theta(1) Worts case theta(m)
IteratorMD::IteratorMD(const MD& _md): md(_md) {
	curr = md.m;
    for( int i = 0; i <md.m; ++i)
        if(md.e[i] != make_pair(NULL_TELEM,NULL_TELEM))
        {
            curr = i;
            break;
        }
}

//theta(1)
TElem IteratorMD::element() const{
    if(!valid())
        throw std::exception();
	return md.e[curr];
}

//theta(1)
bool IteratorMD::valid() const {
    if(curr < md.m)
        return true;
    return false;
}

//Best case : theta(1) Worts case theta(m)
void IteratorMD::urmator() {
    if(!valid())
        throw std::exception();
    curr++;
    while(curr <md.m)
        if(md.e[curr] == make_pair(NULL_TELEM,NULL_TELEM))
            curr++;
        else break;
}

//Best case : theta(1) Worts case theta(m)
void IteratorMD::prim() {
	for( int i = 0; i <md.m; ++i)
        if(md.e[i] != make_pair(NULL_TELEM,NULL_TELEM))
        {
            curr = i;
            break;
        }
}

