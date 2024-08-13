class Carte:
    def __init__(self, id: int, titlu: str, autor: str, an: int):
        self.__id = id
        self.__titlu = titlu
        self.__autor = autor
        self.__an = an

    def get_id(self):
        return self.__id

    def get_titlu(self):
        return self.__titlu

    def get_autor(self):
        return self.__autor

    def get_an(self):
        return self.__an

    def __str__(self):
        return str(self.__id) + ' | ' + self.__titlu + ' | ' + self.__autor + ' | ' + str(self.__an)
