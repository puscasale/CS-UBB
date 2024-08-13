bits 32
global start

extern exit, scanf, printf
import exit msvcrt.dll
import scanf msvcrt.dll
import printf msvcrt.dll


segment data use32 class = data
    cuv times 10 db 0, 0
    ans times 100 db 0, 0
    
    r_format db "%s", 0
    w_format db "%s", 0
    

segment code use32 class = code
    start:
        cld
        mov esi, 0
        
        rep_1:
            push dword cuv
            push dword r_format
            call [scanf]
            add esp, 4 * 2
            
            mov al, [cuv]
            cmp al, '.'
            je exit_rep_1
            
            mov edi, 0
            
            rep_2:
                mov al, [cuv + edi]
                cmp al, 0
                je exit_rep_2
                
                inc edi
                
                jmp rep_2
        
            exit_rep_2:
            dec edi
            
            rep_3:
                cmp edi, -1
                je exit_rep_3
            
                mov al, [cuv + edi]
                mov [ans + esi], al
                inc esi
                dec edi
            
                jmp rep_3
                
            exit_rep_3:
            mov [ans + esi], byte ' '
            inc esi
            
            jmp rep_1
        
        exit_rep_1:
        push dword ans
        push dword w_format
        call [printf]
        add esp, 4 * 2
        
        push dword 0
        call [exit]