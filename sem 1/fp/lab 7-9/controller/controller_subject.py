from repository.repository_subject import *
from domain.domain_subject import *
from user_interface.validator import *

class Subject_Controller:
    def __init__(self, subject_repo: Subject_Repository, subject_validator : Subject_Validator):
        self._subject_repo = subject_repo
        self._subject_validator = subject_validator

    def get_subjects(self) -> list:
        return self._subject_repo.get_all()

    def add(self, id, name, professor):
        """
        Adauga o noua entitate in lista

        :param id: id ul disciplinei
        :param name: numele disciplinei
        :param professor: numele profesorului
        :return: nothing
        """
        subject = Subject(id, name, professor)
        self._subject_validator.validate_subject(subject)
        self._subject_repo.add_subject(subject)

    def delete(self, id):
        """
        Sterge entitatea

        :param id: id ul disciplinei
        :return: nothing
        """
        subject = self._subject_repo.search_subject(id)
        if self._subject_validator.is_number(id) == False:
            raise Exception ("Id ul trebuie sa fie un numar natural")
        self._subject_repo.delete_subject(id)

    def modify_name(self, id, new_name):
        """
        MOdifica numele disciplinei

        :param id: id ul disciplinei
        :param new_name: noul nume
        :return: nothing
        """
        subject = self._subject_repo.search_subject(id)
        new_subject = Subject(id, new_name, self._subject_repo._subjects[id].get_professor())
        self._subject_validator.validate_subject(new_subject)

        self._subject_repo.modify_subject(new_subject)

    def modify_professor(self, id, new_professor):
        """
        Modifica profesorul disciplinei

        :param id: id ul disciplinei
        :param new_professor: noul profesor
        :return: nothing
        """
        subject = self._subject_repo.search_subject(id)
        new_subject = Subject(id, self._subject_repo._subjects[id].get_subject_name(), new_professor)
        self._subject_validator.validate_subject(new_subject)

        self._subject_repo.modify_subject(new_subject)

    def search(self, id):
        """
        Cauta disciplina

        :param id: id ul disciplinei
        :return: disciplina cautata
        """
        if self._subject_validator.is_number(id) == False:
            raise Exception("Id ul trebuie sa fie un numar natural")
        return self._subject_repo.search_subject(id)