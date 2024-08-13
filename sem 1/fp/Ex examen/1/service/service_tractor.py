from repo.repo_tractor import Repo
from domain.tractor import Tractor
from datetime import date


class Service:
    def __init__(self, repo: Repo):
        self.__repo = repo
        self.__undo_list = []

    def add(self, id: int, nume: str, pret: int, model: str, data: str):
        """
        Adds a new tractor entity
        :param id: id for tractor
        :param nume: name for tractor
        :param pret: price for tractor
        :param model: model for tractor
        :param data: date of expiry for tractor
        :return:
        """

        self.prepare_undo()
        data = [int(info.strip()) for info in data.strip().split(':')]
        data = date(data[2], data[1], data[0])
        tractor = Tractor(id, nume, pret, model, data)
        self.__repo.add_tractor(tractor)

    def delete(self, digit: int):
        """
        Delets a tractor entity if the price has the digit in it
        :param digit:
        :return: the number of tractor entities that got deleted
        """
        if digit >= 10 or digit <= -1:
            raise ValueError("Valoare introdusa trebuei sa fie o cifra")

        cnt = 0
        self.prepare_undo()
        tractoare = self.__repo.get_all()
        for id in range (len(tractoare)-1, -1, -1):
            price = str(tractoare[id].get_pret())
            if str(digit) in price:
                self.__repo.delete_tractor(tractoare[id])
                cnt += 1
        self.__repo.write_to_file()
        return cnt

    def filter(self, text: str, number: int):
        """
        Filter the tractor list: if the name contains a certen text and if the price is less then a given number
        :return:
        """
        if number < -1:
            raise ValueError("Numar invalid")
        filter_list = []
        if text != '':
            filter_list = [tractor for tractor in self.__repo.get_all() if text in tractor.get_nume()]
        if number != -1:
            filter_list = [tractor for tractor in self.__repo.get_all() if number > tractor.get_pret()]

        return filter_list

    def get_all(self):
        return self.__repo.get_all()

    def prepare_undo(self):
        new_lst = [element for element in self.__repo.get_all()]
        self.__repo.append_undo(new_lst)

    def undo(self):
        previous_state = self.__repo.get_previous_state()
        tractor_list = [tractor for tractor in previous_state]
        self.__repo.set_all(tractor_list)











