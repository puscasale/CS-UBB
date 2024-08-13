bits 32
global start
extern exit
import exit msvcrt.dll

segment data use32 class=data 
    ;nr pare dublate si cale impare triplate
    s db 1,2,3,4,5,6
    l equ $-s ; calculam lungimea
    d rezb l
segment code use32 class=code
start:
    mov ecx, l
    jecxz final
    mov esi, 0
    start_loop:
    
       mov al, [s+esi]
       cbw
       mov bl, 2
       idiv bc; ah = [s+esi]%2
       cmp ah, 0
       je dublare
       jne triplare
       
       dublare:
          mov al, [s+esi]
          add al, [s+esi]
          jmp adaugare
          
        triplare:
          mov al, [s+esi]
          add al, [s+esi]
          add al, [s+esi]
          
        adaugare:
          mov [d+esi], al
        inc esi  
    loop start_loop
    final:
    
    
push dword 0
call [exit]

    