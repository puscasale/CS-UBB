from service.service_event import Service
from domain.event import Event

class Test:
    def __init__(self, service: Service):
        self.__service = service

    def test_add(self):
        lung = len(self.__service.get_all())
        data = '11.12.2022'
        ora = '12:12'
        desc = 'nuj1'
        self.__service.add(data, ora, desc)
        data2 = '22.2.2024'
        ora2 = '1:12'
        desc2 = 'nuj2'
        self.__service.add(data2, ora2, desc2)
        data2 = '11.1.2022'
        ora2 = '12:1'
        desc2 = 'nuj3'
        self.__service.add(data2, ora2, desc2)
        assert len(self.__service.get_all()) == lung + 3

    def test_filter(self):
        data = '12.1.2022'
        lst = self.__service.filter(data)
        assert len(lst) == 1
        assert lst[0].get_data() == '12.1.2022'

    def test_today(self):
        lst = self.__service.today()
        assert len(lst) == 1
        assert lst[0].get_data() == '21.02.2024'

    def run(self):
        self.test_add()
        self.test_today()
        self.test_filter()
