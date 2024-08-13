bits 32
global start

extern exit, fopen, fclose, fprintf, scanf
import exit msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import fprintf msvcrt.dll
import scanf msvcrt.dll


segment data use32 class = data
    file_name times 20 db 0, 0
    file_mode db "w+", 0
    file_descr dd -1
    file_w_format db "%s ", 0
    
    cuv times 20 db 0, 0
    ans times 200 db 0, 0
    
    r_format db "%s", 0
    counter dd 0
    
    
segment code use32 class = code
    start:
        mov esi, 0
    
        rep_1:
            push dword cuv
            push dword r_format
            call [scanf]
            add esp, 4 * 2
            
            cmp byte [cuv], '.'
            je exit_rep_1
            
            cmp dword [counter], 0
            jne not_file
            
            push dword file_mode
            push dword cuv
            call [fopen]
            add esp, 4 * 2
            
            mov [file_descr], eax
            cmp eax, 0
            je final
            
            mov dword [counter], 1
            jmp skip
            
            not_file:
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
            
            skip:
            jmp rep_1
            
        exit_rep_1:
        push dword ans
        push dword file_w_format
        push dword [file_descr]
        call [fprintf]
        add esp, 4 * 3
        
        push dword [file_descr]
        call [fclose]
        add esp, 4 * 1
        
        final:
        push dword 0
        call [exit]