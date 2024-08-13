class Echipa:
    def __init__(self, nume: str, prenume: str, inaltime: int, post: str):
        self.__nume = nume
        self.__prenume = prenume
        self.__inaltime = inaltime
        self.__post = post

    def get_nume(self):
        """
        Getter pt nume
        """
        return self.__nume

    def get_prenume(self):
        """
        Getter pt prenume
        """
        return self.__prenume

    def get_inaltime(self):
        """
        Getter pt inalime
        """
        return self.__inaltime

    def get_post(self):
        """
        Getter pt post
        """
        return self.__post

    def set_inaltime(self, inaltime):
        """
        setter pt inaltime
        """
        self.__inaltime = inaltime

    def __str__(self):
        return self.__nume + ' | ' + self.__prenume + ' | ' + str(self.__inaltime) + ' | ' + self.__post