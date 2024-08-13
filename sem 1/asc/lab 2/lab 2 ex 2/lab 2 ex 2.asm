bits 32

global start

extern exit

import exit msvcrt.dll

segment data use32 class=data

a db 9
b db 3
c db 13
d db 5
; (a-b)+(c-b-d)+d
segment code use32 class=code
start:

    mov al, [a]; al=a
    mov bl, [b]; bl=b 
    sub al, bl; al=a-b 
    mov cl, [c]; cl=c 
    mov dl, [d]; dl=d 
    sub cl, bl; cl=c-b 
    sub cl, dl; cl=c-b-d 
    add al, cl; al=(a-b)+(c-b-d)
    add al, dl; al=(a-b)+(c-b-d)+d

push dword 0
call [exit]