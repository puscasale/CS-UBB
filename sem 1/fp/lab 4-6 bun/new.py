from functionality import *
from ui import comp_view
from domain import *


def add_competitor(params):
    if len(params) != 11:
        print("Nu sunt destule valori!")
        return

    contest_number = params[0]
    sw = False
    for competitor in competitors:
        if get_id(competitor) == contest_number:
            sw = True
    if sw == True and len(competitors) > 0:
        print(f"Participantul cu numarul {contest_number} a fost deja introdus...")
        return

    sum = 0
    for cnt in range(1, 11):
        if not params[cnt].isdigit():
            print("Valoare invalida.")
            return
        params[cnt] = int(params[cnt])
        if params[cnt] > 10 or params[cnt] < 1:
            print("Valoare invalida.")
            return
        sum += params[cnt]

    add_score(competitors, params[0], sum // 10)
    #comp_view(competitors)


def score_replacement(params):
    if len(params) != 11:
        print("Nu sunt destule valori!")
        return

    contest_number = params[0]
    sw = False
    for competitor in competitors:
        if get_id(competitor) == contest_number:
            sw = True
    if sw == False:
        print(f"Partcipantul cu numarul {contest_number} nu exista.")
        return

    sum = 0
    for cnt in range(1, 11):
        if not params[cnt].isdigit():
            print("Valoare invalida.")
            return
        params[cnt] = int(params[cnt])
        if params[cnt] > 10 or params[cnt] < 1:
            print("Valoare invalida.")
            return
        sum += params[cnt]

    for competitor in competitors:
        if get_id(competitor) == contest_number:
            set_score(competitor, sum // 10)
    comp_view(competitors)


def delete_score_competitor(params):
    if len(params) != 1:
        print("Nu sunt destule valori!")
        return

    id = params[0]
    sw = False
    for competitor in competitors:
        if get_id(competitor) == id:
            sw = True
    if sw == False:
        print(f"Partcipantul cu numarul {id} nu exista.")
        return
    modify_del_one(competitors, id)
    comp_view(competitors)


def filter_less(params):
    if len(params) != 1:
        print("Nu sunt destule valori!")
        return

    score = int(params[0])
    result = []
    result = filter_small(competitors, score)
    comp_view(result)


def print_list(params):
    if len(params) > 0:
        print("Nu sunt destule valori!")
        return
    comp_view(competitors)


def read_data():
    while True:
        option_list = {'adauga': add_competitor, 'modifica': score_replacement,
                       'sterge': delete_score_competitor, 'filtreaza': filter_less, 'afiseaza': print_list}

        statement = input("Introdu cererea: ").strip()
        statement = statement.lower()
        commands = statement.split(";")
        for command in commands:
            command = command.strip()
            command = command.split()
            if command[0] in option_list.keys():
                option_list[command[0]](command[1:])
            else:
                print("Comanda nu exista!")


read_data()