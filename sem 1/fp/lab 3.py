def print_menu():
    print("1.Citire lista")
    print("2.Gasirea segmentelot de lungime maxima cu proprietatea 15\n 3.Gasirea segmentelor de lungime maxima cu proprietatea 16")
    print("4.Iesire")

def read_list():
    lista = input("Introduceti taskurile dvs:\n") 
    taskuri = lista.split(',')
    return taskuri
lista_proprietati = []
v = []
def max_16():
    for i in range (1,len(list),+1):
        
        while aux != 0:
            v[aux%10] = 1
            aux = aux/10
        bux = list[i+1]
        
                   
while True:
    print_menu()
    optiune = int(input("Ce optiune alegeti?\n"))

    if optiune == 1:
        lista_proprietati = read_list()
        print("Lista de numere este", lista_proprietati)

    if optiune == 4:
        break



