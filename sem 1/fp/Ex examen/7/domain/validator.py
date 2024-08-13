from domain.event import Event
from datetime import date


class Valid:

    def validate(self, event: Event):
        errors = []
        an = event.year()
        luna = event.month()
        zi = event.day()
        if '.' not in event.get_data():
            errors.append("Data nu contine '.' ")
        else:
            try:
                data = date(int(an), int(luna), int(zi))
            except ValueError:
                errors.append("Data invalida")

        if ':' not in event.get_ora():
            errors.append("Ora nu contine ':' ")
        else:
            ora = event.hour()
            min = event.min()

            if ora.isnumeric() != True and min.isnumeric() != True:
                errors.append("Ora si minutele trebuei sa fie numere")
            else:
                if 1 < int(ora) > 24:
                    errors.append("Ora invalida")

                if 0 < int(min) > 59:
                    errors.append("Minute invalide")

        if len(errors) != 0:
            errors = '\n'.join(errors)
            raise ValueError(errors)






