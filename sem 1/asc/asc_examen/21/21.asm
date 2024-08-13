bits 32
global start

extern exit, scanf, fopen, fclose, printf, fscanf
import exit msvcrt.dll
import scanf msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import printf msvcrt.dll
import fscanf msvcrt.dll


segment data use32 class = data
    file_name times 20 db 0, 0
    file_mode db "r", 0
    file_descr dd -1
    file_r_format db "%s", 0
    
    r_format_str db "%s", 0
    r_format_dec db "%d", 0
    w_format db "%s ", 0
    
    number dd 0
    cuv times 20 db 0, 0


segment code use32 class = code
    start:
        push dword file_name
        push dword r_format_str
        call [scanf]
        add esp, 4 * 2
        
        push dword number
        push dword r_format_dec
        call [scanf]
        add esp, 4 * 2
        
        push dword file_mode
        push dword file_name
        call [fopen]
        add esp, 4 * 2
        
        mov [file_descr], eax
        cmp eax, 0
        je final
        
        mov esi, 1
        
        rep_1:
            push dword cuv
            push dword file_r_format
            push dword [file_descr]
            call [fscanf]
            add esp, 4 * 3
            
            cmp eax, 1
            jne exit_rep_1
            
            mov eax, esi
            mov edx, 0
            div dword [number]
            
            cmp edx, 0
            jne not_multiple
            
            push dword cuv
            push dword w_format
            call [printf]
            add esp, 4 * 2
            
            not_multiple:
            inc esi
            jmp rep_1
        
        exit_rep_1:
        push dword [file_descr]
        call [fclose]
        add esp, 4 * 1
        
        final:
        push dword 0
        call [exit]