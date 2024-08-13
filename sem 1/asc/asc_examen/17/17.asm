bits 32
global start

extern exit, fopen, fclose, fprintf, scanf
import exit msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import fprintf msvcrt.dll
import scanf msvcrt.dll


segment data use32 class = data
    file_name db "output.txt", 0
    file_mode db "w+", 0
    file_descr dd -1
    file_w_format db "%d ", 0
    
    r_format db "%d", 0
    
    number dd 0
    min_digit dd 9
    max_digit dd 0
    prod dd 0
    ten dd 10

    
segment code use32 class = code
    start:
        push dword number
        push dword r_format
        call [scanf]
        add esp, 4 * 2
        
        mov eax, [number]
        mov edx, 0
        
        rep_1:
            cmp eax, 0
            je exit_rep_1
            
            mov edx, 0
            div dword [ten]
            
            cmp edx, [min_digit]
            jae not_min
            
            mov [min_digit], edx
            
            not_min:
            cmp edx, [max_digit]
            jbe not_max
            
            mov [max_digit], edx
            
            not_max:
            jmp rep_1
            
        exit_rep_1:
        mov eax, [min_digit]
        mul dword [max_digit]
        mov [prod], eax
        
        push dword file_mode
        push dword file_name
        call [fopen]
        add esp, 4 * 2
        
        mov [file_descr], eax
        cmp eax, 0
        je final
        
        push dword [max_digit]
        push dword file_w_format
        push dword [file_descr]
        call [fprintf]
        add esp, 4 * 3
        
        push dword [min_digit]
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