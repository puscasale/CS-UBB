bits 32
global start

extern exit, fopen, fclose, fscanf, printf
import exit msvcrt.dll
import fscanf msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import printf msvcrt.dll


segment data use32 class = data
    file_name db "input.txt", 0
    file_mode db "r", 0
    file_descr dd -1

    r_format db "%x", 0
    w_format db "%d", 0
    
    number dd 0
    min_digit dd 10
    ten dd 10
    

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
            push dword number
            push dword r_format
            push dword [file_descr]
            call [fscanf]
            add esp, 4 * 3
            
            cmp eax, 1
            jne exit_rep_1
            
            mov dword [min_digit], 10
            mov eax, [number]
            mov edx, 0
            
            rep_2:
                cmp eax, 0
                je exit_rep_2
                
                div dword [ten]
                cmp edx, [min_digit]
                jae not_min
                
                mov [min_digit], edx
                
                not_min:
                mov edx, 0
                jmp rep_2
            
            exit_rep_2:
            push dword [min_digit]
            push dword w_format
            call [printf]
            add esp, 4 * 2
            
            jmp rep_1
        
        exit_rep_1:
        push dword [file_descr]
        call [fclose]
        add esp, 4 * 1
        
        final:
        push dword 0
        call [exit]