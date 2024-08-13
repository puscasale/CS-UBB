from domain.carte import Carte


class Valid:
    def validate(self, carte: Carte):
        errors = []
        if carte.get_titlu().isnumeric() == True:
            errors.append("Titul trebuie sa fie string")

        if carte.get_autor().isnumeric() == True:
            errors.append("Autorul trebuie sa fie string")

        if len(errors) !=0:
            errors = '\n'.join(errors)
            raise ValueError(errors)
