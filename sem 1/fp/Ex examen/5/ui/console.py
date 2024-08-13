from service.song_service import Service

class Console:
    def __init__(self, service:Service):
        self.__service = service

    def print_menu(self):
        print("1. Modificare")
        print("2. Random")
        print("3. Exp")
        print("4. afisare")
        print("5. Exit")

    def print_lst(self, lst):
        for el in lst:
            print(el)

    def modify_ui(self):
        try:
            titlu = input("INtroduceti titlul: ")
            gen = input("Introduceti genul nou: ")
            durata = int(input("Introduceti durata noua: "))
            self.__service.modify(titlu, gen, durata)
        except ValueError as err:
            print(err)

    def random_ui(self):
        number = int(input("Introduceti nr de entitati rnadom: "))
        num = self.__service.random(number)
        print(f"Numarul de entitati random adaugate este: {num}")

    def export_ui(self):
        file_name = input("Introduceti numele fisierului: ")
        self.__service.export(file_name)

    def run(self):
        while True:
            self.print_menu()
            cmd = input("Introduceti o comanda: ")

            if cmd == '1':
                self.modify_ui()

            elif cmd == '2':
                self.random_ui()

            elif cmd == '3':
                self.export_ui()

            elif cmd == '4':
                self.print_lst(self.__service.get_all())

            elif cmd == '5':
                break

            else:
                print("Comanda invalida")
