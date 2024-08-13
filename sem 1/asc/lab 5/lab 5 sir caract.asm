bits 32
global start
extern exit
import exit msvcrt.dll

segment data use32 class=data 
    s db 'a', 'B', 'C', 'd'; declaram sirul
    l equ $-s ; calculam lungimea
    d rezb l
segment code use32 class=code
start:

    mov ecx, l 
    mov esi, 0; index
    jecxz final
    inceput_loop:
        mov al, [s+esi]
        cmp al, 'Z'
        jbe pune
        ja transforma
    transforma: 
    sub al, 'a'-'A'; din lit mica in litera mare
          
    pune: 
       mov[d+esi], al
    inc esi; 
    loop inceput_loop 
    final:
    
push dword 0
call [exit]

    