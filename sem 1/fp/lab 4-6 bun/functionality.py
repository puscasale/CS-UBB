from domain import *

def add_score(competitors, contest_nr, score):
    '''
    Adauga un participant
    :param competitors: lista de participanti
    :param contest_nr: numarul participantului introdus
    :param score: scorul participantului introdus
    :return: nothing
    '''
    competitor = create_competitor(contest_nr, score)
    competitors.append(competitor)

def add_insert_score(competitors,contest_nr, score):
    '''
    Insereaza un participant
    :param competitors: lista de participanti
    :param contest_nr: numarul participantului introdus
    :param score: scorul participantului introdus
    :return: nothing
    '''
    competitor = create_competitor(contest_nr, score)
    competitors.append(competitor)

def modify_del_one(competitors, id):
    '''
    Sterge scorul unui participant dat
    :param competitors: lista de participanti
    :param id: numarul participantului caruia i se sterge scorul
    :return: nothing
    '''
    #id = int(id)
    for competitor in competitors:
        if get_id(competitor) == id:
            set_score(competitor, 0)


def modify_del_interval(competitors, start, finish):
    '''
    Sterge scorul unui interval de participanti
    :param competitors: lista de participanti
    :param start: numarul primului participant caruia i se sterge scorul
    :param finish: numarul ultimului participant caruia i se sterge scorul
    :return: nothing
    '''
    start = int(start)
    finish = int(finish)
    for competitor in competitors:
        if get_id(competitor) >= start and get_id(competitor) <= finish:
            set_score(competitor, "0")


def modify_ins(competitors, id, score):
    '''
    Schimba scorul unui participant dat
    :param competitors: lista de participanti
    :param id: numarul participantului caruia i se schimba scorul
    :param score: noul scor
    :return: nothing
    '''
    score = int(score)
    id = int(id)
    for competitor in competitors:
        if get_id(competitor) == id:
            set_score(competitor, score)


def display_small(competitors, score):
    '''
    Tipareste participantii care au scorul mai mic decat un scor introdus
    :param competitors: lista de participanti
    :param score: scorul introdus
    :return: lista de particpanti cu scorul mai mic
    '''
    results = []
    score = int(score)
    for competitor in competitors:
        if get_score(competitor) < score:
            results.append(competitor)
    return results

def display_ord(cpmpetitors):
    '''
    Sorteaza lista in functie de scor
    :param cpmpetitors: lista de participanti
    :return: lista de participnati sortata in functie de scor
    '''
    #sorted_competitors = sorted(competitors, key=lambda x: x['contest_score'], reverse=True)
    sorted_competitors = sorted(competitors, key=lambda x: x[0], reverse=True)
    return sorted_competitors


def display_big(competitors, score):
    '''
    Sorteaza lista dupa scor, pentru participantii care au scorul mai mare decat un scor introdus
    :param competitors: lista de participanti
    :param score: scorul introdus
    :return: lista de partcipanti sortata
    '''
    result = []
    score = int(score)
    for competitor in competitors:
        if get_score(competitor) > score:
            result.append(competitor)
    #sorted_competitors = sorted(result, key=lambda x: x['contest_score'], reverse=True)
    sorted_competitors = sorted(competitors, key=lambda x: x[0], reverse=True)
    return sorted_competitors

def operation_calc_average(competitors, start, finish):
    '''
    Calculeaza media unui subset de participanti
    :param competitors: lisa de participanti
    :param start: numarul primului participant
    :param finish: numarul ultimului participant
    :return: media subsetului de participanti
    '''
    sum = 0
    cnt = 0
    start = int(start)
    finish = int(finish)
    for competitor in competitors:
        if get_id(competitor) >= start and get_id(competitor) <= finish:
            sum += get_score(competitor)
            cnt += 1
    return sum// cnt

def operation_calc_min(competitors, start, finish):
    '''
    Calculeaz minimul unui subset de participanti
    :param competitors: lista de participanti
    :param start: numarul primului participant
    :param finish: numarul ultimului participant
    :return: minimul
    '''
    Min = 101
    start = int(start)
    finish =int(finish)
    for competitor in competitors:
        if get_id(competitor) >= start and get_id(competitor) <= finish:
            if get_score(competitor) <= Min:
                Min = get_score(competitor)
    for competitor in competitors:
        if get_score(competitor) == Min:
            return competitor

