bits 32

global start

extern exit

import exit msvcrt.dll

segment data use32 class=data
    s dd 127F5678h, 0ABCDABCDh
    b resd 1
    l equ ($-s)/4
    s_par dw 0
    s_impar dw 0
    aux dd 0
segment code use32 class=code
   start:
        mov ecx, 4
        mov esi, s
        mov edi, b
        mov ecx, l
        parcuge:
          mov [aux], ecx
          mov ax, 0
          mov [s_impar], ax
          mov [s_par], ax
          
        formare:
          mov al, cl
          cbw
          mov bl, 2
          idiv bl; al = cl/2 ah = cl%2
          cmp ah, 0
          je aduna_par
          jne aduna_impar
          
          aduna_par:
           lodsb; al = byte din sir
           cbw
           add [s_par}, ax
           jmp gata
          
          aduna_impar:
           lodsb; al = byte din sir
           cbw
           add [s_impar], ax
           
          gata: 
           loop gata ; ecx = ecx - 1
           mov edi, b
           mov ax, [s_par]
           stosw; [edi] = ax, edi = edi + 2
           mov ax, [s_impar]
           stosw
           mov ecx, [aux]
         loop parcurge
    
    ; 10, 20
push dword 0
call [exit]