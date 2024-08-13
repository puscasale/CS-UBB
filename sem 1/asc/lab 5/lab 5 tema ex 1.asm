bits 32
global start
extern exit
import exit msvcrt.dll

segment data use32 class=data 
    ;nr pare dublate si cele impare triplate
    s1 db 1, 2, 3, 4
    s2 db 5, 6, 7, 8
    l equ ($-s1) ; calculam lungimea
    d resb l
segment code use32 class=code
start:
   mov ecx, l
   jecxz final
   mov esi, 0
   
   start_loop:
   
     ;mov al, esi
     ;cbw
     mov bl, 2
     mov eax, esi
     idiv bl; ah = edi % 2
     cmp ah, 0
     je par
     jne impar 
     
     par:
      mov al, [s1 + esi]
      add al, [s2 + esi]
      jmp adaugare
      
     impar:
       mov al, [s1 + esi]
       sub al, [s2 + esi]
       
     adaugare:
       mov [d + esi], al 
       
     inc esi 
     
   loop start_loop
   
final: 
push dword 0
call [exit]
