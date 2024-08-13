bits 32
global start
extern exit, printf, scanf
import exit msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll

segment data use32 class=data 
    a dd 0
    b dd 0
    rezultat resd 1
    mesaj_a db "a = ", 0
    mesaj_b db "b = ", 0
    format db "%d", 0
    
    
;Sa se citeasca de la tastatura doua numere a si b (in baza 10) si sa se calculeze: (a+b) * (a-b). Rezultatul inmultirii se va salva in memorie in variabila "rezultat" (definita in segmentul de date).
segment code use32 class=code
start:
   
        push dword mesaj_a
        call [printf]
        add esp, 4*1
        
        push dword a
        push dword format
        call [scanf]
        add esp, 4*2
        
        push dword mesaj_b
        call [printf]
        add esp, 4*1
        
        push dword b
        push dword format
        call [scanf]
        add esp, 4*2
        
        mov eax, [a]
        mov edx, 0
        mov ebx, [b]
        idiv ebx
        mov [rezultat], eax
final: 
push dword 0
call [exit]
