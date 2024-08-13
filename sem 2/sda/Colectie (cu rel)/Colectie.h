#pragma once;

typedef int TElem;

typedef bool(*Relatie)(TElem, TElem);

//in implementarea operatiilor se va folosi functia (relatia) rel (de ex, pentru <=)
// va fi declarata in .h si implementata in .cpp ca functie externa colectiei
bool rel(TElem e1, TElem e2);

class IteratorColectie;

class Nod;

typedef Nod *PNod;

class Nod{
public:
    friend class Colectie;

    Nod(TElem e, int frec, PNod urm);
    TElem element();
    int frecventa();
    PNod urmator();
private:
    TElem e;
    int frec;
    PNod urm;
};

class Colectie {

	friend class IteratorColectie;

private:
	//adresa primului Nod din lista
    PNod prim;
    int dimensiune;
public:
		//constructorul implicit
		Colectie();

		//adauga un element in colectie
		void adauga(TElem e);

		//sterge o aparitie a unui element din colectie
		//returneaza adevarat daca s-a putut sterge
		bool sterge(TElem e);

		//verifica daca un element se afla in colectie
		bool cauta(TElem elem) const;

		//returneaza numar de aparitii ale unui element in colectie
		int nrAparitii(TElem elem) const;


		//intoarce numarul de elemente din colectie;
		int dim() const;

		//verifica daca colectia e vida;
		bool vida() const;

        //elimina toate aparitiile elemntului elem din coletie, returneaza numarul de elemente eliminate
        int eliminaToateAparitiile(TElem elem);

        //returneaza un iterator pe colectie
		IteratorColectie iterator() const;

		// destructorul colectiei
		~Colectie();


};

