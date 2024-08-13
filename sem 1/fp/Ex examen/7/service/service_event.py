from repo.repo_event import Repo
from domain.validator import Valid
from domain.event import Event
from datetime import date
import random

class Service:
    def __init__(self, repo: Repo, valid: Valid):
        self.__repo = repo
        self.__valid = valid
        self.__undo = []

    def add(self, data, ora, desc):
        self.prepare_undo()
        event = Event(data, ora, desc)
        self.__valid.validate(event)
        self.__repo.add(event)

    def delete(self, text):
        self.prepare_undo()
        for event in self.__repo.get_all():
            if text in str(event.get_desc()):
                self.__repo.delete(event)

    def today(self):
        lst = []
        date_today = str(date.today())
        an, luna, zi = date_today.split('-')
        for event in self.__repo.get_all():
            if event.year() == an and event.month() == luna and event.day() == zi:
                lst.append(event)

        lst = sorted(lst, key=lambda x: (x.get_ora()))
        return lst

    def filter(self, data: str):
        lst = []
        zi = data.split('.')[0]
        luna = data.split('.')[1]
        an = data.split('.')[2]
        for event in self.__repo.get_all():
            if event.day() == zi and event.month() == luna and event.year() == an:
                lst.append(event)
        return lst

    def export(self, file_name, text: str):
        lst = []
        for event in self.__repo.get_all():
            if text in event.get_desc():
                lst.append(event)

        self.__repo.exp(file_name, lst)

    def prepare_undo(self):
        lst = [el for el in self.__repo.get_all()]
        self.__repo.appen_undo(lst)

    def undo(self):
        prev_sate = self.__repo.get_prev_sate()
        lst = [el for el in prev_sate]
        self.__repo.set_all(lst)

    def random(self, cnt):
        lst = []
        for i in range(cnt):
            zi = str(random.randint(1, 31))
            zi = zi + '.'
            luna = str(random.randint(1, 12))
            luna = zi + luna + '.'
            an = str(random.randint(2019, 2024))
            data = luna + an


            hour = str(random.randint(1, 24))
            hour = hour+':'
            min = str(random.randint(0, 59))
            ora = hour+min

            vocale = 'aeiou'
            consoane = 'bcdfghjklmnpqrstvwxyz'
            lungime = random.randint(9, 12)
            desc = list(' '*lungime)
            spatiu = random.randint(1, lungime - 1)

            for j in range(lungime):
                if j != spatiu:
                    if j % 2 == 0:
                        desc[j] = random.choice(vocale)
                    else:
                        desc[j] = random.choice(consoane)
            desc = ''.join(desc)
            event = Event(data, ora, desc)
            self.__repo.add(event)
            lst.append(event)
        return lst


    def get_all(self):
        return self.__repo.get_all()