def operation_tip(competitors, start, finish):
    '''
    Tipareste subsetul de participanti care au scorul multiplu de 10
    :param competitors: lista de participanti
    :param start: numarul primului participant
    :param finish: numarul ultimului participant
    :return: lista de participanti care indeplinesc criteriile
    '''
    result = []
    start = int(start)
    finish = int(finish)
    for competitor in competitors:
        if get_id(competitor) >= start and get_id(competitor) <= finish:
            if get_score(competitor) % 10 == 0:
                result.append(competitor)
    return result


def filter_multiple(competitor, number):
    '''
    Filtreaza participantii care au scorul multiplu unui numar introdus
    :param competitor: lista de participanti
    :param number: numarul introdus
    :return: lisat de participanti care indeplinesc criteriile
    '''
    result = []
    number = int(number)
    for competitor in competitors:
        if get_score(competitor) % number == 0:
            result.append(competitor)
    return result


def filter_small(competitor, score):
    '''
    Filtreaza participantii care au scorul mai mic decat un scor introdus
    :param competitor: lista de participanti
    :param score: scorul introdus
    :return: lisat de participanti care indeplinesc criteriile
    '''
    results = []
    score = int(score)
    for competitor in competitors:
        if get_score(competitor) < score:
            results.append(competitor)
    return results

def copy_competitors(competitors):
    '''
    Copieaza lista de participanti
    :param competitors: lisa de participanti
    :return: lista de participanti copiata
    '''
    result =[]
    for competitor in competitors:
        result.append(create_competitor(get_id(competitor), get_score(competitor)))
    return result

def register_for_undo(undo_list, current_competitors):
    undo_list.append(copy_competitors(current_competitors))

def pop_undo_list(undo_list, competitors):
    if undo_list:
        state = undo_list.pop()
        competitors.clear()
        competitors.extend(state)
        return competitors
    else:
        print("Nu exista nicio actiune pentru undo")
        return competitors
