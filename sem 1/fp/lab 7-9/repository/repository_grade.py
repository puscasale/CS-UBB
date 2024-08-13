from domain.domain_grade import *
from user_interface.validator import *
class Grade_Repository(Validator):
    def __init__(self) -> None:
        self._grades = []

    def find(self, student, subject):
        """
        Returneaza o nota pt un student si o disciplina data
        """
        for grade in self._grades:
            if grade.get_student() == student and grade.get_subject() == subject:
                return grade
        return None

    def get_all(self):
        return [self._grades[identifier] for identifier in self._grades]

    def add(self, grade: Grade):
        """
        Adauga un obiect nota
        """
        if self.find(grade.get_student(), grade.get_subject())!= None:
            raise Exception("A fost deja notata")
        if self.is_grade(grade.get_grade()) == False:
            raise Exception ("Notarea se realizeaza de la 1 la 10")

        self._grades.append(grade)

    def size(self):
        return len(self._grades)

    def get_grade_for_student(self, student_id):
        """
        Toate notele pt un student
        """
        rez = []
        for grade in self._grades:
            if grade.get_student() == student_id:
                rez.append(grade)
        if rez == []:
            raise Exception("Studentul nu a fost notat")
        else: return rez

    def get_grade_for_student_by_subject(self, student_id, subject_id):
        """
        Get the grade of a specific student by a subject
        """
        st_grade = 0
        for grade in self._grades:
            if grade.get_student() == student_id and grade.get_subject() == subject_id:
                st_grade = int(grade.get_grade())
        return st_grade

    def get_all_grades_for_student(self, student_id):
        """
        Get all grades of a specific student
        """
        grades = []
        for grade in self._grades:
            if grade.get_student() == student_id:
                grades.append(int(grade.get_grade()))
        return grades

class Grade_Repository_file(Grade_Repository):
    def __init__(self, file_name):
        super().__init__()
        self.__file_name = file_name

    def read_from_file(self):
        try:
            f = open(self.__file_name, "r")
        except IOError:
            raise Exception(f"Fisierul {self.__file_name} nu exista")

        self._grades.clear()
        lines = f.readlines()

        for line in lines:
            if line != "":
                tokens = line.strip().split(",")
                student_id = tokens[0]
                subject_id = tokens[1]
                grade = tokens[2]
                grade = Grade(student_id, subject_id, grade)
                self._grades.append(grade)

        f.close()

    def write_to_file(self):
        try:
            f = open(self.__file_name, "a")
        except IOError:
            raise Exception(f"Fisierul {self.__file_name} nu exista")

        for grade in self._grades:
            f.write(f"{grade.get_student()},{grade.get_subject()},{grade.get_grade()}" + '\n')

        f.close()

    def find(self, student, subject):
        self.read_from_file()
        return super().find(student, subject)

    def get_all(self):
        self.read_from_file()
        return super().get_all()

    def add(self, grade: Grade):
        self.read_from_file()
        super().add(grade)
        self.write_to_file()

    def get_grade_for_student(self, student_id):
        self.read_from_file()
        return super().get_grade_for_student(student_id)

    def get_grade_for_student_by_subject(self, student, subject_id):
        self.read_from_file()
        return super().get_grade_for_student_by_subject(student, subject_id)

    def get_all_grades_for_student(self, student_id):
        self.read_from_file()
        return super().get_all_grades_for_student(student_id)



"""
class Grade_Repository_file(Grade_Repository):
    def __init__(self, file_name):
        super().__init__()
        self.__file_name = file_name

    def read_from_file(self):
        try:
            f = open(self.__file_name, "r")
        except IOError:
            raise Exception(f"Fsisierul {self.__file_name} nu exista")

        self._grades.clear()
        lines = f.readlines()

        for line in lines:
            if line != "":
                tokens = line.strip().split(",")
                student_id = tokens[0]
                subject_id = tokens[1]
                grade = tokens[2]
                grade = Grade(student_id, subject_id, grade)
                self._grades.append(grade)

        f.close()

    def write_to_file(self):
        try:
            f = open(self.__file_name, "r")
        except IOError:
            raise Exception(f"Fsisierul {self.__file_name} nu exista")

        for grade in self._grades:
            f.write(f"{grade.get_student()},{grade.get_subject()},{grade.get_grade()}" + '\n')

        f.close()

    def find(self, student, subject):
        self.read_from_file()
        return super().find(student, subject)

    def get_all(self):
        self.read_from_file()
        return super().get_all()

    def add(self, grade: Grade):
        self.read_from_file()
        super().add(grade)
        self.write_to_file()

    def get_grade_for_student(self, student):
        self.read_from_file()
        return super().get_grade_for_student(student)

    def get_grade_for_student_by_subject(self, student, subject_id):
        self.read_from_file()
        return super().get_grade_for_student_by_subject(student, subject_id)

    def get_all_grades_for_student(self, student):
        self.read_from_file()
        return super().get_all_grades_for_student(student)
"""