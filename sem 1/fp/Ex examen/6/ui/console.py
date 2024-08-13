from service.serice_biblio import Service

class Console:
    def __init__(self, service: Service):
        self.__service = service

    def print_menu(self):
        print("1. Adaugare")
        print("2. Stergere")
        print("3. Filtrare")
        print("4. Undo")
        print("5. Export")
        print("6. Afisare")
        print("7. Random")
        print("8. Exit")

    def print_lst(self, lst):
        for el in lst:
            print(el)

    def add_ui(self):
        try:
            id = int(input("Introduceti id: "))
            titlu = input("Introduceti titlu: ")
            autor = input("Introduceti autor: ")
            an = int(input("Introduceti anul: "))
            self.__service.add(id, titlu, autor, an)

        except ValueError as err:
            print(err)

    def delete_ui(self):
        number = int(input("Introduceti numarul: "))
        self.__service.delete(number)

    def filter_ui(self):
        text = ''
        number = -1
        text = input("Introduceti filtrul de text: ")
        number = int(input("Introduceti filtrul de numar: "))
        print(f"Filtrul curent este: {text}, {number}")
        lst = self.__service.filter(text, number)
        if len(lst) == 0:
            print("Nu exista elemente")
        else:
            for el in lst:
                print(el)

    def undo_ui(self):
        try:
            self.__service.undo()
        except ValueError as err:
            print(err)

    def export_ui(self):
        try:
            file_name = input("Introduceti numele/calea fisierului:").strip()
            self.__service.export(file_name)
        except FileNotFoundError:  # nu e nevoie de asta de fapt, ca daca nu exista fisierul, il face el
            print("Fisierul introdus nu exista sau nu a putut fi deschis.")

    def random_ui(self):
        cnt = int(input("Introduceti nr de entitati random: "))
        lst = self.__service.random(cnt)
        for el in lst:
            print(el)

    def run(self):
        while True:
            self.print_menu()
            cmd = input("Intrpduceti comanda: ")

            if cmd == '1':
                self.add_ui()

            elif cmd == '2':
                self.delete_ui()

            elif cmd == '3':
                self.filter_ui()

            elif cmd == '4':
                self.undo_ui()

            elif cmd == '5':
                self.export_ui()

            elif cmd == '6':
                self.print_lst(self.__service.get_all())

            elif cmd == '7':
                self.random_ui()

            elif cmd == '8':
                break
            else:
                print("comanda invalida")
