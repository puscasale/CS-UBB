from repository.repository_student import *
from domain.domain_student import *
from user_interface.validator import *
import random
import string

class Student_Controller:
    def __init__(self, student_repo: Student_repository, student_validator : Student_Validator):
        self._student_repo = student_repo
        self._student_validator = student_validator

    def get_students(self)-> list:
        """
        Returneaza lista cu toti studentii
        """
        return self._student_repo.get_all()

    def add(self, id, name):
        """
        Adauga o noua entitate in lista

        :param id: id-ul studentului
        :param name: numele studentului
        :return: nothing
        """
        student = Student(id, name)
        self._student_validator.validate_student(student)
        self._student_repo.add_student(student)

    def modify_student_name(self, id, new_name):
        """
        Modifica numele studentului

        :param id: id-ul studentului
        :param new_name: noul nume al studentului
        :return: nothing
        """
        student = self._student_repo.search_student(id)

        new_student = Student(id, new_name)
        self._student_validator.validate_student(new_student)
        self._student_repo.modify_student(new_student)

    def delete(self, id):
        """
        Sterge entitatea

        :param id: id ul studentului
        :return: nothing
        """
        student = self._student_repo.search_student(id)
        if self._student_validator.is_number(id) == False:
            raise Exception (f"Id ul trebuie sa fie un numar natural")
        self._student_repo.delete_student(id)

    def search(self, id):
        """
        Cauta studentul

        :param id: id ul studentului
        :return: studentul cautat
        """
        if self._student_validator.is_number(id) == False:
            raise Exception(f"ID-ul trebuie sa fie un numar natural")
        return self._student_repo.search_student(id)

    def random_student(self, cnt):
        while cnt:
            id_random = random.randint(1, 30)
            name_length = random.randint(3, 10)
            name_random = ''.join(random.choice(string.ascii_letters) for _ in range(name_length))

            if not id_random in self._student_repo._students:
                self.add(id_random, name_random)
                cnt = cnt - 1



