from service.emisiune_service import Service

class Test:
    def __init__(self, service: Service):
        self.__service = service

    def test_delete(self):
        nume = "nume1"
        tip = "tip1"
        self.__service.delete(nume, tip)
        assert self.__service.get_all()[0].get_nume() == "nume2"
        assert self.__service.get_all()[0].get_tip() == "tip2"

    def test_modify(self):
        nume = "nume3"
        tip = "tip3"
        durata = 2
        desc = "descriere_noua"
        self.__service.modify(nume, tip, durata, desc)
        assert self.__service.get_all()[1].get_durata() == 2
        assert self.__service.get_all()[1].get_descriere() == "descriere_noua"

    def test_blocare(self):
        tip = "tip4"
        list = self.__service.blocare(tip)
        assert len(list) == 1

    def run_test(self):
        self.test_delete()
        self.test_modify()
        self.test_blocare()