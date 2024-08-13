bits 32

global start

extern exit

import exit msvcrt.dll

segment data use32 class=data

a db 5
b db 6
; 5-6
segment code use32 class=code
start:

    mov al, [a]; al=a 
    mov bl, [b]; bl=b
    sub al, bl; al=a-b

push dword 0
call [exit]