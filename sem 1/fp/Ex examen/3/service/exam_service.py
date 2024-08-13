from repo.exam_repo import Repo
from validator import Validator
from domain.exam import Exam
from datetime import date


class Service:
    def __init__(self, repo: Repo, valid: Validator):
        self.__repo = repo
        self.__valid = valid

    def add(self, data: str, ora: str, materie: str, tip: str):
        exam = Exam(data, ora, materie, tip)
        self.__valid.validate(exam)
        if self.__repo.is_double(exam) == True:
            raise ValueError("Exista deja acest examen la aceatsa materie cu ac tip")
        else:
            self.__repo.add_exam(exam)

    def exp(self, file_name, text):
        new_list = []
        for exam in self.__repo.get_all():
            if text in exam.get_materie():
                new_list.append(exam)
        new_list = sorted(new_list, key=lambda x: (x.get_data(), x.get_ora()))
        self.__repo.export_exam(file_name, new_list)

    def get_all(self):
        return self.__repo.get_all()

    def next_examns(self, set_date: str):
        exam_list = []
        set_day, set_month = set_date.split('.')
        for exam in self.__repo.get_all():
            day = exam.day()
            month = exam.month()
            if int(day) >= int(set_day) and int(month) >= int(set_month):
                if int(day) <= int(set_day) + 3:
                    exam_list.append(exam)

        return exam_list

    def tomorrow_exam(self):
        exam_list = self.__repo.get_all()
        next_exams_list = []
        set_day, set_month = date.today().day + 1, date.today().month
        for exam in exam_list:
            day = exam.day()
            month = exam.month()
            if int(day) == int(set_day) and int(month) == int(set_month):
                next_exams_list.append(exam)

        next_exams_list = sorted(next_exams_list, key=lambda x: x.hour())

        return next_exams_list



