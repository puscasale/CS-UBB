bits 32

global start

extern exit

import exit msvcrt.dll

segment data use32 class=data
 
    b db 3
    c db 2
    a dd 9
    x dq 20
  ; (a+b)/(2-b*b+b/c)-x
  ; fara semn
 
 segment code use32 class=code
start:

    ; b*b 
    mov bl, [b]
    mov al, [b]
    mov ah, 0; ax = b 
    mul bl;  ax = b * b 
    mov bx, ax
    
    ;b/c 
    mov al, [b]
    mov ah, 0; ax = b 
    mov cl, [c]
    div cl; al = b / c
    
    ;(2-b*b+b/c)
    mov cx, 2
    sub cx, bx; cx = 2 - b * b 
    mov ah, 0; ax = b / c 
    add cx, ax; cx = 2 - b * b + b / c
    
    ;a + b
    mov bl, [b]
    mov bh, 0; bx = b 
    mov eax, 0
    mov ax, bx; eax = b 
    add eax, [a]; eax = a + b
    
    push eax
    pop ax
    pop dx
    
    ;(a+b)/(2-b*b+b/c)
    idiv cx; ax = (a+b)/(2-b*b+b/c) 
    mov bx, ax
    
    ;(a+b)/(2-b*b+b/c)-x
    mov eax, 0
    mov ax, bx; eax = (a+b)/(2-b*b+b/c)
    mov edx, 0; edx:eax = (a+b)/(2-b*b+b/c)
    mov ebx, dword[x + 0]
    mov ecx, dword[x + 4]; ecx:ebx = x
    clc 
    sub eax, ebx 
    sbb edx, ecx; ecx:ebx = (a+b)/(2-b*b+b/c)-x

push dword 0
call [exit]