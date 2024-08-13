from domain.tractor import Tractor
from datetime import date

class Repo:
    def __init__(self, file_name):
        self.__file_name = file_name
        self.__tractoare = []
        self.__undo_list = []
        self.load_from_file()

    def get_all(self):
        """
        Get all tractor entities
        """
        return self.__tractoare

    def add_tractor(self, tractor: Tractor):
        """
        Adds a tractor to the list
        :param tractor: tractor entitie
        :return:
        """
        self.__tractoare.append(tractor)
        self.write_to_file()

    def delete_tractor(self, tractor: Tractor):
        """
        Deletes a tractor from the list
        :param tractor:
        :return:
        """
        self.__tractoare.remove(tractor)

    def load_from_file(self):
        """
        Loads the data from the file
        :return:
        """
        with open(self.__file_name, 'r') as file:
            lines = file.readlines()
            lines = [line.strip() for line in lines if line != '']
            for line in lines:
                info = [inf.strip() for inf in line.split(', ')]
                id = int(info[0])
                nume = info[1]
                pret = int(info[2])
                model = info[3]
                zi, luna, an = info[4].split(':')
                data = date(int(an), int(luna), int(zi))
                tractor = Tractor(id, nume, pret, model, data)
                self.__tractoare.append(tractor)


    def write_to_file(self):
        """
        Writes the data to the file
        :return:
        """
        lst = []
        for tractor in self.__tractoare:
            id = str(tractor.get_id())
            nume = tractor.get_nume()
            pret = str(tractor.get_pret())
            model = tractor.get_model()

            data = tractor.get_data()
            zi = str(data.day)
            luna = str(data.month)
            an = str(data.year)

            data = [zi, luna, an]
            data = ':'.join(data)
            info = [id, nume, pret, model, data]
            info = ", ".join(info)

            lst.append(info)

        with open(self.__file_name, 'w') as file:
            file.write("\n".join(lst))

    def set_all(self, lst):
        self.__tractoare = lst
        self.write_to_file()

    def append_undo(self, lst: list):
        self.__undo_list.append(lst)

    def get_previous_state(self):
        if len(self.__undo_list) == 0:
            raise ValueError("Nu se poaet efectua undo.")
        return self.__undo_list.pop()

