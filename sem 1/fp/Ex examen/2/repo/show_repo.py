from domain.show_domain import Show

class Repo:
    def __init__(self, file_name):
        self.__file_name = file_name
        self.__shows = []
        self.load_from_file()

    def load_from_file(self):

        with open(self.__file_name, 'r') as file:
            lines = file.readlines()
            line = [line.strip() for line in lines if lines != '']
            for line in lines:
                info = [inf.strip() for inf in line.split(', ')]
                nume = info[0]
                artist = info[1]
                gen = info[2]
                durata = int(info[3])
                show = Show(nume, artist, gen, durata)
                self.__shows.append(show)

    def write_to_file(self):

        list_to_write = []
        for show in self.__shows:
            nume = show.get_nume()
            artist = show.get_artist()
            gen = show.get_gen()
            durata = str(show.get_durata())
            info = [nume, artist, gen, durata]
            info = ', '.join(info)
            list_to_write.append(info)
        with open(self.__file_name, 'w') as file:
            file.write("\n".join(list_to_write))

    def exp(self, file_name):
        lst = self.__shows
        lst = sorted(lst, key=lambda x: (x.get_artist(), x.get_nume()))
        list_to_write = []
        for show in lst:
            nume = show.get_nume()
            artist = show.get_artist()
            gen = show.get_gen()
            durata = str(show.get_durata())
            info = [nume, artist, gen, durata]
            info = ', '.join(info)
            list_to_write.append(info)
        with open(file_name, 'w') as file:
            file.write("\n".join(list_to_write))

    def add_show(self, show: Show):
        self.__shows.append(show)
        self.write_to_file()

    def get_all(self):
        return self.__shows


