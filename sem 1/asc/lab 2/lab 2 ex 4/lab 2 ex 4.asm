bits 32

global start

extern exit

import exit msvcrt.dll

segment data use32 class=data

a db 2
b db 4
d dw 3
;  2*(b-1)–a*a  – d
segment code use32 class=code
start:
  mov bx, [a] ; bx = a
  mov ax, [a] ; ax = a 
  mul bx ; ax = a*a  
  mov bx, ax ; bx = a*a
  mov ax, 2 ; ax = 2
  mov dx, [b] ; dx = b 
  sub dx , 1; dx = b - 1
  mul dx; ax = 2*(b -1)
  sub ax, bx; ax = 2*(b-1)-a*a 
  sub ax, [d]; ax = 2*(b-1)-a*a-d
  
   
    

push dword 0
call [exit]