bits 32

global start

extern exit

import exit msvcrt.dll

segment data use32 class=data

a dw 4
b dw 12
c dw 5
d dw 2
; (b+b)-c-(a+d)
segment code use32 class=code
start:

    mov bx, [b] ;bx=b 
    add bx, [b]; bx=b+b 
    mov ax, [a]; ax=a
    add ax, [d]; ax=a+d 
    sub bx, [c]; bx= (b+b)-c
    sub bx, ax; bx= (b+b)-c-(a+d)
    

push dword 0
call [exit]