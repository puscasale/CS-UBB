numar = int(input("Introduceti un numar:"))
def function_prim(numar):
    if numar<2:
        return False
    if numar==2:
        return True
    if numar%2==0:
        return False
    for i in range(3,numar,1):
        if numar%i==0:
            return False
    return True

ok=1
for divizor in range(numar-1,1,-1):
    if function_prim(divizor) == True:
        ok=0
        break

if ok == 1: 
    print("Nu exista un astfel de numar")
else: 
    print("Cel mai mare numar prim mai mic ca si", numar, "este", divizor)
    