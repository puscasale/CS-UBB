from domain.domain_student import *
from domain.domain_subject import *
from repository.repository_student import *
from repository.repository_subject import *
import unittest

class Tests(unittest.TestCase):
    def setUp(self):
        self.student_collection = Student_repository()
        self.student1 = Student(1, "John")
        self.student2 = Student(2, "Jane")
        self.student_collection.add_student(self.student1)
        self.student_collection.add_student(self.student2)
        self.student3 = Student(1, "Ben")
        self.subject_collection = Subject_Repository()
        self.subject1 = Subject(1, "math", "Lane")
        self.subject2 = Subject(2, "info", "Kate")
        self.subject_collection.add_subject(self.subject1)
        self.subject_collection.add_subject(self.subject2)
        self.subject3 = Subject(1, "english", "Smith")

    def test_get_id_student(self):
        self.assertEqual(self.student1.get_id_student(), 1)
        self.assertEqual(self.student2.get_id_student(), 2)

    def test_get_student_name(self):
        self.assertEqual(self.student1.get_student_name(), "John")
        self.assertEqual(self.student2.get_student_name(), "Jane")

    def test_set_student_name(self):
        self.student1.set_student_name("Sean")
        self.assertEqual(self.student1.get_student_name(), "Sean")

    def test_get_subject_id(self):
        self.assertEqual(self.subject1.get_subject_id(), 1)
        self.assertEqual(self.subject2.get_subject_id(), 2)

    def test_get_subject_name(self):
        self.assertEqual(self.subject1.get_subject_name(), "math")
        self.assertEqual(self.subject2.get_subject_name(), "info")

    def test_get_professor(self):
        self.assertEqual(self.subject1.get_professor(), "Lane")
        self.assertEqual(self.subject2.get_professor(), "Kate")

    def test_set_subject_name(self):
        self.subject1.set_subject_name("spanish")
        self.assertEqual(self.subject1.get_subject_name(), "spanish")

    def test_set_professor(self):
        self.subject1.set_professor("Blake")
        self.assertEqual(self.subject1.get_professor(), "Blake")

    def test_get_all(self):
        all_students = self.student_collection.get_all()
        self.assertEqual(len(all_students), 2)
        self.assertIn(self.student1, all_students)

    def test_len(self):
        self.assertEqual(len(self.student_collection), 2)

    def test_add_student(self):
        all_students = self.student_collection.get_all()
        student3 = Student(3, "Marc")
        self.student_collection.add_student(student3)
        self.assertIn(self.student3, all_students)

    def test_delete_student(self):
        all_students = self.student_collection.get_all()
        self.student_collection.delete_student(1)

    def test_add_subject(self):
        subject3 = Subject(3, "romanian", "Cata")
        self.subject_collection.add_subject(subject3)
        self.assertEqual(len(self.subject_collection), 3)

    def test_delete_subject(self):
        self.subject_collection.delete_subject(1)
        self.assertEqual(len(self.subject_collection), 1)

if __name__ == '__main__':
    unittest.main()







