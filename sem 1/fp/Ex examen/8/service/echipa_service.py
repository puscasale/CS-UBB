from domain.validator import Validate
from domain.echipa_domain import Echipa
from repo.echipa_repo import Repo
import random

class Service:
    def __init__(self, repo: Repo, valid: Validate):
        self.__repo = repo
        self.__valid = valid

    def add(self, nume, prenume, inaltime, post):
        """
        Creaza o entitate noua si o adauga in lista
        :param nume: numele
        :param prenume: prenumele
        :param inaltime: inaltimea in cm
        :param post: postul
        """
        self.prepare_undo()
        echipa = Echipa(nume, prenume, inaltime, post)
        self.__valid.validate(echipa)
        self.__repo.add(echipa)

    def modify(self, nume, prenume, inaltime_nou):
        """
        Modifica inaltimea unui jucator cu numele si prenumele specificat
        :param nume: numele
        :param prenume: prenumele
        :param inaltime_nou: noua inaltime
        """
        for echipa in self.__repo.get_all():
            if nume == echipa.get_nume() and prenume == echipa.get_prenume():
                echipa.set_inaltime(inaltime_nou)
                self.__repo.write_to_file()

    def prepare_undo(self):
        lst = [el for el in self.__repo.get_all()]
        self.__repo.append_undo(lst)

    def undo(self):
        prev_sate = self.__repo.get_previous_state()
        lst = [el for el in prev_sate]
        self.__repo.set_all(lst)

    def export(self, file_name):
        """
        Creaza o noua liste cu entitati jucatori cu inaltimi si posturi random, iar mai apoi sorteaza aceasta lista
        :param file_name:
        :return: lista sortata
        """
        lst = []
        posturi = ['fundas', 'pivot', 'extrema']
        for echipa in self.__repo.get_all():
            nume = echipa.get_nume()
            prenume = echipa.get_prenume()
            inaltime = random.randint(170, 230)
            post = random.choice(posturi)
            new_exhipa = Echipa(nume, prenume, inaltime, post)
            lst.append(new_exhipa)

        lst = sorted(lst, key=lambda x: x.get_inaltime())
        self.__repo.eporrt(file_name, lst)

    def creare_echipa(self):
        """
        Constueste o echipa care sa contina 2 fundasi, 2 extreme si un pivot cu media de inaltime cea mai mare
        :return: noua lista care contine echipa
        """
        new = []
        lst = self.__repo.get_all()
        lst = sorted(lst, key=lambda x: x.get_inaltime(), reverse=True)
        piv = 1
        fund = 2
        ext = 2
        for echipa in lst:
            if piv != 0:
                if echipa.get_post() == 'pivot':
                    new.append(echipa)
                    piv = piv - 1
            else:
                break

        for echipa in lst:
            if fund != 0:
                if echipa.get_post() == 'fundas':
                    new.append(echipa)
                    fund = fund - 1
            else:
                break

        for echipa in lst:
            if ext != 0:
                if echipa.get_post() == 'extrema':
                    new.append(echipa)
                    ext = ext - 1
            else:
                break
        return new

    def get_all(self):
        return self.__repo.get_all()

    def importt(self, file_name):
        nume_lst, prenume_lst = self.__repo.importt(file_name)
        lst = []
        cnt = len(nume_lst)
        posturi = ['fundas', 'pivot', 'extrema']
        for i in range(cnt):
            nume = nume_lst[i]
            prenume = prenume_lst[i]
            inaltime = random.randint(170, 230)
            post = random.choice(posturi)
            echipa = Echipa(nume, prenume, inaltime, post)
            lst.append(echipa)

        return lst

    def delete(self, text):
        entities_to_delete = []
        for echipa in self.__repo.get_all():
            if text in echipa.get_post():
                entities_to_delete.append(echipa)
        for echipa in entities_to_delete:
            self.__repo.delete(echipa)
        self.__repo.write_to_file()

