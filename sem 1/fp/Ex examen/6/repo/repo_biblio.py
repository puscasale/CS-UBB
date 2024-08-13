from domain.carte import Carte

class Repo:
    def __init__(self, file_name):
        self.__file_name = file_name
        self.__carti = []
        self.__undo = []
        self.load_from_file()

    def load_from_file(self):
        with open(self.__file_name, 'r') as file:
            lines = file.readlines()
            lines = [line.strip() for line in lines if line != '']
            for line in lines:
                info = [inf.strip() for inf in line.split(', ')]
                id = int(info[0])
                titlu = info[1]
                autor = info[2]
                an = int(info[3])
                carte = Carte(id, titlu, autor, an)
                self.__carti.append(carte)

    def write_to_file(self):
        list_to_write = []
        for carte in self.__carti:
          id = str(carte.get_id())
          titlu = carte.get_titlu()
          autor = carte.get_autor()
          an = str(carte.get_an())
          info = [id, titlu, autor, an]
          info = ', '.join(info)
          list_to_write.append(info)

        list_to_write = '\n'.join(list_to_write)

        with open(self.__file_name, 'w') as file:
            file.write(list_to_write)

    def export(self, file_name):
        lst = self.__carti
        lst = sorted(lst, key=lambda x: (x.get_an()))
        list_to_write = []
        for carte in lst:
            id = str(carte.get_id())
            titlu = carte.get_titlu()
            autor = carte.get_autor()
            an = str(carte.get_an())
            info = [id, titlu, autor, an]
            info = ', '.join(info)
            list_to_write.append(info)

        list_to_write = '\n'.join(list_to_write)

        with open(file_name, 'w') as file:
            file.write(list_to_write)

    def add(self, carte: Carte):
        self.__carti.append(carte)
        self.write_to_file()

    def delet(self, carte: Carte):
        self.__carti.remove(carte)
        self.write_to_file()

    def get_all(self):
        return self.__carti

    def set_all(self, lst):
        self.__carti = lst
        self.write_to_file()

    def append_undo(self, lst: list):
        self.__undo.append(lst)

    def get_previous_state(self):
        if len(self.__undo) == 0:
            raise ValueError("Nu se poaet efectua undo.")
        return self.__undo.pop()
