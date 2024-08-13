from service.echipa_service import Service


class Test:
    def __init__(self, service: Service):
        self.__service = service

    def test_add(self):
        """
        Testare fct de add
        :return:
        """
        lung = len(self.__service.get_all())
        nume = 'Cristi'
        prenume = 'Piscas'
        inaltime = 176
        post = 'pivot'
        self.__service.add(nume, prenume, inaltime, post)
        assert self.__service.get_all()[1].get_nume() == 'Cristi'
        assert self.__service.get_all()[1].get_prenume() == 'Piscas'
        assert self.__service.get_all()[1].get_inaltime() == 176
        assert self.__service.get_all()[1].get_post() == 'pivot'
        assert len(self.__service.get_all()) == lung + 1

    def test_modify(self):
        """
        Testare fct modify
        :return:
        """
        nume = 'Ale'
        prenume = 'Sefa'
        inaltime_nou = 190
        self.__service.modify(nume, prenume, inaltime_nou)
        assert self.__service.get_all()[0].get_inaltime() == inaltime_nou

    def run(self):
        self.test_modify()
        self.test_add()