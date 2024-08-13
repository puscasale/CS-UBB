from service.exam_service import Service


class Console:
    def __init__(self, service: Service):
        self.__service = service

    def print_menu(self):
        print("1. Adaugare")
        print("2. Urm 3 zile")
        print("3. Exp")
        print("4. Afis")
        print("5. Exit")

    def print_list(self, lst):
        for el in lst:
            print(el)

    def add_ui(self):
        try:
            data = input("Introduceti data: ")
            ora = input("Ontroduceti ora: ")
            materie = input("Introduceti materia: ")
            tip = input("Introduceti tipul: ")
            self.__service.add(data, ora, materie, tip)

        except ValueError as err:
            print(err)

    def export_ui(self):
        file_name = input("Introduceti numele fisierului: ")
        text = input("Introduceti textul: ")
        self.__service.exp(file_name, text)

    def next_exams_ui(self):
        set_date = input("Introduceti data: ")
        new_list = self.__service.next_examns(set_date)
        if len(new_list) == 0:
            print("Nu exista examene in urmatoarele 3 zile")
        else:
            for el in new_list:
                print(el)

    def tomorrow_examns_ui(self):
        exams_list = []
        exams_list = self.__service.tomorrow_exam()
        for el in exams_list:
            print(el)

    def run(self):
        print("examenele de maine sunt:")
        self.tomorrow_examns_ui()
        while True:
            self.print_menu()
            cmd = input("Introduceti coamnda: ")
            if cmd == '1':
                self.add_ui()

            elif cmd == '2':
                self.next_exams_ui()

            elif cmd == '3':
                self.export_ui()

            elif cmd == '4':
                self.print_list(self.__service.get_all())

            elif cmd == '5':
                break

            else:
                print("Comanda invalida")

