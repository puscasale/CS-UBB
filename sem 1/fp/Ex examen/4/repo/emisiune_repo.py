from domain.emisiune import Emisiune

class Repo:
    def __init__(self, file_name):
        self.__file_name = file_name
        self.__emisiuni = []
        self.load_from_file()

    def load_from_file(self):
        with open(self.__file_name, 'r') as file:
            lines = file.readlines()
            lines = [line.strip() for line in lines if line != '']
            for line in lines:
                info = [inf.strip() for inf in line.split(', ')]
                nume = info[0]
                tip = info[1]
                durata = int(info[2])
                descriere = info[3]
                emisiune = Emisiune(nume, tip, durata, descriere)
                self.__emisiuni.append(emisiune)

    def write_to_file(self):
        list_to_write = []
        for emisiune in self.__emisiuni:
            nume = emisiune.get_nume()
            tip = emisiune.get_tip()
            durata = str(emisiune.get_durata())
            descriere = emisiune.get_descriere()
            info = [nume, tip, durata, descriere]
            info = ', '.join(info)
            list_to_write.append(info)

        list_to_write = '\n'.join(list_to_write)

        with open(self.__file_name, 'w') as file:
            file.write(list_to_write)

    def get_all(self):
        return self.__emisiuni

    def delete_em(self, emisune: Emisiune):
        self.__emisiuni.remove(emisune)

