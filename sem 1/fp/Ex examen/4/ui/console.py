from service.emisiune_service import Service

class Console:
    def __init__(self, service: Service):
        self.__service = service
        self.__tip = ''

    def print_menu(self):
        print("1. Stergere")
        print("2. Modificare")
        print("3. Program")
        print("4. Blocare")
        print("5. Afisare")
        print("6. Exit")

    def blocare_ui(self):
        self.__tip = input("Introduceti tipul: ")
        block_list = self.__service.blocare(self.__tip)
        print("Emisiunile blocate sunt: ")
        for el in block_list:
            print(el)

    def print_list(self, lst):
        for el in lst:
            print(el)

    def delete_ui(self):
        nume = input("Introduceti numele: ")
        tip = input("Introduceti tipul: ")
        if tip == self.__tip:
            print("Emisiune blocata")
        else:
            try:
             self.__service.delete(nume, tip)
            except ValueError as err:
                print(err)

    def modify_ui(self):
        nume = input("Introduceti numele: ")
        tip = input("Introduceti tipul: ")
        durata = int(input("Introducti durata: "))
        descriere = input("Introduceti decsrierea: ")
        if tip == self.__tip:
            print("Emisiune blocata")
        else:
            try:
                self.__service.modify(nume, tip, durata, descriere)
            except ValueError as err:
                print(err)

    def program_ui(self):
        inceput = int(input("Introduceti ora de inceput: "))
        sf = int(input("Introduceti ora de sfarsit: "))
        lst = self.__service.program(inceput, sf)
        print("Ora | Nume | Tip | Descriere")
        for el in lst:
            print(el)

    def start(self):
        while True:
            self.print_menu()
            cmd = input("Introduceti comanda: ")

            if cmd == '1':
                self.delete_ui()

            elif cmd == '2':
                self.modify_ui()

            elif cmd == '3':
                pass

            elif cmd == '4':
                self.blocare_ui()

            elif cmd == '5':
                self.print_list(self.__service.get_all())

            elif cmd == '6':
                break

            else:
                print("Comanda invalida")


