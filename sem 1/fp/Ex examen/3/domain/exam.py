class Exam:
    def __init__(self, data: str, ora: str, materie: str, tip: str):
        self.__data = data
        self.__ora = ora
        self.___materie = materie
        self.__tip = tip

    def get_data(self):
        return self.__data

    def get_ora(self):
        return self.__ora

    def get_materie(self):
        return self.___materie

    def get_tip(self):
        return self.__tip

    def __str__(self):
        return self.__data + ' | ' + self.__ora + ' | ' + self.___materie + ' | ' + self.__tip

    def day(self):
        return self.__data.split('.')[0]

    def month(self):
        return self.__data.split('.')[1]

    def hour(self):
        return int(self.__ora.split(':')[0])
