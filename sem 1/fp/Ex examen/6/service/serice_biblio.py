from repo.repo_biblio import Repo
from domain.validator import Valid
from domain.carte import Carte
import random

class Service:
    def __init__(self, repo: Repo, valid: Valid):
        self.__repo = repo
        self.__valid = valid
        self.__undo = []

    def add(self, id, titlu, autor, an):
        carte = Carte(id, titlu, autor, an)
        self.__valid.validate(carte)
        self.__repo.add(carte)

    def delete(self, cifra):
        self.prepare_undo()
        for carte in self.__repo.get_all():
            if str(cifra) in str(carte.get_an()):
                self.__repo.delet(carte)

    def filter(self, text, numar):
        lst = []
        if text != '' and numar != -1:
            for carte in self.__repo.get_all():
                if text in carte.get_titlu() and carte.get_an() < numar:
                    lst.append(carte)

        elif text !='' and numar == -1:
            for carte in self.__repo.get_all():
                if text in carte.get_titlu():
                    lst.append(carte)

        else:
            for carte in self.__repo.get_all():
                if carte.get_an() < numar:
                    lst.append(carte)

        return lst

    def prepare_undo(self):
        new_lst = [element for element in self.__repo.get_all()]
        self.__repo.append_undo(new_lst)

    def undo(self):
        previous_state = self.__repo.get_previous_state()
        _list = [tractor for tractor in previous_state]
        self.__repo.set_all(_list)

    def export(self, file_name):
        self.__repo.export(file_name)

    def random(self, number):

        lst = []
        for i in range(number):
            vocale = "aeiou"
            consoane = "bcdfghjklmnpqrstvwxyz"
            lungime_titlu = random.randint(9, 12)
            titlu = list(' ' * lungime_titlu)
            spatiu_titlu = random.randint(1, lungime_titlu - 1)

            for j in range(lungime_titlu):
                if j != spatiu_titlu:
                    if j % 2 == 0:
                        titlu[j] = random.choice(vocale)
                    else:
                        titlu[j] = random.choice(consoane)
            titlu = ''.join(titlu)

            lungime_autor = random.randint(9, 12)
            autor = list(' '*lungime_autor)
            spatiu_autor = random.randint(1, lungime_autor -1)

            for j in range(lungime_autor):
                if j != spatiu_autor:
                    if j % 2 == 0:
                        autor[j] = random.choice(vocale)
                    else:
                        autor[j] = random.choice(consoane)

            autor = ''.join(autor)

            id = random.randint(1, 100)
            an = random.randint(1980, 2024)

            carte = Carte(id, titlu, autor, an)
            self.__repo.add(carte)
            lst.append(carte)

        return lst

    def get_all(self):
        return self.__repo.get_all()
