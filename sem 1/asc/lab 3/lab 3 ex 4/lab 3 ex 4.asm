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
  ; cu semn
 
 segment code use32 class=code
start:

    ; b*b 
    mov bl, [b]
    mov al, [b]
    cbw; ax = b
    imul bl;  ax = b * b 
    mov bx, ax; bx = b * b
    
    ;b/c 
    mov al, [b]
    cbw; ax = b
    mov cl, [c]
    idiv cl; al = b / c
    cbw; ax = b / c
    
    ;(2-b*b+b/c)
    mov cx, 2
    sub cx, bx; cx = 2 - b * b 
    add cx, ax; cx = 2 - b * b + b / c
    
    
    ;a + b
    mov al, [b]
    cbw;  ax = b 
    cwd; dx:ax = b
    add eax, [a]; eax = a + b
    
    ;(a+b)/(2-b*b+b/c)
    idiv cx; ax = (a+b)/(2-b*b+b/c)
    cwde; eax = (a+b)/(2-b*b+b/c)
    
    ;(a+b)/(2-b*b+b/c)-x
    cdq; edx:eax = (a+b)/(2-b*b+b/c)
    mov ebx, dword[x + 0]
    mov ecx, dword[x + 4]; ecx:ebx = x
    clc 
    sub eax, ebx 
    sbb edx, ecx; ecx:ebx = (a+b)/(2-b*b+b/c)-x

push dword 0
call [exit]