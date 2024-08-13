#pragma once
#include <string>
using namespace std;
#define NULL_TVALOARE -1;
typedef int TElem;

class AB;

class IteratorAB;

class Nod{
public:
    TElem elem;
    Nod* st;
    Nod* dr;
    Nod(){
        elem = 0;
        st = NULL;
        dr = NULL;
    }
    Nod(TElem e, Nod* st1, Nod* dr1){
        elem = e;
        st = st1;
        dr = dr1;
    }
};

typedef Nod* PNod;
class AB {

private:
	/* aici e reprezentarea */
    Nod* rad;
    void distruge(PNod p);
    PNod copiere(PNod p) const;
    void disSub(PNod p);

public:
	friend class IteratorAB;
	friend class IteratorPreordine;
	friend class IteratorInordine;
	friend class IteratorPostordine;
	friend class IteratorLatime;

		//constructorul implicit
		AB();

		//contructor de copiere
		AB(const AB& ab);

		//creeaza un arbore binar care se reduce la o frunza
		AB(TElem elem);

		//constructor arbore binar
		AB(const AB& st, TElem elem, const AB& dr);

		//adauga unui arbore binar subarborele stang
		//arunca exceptie daca arborele este vid
		void adaugaSubSt(const AB& st);

		//adauga unui arbore binar subarborele drept
		//arunca exceptie daca arborele este vid
		void adaugaSubDr(const AB& dr);

		//verifica daca arborele este vid
   		 bool vid() const;

		//accesare element din radacina
		//arunca exceptie daca arborele este vid
		TElem element() const;

		//accesare subarbore stang
		//arunca exceptie daca arborele este vid
		AB stang() const;

		//accesare subarbore drept
		//arunca exceptie daca arborele este vid
		AB drept() const;

        //gaseste si returneaza valoarea minima din arbore
        //Daca arborele este vid, se returneaza NULL_TVALOARE
        int valoareMinima() const;

		//iteratori pe arborele binar (ordine="preordine", "postordine", "inordine", "latime")
		IteratorAB* iterator(string ordine) const;

		// destructorul arborelui binar
		~AB();
};



