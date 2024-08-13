#include "AB.h"
#include "IteratorAB.h"

//CF: Theta(1) CD: Theta(n) OC: O(n)
IteratorInordine::IteratorInordine(const AB& _ab):ab(_ab) {
	act = _ab.rad;
    prim();
}

//CF: Theta(1) CD: Theta(n) OC: O(n)
void IteratorInordine::prim(){
    while (!s.empty())
        s.pop();
    act = ab.rad;

    while (act != NULL){
        s.push(act);
        act = act->st;
    }

    if(!s.empty())
        act = s.top();
}

//Theta(1)
bool IteratorInordine::valid(){
	return act != NULL;
}

//Theta(1)
TElem IteratorInordine::element() {
	if(!valid())
        throw std::exception();
    return act->elem;
}

//Theta(1)
void IteratorInordine::urmator(){
    if(!valid())
        throw std::exception();
    PNod aux = s.top();
    s.pop();
    if(act->dr != NULL){
        act = act->dr;
        while (act != NULL){
            s.push(act);
            act = act->st;
        }
    }

    if(!s.empty())
        act = s.top();
    else
        act = NULL;
}

//Theta(1)
IteratorPreordine::IteratorPreordine(const AB& _ab):ab(_ab){
	act = NULL;
    prim();
}

//CF: Theta(1) CD: Theta(n) OC: O(n)
void IteratorPreordine::prim(){
    while (!s.empty())
        s.pop();
    act = ab.rad;
    s.push(ab.rad);
}

//Theta(1)
bool IteratorPreordine::valid(){
    return act != NULL;
}

//Theta(1)
TElem IteratorPreordine::element(){
	if(!valid())
        throw std::exception();
    return act->elem;
}

//Theta(1)
void IteratorPreordine::urmator(){
    if(!valid())
        throw std::exception();
    PNod aux = s.top();
    s.pop();

    if(aux->dr != NULL)
        s.push(aux->dr);
    if(aux->st != NULL)
        s.push(aux->st);

    if(!s.empty())
        act = s.top();
    else
        act = NULL;
}

//Theta(1)
IteratorPostordine::IteratorPostordine(const AB& _ab):ab(_ab){
	act.p = _ab.rad;
}

//CF: Theta(1) CD: Theta(n) OC: O(n)
void IteratorPostordine::prim(){
	while(!s.empty())
        s.pop();
    act.k = 0;
    act.p = ab.rad;
    s.push(act);
    while(act.p != NULL){
        el x;
        x.k = 0;
        x.p = act.p;
        s.push(x);
        act.p = act.p->st;
    }
}

//Theta(1)
bool IteratorPostordine::valid(){
    return act.p != NULL && !s.empty();
}

//Theta(1)
TElem IteratorPostordine::element(){
 	if(!valid())
        throw std::exception();
    return act.p->elem;

}

//CF: Theta(1) CD: Theta(n) OC: O(n)
void IteratorPostordine::urmator(){
    if(!valid())
        throw std::exception();
    while(act.p != NULL){
        el x;
        x.k = 0;
        x.p = act.p;
        s.push(x);
        act.p = act.p->st;
    }

    el x = s.top();
    s.pop();
    if(x.k == 0){
        x.k = 1;
        s.push(x);
        act.p = x.p->dr;
    }
}

//Theta(1)
IteratorLatime::IteratorLatime(const AB& _ab):ab(_ab){
	act = NULL;
    prim();
}

//CF: Theta(1) CD: Theta(n) OC: O(n)
void IteratorLatime::prim(){
    while (!q.empty())
        q.pop();
    act = ab.rad;
    q.push(ab.rad);
}

//Theta(1)
bool IteratorLatime::valid(){
    return act != NULL;
}

//Theta(1)
TElem IteratorLatime::element(){
	if(!valid())
        throw std::exception();
    return act->elem;
}

//Theta(1)
void IteratorLatime::urmator(){
    if(!valid())
        throw std::exception();

    PNod aux = q.front();
    q.pop();
    if(aux->st != NULL)
        q.push(aux->st);

    if(aux->dr != NULL)
        q.push(aux->dr);

    if(!q.empty())
        act = q.front();
    else act = NULL;
}
