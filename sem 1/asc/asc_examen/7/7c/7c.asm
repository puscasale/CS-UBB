bits 32
global start

extern exit, fopen, fclose, fprintf, printf
import exit msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import fprintf msvcrt.dll
import printf msvcrt.dll


segment data use32 class = data
    arr dq 51AFA234h, 23BC11C537A3F415h, 0FF5h, 333D72348h
    len dd ($ - arr) / 4
    counter dd 0
    
    file_name db "iesire.txt", 0
    file_mode db "w", 0
    file_descr dd -1
    
    w_format_hex db "%x ", 0
    w_format_dec db "%d ", 0
    
    
segment code use32 class = code
    start:      
        push dword file_mode
        push dword file_name
        call [fopen]
        add esp, 4 * 2
        
        mov [file_descr], eax
        cmp eax, 0
        je final
    
        mov esi, arr
        cld
    
        rep_1:
            cmp dword [len], 0
            jbe exit_rep_1
            
            lodsd
            
            cmp eax, 0AAAh
            jb not_good
            
            cmp eax, 0FFFFh
            ja not_good
            
            inc dword [counter]
            
            push eax
            push dword w_format_hex
            push dword [file_descr]
            call [fprintf]
            add esp, 4 * 3
            
            not_good:
            dec dword [len]
            jmp rep_1
        
        exit_rep_1:
        push dword [counter]
        push dword w_format_dec
        push dword [file_descr]
        call [fprintf]
        add esp, 4 * 3
        
        push dword [file_descr]
        call [fclose]
        add esp, 4 * 1
        
        final:
        push dword 0
        call [exit]