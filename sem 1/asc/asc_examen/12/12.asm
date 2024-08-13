bits 32
global start

extern exit, fopen, fclose, fscanf, printf
import exit msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import fscanf msvcrt.dll
import printf msvcrt.dll


segment data use32 class = data
    file_name db "input.txt", 0
    file_mode db "r", 0
    file_descr dd -1
    file_r_format db "%d", 0
    
    w_format db "%d%d", 0
    
    number dd 0
    result dq 1
    
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
            push dword file_r_format
            push dword [file_descr]
            call [fscanf]
            add esp, 4 * 3
            
            cmp eax, 1
            jne exit_rep_1
            
            mov eax, [result + 0]
            mov edx, [result + 4]
            mul dword [number]
            mov [result + 0], eax
            mov [result + 4], edx
        
            jmp rep_1
            
        exit_rep_1:
        push dword [result + 0]
        push dword [result + 4]
        push dword w_format
        call [printf]
        add esp, 4 * 3
        
        push dword [file_descr]
        call [fclose]
        add esp, 4 * 1
        
        final:
        push dword 0
        call [exit]