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
    file_mode db "w", 0
    file_descr dd -1
    file_w_format db "%d ", 0
    
    r_format db "%d", 0
    
    m dd 0
    n dd 0
    number dd 0
    counter dd 0
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
        
        push dword m
        push dword r_format
        call [scanf]
        add esp, 4 * 2
        
        push dword n
        push dword r_format
        call [scanf]
        add esp, 4 * 2
        
        rep_1:
            cmp dword [m], 0
            je exit_rep_1
        
            push dword number
            push dword r_format
            call [scanf]
            add esp, 4 * 2
            
            mov dword [counter], 0
            mov eax, [number]
            mov edx, 0
            
            rep_2:
                cmp eax, 0
                je exit_rep_2
                
                mov edx, 0
                div dword [ten]
                test edx, 01h
                jnz not_par
                
                inc dword [counter]
                
                not_par:
                jmp rep_2
                
            exit_rep_2:
            mov eax, [counter]
            cmp eax, [n]
            jb not_min_par_digits
            
            push dword [number]
            push dword file_w_format
            push dword [file_descr]
            call [fprintf]
            add esp, 4 * 3
            
            not_min_par_digits:
            dec dword [m]
            jmp rep_1
           
        exit_rep_1:
        push dword [file_descr]
        call [fclose]
        add esp, 4 * 1
        
        final:
        push dword 0
        call [exit]