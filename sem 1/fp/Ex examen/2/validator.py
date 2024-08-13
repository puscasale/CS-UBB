from domain.show_domain import Show
class Validator:
    def validate(self, show):
        errors = []
        if show.get_nume() == '':
            errors.append("Numele trebuei sa fie nevid")

        if show.get_artist() == '':
            errors.append("Artistul trebuei sa fie nevid")

        durata = int(show.get_durata())

        if  durata <= 0:
            errors.append("Durata trebuei sa fie un intreg pozitiv")

        if show.get_gen() != 'Comedie' and show.get_gen() != 'Concert' and show.get_gen() != 'Balet' and show.get_gen() != 'Altele':
            errors.append("Genul trebuei sa fie unul dintre: Comedie, Concert, Balet sau Altele")

        if len(errors) > 0:
            err = '\n'.join(errors)
            raise ValueError(err)

