from service.service_event import Service

class Console:
    def __init__(self, service: Service):
        self.__service = service

    def print_menu(self):
        print("1. Adaugare")
        print("2. Stergere")
        print("3. Undo")
        print("4. Export")
        print("5. Filtrare")
        print("6. Random")
        print("7. Afis")
        print("8. Exit")

    def print_lst(self, lst):
        for el in lst:
            print(el)

    def add_ui(self):
        try:
            data = input("Introduceti data: ")
            ora = input("Introduceti ora: ")
            desc = input("Intrpduceti desc: ")
            self.__service.add(data, ora, desc)
        except ValueError as err:
            print(err)

    def delete_ui(self):
        text = input("Introduceti textul: ")
        self.__service.delete(text)

    def undo(self):
        try:
            self.__service.undo()
        except ValueError as err:
            print(err)

    def export_ui(self):
        try:
            file_name = input("Introduceti numele fisierului: ")
            text = input("Introduceti textul: ")
            self.__service.export(file_name, text)
        except FileNotFoundError:
            print("Nu merge exp")

    def filter_ui(self):
        data = input("Introdceti data: ")
        lst = self.__service.filter(data)
        if len(lst) != 0:
            for el in lst:
                print(el)
        else:
            print("Nu exista niciun eveniment cu aceasta data")

    def random_ui(self):
        try:
            cnt = int(input("Introduceti nr de entitati random: "))
            lst = self.__service.random(cnt)
            for el in lst:
                print(el)
        except ValueError as err:
            print(err)

    def today_ui(self):
        lst = self.__service.today()
        if len(lst) != 0:
            print("Evenimentele de astazi sunt: ")
            for el in lst:
                print(el)
        else:
            print("Astazi nu exista evenimnete")

    def start(self):
        self.today_ui()
        while True:
            self.print_menu()
            cmd = input("Introduceti comanda: ")

            if cmd == '1':
                self.add_ui()

            elif cmd == '2':
                self.delete_ui()

            elif cmd == '3':
                self.undo()

            elif cmd == '4':
                self.export_ui()

            elif cmd == '5':
                self.filter_ui()

            elif cmd == '6':
                self.random_ui()

            elif cmd == '7':
                self.print_lst(self.__service.get_all())

            elif cmd == '8':
                break

            else:
                print("Comanda invalida")
