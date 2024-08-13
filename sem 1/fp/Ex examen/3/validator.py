from domain.exam import Exam
from datetime import date
class Validator:
    def validate(self, exam):
        errors = []
        if ':' not in exam.get_ora():
            errors.append("Ora este in format invalid")
        else:
            time = exam.get_ora().split(':')
            hour, min = time[0], time[1]
            if not hour.isnumeric() or not min.isnumeric():
                errors.append("Ora si minutele trebuei sa fie numere")

            elif 0 > int(hour) > 24 or  0 > int(min) > 59:
                errors.append("Ora sau minute invalide")

        if '.' not in exam.get_data():
            errors.append("Data este in format invalid")
        else:
            data = exam.get_data().split('.')
            day, month = str(data[0]), str(data[1])
            if not day.isnumeric() or not month.isnumeric():
                errors.append("Ziua si luna trebuei sa fie numere")

            elif 0 > int(month) > 12:
                errors.append("Luna invalida")

            else:
                try:
                    data = date(2024, int(month), int(day))
                except ValueError:
                    errors.append("Ziua invalida")

        if exam.get_tip() != 'normal' and exam.get_tip() != 'restanta':
            errors.append("Tipul trebuei sa fie normal sau restanta")

        if len(errors):
            errors = '\n'.join(errors)
            raise ValueError(errors)

