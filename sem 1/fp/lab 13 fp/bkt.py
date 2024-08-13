"""
Se da o lista de numere intregi.
Generati toate permutarile listei pentru care numerele au aspect de munte.
"""


def is_mountain(elements):
    if not elements:
        return False

    varf = elements.index(max(elements))

    for i in range(varf):
        if elements[i] >= elements[i + 1]:
            return False

    if varf >= len(elements) - 1 or varf == 0:
        return False

    if varf < len(elements) - 1:
        for i in range(varf, len(elements) - 1):
            if elements[i] <= elements[i + 1]:
                return False

    return True


def back_recursive(list, perm, used, result):
    if not list:
        return False

    if len(perm) == len(list):
        if is_mountain(perm):
            result.append(perm[:])
        return

    n = len(list)
    for i in range(n):
        if not used[i]:
            used[i] = True
            perm.append(list[i])
            back_recursive(list, perm, used, result)
            perm.pop()
            used[i] = False


def test_recursive():
    result = []
    back_recursive([1, 2, 3], [], [False] * 3, result)
    assert result == [[1, 3, 2], [2, 3, 1]]

    result = []
    back_recursive([1, 2, 3, 4], [], [False] * 4, result)
    assert result == [[1, 2, 4, 3], [1, 3, 4, 2], [1, 4, 3, 2], [2, 3, 4, 1], [2, 4, 3, 1], [3, 4, 2, 1]]


def back_iterative(list):
    if not list:
        return False

    n = len(list)
    result = []
    stack = [(list, [])]

    while stack:
        arr, perm = stack.pop()
        if len(perm) == n:
            if is_mountain(perm):
                result.append(perm)
        else:
            for i in range(len(arr)):
                perm_next = perm + [arr[i]]
                arr_next = arr[:i] + arr[i + 1:]
                stack.append((arr_next, perm_next))

    return result[::-1]


def test_iterative():
    result = back_iterative([1, 2, 3])
    assert result == [[1, 3, 2], [2, 3, 1]]

    result = back_iterative([1, 2, 3, 4])
    assert result == [[1, 2, 4, 3], [1, 3, 4, 2], [1, 4, 3, 2], [2, 3, 4, 1], [2, 4, 3, 1], [3, 4, 2, 1]]


if __name__ == "__main__":
    test_recursive()
    test_iterative()

    lista = [1, 2, 3, 5, 6]
    result = []
    back_recursive(lista, [], [False] * len(lista), result)
    #result = back_iterative(lista)

    for perm in result:
        print(perm)


