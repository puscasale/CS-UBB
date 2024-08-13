bits 32

global start

extern exit

import exit msvcrt.dll

segment data use32 class=data
 
    a db 2
    b dw 7
    c dd 4
    d dq 20
  ; d-(a+b+c)-(a+a)
  ; cu semn
 
 segment code use32 class=code
start:
   
   ;a + b 
   mov al, [a]
   cbw ; ax = a
   add ax, [b]; ax = a + b
   
   ;a + b + c 
   cwde; eax = a + b
   add eax, [c]; eax = a + b + c
   
   ;d - (a + b + c)
   cdq; edx:eax = a + b + c
   mov ebx, dword [d + 0]
   mov ecx, dword [d + 4]; ecx:ebx = d
   clc
   sub ebx, eax 
   sbb ecx, edx; ecx:edx = d-(a+b+c)
   
   ; a + a 
   mov al, [a]
   add al, [a]; al = a + a 
   cbw; ax = a + a 
   cwde; eax = a + a 
   cdq; edx:eax = a + a 
   clc 
   sub ebx, eax 
   sbb ecx, edx; ecx:edx = d-(a+b+c)-(a+a)
   

   
   
push dword 0
call [exit]