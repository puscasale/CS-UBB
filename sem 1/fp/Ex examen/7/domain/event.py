from datetime import date

class Event:
    def __init__(self, data: str, ora: str, desc: str):
        self.__data = data
        self.__ora = ora
        self.__desc = desc

    def get_data(self):
        return self.__data

    def day(self):
        return self.__data.split('.')[0]

    def month(self):
        return self.__data.split('.')[1]

    def year(self):
        return self.__data.split('.')[2]

    def hour(self):
        return self.__ora.split(':')[0]

    def min(self):
        return self.__ora.split(':')[1]

    def get_ora(self):
        return self.__ora

    def get_desc(self):
        return self.__desc

    def __str__(self):
        return str(self.__data) + ' | ' + self.__ora + ' | ' + self.__desc
