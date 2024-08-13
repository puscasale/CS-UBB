from domain.echipa_domain import Echipa
import random

class Repo:
    def __init__(self, file_name):
        self.__file_name = file_name
        self.__echipe = []
        self.__undo = []
        self.load_from_file()

    def load_from_file(self):
        """
        Incarca elementele din fisier
        """
        with open(self.__file_name, 'r') as file:
            lines = file.readlines()
            lines = [line.strip() for line in lines if line != ' ']
            for line in lines:
                info = [inf.strip() for inf in line.split(', ')]
                nume = info[0]
                prenume = info[1]
                inaltime = int(info[2])
                post = info[3]
                echipa = Echipa(nume, prenume, inaltime, post)
                self.__echipe.append(echipa)

    def importt(self, file_name):
        """
        Incarca elementele din fisier
        """
        nume_lst = []
        prenume_lst = []
        with open(file_name, 'r') as file:
            lines = file.readlines()
            lines = [line.strip() for line in lines if line != ' ']
            for line in lines:
                info = [inf.strip() for inf in line.split(', ')]
                nume = info[0]
                nume_lst.append(nume)
                prenume = info[1]
                prenume_lst.append(prenume)

        return nume_lst, prenume_lst


    def write_to_file(self):
        """
        Scrie datele in fisier
        """
        lst = []
        for echipa in self.__echipe:
            nume = echipa.get_nume()
            prenume = echipa.get_prenume()
            inaltime = str(echipa.get_inaltime())
            post = echipa.get_post()
            info = [nume, prenume, inaltime, post]
            info = ', '.join(info)
            lst.append(info)

        lst = '\n'.join(lst)
        with open(self.__file_name, 'w') as file:
            file.write(lst)

    def eporrt(self, file_name, lstt):
        """
        Exporta intr un fizier o lista
        :param file_name:
        :param lstt:
        :return:
        """
        lst = []
        for echipa in lstt:
            nume = echipa.get_nume()
            prenume = echipa.get_prenume()
            inaltime = str(echipa.get_inaltime())
            post = echipa.get_post()
            info = [nume, prenume, inaltime, post]
            info = ', '.join(info)
            lst.append(info)

        lst = '\n'.join(lst)
        with open(file_name, 'w') as file:
            file.write(lst)

    def add(self, echipa: Echipa):
        """
        Adauga un jucator in lista
        """
        self.__echipe.append(echipa)
        self.write_to_file()

    def set_all(self, lst):
        self.__echipe = lst
        self.write_to_file()

    def append_undo(self, lst):
        self.__undo.append(lst)

    def get_previous_state(self):
        if len(self.__undo) == 0:
            raise ValueError("Nu se poate efectua undo")
        return self.__undo.pop()

    def get_all(self):
        """
        Returneaza toate entitatile jucator
        """
        return self.__echipe

    def delete(self, echipa: Echipa):
        """
        Sterge o entitate fin lista
        :param echipa:
        :return:
        """
        self.__echipe.remove(echipa)