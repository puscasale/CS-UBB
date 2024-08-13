from service.exam_service import Service
from repo.exam_repo import Repo
from domain.exam import Exam


class Tests:
    def __init__(self, service: Service):
        self.__service = service

    def add_test(self):
        data = "15.02"
        ora = "12:00"
        materie = "ASC"
        tip = "normal"
        self.__service.add(data, ora, materie, tip)
        all = self.__service.get_all()
        assert all[0].get_data() == "15.02"
        assert all[0].get_ora() == "12:00"
        assert all[0].get_materie() == "ASC"
        assert all[0].get_tip() == "normal"

    def next_examns_test(self):
        data1 = "06.02"
        ora1 = "12:00"
        materie1 = "Fp"
        tip1 = "normal"
        self.__service.add(data1, ora1, materie1, tip1)
        data = "07.02"
        ora = "12:00"
        materie = "AS"
        tip = "normal"
        self.__service.add(data, ora, materie, tip)
        data2 = "08.02"
        ora2 = "12:00"
        materie2 = "A"
        tip2 = "normal"
        self.__service.add(data2, ora2, materie2, tip2)
        set_date = "05.02"
        next = []
        next = self.__service.next_examns(set_date)
        assert next[0].get_data() == "06.02"
        assert next[1].get_data() == "07.02"
        assert next[2].get_data() == "08.02"

    def tomorrow_exams_test(self):
        data = "15.02"
        ora = "11:00"
        materie = "Lc"
        tip = "normal"
        self.__service.add(data, ora, materie, tip)
        lst = self.__service.tomorrow_exam()
        assert lst[0].get_data() == "15.02"
        assert lst[1].get_data() == "15.02"

    def run(self):
        self.add_test()
        self.tomorrow_exams_test()
        self.next_examns_test()