from domain.exam import Exam


class Repo:
    def __init__(self, file_name):
        self.__file_name = file_name
        self.__exams = []
        self.load_from_file()

    def load_from_file(self):
        with open(self.__file_name, 'r') as file:
            lines = file.readlines()
            lines = [line.strip() for line in lines if line != '']
            for line in lines:
                info = [inf.strip() for inf in line.split(', ')]
                data = info[0]
                ora = info[1]
                materie = info[2]
                tip = info[3]
                exam = Exam(data, ora, materie, tip)
                self.__exams.append(exam)

    def write_to_file(self):
        list_to_write = []
        for exam in self.__exams:
            data = exam.get_data()
            ora = exam.get_ora()
            materie = exam.get_materie()
            tip = exam.get_tip()
            info = [data, ora, materie, tip]
            info = ', '.join(info)
            list_to_write.append(info)

        list_to_write = '\n'.join(list_to_write)
        with open(self.__file_name, 'w') as file:
            file.write(list_to_write)

    def get_all(self):
        return self.__exams

    def add_exam(self, exam: Exam):
        self.__exams.append(exam)
        self.write_to_file()

    def export_exam(self, file_name, lst):
        list_to_write = []
        for exam in lst:
            data = exam.get_data()
            ora = exam.get_ora()
            materie = exam.get_materie()
            tip = exam.get_tip()
            info = [data, ora, materie, tip]
            info = ', '.join(info)
            list_to_write.append(info)

        list_to_write = '\n'.join(list_to_write)
        with open(file_name, 'w') as file:
            file.write(list_to_write)

    def is_double(self, other: Exam):
        for exam in self.__exams:
            if (exam.get_materie() == other.get_materie()) and (exam.get_tip() == other.get_tip()):
                return True
        return False
