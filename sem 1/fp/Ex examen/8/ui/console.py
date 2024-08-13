from service.echipa_service import Service

class Console:
    def __init__(self, service: Service):
        self.__service = service

    def print_menu(self):
        """
        Printeaza meniul
        """
        print("1. Adaugare")
        print("2. Modificare")
        print("3. Export")
        print("4. Undo")
        print("5. Afis")
        print("6. Import")
        print("7. Exit")
        print("8. Stergere")

    def print_lst(self, lst):
        """
        Printeaza toate elem dintr o lista
        :param lst:
        :return:
        """
        for el in lst:
            print(el)

    def add_ui(self):
        try:
            nume = input("Introduceti numele: ")
            prenume = input("Introduceti prenumele: ")
            inaltime = int(input("Introduceti inaltimea(cm): "))
            post = input("Introduceti postul: ")
            self.__service.add(nume, prenume, inaltime, post)
        except ValueError as err:
            print(err)

    def modify_ui(self):
        nume = input("Introduceti numele: ")
        prenume = input("Introduceti prenumele: ")
        inaltime_nou = int(input("Introduceti noua inaltime: "))
        self.__service.modify(nume, prenume, inaltime_nou)

    def export(self):
        try:
            file_name = input("Introduceti numele fisierului: ")
            self.__service.export(file_name)
        except FileNotFoundError as err:
            print(err)

    def echipa_ui(self):
        print("Echipa cu cea mai mare medie de inaltime este: ")
        lst = self.__service.creare_echipa()
        for el in lst:
            print(el)

    def undo_ui(self):
        try:
            self.__service.undo()
        except ValueError as err:
            print(err)

    def import_ui(self):
        file_name = input("Introducetci numele de unde sa se importe: ")
        lst = self.__service.importt(file_name)
        for el in lst:
            print(el)

    def delete_ui(self):
        text = input("Introduceti textul: ")
        self.__service.delete(text)

    def run(self):
        self.echipa_ui()
        while True:
            self.print_menu()
            cmd = input("Introduceti comanda: ")

            if cmd == '1':
                self.add_ui()

            elif cmd == '2':
                self.modify_ui()

            elif cmd == '3':
                self.export()

            elif cmd == '4':
                self.undo_ui()

            elif cmd == '5':
                self.print_lst(self.__service.get_all())

            elif cmd == '6':
                self.import_ui()

            elif cmd == '7':
                break

            elif cmd == '8':
                self.delete_ui()

            else:
                print("Comanda invalida")