"""
def pop_undo_list(undo_list):
    if not undo_list:
        raise ValueError("Undo nu se poate realiza")
    return undo_list.pop()



def test_add_score():
    competitors = []
    add_score(competitors, 2, 45)
    assert competitors[0] == {'competitor_nr': 2, 'contest_score': 45}
    assert len(competitors) == 1
    add_score(competitors, 1, 34)
    assert get_score(competitors[1]) == 34
    assert len(competitors) == 2


def test_modify_ins():
    competitors = []
    add_score(competitors, 1, 34)
    add_score(competitors, 2, 45)
    add_score(competitors, 3, 64)
    modify_ins(competitors, 2, 50)
    assert get_score(competitors[1]) == 50


def test_modify_del_one():
    competitors = []
    add_score(competitors, 1, 34)
    add_score(competitors, 2, 45)
    add_score(competitors, 3, 64)
    modify_del_one(competitors, 2)
    assert get_score(competitors[1]) == "0"


def test_modify_del_interval():
    competitors = []
    add_score(competitors, 1, 34)
    add_score(competitors, 2, 45)
    add_score(competitors, 3, 64)
    modify_del_interval(competitors, 2, 3)
    assert competitors == [{'competitor_nr': 1, 'contest_score': 34}, {'competitor_nr': 2, 'contest_score': 0},
                           {'competitor_nr': 3, 'contest_score': 0}]


def test_filter_small():
    competitors_list = [{'competitor_nr': 1, 'contest_score': 12}, {'competitor_nr': 2, 'contest_score': 2},
                        {'competitor_nr': 3, 'contest_score': 9}]
    assert filter_small(competitors_list, 10) == [{'competitor_nr': 2, 'contest_score': 2},
                                                  {'competitor_nr': 3, 'contest_score': 9}]


def test_display_ord():
    # competitors_list = [[1, 12], [2, 2], [3, 9]]
    competitors_list = [{'competitor_nr': 1, 'contest_score': 12}, {'competitor_nr': 2, 'contest_score': 2},
                        {'competitor_nr': 3, 'contest_score': 9}]
    assert display_ord(competitors_list) == [{'competitor_nr': 1, 'contest_score': 12},
                                                      {'competitor_nr': 3, 'contest_score': 9},
                                                      {'competitor_nr': 2, 'contest_score': 2}]


def test_display_big():
    competitors_list = [{'competitor_nr': 1, 'contest_score': 12}, {'competitor_nr': 2, 'contest_score': 2},
                        {'competitor_nr': 3, 'contest_score': 9}, {'competitor_nr': 4, 'contest_score': 37}]
    assert display_big(competitors_list, 10) == [{'competitor_nr': 4, 'contest_score': 37},
                                                 {'competitor_nr': 1, 'contest_score': 12}]


def test_operation_calc_average():
    competitors_list = [{'competitor_nr': 1, 'contest_score': 12}, {'competitor_nr': 2, 'contest_score': 2},
                        {'competitor_nr': 3, 'contest_score': 8}, {'competitor_nr': 4, 'contest_score': 8}]
    assert operation_calc_average(competitors_list, 2, 3) == 5
    assert operation_calc_average(competitors_list, 3, 4) == 8


def test_operation_calc_min():
    competitors_list = [{'competitor_nr': 1, 'contest_score': 12}, {'competitor_nr': 2, 'contest_score': 2},
                        {'competitor_nr': 3, 'contest_score': 8}, {'competitor_nr': 4, 'contest_score': 8}]
    assert operation_calc_min(competitors_list, 1, 3) == {'competitor_nr': 2, 'contest_score': 2}


def test_operation_tip():
    competitors_list = [{'competitor_nr': 1, 'contest_score': 12}, {'competitor_nr': 2, 'contest_score': 20},
                        {'competitor_nr': 3, 'contest_score': 8}, {'competitor_nr': 4, 'contest_score': 80}]
    assert operation_tip(competitors_list, 2, 4) == [{'competitor_nr': 2, 'contest_score': 20},
                                                       {'competitor_nr': 4, 'contest_score': 80}]


def test_filter_multiple():
    competitors_list = [{'competitor_nr': 1, 'contest_score': 12}, {'competitor_nr': 2, 'contest_score': 20},
                        {'competitor_nr': 3, 'contest_score': 8}, {'competitor_nr': 4, 'contest_score': 80}]
    assert filter_multiple(competitors_list, 10) == [{'competitor_nr': 2, 'contest_score': 20},
                                                     {'competitor_nr': 4, 'contest_score': 80}]


def test_add_score():
    competitors = []
    add_score(competitors, 2, 45)
    assert competitors[0] == [2, 45]
    assert len(competitors) == 1
    add_score(competitors, 1, 34)
    assert get_score(competitors[1]) == 34
    assert len(competitors) == 2

def test_modify_ins():
    competitors = []
    add_score(competitors, 1, 34)
    add_score(competitors, 2, 45)
    add_score(competitors, 3, 64)
    modify_ins(competitors, 2, 50)
    assert get_score(competitors[1]) == 50

def test_modify_del_one():
    competitors = []
    add_score(competitors, 1, 34)
    add_score(competitors, 2, 45)
    add_score(competitors, 3, 64)
    modify_del_one(competitors, 2)
    assert get_score(competitors[1]) == "0"

def test_modify_del_interval():
    competitors = []
    add_score(competitors, 1, 34)
    add_score(competitors, 2, 45)
    add_score(competitors, 3, 64)
    modify_del_one(competitors, 2, 3)
    assert competitors == [[1, 34], [2, 0], [3, 0]]

def test_filter_small():
    competitors_list = [[1, 12], [2, 2], [3, 9]]
    assert filter_small(competitors_list, 10) == [[2, 2], [3, 9]]
    
def test_display_big():
    competitors_list = [[1, 12], [2, 2], [3, 9], [4, 37]]
    assert display_big(competitors_list, 10) == [[4, 37], [1, 12]]

def test_display_ord():
    competitors_list = [[1, 12], [2, 2], [3, 9]]
    assert display_ord(competitors_list) == [[1, 12], [3, 9], [2, 2]]
   

def test_operation_calc_average():
    competitors_list = [[1, 12], [2, 2], [3, 8], [4, 8]]
    assert operation_calc_average(competitors_list, 2, 3) == 5
    assert operation_calc_average(competitors_list, 3, 4) == 8
    
def test_operation_calc_min():
    competitors_list = [[1, 12], [2, 2], [3, 8], [4, 8]]
    assert operation_calc_min(competitors_list, 1, 3) == [2, 2]
    
def test_operation_tip():
    competitors_list = [[1, 12], [2, 20], [3, 8], [4, 80]]
    assert operation_tip(competitors_list, 2, 4) == [[2, 20], [4, 80]]
    
def test_filter_multiple():
    competitors_list = [[1, 12], [2, 20], [3, 8], [4, 80]]
    assert filter_multiple(competitors_list, 10) == [[2, 20], [4, 80]]
    
 
if __name__ == "__main__":
 test_add_score()
 test_modify_ins()
 test_modify_del_one()
 test_modify_del_interval()
 test_filter_small()
 test_display_ord()
 test_display_big()
 test_operation_calc_average()
 test_operation_calc_min()
 test_operation_tip()
 test_filter_multiple()
 """