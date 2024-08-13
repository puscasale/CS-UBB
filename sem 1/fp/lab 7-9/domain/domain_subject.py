class Subject:
    def __init__(self, subject_id, subject_name, professor):
        self.__subject_id = subject_id
        self.__subject_name = subject_name
        self.__professor = professor

    def get_subject_id(self):
        return self.__subject_id

    def set_subject_id(self, subject_id):
        self.__subject_id = subject_id

    def get_subject_name(self):
        return self.__subject_name

    def set_subject_name(self, subject_name):
        self.__subject_name = subject_name

    def get_professor(self):
        return self.__professor

    def set_professor(self, professor):
        self.__professor = professor

    def __str__(self):
        return f"ID Disciplina: {self.__subject_id}, Nume: {self.__subject_name}, Profesor: {self.__professor}"

    def __eq__(self, other):
        if not isinstance(other, Subject):
            return False
        return self.get_subject_id() == other.get_subject_id()