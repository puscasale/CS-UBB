from datetime import date
class Tractor:
    def __init__(self, id: int, nume: str, pret: int, model: str, data: date):
        self.__id = id
        self.__nume = nume
        self.__pret = pret
        self.__model = model
        self.__data = data

    def get_id(self):
        """
        Getter pt id
        :return: id
        """
        return self.__id

    def get_nume(self):
        """
        Getter pt nume
        :return: nume
        """
        return self.__nume

    def get_pret(self):
        """
        Getter pt pret
        :return: pret
        """
        return self.__pret

    def get_model(self):
        """
        Getter pt model
        :return: model
        """
        return self.__model

    def get_data(self):
        """
        Getter pt data
        :return: data
        """
        return self.__data

    def __str__(self):
        return str(self.__id) + ' | ' + self.__nume + ' | ' + str(self.__pret) + ' | ' + self.__model + ' | ' + str(self.__data)