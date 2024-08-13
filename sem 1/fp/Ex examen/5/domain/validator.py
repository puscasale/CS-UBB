from domain.song_domain import Song


class Validator:
    def validate_durata(self, durata):
        errors = []
        if  durata < 0:
            errors.append("Durata trebuei sa fie un numar intreg pozitiv")

        if len(errors) != 0:
            errors = '\n'.join(errors)
            raise ValueError(errors)

    def validate_gen(self, gen):
        errors = []
        if gen != 'Rock' and gen != 'Pop' and gen != 'Jazz' and gen != 'Altele':
            errors.append("Gen invalid")

        if len(errors) != 0:
            errors = '\n'.join(errors)
            raise ValueError(errors)