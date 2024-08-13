bits 32

global start

extern exit

import exit msvcrt.dll

segment data use32 class=data

a db 9
b db 4
c db 2
; (a-c)*3+b*b

segment code use32 class=code
start:

    mov bl, [a];   bl=a
    sub bl, [c];   bl=a-c
    mov ax, 3;   ax=3
    mul bl;   ax=(a-c)*3
    mov cl, al;   cx=3*(a-c)
    mov ax, [b]; ax=b
    mov bl, [b]; bx=b
    mul bl; al=b*b
    add cl,al;  cx=3*(a-c)+b*b
    

push dword 0
call [exit]