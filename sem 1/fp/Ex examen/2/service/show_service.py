from repo.show_repo import Repo
from validator import Validator
from domain.show_domain import Show
import random


class Service:
    def __init__(self, repo: Repo, valid: Validator):
        self.__repo = repo
        self.__valid = valid

    def get_all(self):
        return self.__repo.get_all()

    def add(self, titlu: str, artist: str, gen: str, durata: int):
        show = Show(titlu, artist, gen, durata)
        self.__valid.validate(show)
        self.__repo.add_show(show)

    def modify(self, titlu: str, artist: str, gen_nou: str, durata_nou: int):
        shows = self.__repo.get_all()
        for show in shows:
            if show.get_nume() == titlu and show.get_artist() == artist:
                show.set_gen(gen_nou)
                show.set_durata(durata_nou)
        self.__repo.write_to_file()

    def random(self, cnt: int):
        random_show_list = []
        for i in range(cnt):

            vocale = "aeiou"
            consoane = "bcdfghjklmnpqrstvwxyz"
            lungime_titlu = random.randint(9, 12)
            titlu = list(' ' * lungime_titlu)
            spatiu_titlu = random.randint(1, lungime_titlu-1)

            for j in range(lungime_titlu):
                if j != spatiu_titlu:
                    if j % 2 == 0:
                        titlu[j] = random.choice(vocale)
                    else:
                        titlu[j] = random.choice(consoane)
            titlu = ''.join(titlu)

            lungime = random.randint(9, 12)
            artist = list(' ' * lungime)
            spatiu = random.randint(1, lungime - 1)

            for j in range(lungime):
                if j != spatiu:
                    if j % 2 == 0:
                        artist[j] = random.choice(vocale)
                    else:
                        artist[j] = random.choice(consoane)
            artist = ''.join(artist)

            random_gen = ['Comedie', 'Concert', 'Balet', 'Altele']
            gen = random.choice(random_gen)
            gen = ''.join(gen)
            durata = random.randint(1, 10800)

            show = Show(titlu, artist, gen, durata)
            self.__repo.add_show(show)
            random_show_list.append(show)

        return random_show_list

    def export(self, file_name):
        self.__repo.exp(file_name)


