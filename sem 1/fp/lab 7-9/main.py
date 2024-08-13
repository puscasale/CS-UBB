from user_interface.ui import *
from domain.domain_subject import *
from domain.domain_student import *
from controller.controller_student import *
from controller.controller_subject import *
from controller.controller_grade import *
from repository.repository_subject import *
from repository.repository_student import *
from testing import *



def main():
    student_repo = Student_repository_file("data/students.txt")
    student_validator = Student_Validator()
    student_control = Student_Controller(student_repo, student_validator)

    subject_repo = Subject_Repository_file("data/subjects.txt")
    subject_validator = Subject_Validator()
    subject_control = Subject_Controller(subject_repo, subject_validator)

    grade_repo = Grade_Repository_file("data/grades.txt")

    validator = Validator()

    common_control = Grade_Manager(grade_repo, student_repo)

    console = UI(student_control, subject_control, common_control)
    console.option_main_menu()

if __name__ == "__main__":
    main()