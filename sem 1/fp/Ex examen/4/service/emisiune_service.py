from repo.emisiune_repo import Repo
from domain.emisiune import Emisiune
import random


class Service:
    def __init__(self, repo: Repo):
        self.__repo = repo

    def delete(self, nume: str, tip: str):
        ok = 0
        for emisiune in self.__repo.get_all():
            if emisiune.get_nume() == nume and emisiune.get_tip() == tip:
                self.__repo.delete_em(emisiune)
                self.__repo.write_to_file()
                ok = 1
        if ok == 0:
            raise ValueError("Nu exista nicio emisiune cu acest nume si tip")

    def modify(self, nume: str, tip: str, durata_nou: int, descriere_nou: str):
        ok = 0
        for emisiune in self.__repo.get_all():
            if emisiune.get_nume() == nume and emisiune.get_tip() == tip:
                emisiune.set_durata(durata_nou)
                emisiune.set_descriere(descriere_nou)
                self.__repo.write_to_file()
                ok = 1
        if ok == 0:
            raise ValueError("Nu exista nicio emisiune cu acest nume si tip")

    def program(self, ora_in: int, ora_sf: int):
        nr_ore = ora_sf-ora_in
        unused_lst = self.__repo.get_all()
        program = []
        inceput = ora_in
        while nr_ore != 0:
            if unused_lst != []:
                em_aleasa = random.choice(unused_lst)
                local_un = self.__repo.get_all()
                local_un.remove(em_aleasa)
                while em_aleasa.get_durata() > nr_ore:
                    em_aleasa = random.choice(local_un)
                    local_un.remove(em_aleasa)
                if local_un != []:
                    unused_lst.remove(em_aleasa)
                nume = em_aleasa.get_nume()
                tip = em_aleasa.get_tip()
                desc = em_aleasa.get_descriere()
                info = [str(inceput), nume, tip, desc]
                info = ' | '.join(info)
                program.append(info)
                inceput = inceput + em_aleasa.get_durata()
            else:
                raise ValueError("Nu stiu bag pl")
            nr_ore = nr_ore - em_aleasa.get_durata()

    def blocare(self, text):
        block_list = []
        for emisiune in self.__repo.get_all():
            if emisiune.get_tip() == text:
                block_list.append(emisiune)

        return block_list

    def get_all(self):
        return self.__repo.get_all()
