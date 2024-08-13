class Emisiune:
    def __init__(self, nume: str, tip: str, durata: int, descriere: str):
        self.__nume = nume
        self.__tip = tip
        self.__durata = durata
        self.__descriere = descriere

    def get_nume(self):
        return self.__nume

    def get_tip(self):
        return self.__tip

    def get_durata(self):
        return self.__durata

    def get_descriere(self):
        return self.__descriere

    def set_durata(self, durata):
        self.__durata = durata

    def set_descriere(self, descriere):
        self.__descriere = descriere

    def __str__(self):
        return self.__nume + ' | ' + self.__tip + ' | ' + str(self.__durata) + ' | ' + self.__descriere