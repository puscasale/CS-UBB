bits 32
global start

extern exit, fopen, fclose, fread, fprintf, scanf
import exit msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import fread msvcrt.dll
import fprintf msvcrt.dll
import scanf msvcrt.dll


segment data use32 class = data
    file_name times 20 db 0, 0
    file_mode db "r+", 0
    file_descr dd -1
    file_r_format db "%c", 0
    file_w_format db "%d", 0
    
    r_format db "%s", 0
    
    counter dd 0
    len equ 100
    buffer resb len
    
    
segment code use32 class = code
    start:
        push dword file_name
        push dword r_format
        call [scanf]
        add esp, 4 * 2
        
        push dword file_mode
        push dword file_name
        call [fopen]
        add esp, 4 * 2
        
        mov [file_descr], eax
        cmp eax, 0
        je final
        
        rep_1:
            push dword [file_descr]
            push dword len
            push dword 1
            push dword buffer
            call [fread]
            add esp, 4 * 4
            
            cmp eax, 0
            je exit_rep_1
            
            add dword [counter], eax
        
            jmp rep_1
        
        exit_rep_1:
        push dword [counter]
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