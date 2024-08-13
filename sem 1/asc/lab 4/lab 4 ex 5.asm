bits 32

global start

extern exit

import exit msvcrt.dll

segment data use32 class=data
    a db 10100110b
    b db 00001011b
    c resd 1
;Se dau octetii A si B. Sa se obtina dublucuvantul C
;bitii 16-31 ai lui C sunt 1
;bitii 0-3 ai lui C coincid cu bitii 3-6 ai lui B
;bitii 4-7 ai lui C au valoarea 0
;bitii 8-10 ai lui C au valoarea 110
;bitii 11-15 ai lui C coincid cu bitii 0-4 ai lui A
 segment code use32 class=code
start:
    
    ;bitii 16-31 ai lui C sunt 1
    mov bx, 0
    or bx, 1111111111111111b; bx = 1111 1111 1111 1111b = FFFFh
    
    ;bitii 0-3 ai lui C coincid cu bitii 3-6 ai lui B
    mov ax, 0
    mov dl, [b]
    mov dh, 0; dx = b
    and dx, 0000000001111000b; dx = 0000 0000 0000 1000b = 0008h
    shr dx,3; dx = 0000 0000 0000 0001b = 0001h
    or ax, dx; ax = 0000 0000 0000 0001b = 0001h
    
    ;bitii 4-7 ai lui C au valoarea 0
    and ax, 1111111100001111b; ax = 0000 0000 0000 0001b = 0001h
    
    ;bitii 8-10 ai lui C au valoarea 110
    or ax, 0000011000000000b ; ax = 0000 0110 0000 0001b = 0601h
    
    ;bitii 11-15 ai lui C coincid cu bitii 0-4 ai lui A
    mov cl, [a]
    mov ch, 0; cx = a
    and cx, 0000000000011111b; cx = 0000 0000 0000 0110b= 0006h
    shl cx,11 ; cx = 0011 0000 0000 0000b = 3000h 
    or ax, cx; ax = 0011 0110 0000 0001b = 3601h
    mov [c], ax
    mov [c+4], bx; c = 1111 1111 1111 1111 0011 0000 0000 0001b = FFFF3601h
    
push dword 0
call [exit]