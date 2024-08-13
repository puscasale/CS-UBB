from functionality import *
import textwrap

def print_comp_menu():
    print(textwrap.dedent(""" 
    Participanti

    Optiuni:
        1. Vizualizare participanti
        2. Mergi inapoi
    """))

def print_add_menu():
    print(textwrap.dedent("""
    Adaugă un scor la un participant

    Optiuni:
        1. Adaugă scor pentru un nou participant (ultimul participant)
        2. Inserare scor pentru un participant
        3. Mergi inapoi
        4. Undo
    """))

def print_modify_menu():
    print(textwrap.dedent("""
    Modificare scor

    Optiuni:
        1. Șterge scorul pentru un participant dat
        2. Șterge scorul pentru un interval de participanți
        3. Înlocuiește scorul de la un participant
        4. Mergi inapoi
        5. Undo
    """))

def print_display_menu():
    print(textwrap.dedent("""
    Tipărește lista de participanți

    Optinui:
        1. Tipărește participanții care au scor mai mic decât un scor dat
        2. Tipărește participanții ordonat după scor
        3. Tipărește participanții cu scor mai mare decât un scor dat, ordonat după scor
        4. Mergi inapoi
    """))

def print_operation_menu():
    print(textwrap.dedent("""
    Operații pe un subset de participanți

    Optiuni:
        1. Calculează media scorurilor pentru un interval dat 
        2. Calculează scorul minim pentru un interval de participanți dat
        3. Tipărește participanții dintr-un interval dat care au scorul multiplu de 10
        4. Mergi inapoi
    """))

def print_filter_menu():
    print(textwrap.dedent("""
    Filtrare

    Optiuni: 
        1. Filtrare participanți care au scorul multiplu unui număr dat
        2. Filtrare participanți care au scorul mai mic decât un scor dat
        3. Mergi inapoi
    """))

def print_main_menu():
    print(textwrap.dedent("""
    Competitie

    Optiuni:
        0. Participanti
        1. Adaugă un scor la un participant
        2. Modificare scor
        3. Tipărește lista de participanți
        4. Operații pe un subset de participanți
        5. Filtrare
    """))

def read_valid_number(message: str):
    while True:
        try:
            user_input = input(message).strip()
            user_input = int(user_input)
            return user_input
        except ValueError:
            print("Valoare invalida. Introduceti din nou")

def read_valid_id(competitors, message: str):
    while True:
        number = read_valid_number(message)
        sw = False
        for competitor in competitors:
            if get_id(competitor) == number:
                sw = True
        if sw == True and len(competitors) > 0:
            print(f"Participantul cu numarul {number} a fost deja introdus")
        else:
            return int(number)

def valid_id(competitors, message: str):
    while True:
        number = read_valid_number(message)
        sw = False
        for competitor in competitors:
            if get_id(competitor) == number:
                sw = True
        if sw == False:
            print(f"Participantul cu numarul {number} nu exista")
        else:
            return int(number)

def read_valid_score(message: str):
    score = input(message).strip()
    if not score.isdigit():
        print("Eroare: Valoarea introdusa trebuie sa fie un numar natural mai mic decat sau egal decat 10")
        return read_valid_score(message)
    else:
        score = int(score)
        if score > 10:
            print("Eroare: Valoarea introduse trebuie sa fie mai mica sau egala cu 10")
            return read_valid_score(message)
    return int(score)

def option_valid(message: str):
    while True:
        try:
            option = input(message).strip()
            if not option.isdigit():
                raise ValueError("Valoarea introdusa trebuie sa fie un numar natural")
            return int(option)
        except ValueError as error:
            print(error)


def comp_view(competitors):
    for competitor in competitors:
        print(f"Participant: {get_id(competitor)} - Scorul: {get_score(competitor)}")

def option_main_menu():
    while True:
        user_input = option_valid("Alege o optiune: ")
        if user_input == 0:
            comp_menu(competitors)
            break
        elif user_input == 1:
            add_menu(competitors)
            break
        elif user_input == 2:
            modify_menu(competitors)
            break
        elif user_input == 3:
            display_menu(competitors)
            break
        elif user_input == 4:
            operation_menu(competitors)
            break
        elif user_input == 5:
            filter_menu(competitors)
            break
        else:
            print("Optiunea trebuie sa fie un numar intre 0 si 5")

def option_filter_menu(competitors):
    while True:
        user_input = input("Alege o optiune: ").strip()
        if user_input == "1":
            number = input("Introduceti numarul: ")
            result = []
            result = filter_multiple(competitors, number)
            print("Lista a fost filtrata")
            comp_view(result)

        elif user_input == "2":
            score = input("Introduceti scorul de filtrare: ")
            result = []
            result = filter_small(competitors, score)
            print("Lista a fost filtrata")
            comp_view(result)

        elif user_input == "3":
            main_menu()
            break
        else:
            print("Optiunea trebuie sa fie un numar intre 1 si 3")

