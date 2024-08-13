from repository.repository_grade import *
from repository.repository_student import *


class Grade_Manager:
    def __init__(self, grade_repo : Grade_Repository, student_repo : Student_repository):
        self.__grade_repo = grade_repo
        self.__student_repo = student_repo


    def assign(self, student_id, subject_id, grade):
        """
        Asigneaza nota la un student si o disciplina
        :param student_id: id ul studentului
        :param subject_id: id ul disciplinei
        :param grade: nota
        :return: nota
        """
        student = self.__student_repo.search_student(student_id)
        grade = Grade(student_id, subject_id, grade)
        self.__grade_repo.add(grade)
        return grade

    def list_grades_for_student(self, student_id):
        """
        Lista notelor pt un student
        :param student_id: id ul studentului
        :return: lista
        """
        student = self.__student_repo.search_student(student_id)
        return self.__grade_repo.get_grade_for_student(student_id)


    def top_students_by_gpa(self):
        """
        Top 20% din studenti dupa media la toate notele
        :return: lisa studentilor din top
        """
        students = self.__student_repo.get_all()
        averages = {}

        for student in students:
            grades = self.__grade_repo.get_all_grades_for_student(student.get_id_student())
            sum_grades = sum(grades)
            total_grades = len(grades)
            if total_grades > 0:
                averages[student.get_id_student()] = round(sum_grades / total_grades, 2)

        result = []
        top_students = []

        for key, value in averages.items():
            student = self.__student_repo.get_student(key)
            student_name = student.get_student_name()
            student_average = value
            dto = StudentGradeDTO(student_name, student_average)
            result.append(dto)

        result.sort(key=lambda x: x.get_grade(), reverse=True)

        grade_index = int(0.2 * len(result))
        grade_g = result[grade_index].get_grade()

        top_students = [student for student in result if student.get_grade() >= grade_g]

        return top_students


    def students_grade_for_subject(self, subject_id):
        """
        Lista de studenti ordonati pt o disciplina

        :param subject_id: id ul disciplinei
        :return: lista de studenti ordonata
        """
        students = self.__student_repo.get_all()
        result = []

        for student in students:
            grade = self.__grade_repo.get_grade_for_student_by_subject(student.get_id_student(), subject_id)
            student_name = student.get_student_name()
            if grade > 0:
                dto = StudentGradeDTO(student_name, grade)
                result.append(dto)

        ord_students = self.bubble_sort(result, key=lambda x: (-x.get_grade(), x.get_name()))
        return ord_students

    def students_by_subject_sorted_by_name(self, subject_id):
        """
        Lista de studenti ordonata alfabetic pt o disciplina

        :param subject_id: id ul disciplinei
        :return: lista de studenti ordonata
        """
        students = self.__student_repo.get_all()
        result = []

        for student in students:
            grade = self.__grade_repo.get_grade_for_student_by_subject(student.get_id_student(), subject_id)
            student_name = student.get_student_name()
            if grade > 0:
                dto = StudentGradeDTO(student_name, grade)
                result.append(dto)

        sorted_students_by_name = self.gnome_sort(result,key=lambda x: x.get_name())

        return sorted_students_by_name

    def bubble_sort(self, arr, key=None):

        n = len(arr)

        for i in range(n):
            # Last i elements are already in place, so we don't need to check them
            for j in range(0, n - i - 1):
                # If the key function is provided, use it to compare elements; otherwise, use default comparison
                if key:
                    if key(arr[j]) > key(arr[j + 1]):
                        arr[j], arr[j + 1] = arr[j + 1], arr[j]
                else:
                    if arr[j] > arr[j + 1]:
                        arr[j], arr[j + 1] = arr[j + 1], arr[j]
        return arr

    def gnome_sort(self, arr, key=None):
        i = 0
        n = len(arr)

        while i < n:
            if i == 0 or (key and key(arr[i]) >= key(arr[i - 1])) or (not key and arr[i] >= arr[i - 1]):
                i += 1
            else:
                arr[i], arr[i - 1] = arr[i - 1], arr[i]
                i -= 1

        return arr

    def students_by_subject_sorted_by_grades(self, subject_id):
        """
        Lista de studenti ordonata dupa note pt o disciplina

        :param subject_id: id ul disciplinei
        :return: lista de studenti ordonata
        """
        students = self.__student_repo.get_all()
        result = []

        for student in students:
            grade = self.__grade_repo.get_grade_for_student_by_subject(student.get_id_student(), subject_id)
            student_name = student.get_student_name()
            if grade > 0:
                dto = StudentGradeDTO(student_name, grade)
                result.append(dto)

        sorted_students_by_grade = self.bubble_sort(result, key=lambda x: x.get_grade())

        return sorted_students_by_grade



