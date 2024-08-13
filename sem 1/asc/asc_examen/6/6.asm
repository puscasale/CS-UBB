bits 32
global start

extern exit, fopen, fclose, fscanf, printf
import exit msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import fscanf msvcrt.dll
import printf msvcrt.dll


segment data use32 class = data
    file_name db "numere.txt", 0
    file_mode db "r", 0
    file_descr dd -1
    
    impar times 25 dd 0, 0
    par times 25 dd 0, 0
    
    number dd 0
    
    r_format db "%d", 0
    w_format db "%d ", 0
    new_line db "%c", 0
    

segment code use32 class = code
    start:
        push dword file_mode
        push dword file_name
        call [fopen]
        add esp, 4 * 2
        
        mov [file_descr], eax
        cmp eax, 0
        je final
        
        mov esi, 0
        mov edi, 0
        
        rep_1:
            push dword number
            push dword r_format
            push dword [file_descr]
            call [fscanf]
            add esp, 4 * 3
            
            cmp eax, 1
            jne exit_rep_1
            
            mov eax, [number]
            test eax, 01h
            jz is_par
            
            mov [impar + esi], eax
            add esi, 4
            jmp skipper 
            
            is_par:
            mov [par + edi], eax
            add edi, 4
            
            skipper:
            jmp rep_1
            
        exit_rep_1:
        mov esi, impar
        
        rep_2:
            lodsd
            cmp eax, 0
            je exit_rep_2
            
            push eax
            push dword w_format
            call [printf]
            add esp, 4 * 2
            
            jmp rep_2

        exit_rep_2:
        push dword 10
        push dword new_line
        call [printf]
        add esp, 4 * 2
        
        mov esi, par
        
        rep_3:
            lodsd
            cmp eax, 0
            je exit_rep_3
            
            push eax
            push dword w_format
            call [printf]
            add esp, 4 * 2
            
            jmp rep_3

        exit_rep_3:
        push dword [file_descr]
        call [fclose]
        add esp, 4 * 1
        
        final:
        push dword 0
        call [exit]