from domain.domain_student import *
from domain.domain_subject import *
from repository.repository_student import *
from repository.repository_subject import *

class Validator:
    def is_number(self, str : str):
        try:
            str = int(str)
            return str > 0
        except ValueError:
            return False

    def is_name(self, str: str):
        return str.isalpha()

    def is_grade(self, str : str):
        try:
            grade = float(str)
            return grade >= 0 and grade <= 10
        except ValueError:
            return False


class Student_Validator(Validator):
    def validate_student(self, student : Student) -> None:
        errors = ""
        if self.is_number(student.get_id_student()) == False:
            errors += "Id ul trebuie sa fie un numar natural"

        if self.is_name(student.get_student_name()) == False:
            errors += "Numele trebuie sa fie format strict din litere"

        if len(errors) > 0:
            errors = errors[:-1]
            raise Exception(errors)



class Subject_Validator(Validator):
    def validate_subject(self, subject: Subject):
        errors = ""
        if self.is_number(subject.get_subject_id()) == False:
            errors += "Id ul trebuie sa fie un numar natural"

        if self.is_name(subject.get_subject_name()) == False:
            errors += "Numele trebuie sa fie format strict din litere"

        if self.is_name(subject.get_professor()) == False:
            errors += "Numele trebuie sa fie format strict din litere"

        if len(errors) > 0:
            errors = errors[:-1]
            raise  Exception(errors)


