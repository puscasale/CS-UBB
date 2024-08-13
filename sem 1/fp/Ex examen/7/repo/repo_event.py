from domain.event import Event
from datetime import date


class Repo:
    def __init__(self, file_name):
        self.__filen_name = file_name
        self.__events = []
        self.__undo = []
        self.load_from_file()

    def load_from_file(self):
        with open(self.__filen_name, 'r') as file:
            lines = file.readlines()
            lines = [line.strip() for line in lines if line != '']
            for line in lines:
                info = [inf.strip() for inf in line.split(', ')]
                data = info[0]
                ora = info[1]
                desc = info[2]
                event = Event(data, ora, desc)
                self.__events.append(event)

    def write_to_file(self):
        lst = []
        for event in self.__events:
            data = event.get_data()
            ora = event.get_ora()
            desc = event.get_desc()
            info = [data, ora, desc]
            info = ', '.join(info)
            lst.append(info)

        lst = '\n'.join(lst)
        with open(self.__filen_name, 'w') as file:
            file.write(lst)

    def exp(self, file_name, lis):
        lst = []
        lst = sorted(lst, key=lambda x: (x.get_data(), x.get_ora()))
        for event in lis:
            data = event.get_data()
            ora = event.get_ora()
            desc = event.get_desc()
            info = [data, ora, desc]
            info = ', '.join(info)
            lst.append(info)

        lst = '\n'.join(lst)
        with open(file_name, 'w') as file:
            file.write(lst)

    def get_all(self):
        return self.__events

    def add(self, event: Event):
        self.__events.append(event)
        self.write_to_file()

    def delete(self, event: Event):
        self.__events.remove(event)
        self.write_to_file()

    def set_all(self, lst):
        self.__events = lst
        self.write_to_file()

    def appen_undo(self, lst):
        self.__undo.append(lst)

    def get_prev_sate(self):
        if len(self.__undo) == 0:
            raise ValueError("Undo nu se poate efectua")
        return self.__undo.pop()


