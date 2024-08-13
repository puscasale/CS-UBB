from domain.domain_student import *

class Student_repository():
    def __init__(self) -> None:
        self._students = {}

    def get_all(self):
        return [self._students[identifier] for identifier in self._students.keys()]

    def __len__(self):
        return len(self._students)

    def get_student(self, id):
        return self._students[id]

    def add_student(self, student: Student):
        """
        Adauga un student in repo
        """
        student_id = student.get_id_student()
        if student_id in self._students.keys():
            raise Exception(f"Studentul cu id-ul {student_id} a fost deja introdus" )
        self._students[student_id] = student

    def modify_student(self, new_student : Student):
        """
        Modifica un student existen in repo
        """
        student_id = new_student.get_id_student()
        if student_id not in self._students.keys():
            raise Exception(f"Studentul cu id ul {student_id} nu exista")
        self._students[student_id] = new_student

    def delete_student(self, id) :
        """
        Sterge un student existent din repo
        """
        if id not in self._students:
            raise Exception("Nu exista student cu acest id")
        self._students.pop(id)

    def search_student(self, student_id):
        """
        Cauta un student dupa id
        """
        if student_id not in self._students.keys():
            raise Exception(f"Studentul cu ID-ul {student_id} nu exista")

        return self._students[student_id] if self._students[student_id] else self.search_student(student_id)

    #def search_student(self, student_id):
    #    """
    #    Cauta un student dupa id
    #    """
    #   if student_id not in self._students.keys():
     #       raise Exception(f"Studentul cu ID-ul {student_id} nu exista")
     #   return self._students[student_id]



class Student_repository_file(Student_repository):
    def __init__(self, file_name):
        super().__init__()
        self.__file_name = file_name

    def read_students_from_file(self):
        try:
            f = open(self.__file_name, "r")
        except IOError:
            raise Exception(f"Fisierul {self.__file_name} nu exista")
        self._students.clear()
        lines = f.readlines()

        for line in lines:
            if line != "":
                tokens = line.strip().split(",")
                id = tokens[0]
                name = tokens[1]
                student = Student(id, name)
                self._students[id] = student
        f.close()

    def write_to_file(self):
        try:
            f = open(self.__file_name, "w")
        except IOError:
            raise Exception(f"Fisierul {self.__file_name} nu exista")
        for student in self._students.values():
            f.write(f"{student.get_id_student()},{student.get_student_name()}" + "\n")
        f.close()

    def add_student(self, student: Student):
        self.read_students_from_file()
        super().add_student(student)
        self.write_to_file()

    def get_all(self):
        self.read_students_from_file()
        return super().get_all()

    def modify_student(self, new_student : Student):
        self.read_students_from_file()
        super().modify_student(new_student)
        self.write_to_file()

    def delete_student(self, id):
        self.read_students_from_file()
        super().delete_student(id)
        self.write_to_file()

    def search_student(self, student_id):
        self.read_students_from_file()
        return super().search_student(student_id)

    def get_student(self, id):
        self.read_students_from_file()
        return super().get_student(id)

    def clean_up(self):
        self._students = []
        self.write_to_file()













