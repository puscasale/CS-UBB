import sys

def print_menu():
    print( """
    1. Citirea unei liste de numere intregi
    2. Gasirea secventei de lungime maxima cu proprietatea ca reprezinta o secventa sub forma de munte
    3. Gasirea secventei de lungime maxima cu proprietatea ca scrierea lor in baza 10 folosesc aceleasi cifre
    4. GAsirea secventei de lungime maxima cu proprietatea ca x[i] < x[i+1] < ... < x[i+p]
    5. Iesire
         """ )
    
def read_list():
    raw_list = input("Introduce-ti lista: ")
    string_list = raw_list.split(' ')
    numbers = []
    for number in string_list:
        numbers.append(int(number))  
    print('Lista a fost citita')
    return numbers

def exitProgram():
    exit()

def strIncreasing (numbers):
    left = 0
    maxLen = 1
    maxLeft = 0
    maxRight = 0

    for right in range(1, len(numbers)):
        if numbers[right - 1] < numbers[right]:
            if (right - left + 1) > maxLen:
                maxLen = right - left + 1
                maxLeft = left 
                maxRight = right 
        else:
                left = right 
    return numbers[maxLeft : maxRight + 1]

def maxMountain(numbers):
    if len(numbers) < 3:
        return "Secventa de lungime maxima nu a fost gasita"
        sys.exit(0)
    right = 0
    left = 0
    maxRight = 0
    maxLeft = 0
    maxLen = 0

    while right < len(numbers) - 1:
        peak = right 

        while peak < len(numbers) - 1 and numbers[peak] < numbers[peak + 1]:
            peak += 1
        
        if right == peak:
            right = left = peak + 1
        else:
            m_end = peak
            while m_end < len(numbers) - 1 and numbers[m_end] > numbers[m_end + 1]:
                m_end += 1
            
            if m_end != peak:
                if (m_end - left + 1) > maxLen:
                    maxLen = m_end - left + 1
                    maxRight = m_end
                    maxLeft = left
            right = left = m_end

    if maxLen > 0:
        return numbers[maxLeft : maxRight + 1] 
    else: return "Lista nu a fost gasita"

def checkDigits(num1, num2):
    num1 = abs(num1)
    num2 = abs(num2)
    digits1 = set()
    digits2 = set()

    while num1 > 0:
        digits1.add(num1 % 10)
        num1 //= 10
    
    while num2 > 0:
        digits2.add(num2 % 10)
        num2 //= 10

    return digits1 == digits2

def sameDigits(numbers):
    left = 0
    maxLen = 1
    maxLeft = 0
    maxRight = 0

    for right in range (1, len(numbers)):
        if checkDigits(numbers[right], numbers[right - 1]) == False:
            left = right 
        if (right - left + 1) > maxLen:
            maxLen = right - left + 1
            maxLeft = left
            maxRight = right

    return numbers[maxLeft : maxRight + 1]

def test_maxMountain():
    assert maxMountain([1, 2, 3, 2, 1]) == [1, 2, 3, 2, 1]
    assert maxMountain([1, 2, 3, 2, 4, 5, 6, 4, 3]) == [2, 4, 5, 6, 4, 3]
    assert maxMountain([2, 3, 2, 3, 2]) == [2, 3, 2]

def test_sameDigits():
    assert sameDigits([123, 312, 3213, 112, 133]) == [123, 321, 3213]
    assert sameDigits([0, 0]) == [0, 0]
    assert sameDigits([2, 23, 234, 2345]) == [2]

def test_strIncreasing():
    assert strIncreasing([1, 3, 7, 2]) == [1, 3, 7]
    assert strIncreasing([9 , 8, 7, 6]) == [9]
    assert strIncreasing([5, 6, 7, 1, 2, 3, 4]) == [1, 2, 3, 4]

def main():
    
    test_maxMountain()
    test_sameDigits()
    test_strIncreasing()

    print_menu()

    numbers = None

    while True:
        optiune = int(input("Alege o optiune: "))
        if optiune == 1:
            numbers = read_list()
        elif optiune == 2 or optiune == 3 or optiune == 4:
            if numbers == None:
                print("Lista nu a fost citita")
                numbers = read_list()
            elif optiune == 2:
                f = maxMountain(numbers)
                print(f)
            elif optiune == 3:
               f =  sameDigits(numbers)
               print(f)
            elif optiune == 4:
                f = strIncreasing(numbers)
                print(f)
        elif optiune == 5:
            exitProgram()
        elif optiune < 0 or optiune > 5:
            print("Optiunea aleasa nu exista")

main ()