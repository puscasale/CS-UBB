bits 32

global start

extern exit

import exit msvcrt.dll

segment data use32 class=data
    a dq 0101101011101000100010001111011010100010101110100010100101001111b
    n resb 1
    b resb 4
    c db 0
 
;Se da quadwordul A. Sa se obtina numarul intreg N reprezentat de bitii 17-19 ai lui A. Sa se obtina apoi in B dublucuvantul rezultat prin rotirea spre stanga a dublucuvantului superior al lui A cu N pozitii. Sa se obtina octetul C astfel:
;bitii 0-2 ai lui C sunt bitii 9-11 ai lui B
;bitii 3-7 ai lui C sunt bitii 20-24 ai lui B

 segment code use32 class=code
start:
    
    ;bitii 17-19 ai lui A
    mov eax, [a+0]; eax = 1010 0010 1011 1010 0010 1001 0100 1111b = A2BA294Fh 
    and eax, 00000000000011100000000000000000b
    ror eax, 17; eax = 0000 0000 0000 0000 0000 0000 0000 0101b=00000005h 
    mov [n], al
    
    ;B dublucuvantul rezultat prin rotirea spre stanga a dublucuvantului superior al lui A cu N pozitii
    mov eax, [a+4]; eax = 0101 1010 1110 1000 1000 1000 1111 0110b = 5AE888F6h
    mov cl, [n]
    rol eax, cl; eax = 0101 1101 0001 0001 0001 1110 1100 1011b = 5D111ECBh
    mov [b], eax
    
    ;bitii 0-2 ai lui C sunt bitii 9-11 ai lui B
    mov eax, [b]
    and eax, 00000000000000000000111000000000b
    shr eax, 9 ; eax =  0000 0000 0000 0000 0000 0000 0000 0111b = 00000007h
    or [c], al
    
    ;bitii 3-7 ai lui C sunt bitii 20-24 ai lui B
    mov eax, [b]
    and eax, 00000001111100000000000000000000b
    ror eax, 17 ; eax = 0000 0000 0000 0000 0000 0000 1000 1000b= 00000088h
    or [c], al; 1000 1111b = 8Fh
    
    
push dword 0
call [exit]