bits 32
global start

extern exit, scanf, fopen, fclose, fprintf
import exit msvcrt.dll
import scanf msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import fprintf msvcrt.dll


segment data use32 class = data
    file_name db "output.txt", 0
    file_mode db "w+", 0
    file_descr dd -1
    file_w_format db "%s ", 0
    
    r_format_dec db "%d", 0
    r_format_str db "%s", 0
    
    n dd 0
    cuv times 20 db 0, 0
    first_chr db 0
    last_chr db 0
    
segment code use32 class = code
    start:
        push dword file_mode
        push dword file_name
        call [fopen]
        add esp, 4 * 2
        
        mov [file_descr], eax
        cmp eax, 0
        je final
        
        push dword n
        push dword r_format_dec
        call [scanf]
        
        rep_1:
            push dword cuv
            push dword r_format_str
            call [scanf]
            add esp, 4 * 2
            
            mov al, [cuv]
            cmp al, '#'
            je exit_rep_1
            
            mov esi, 0
            
            rep_2:
                mov al, [cuv + esi]
                cmp al, 0
                je exit_rep_2
                
                cmp esi, 1
                jae not_first
                
                mov [first_chr], al
                
                not_first:
                mov [last_chr], al
                
                inc esi
                jmp rep_2
            
            exit_rep_2:
            cmp esi, [n]
            jb not_good
            
            mov al, [first_chr]
            cmp al, [last_chr]
            jne not_good
            
            push dword cuv
            push dword file_w_format
            push dword [file_descr]
            call [fprintf]
            add esp, 4 * 3
            
            not_good:
            jmp rep_1
            
        exit_rep_1:
        push dword [file_descr]
        call [fclose]
        add esp, 4 * 1
        
        final:
        push dword 0
        call [exit]