from service.service_tractor import Service
from datetime import *

class Console:
    def __init__(self, service: Service):
        self.__service = service

    def print_menu(self):
        print("1. Adaugare")
        print("2. Stergere")
        print("3. Filtrare")
        print("4. Undo")
        print("5. Afisare")
        print("6. Exit")

    def print_list(self, lst):
        for entity in lst:
            print(entity)

    def add_ui(self):
        try:
            id = int(input("Introduceti id: ").strip())
            nume = input("Introduceti numele: ").strip()
            pret = int(input("Introduceti pretul: ").strip())
            model = input("Introduceti modelul: ").strip()
            data = input("Introduceti data de exipare: ").strip()
            self.__service.add(id, nume, pret, model, data)
        except ValueError as err:
            print(err)

    def delete_ui(self):
        try:
            digit = int(input("Introduceti o cifra: ").strip())
            cnt = self.__service.delete(digit)
            print(f"NR de tractoare sterse:{cnt}")
        except ValueError as err:
            print(err)

    def undo_ui(self):
        lista = self.__service.undo()
        print("Undo a fost realizat")

    def filter_ui(self):
        try:
            text = input("Introduceti textul: ").strip()
            number = int(input("Introduceti numarul: ").strip())
            print(f"Filtru curent: {text}, {number}")
            filtered_list = self.__service.filter(text, number)
            for tractor in filtered_list:
                if tractor.get_data() < date.today():
                    print(f"*{tractor}")
                else:
                    print(tractor)
        except ValueError as err:
            print(err)


    def start(self):
        while True:
            try:
                self.print_menu()
                cmd = input("Introduceti o optiune: ")

                if cmd == '1':
                    self.add_ui()

                elif cmd == '2':
                    self.delete_ui()

                elif cmd == '3':
                    self.filter_ui()

                elif cmd == '4':
                    self.undo_ui()

                elif cmd == '5':
                    self.print_list(self.__service.get_all())

                elif cmd == '6':
                    break
                else:
                    print("comanda invalida")
            except ValueError as err:
                print(err)