def option_add_menu(competitors):
    undo_list = []
    while True:
        user_input = option_valid("Alege o optiune: ")
        if user_input == 1:
            register_for_undo(undo_list, competitors)
            id = read_valid_id(competitors, "Introduceti  numarul participantului: ")
            sum = 0
            cnt = 1
            while cnt <= 10:
                score = read_valid_score(f"Introduceti scorul la proba {cnt}: ")
                sum += score
                cnt +=1
            add_score(competitors, id, sum//10)

        elif user_input == 2:
            register_for_undo(undo_list, competitors)
            id = read_valid_id(competitors, "Introduceti  numarul participantului: ")
            sum = 0
            cnt = 1
            while cnt <= 10:
                score = read_valid_score(f"Introduceti scorul la proba {cnt}: ")
                sum += score
                cnt += 1
            add_insert_score(competitors, id, sum // 10)

        elif user_input == 3:
            main_menu()
            break
        elif user_input == 4:
            competitors = pop_undo_list(undo_list, competitors)
            print("Undo a fost realizat")
        else:
            print("Optiunea trebuie sa fie un numar intre 1 si 4")

def option_modify_menu(competitors):
    undo_list = []
    while True:
        user_input = option_valid("Alege o optiune: ")
        if user_input == 1:
            register_for_undo(undo_list, competitors)
            id = valid_id(competitors, "Introduceti un id: ")
            print("Scorul participantului a fost sters")
            modify_del_one(competitors, id)

        elif user_input == 2:
            register_for_undo(undo_list, competitors)
            start = valid_id(competitors, "Introduceti id1: ")
            finish = valid_id(competitors, "Introduceti id2: ")
            print("Scorurile sau fost sterse")
            modify_del_interval(competitors, start, finish)

        elif user_input == 3:
            register_for_undo(undo_list, competitors)
            id = valid_id(competitors, "Introduceti id: ")
            score = read_valid_score("Introduceti noul scor: ")
            print("Scorul a fost modificat")
            modify_ins(competitors, id, score)

        elif user_input == 4:
            main_menu()

        elif user_input == 5:
            competitors = pop_undo_list(undo_list, competitors)
            print("Undo a fost realizat")

        else:
            print("Optiunea trebuie sa fie un numar intre 1 si 5")
def option_display_menu(competitors):
    while True:
        user_input = option_valid("Alege o optiune: ")
        if user_input == 1:
            score = read_valid_score("Introduceti scorul: ")
            result = []
            result = display_small(competitors, score)
            comp_view(result)

        elif user_input == 2:
            result = []
            result = display_ord(competitors)
            comp_view(result)

        elif user_input == 3:
            score = read_valid_score("Introduceti un scor: ")
            result = []
            result = display_big(competitors, score)
            comp_view(result)

        elif user_input == 4:
            main_menu()
            break
        else:
            print("Optiunea trebuie sa fie un numar intre 1 si 4")


def option_operation_menu(competitors):
    while True:
        user_input = option_valid("Alege o optiune: ")
        if user_input == 1:
            start = valid_id(competitors, "Introdueti id primului participant: ")
            finish = valid_id(competitors, "Introduceti id ultimului participant: ")
            result = operation_calc_average(competitors, start, finish)
            print(f"Media scorurilor este: {result}")

        elif user_input == 2:
            start = valid_id(competitors, "Introdueti id primului participant: ")
            finish = valid_id(competitors, "Introduceti id ultimului participant: ")
            result = operation_calc_min(competitors, start, finish)
            print(f"Participantul cu scorul minim {get_score(result)} este {get_id(result)}")

        elif user_input == 3:
            result = []
            start = valid_id(competitors, "Introdueti id primului participant: ")
            finish = valid_id(competitors, "Introduceti id ultimului participant: ")
            result = operation_tip(competitors, start, finish)
            print("Participantii care corespund cerintei sunt: ")
            comp_view(result)

        elif user_input == 4:
            main_menu()
            break
        else:
            print("Optiunea trebuie sa fie un numar intre 1 si 4")


def option_comp_menu(competitors):
    while True:
        user_input = option_valid("Alege o optiune: ")
        if user_input == 1:
            comp_view(competitors)

        elif user_input == 2:
            main_menu()
            break
        else:
            print("Optiunea trebuie sa fie un numar intre 1 si 2")

def comp_menu(competitors):
    print_comp_menu()
    option_comp_menu(competitors)


def filter_menu(competitors):
    print_filter_menu()
    option_filter_menu(competitors)


def operation_menu(competitors):
    print_operation_menu()
    option_operation_menu(competitors)


def display_menu(competitors):
    print_display_menu()
    option_display_menu(competitors)


def modify_menu(competitors):
    print_modify_menu()
    option_modify_menu(competitors)


def add_menu(competitors):
    print_add_menu()
    option_add_menu(competitors)


def main_menu():
    print_main_menu()
    option_main_menu()
