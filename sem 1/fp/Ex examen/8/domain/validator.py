from domain.echipa_domain import Echipa

class Validate:
    def validate(self, echipa: Echipa):
        """
        Validator pt echipa
        """
        errors = []
        if echipa.get_nume() == '':
            errors.append("Numele nu poate sa fie vid")

        if echipa.get_prenume() == '':
            errors.append("Prenumele nu poate sa fie vid")

        if echipa.get_post() != 'fundas' and echipa.get_post() != 'pivot' and echipa.get_post() != 'extrema':
            errors.append("Postul trebuei sa fie fundas sau pivot sau extrema")

        if echipa.get_inaltime() < 0:
            errors.append("Inaltimea trebuie sa fie un numar pozitiv")

        if len(errors) != 0:
            errors = '\n'.join(errors)
            raise ValueError(errors)
