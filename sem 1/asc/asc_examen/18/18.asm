bits 32
global start

extern exit, fopen, fclose, fread, printf
import exit msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import fread msvcrt.dll
import printf msvcrt.dll


segment data use32 class = data
    file_name db "input.txt", 0
    file_mode db "r", 0
    file_descr dd -1
    
    max_len equ 100
    buffer resb max_len
    
    ans times 100 db 0, 0
    
    w_format db "%s", 0
    

segment code use32 class = code
    start:
        push dword file_mode
        push dword file_name
        call [fopen]
        add esp, 4 * 2
        
        mov [file_descr], eax
        cmp eax, 0
        je final
        
        push dword [file_descr]
        push dword max_len
        push dword 1
        push dword buffer
        call [fread]
        add esp, 4 * 4
        
        mov edi, eax
        dec edi
        
        mov esi, 0
        
        rep_1:
            cmp edi, -1
            je exit_rep_1
        
            mov al, [buffer + edi]
            mov [ans + esi], al
            
            inc esi
            dec edi
            jmp rep_1
        
        exit_rep_1:
        push dword ans
        push dword w_format
        call [printf]
        add esp, 4 * 2
        
        push dword [file_descr]
        call [fclose]
        add esp, 4 * 1
        
        final:
        push dword 0
        call [exit]