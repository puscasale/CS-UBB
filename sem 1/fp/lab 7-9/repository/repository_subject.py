from domain.domain_subject import *

class Subject_Repository:
    def __init__(self) -> None:
        self._subjects = {}

    def get_all(self):
        return [self._subjects[identifier] for identifier in self._subjects.keys()]

    def get_subject(self, id):
        return self._subjects[id]

    def __len__(self):
        return len(self._subjects)

    def add_subject(self, subject: Subject):
        """
        Adauga o disciplina in repo
        """
        id = subject.get_subject_id()
        if id in self._subjects.keys():
            raise Exception (f"Disciplina cu id ul {id} a fost introdusa deja")
        self._subjects[id] = subject

    def modify_subject(self, new_subject : Subject):
        """
        Modifica o disciplina
        """
        id = new_subject.get_subject_id()
        if id not in self._subjects.keys():
            raise Exception("Nu exista disciplina cu acest id")
        self._subjects[id] = new_subject

    def delete_subject(self, id):
        """
        Sterge o disciplina dupa id
        :param id: id disciplina
        """
        if id not in self._subjects.keys():
            raise Exception("Nu exista disciplina cu acest id")
        self._subjects.pop(id)

    #def search_subject(self, id):
    #    """
     #   Cauta o disciplina dupa id
     #   :param id: id disciplina
     #   """
     #   if id not in self._subjects.keys():
     #       raise Exception(f"Nu exista disciplina cu acest id")
     #   return self._subjects[id]

    def search_subject(self, id):
        """
        Cauta o disciplina dupa id
        :param id: id disciplina
        """
        if id not in self._subjects.keys():
            raise Exception(f"Nu exista disciplina cu acest id")
        return self._subjects[id] if self._subjects[id] else self.search_subject(id)


class Subject_Repository_file(Subject_Repository):
    def __init__(self, file_name):
        super().__init__()
        self.__file_name = file_name

    def read_from_file(self):
        try:
            f = open(self.__file_name, "r")
        except IOError:
            raise Exception(f"Fisierul {self.__file_name} nu exista")

        self._subjects.clear()
        lines = f.readlines()

        for line in lines:
            if line != "":
                tokens = line.strip().split(",")
                id = tokens[0]
                name = tokens[1]
                professor = tokens[2]
                subject = Subject(id, name, professor)
                self._subjects[id] = subject
        f.close()

    def write_to_file(self):
        try:
            f = open(self.__file_name, "w")
        except IOError:
            raise Exception(f"Fisierul {self.__file_name} nu exista")

        for subject in self._subjects.values():
            f.write(f"{subject.get_subject_id()},{subject.get_subject_name()},{subject.get_professor()}" + '\n')
        f.close()

    def add_subject(self, subject: Subject):
        self.read_from_file()
        super().add_subject(subject)
        self.write_to_file()

    def modify_subject(self, new_subject : Subject):
        self.read_from_file()
        super().modify_subject(new_subject)
        self.write_to_file()

    def delete_subject(self, id):
        self.read_from_file()
        super().delete_subject(id)
        self.write_to_file()

    def get_all(self):
        self.read_from_file()
        return super().get_all()

    def get_subject(self, id):
        self.read_from_file()
        return super().get_subject(id)

    def search_subject(self, id):
        self.read_from_file()
        return super().search_subject(id)





"""
class Subject_Repository_file(Subject_Repository):
    def __init__(self, file_name):
        Subject_Repository.__init__(self)
        self.__file_name = file_name
        self.load_from_file()

    def load_from_file(self):
        with open(self.__file_name, mode = 'r') as subjects_file:
            lines = subjects_file.readlines()
            lines = [line.strip() for line in lines if line.strip() != '']
            for line in lines:
                id, name, professor = line.split(',')
                id = id.strip()
                name = name.strip()
                professor = professor.strip()
                id = int(id)
                Subject_Repository.add_subject(self, Subject(id, name, professor))

    def add_subject(self, subject: Subject):
        Subject_Repository.add_subject(self, subject)
        self.write_to_file()

    def delete_subject(self, id):
        deleted_subject = Subject_Repository.delete_subject(self, id)
        self.write_to_file()
        return deleted_subject

    def modify_subject(self, new_subject : Subject):
        Subject_Repository.modify_subject(self, new_subject)
        self.write_to_file()

    def search_subject(self, id):
        searched_subject = Subject_Repository.search_subject(self, id)
        self.write_to_file()
        return searched_subject

    def write_to_file(self):
        subjects = Subject_Repository.get_all(self)
        subjects = [str(subject.get_subject_id)+ ',' + subject.get_subject_name()+ ','+ subject.get_professor() for subject in subjects]
        with open(self.__file_name, mode = 'w') as subjects_file:
            text_to_write = '\n'.join(subjects)
            subjects_file.write(text_to_write)

"""