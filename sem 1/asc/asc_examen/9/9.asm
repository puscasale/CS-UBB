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
    r_file_name times 100 db 0, 0
    r_file_mode db "r", 0
    r_file_descr dd -1
    
    w_file_name db "output.txt", 0
    w_file_mode db "w", 0
    w_file_descr dd -1
    w_file_w_format_chr db "%c", 0
    w_file_w_format_dec db "%d", 0
    
    r_mode db "%s", 0
    
    len equ 100
    text times len db 0
    

segment code use32 class = code
    start:
        push dword r_file_name
        push dword r_mode
        call [scanf]
        add esp, 4 * 2
        
        push dword r_file_mode
        push dword r_file_name
        call [fopen]
        add esp, 4 * 2
        
        mov [r_file_descr], eax
        cmp eax, 0
        je final
        
        push dword w_file_mode
        push dword w_file_name
        call [fopen]
        add esp, 4 * 2
        
        mov [w_file_descr], eax
        cmp eax, 0
        je final
        
        push dword [r_file_descr]
        push dword len
        push dword 1
        push dword text
        call [fread]
        add esp, 4 * 4
        
        mov esi, text
        
        rep_1:
            mov eax, 0
            lodsb
            cmp al, 0
            je exit_rep_1
            
            cmp al, 'a'
            jb skipper
            
            push eax
            push dword w_file_w_format_dec
            push dword [w_file_descr]
            call [fprintf]
            add esp, 4 * 3
            
            skipper:
            push eax
            push dword w_file_w_format_chr
            push dword [w_file_descr]
            call [fprintf]
            add esp, 4 * 3
            
            jmp rep_1
        
        exit_rep_1:
        push dword [r_file_descr]
        call [fclose]
        add esp, 4 * 1
        
        push dword [w_file_descr]
        call [fclose]
        add esp, 4 * 1
    
        final:
        push dword 0
        call [exit]