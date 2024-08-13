from controller.controller_student import *
from controller.controller_subject import *
from controller.controller_grade import *
from user_interface.menu import *

class UI:
    def __init__(self, student_control: Student_Controller, subject_control: Subject_Controller, common_control : Grade_Manager):
        self._student_control = student_control
        self._subject_control = subject_control
        self._grade_contol = common_control

    def valid_option(self, str :str):
        try:
            str = int(str)
            return str > -1
        except ValueError:
            return False



    def option_main_menu(self):
        try:
            MENU.print_main_menu()
            while True:
                user_input = input("Alege o optiune: ")
                if not self.valid_option(user_input):
                    print("Optiune invalida")
                else: user_input = int(user_input)

                if user_input == 1:
                    UI.option_student_menu(self)

                elif user_input == 2:
                    UI.option_subject_menu(self)

                elif user_input == 3:
                    UI.option_grades_menu(self)

                elif user_input == 4:
                    UI.option_statistic_menu(self)

                elif user_input == 5:
                    exit()
                else:
                    print("Optiunea trebuie sa fie un numar intre 1 si 5")
        except Exception as e:
            print(e)
            print("\n")
            UI.option_main_menu(self)

    def option_student_menu(self):
        try:
            MENU.print_student_menu()
            while True:
                user_input = input("Alege o optiune: ")
                if not self.valid_option(user_input):
                    print("Optiune invalida")
                else: user_input = int(user_input)

                if user_input == 0:
                    students = self._student_control.get_students()
                    if len(students) == 0:
                        print("Nu exista niciun student.")
                    for student in students:
                        print(student)

                elif user_input == 1:
                    id = input("Introduceti id student: ")
                    name = input("Introduceti numele studentului: ")
                    self._student_control.add(id, name)

                elif user_input == 2:
                    id = input("Introduceti ID student: ")
                    self._student_control.delete(id)

                elif user_input == 3:
                    id = input("Introduceti id student: ")
                    name = input("Introduceri noul nume: ")
                    self._student_control.modify_student_name(id, name)

                elif user_input == 4:
                    id = input("Introduceti un id: ")
                    print(f"Studentul cautat este : {self._student_control.search(id)}")


                elif user_input == 5:
                   UI.option_main_menu(self)

                elif user_input == 6:
                    cnt = input("Introduceti numarul de entitati random: ")
                    self._student_control.random_student(cnt)
                    print("Studentii au fost adaugati")

                else:
                    print("Optiunea trebuie sa fie un numar intre 0 si 6")
        except Exception as e:
            print(e)
            print("\n")
            UI.option_student_menu(self)

    def option_subject_menu(self):
        try:
            MENU.print_subject_menu()
            while True:
                user_input = input("Alege o optiune: ")
                if not self.valid_option(user_input):
                    print("Optiune invalida")

                else: user_input = int(user_input)

                if user_input == 0:
                    subjects = self._subject_control.get_subjects()
                    if len(subjects) == 0:
                        print("Nu existsa nicio disciplina")
                    for subject in subjects:
                         print(subject)

                elif user_input == 1:
                    id = input("Introduceti un id: ")
                    name = input("Introduceti un nume: ")
                    professor = input("Introduceti un prosefor: ")
                    self._subject_control.add(id, name, professor)

                elif user_input == 2:
                    id = input("Introduceti un id: ")
                    self._subject_control.delete(id)

                elif user_input == 3:
                    id = input("introduceti un id: ")
                    name = input("Introduceti noul nume: ")
                    self._subject_control.modify_name(id, name)

                elif user_input == 4:
                    id = input("Introduceti un id: ")
                    professor = input("Introduceti un profesor: ")
                    self._subject_control.modify_professor(id, professor)

                elif user_input == 5:
                    id = input("Introduceti un id: ")
                    print(f"Disciplina cautata este: {self._subject_control.search(id)}\n")

                elif user_input == 6:
                    UI.option_main_menu(self)
                else:
                    print("Optiunea trebuie sa fie un numar intre 0 si 6")
        except Exception as e:
            print(e)
            print("\n")
            UI.option_subject_menu(self)

    def option_grades_menu(self):
        try:
            MENU.print_grades_menu()
            while True:
                user_input = input("Alege o optiune: ")
                if not self.valid_option(user_input):
                    print("Optiune invalida")

                else:
                    user_input = int(user_input)

                if user_input == 0:
                    student_id = input("Id ul studentului: ")
                    student = self._student_control.search(student_id)
                    rez = self._grade_contol.list_grades_for_student(student_id)
                    if len(rez):
                        for grade in rez:
                            print(grade)
                    else: print("Studentul nu a fost notat")

                elif user_input == 1:
                    id_student = input("Id student: ")
                    id_subject = input("Id disciplina: ")
                    grade = input("Nota: ")
                    self._grade_contol.assign(id_student, id_subject, grade)

                elif user_input == 2:
                    UI.option_main_menu(self)
                else:
                    print("Optiunea trebuie sa fie un numar intre 0 si 2")
        except Exception as e:
            print(e)
            print("\n")
            UI.option_grades_menu(self)

    def option_statistic_menu(self):
        try:
            MENU.print_statistic_menu()
            while True:
                user_input = input("Alege o optiune: ")
                if not self.valid_option(user_input):
                    print("Optiune invalida")

                else:
                    user_input = int(user_input)

                if user_input == 1:
                    subject_id = input("Id disciplina: ")
                    students_list = self._grade_contol.students_grade_for_subject(subject_id)
                    for student in students_list:
                        print(student)

                elif user_input == 2:
                    subject_id = input("Id disciplina: ")
                    students_list = self._grade_contol.students_by_subject_sorted_by_name(subject_id)

                    for student in students_list:
                        print(student)

                elif user_input == 3:
                    subject_id = input("Id disciplina: ")
                    students_list = self._grade_contol.students_by_subject_sorted_by_grades(subject_id)
                    for student in students_list:
                        print(student)

                elif user_input == 4:
                    students_list = self._grade_contol.top_students_by_gpa()
                    print("Primii 20% de elevi din clasa sunt: \n")
                    for student in students_list:
                        print(student)

                elif user_input == 5:
                    UI.option_main_menu(self)
                else:
                    print("Optiunea trebuie sa fie un numar intre 1 si 5")
        except Exception as e:
            print(e)
            print("\n")
            UI.option_statistic_menu(self)

