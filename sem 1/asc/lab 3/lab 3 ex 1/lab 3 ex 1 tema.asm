bits 32

global start

extern exit

import exit msvcrt.dll

segment data use32 class=data
 
 a db 3
 b dw 5
 c dd 2
 d dq 16
 ; (d-c)+(b-a)-(b+b+b)
 ; fara semn
 
 segment code use32 class=code
start:

   ;d-c
   mov eax, [c]
   mov edx, 0; edx:eax = c 
   mov ebx,dword [d + 0]
   mov ecx,dword [d + 4] ; ecx:ebx = d 
   
   clc
   sub ebx, eax
   sbb ecx, edx; ecx:ebx = d - c
   
   ;b-a 
   mov al, [a]
   mov ah, 0 ; ax = a
   mov dx, [b]; 
   sub dx, ax; dx = b - a 
   
   ;(d-c)+(b-a)
   mov eax, 0
   mov ax, dx; eax = b - a
   mov edx, 0; edx:eax = b - a 
   
   clc 
   add ebx, eax 
   adc ecx, edx; ecx:ebx = (d-c)+(b-a)
   
   ;b+b+b 
   mov dx, [b]
   add dx, [b]
   add dx, [b] ;dx = b + b + b 
   
   ;(d-c)+(b-a)-(b+b+b)
   mov eax, 0
   mov ax, dx; eax = b + b + b 
   mov edx, 0; edx:eax = b + b + b 
   
   clc 
   sub ebx, eax
   sbb ecx, edx; ecx:ebx = (d-c)+(b-a)-(b+b+b)
   
push dword 0
call [exit]