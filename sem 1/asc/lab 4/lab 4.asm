bits 32

global start

extern exit

import exit msvcrt.dll

segment data use32 class=data
    a dw 1100001110100110b
    b dw 1111100000001011b
    c resw 1
 
 
 segment code use32 class=code
start:
    ;bitii 0-2 ai lui C coincid cu bitii 10-12 ai lui B
    mov ax, 0
    mov bx, [b]
    and bx, 0001110000000000b; bx = 000110...b
    shr bx, 10
    or ax, bx; ax = ...0110b = 006h
    
    ;bitii 3-6 ai lui C au valoarea 1
    mov bx, 0000000001111000b
    or ax, bx; ax = ....111 0b
    
    ;bitii 7-10 ai lui C coincid cu bitii 1-4 ai lui A
    mov bx, 0000000000011110b
    mov dx, [a]
    and dx, bx; dx =  00...00110b
    shl dx, 6; dx = 00...001100b
    or ax, dx; ax = rezultat partial
    
    ;bitii 11-12 ai lui C au valoarea 0
    and ax, 1110011111111111b
    
    ;bitii 13-15 ai lui C concid cu inverul bitilor 9-11 ai lui B
    mov dx, [b]
    not dx; inv b
    and dx, 0000111000000000b
    shl dx, 4
    or ax, dx 
    mov [c], 0;
    or [c], ax; sau mov [c], ax
    
    ;Tema 5, 28

push dword 0
call [exit]