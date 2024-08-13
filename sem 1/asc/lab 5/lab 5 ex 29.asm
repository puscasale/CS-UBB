bits 32
global start
extern exit
import exit msvcrt.dll

segment data use32 class=data 
    s db 1,2,3,4,5,6
    l equ ($-s)-1
    d resb l
;Se da un sir de octeti S. Sa se construiasca sirul D ale carui elemente reprezinta suma fiecaror doi octeti consecutivi din sirul S
segment code use32 class=code
start:
    mov ecx, l
    mov esi, 0
    jecxz final

start_loop:
    mov bl, [s + esi]
    add bl, [s + esi + 1]
    mov [d + esi], bl
    inc esi

    loop start_loop

final:
    push dword 0
    call [exit]