from service.show_service import Service

class Console:
    def __init__(self, service: Service):
        self.__service = service

    def print_menu(self):
        print("1. Adaugare")
        print("2. Modificare")
        print("3. Random")
        print("4. Export")
        print("5. Afisare")
        print("6. Exit")

    def print_list(self, lst):
        for el in lst:
            print(el)

    def add_ui(self):
        try:
            titlu = input("Introduceti un titlu: ").strip()
            artist = input("Introduceti un artist: ").strip()
            gen = input("Introduceti un gen: ").strip()
            durata = int(input("Intrduceti o durata: ").strip())

            self.__service.add(titlu, artist, gen, durata)
            print("Piesa a fost adaugata")

        except ValueError as err:
            print(str(err))

    def modify_ui(self):
        try:
            titlu = input("Introduceti un titlu: ").strip()
            artist = input("Introduceti un artist: ").strip()
            gen_nou = input("Introduceti noul gen: ").strip()
            durata_nou = int(input("Intrdouceti noua durata: ").strip())

            self.__service.modify(titlu, artist, gen_nou, durata_nou)

        except ValueError as err:
            print(str(err))

    def random_ui(self):
        cnt = int(input("Introduceti nr de spectacole random: ").strip())
        random_list = self.__service.random(cnt)
        for el in random_list:
            print(el)

    def export_ui(self):
        file_name = input("Introduceti numele fisierului: ")
        self.__service.export(file_name)
        print("Exportu a fost realizat cu succes")

    def run(self):
        while True:
            self.print_menu()
            cmd = input("Introduceti o comanda: ").strip()

            if cmd == '1':
                self.add_ui()

            elif cmd == '2':
                self.modify_ui()

            elif cmd == '3':
                self.random_ui()

            elif cmd == '4':
                self.export_ui()

            elif cmd == '5':
                self.print_list(self.__service.get_all())

            elif cmd == '6':
                break

            else:
                print("Comanda invalida")
