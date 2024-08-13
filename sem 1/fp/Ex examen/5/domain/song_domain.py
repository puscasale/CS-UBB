class Song:
    def __init__(self, titlu: str, artist:str, gen:str, durata: int):
        self.__titlu = titlu
        self.__artist = artist
        self.__gen = gen
        self.__durata = durata

    def get_titlu(self):
        return self.__titlu

    def get_artist(self):
        return self.__artist

    def get_gen(self):
        return self.__gen

    def get_durata(self):
        return self.__durata

    def set_durata(self, durata):
        self.__durata = durata

    def set_gen(self, gen):
        self.__gen = gen

    def __str__(self):
        return self.__titlu + ' | ' + self.__artist + ' | ' + self.__gen + ' | ' + str(self.__durata)

class Song_Dto:
    def __init__(self, artist:str, titlu:str, an:int, gen:str):
        self.__titlu = titlu
        self.__artist = artist
        self.__gen = gen
        self.__an = an

    def get_titlud(self):
        return self.__titlu

    def get_artistd(self):
        return self.__artist

    def get_gend(self):
        return self.__gen

    def get_and(self):
        return self.__an

    def __str__(self):
        return self.__artist + ' | ' + self.__titlu + ' | ' + str(self.__an) + ' | ' + self.__gen