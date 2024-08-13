class Show:
    def __init__(self, nume: str, artist: str, gen: str, durata: int):
        self.__nume = nume
        self.__artist = artist
        self.__gen = gen
        self.__durata = durata

    def get_nume(self):
        return self.__nume

    def get_artist(self):
        return self.__artist

    def get_gen(self):
        return self.__gen

    def get_durata(self):
        return self.__durata

    def set_gen(self, gen):
        self.__gen = gen

    def set_durata(self, durata):
        self.__durata = durata

    def __eq__(self, other):
        return self.__nume == other.get_nume() and self.__artist == other.get_artist()

    def __str__(self):
        return self.__nume + ' | ' + self.__artist + ' | ' + self.__gen + ' | ' + str(self.__durata)