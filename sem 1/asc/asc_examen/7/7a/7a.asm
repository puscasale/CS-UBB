bits 32
global start

extern exit, printf
import exit msvcrt.dll
import printf msvcrt.dll


segment data use32 class = data
    arr dq 51AFA234h, 23BC11C537A3F411h, 0FF1Ah, 333D72348h
    len dd ($ - arr)
    
    w_format db "%x ", 0
    
    
segment code use32 class = code
    start:      
        mov esi, 0
        cld
    
        rep_1:
            cmp dword [len], 0
            je exit_rep_1
            
            mov eax, 0
            mov al, [arr + esi]
            
            push eax
            push dword w_format
            call [printf]
            add esp, 4 * 2
            
            inc esi
            dec dword [len]
            jmp rep_1
        
        exit_rep_1:
        push dword 0
        call [exit]