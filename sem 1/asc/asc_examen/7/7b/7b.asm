bits 32
global start

extern exit, printf
import exit msvcrt.dll
import printf msvcrt.dll


segment data use32 class = data
    arr dq 51AFA234h, 23BC11C537A3F415h, 0FF5h, 333D72348h
    len dd ($ - arr) / 2
    
    w_format db "%x ", 0
    
    d times 25 dw 0, 0
    k equ 5
    ten dd 10
    
    
segment code use32 class = code
    start:      
        mov esi, arr
        mov edi, d
        cld
    
        rep_1:
            cmp dword [len], 0
            jbe exit_rep_1
            
            mov eax, 0
            lodsw
            
            mov ebx, eax
            mov edx, 0
            div dword [ten]
            cmp edx, k
            jne not_eq
            
            mov eax, ebx
            stosw
            
            not_eq:
            dec dword [len]
            jmp rep_1
        
        exit_rep_1:
        push dword 0
        call [exit]