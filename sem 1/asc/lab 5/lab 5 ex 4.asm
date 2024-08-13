bits 32
global start
extern exit
import exit msvcrt.dll

segment data use32 class=data 
    s db 1,10,3,9
    f db 5,6, 7, 8
    l equ ($-s)/2
    d resb l
;Se dau doua siruri de octeti S1 si S2 de aceeasi lungime. Sa se construiasca sirul D astfel: fiecare element de pe pozitiile pare din D este suma elementelor de pe pozitiile corespunzatoare din S1 si S2, iar fiecare element de pe pozitiile impare are ca si valoare diferenta elementelor de pe pozitiile corespunzatoare din S1 si S2.
segment code use32 class=code
start:
    mov ecx, l
    mov esi, 0
    jecxz final

start_loop:
    mov bl, 2
    mov eax, esi
    div bl 
    cmp ah, 0
    jz par
    jmp impar

par:
    mov bl, [s + esi]
    add bl, [f + esi]
    jmp adaugare

impar:
    mov bl, [s + esi]
    sub bl, [f + esi]

adaugare:
    mov [d + esi], bl
    inc esi

    loop start_loop

final:
    push dword 0
    call [exit]