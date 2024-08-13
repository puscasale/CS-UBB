bits 32
global start

extern exit, scanf, fprintf, fopen, fclose
import exit msvcrt.dll
import scanf msvcrt.dll
import fprintf msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll


segment data use32 class = data
    file_name db "output.txt", 0
    file_mode db "w", 0
    file_descr dd -1
    
    r_format db "%d", 0
    w_format db "%x%c", 0
    
    counter dd 0
    number dd 0
    p_sum dd 0
    i_sum dd 0
    diff dd 0
    

segment code use32 class = code
    start:
        push dword counter
        push dword r_format
        call [scanf]
        add esp, 4 * 2 
        
        rep_1:
            cmp dword [counter], 0
            je exit_rep_1
            
            push dword number
            push dword r_format
            call [scanf]
            add esp, 4 * 2
            
            test dword [number], 01h
            jz par
            
            mov eax, [i_sum]
            add eax, [number]
            mov [i_sum], eax
            jmp skip
            
            par:
            mov eax, [p_sum]
            add eax, [number]
            mov [p_sum], eax
                
            skip:
            dec dword [counter]
            jmp rep_1
            
        exit_rep_1:
        
        mov eax, [p_sum]
        sub eax, [i_sum]
        mov [diff], eax
   
        push dword file_mode
        push dword file_name
        call [fopen]
        add esp, 4 * 2
        
        mov [file_descr], eax
        
        cmp eax, 0
        je final
        
        push dword 10
        push dword [p_sum]
        push dword w_format
        push dword [file_descr]
        call [fprintf]
        add esp, 4 * 4
        
        push dword 10
        push dword [i_sum]
        push dword w_format
        push dword [file_descr]
        call [fprintf]
        add esp, 4 * 4
        
        push dword 10
        push dword [diff]
        push dword w_format
        push dword [file_descr]
        call [fprintf]
        add esp, 4 * 4
        
        push dword [file_descr]
        call [fclose]
        add esp, 4 * 1
        
        final:
            push dword 0
            call [exit]