from domain.song_domain import Song
from domain.song_domain import Song_Dto

class Repo:
    def __init__(self, file_name):
        self.__file_name = file_name
        self.__songs = []

    def load_form_file(self):
        with open(self.__file_name, 'r') as file:
            lines = file.readlines()
            lines = [line.strip() for line in lines if line != '']
            for line in lines:
                info = [inf.strip() for inf in line.split(', ')]
                titlu = info[0]
                artist = info[1]
                gen = info[2]
                durata = int(info[3])
                song = Song(titlu, artist, gen, durata)
                self.__songs.append(song)

    def write_to_file(self):
        list_to_write = []
        for song in self.__songs:
            titlu = song.get_titlu()
            artist = song.get_artist()
            gen = song.get_gen()
            durata = str(song.get_durata())
            info = [titlu, artist, gen, durata]
            info = ', '.join(info)
            list_to_write.append(info)

        list_to_write = '\n'.join(list_to_write)

        with open(self.__file_name, 'w') as file:
            file.write(list_to_write)

    def get_all(self):
        return self.__songs

    def add(self, song: Song):
        self.__songs.append(song)
        self.write_to_file()

    def exp(self, file_name, lst):
        list_to_write = []
        for song in lst:
            titlu = song[1]
            artist = song[0]
            gen = song[2]
            an = str(song[3])
            info = [artist, titlu, gen, an]
            info = ', '.join(info)
            list_to_write.append(info)

        list_to_write = '\n'.join(list_to_write)

        with open(file_name, 'w') as file:
            file.write(list_to_write)
