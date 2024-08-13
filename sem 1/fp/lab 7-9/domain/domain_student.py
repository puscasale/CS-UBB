class Student:
    def __init__(self, student_id, student_name):
        self.__student_id = student_id
        self.__student_name = student_name

    def get_id_student(self):
        return self.__student_id

    def set_id_student(self, student_id):
        self.__student_id = student_id

    def get_student_name(self):
        return self.__student_name

    def set_student_name(self, student_name):
        self.__student_name = student_name

    def __str__(self):
        return f"Student ID: {self.__student_id}, Nume: {self.__student_name}"

    def __eq__(self, other):
        if not isinstance(other, Student):
            return False
        return self.get_id_student() == other.get_id_student()



