from domain.song_domain import Song
from domain.validator import Validator
from repo.song_repo import Repo
import random

class Service:
    def __init__(self, repo: Repo, valid: Validator):
        self.__repo = repo
        self.__repo.load_form_file()
        self.__valid = valid

    def get_all(self):
        return self.__repo.get_all()

    def modify(self, titlu: str, gen_nou:str, durata_nou:int):
        self.__valid.validate_gen(gen_nou)
        self.__valid.validate_durata(durata_nou)
        for song in self.__repo.get_all():
            if song.get_titlu() == titlu:
                song.set_durata(durata_nou)
                song.set_gen(gen_nou)
        self.__repo.write_to_file()

    def random(self, number: int):
        titluri = ['tit1', 'tit2', 'tit3', 'tit4']
        artisti = ['art1', 'art2', 'art3', 'art4']
        genuri = ['Rock', 'Pop', 'Jazz', 'Altele']
        for i in range(number):
            titlu = random.choice(titluri)
            artist = random.choice(artisti)
            gen = random.choice(genuri)
            durata = random.randint(120, 360)
            song = Song(titlu, artist, gen, durata)
            self.__repo.add(song)

        return number

    def export(self, file_name):
        lst = []
        for song in self.__repo.get_all():
            artist = song.get_artist()
            titlu = song.get_titlu()
            gen = song.get_gen()
            an = random.randint(1990, 2024)
            info = [artist, titlu, gen, an]
            lst.append(info)
        self.__repo.exp(file_name, lst)