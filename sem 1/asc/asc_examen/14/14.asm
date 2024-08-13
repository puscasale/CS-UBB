bits 32
global start

extern exit, fopen, fclose, fscanf, printf
import exit msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import fscanf msvcrt.dll
import printf msvcrt.dll


segment data use32 class = data
    file_name db "preufung.txt", 0
    file_mode db "r", 0
    file_descr dd -1
    file_r_format db "%s", 0
    
    w_format db "%s%c", 0
    
    cuv times 20 db 0, 0
    two dd 2
    

segment code use32 class = code
    start:
        push dword file_mode
        push dword file_name
        call [fopen]
        add esp, 4 * 2
        
        mov [file_descr], eax
        cmp eax, 0
        je final
        
        rep_1:
            push dword cuv
            push dword file_r_format
            push dword [file_descr]
            call [fscanf]
            add esp, 4 * 3
            
            cmp eax, 1
            jne exit_rep_1
            
            mov esi, 0
            
            rep_2:
                mov al, [cuv + esi]
                cmp al, 0
                je exit_rep_2
            
                inc esi
                jmp rep_2
                
            
            exit_rep_2:
            test esi, 01h
            jz not_good
            
            mov eax, esi
            mov edx, 0
            div dword [two]
            mov esi, eax
            mov [cuv + esi], byte ' '
            
            push dword 10
            push dword cuv
            push dword w_format
            call [printf]
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