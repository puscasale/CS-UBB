bits 32
global start

extern exit, fopen, fclose, fprintf, scanf
import exit msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import fprintf msvcrt.dll
import scanf msvcrt.dll


segment data use32 class = data
    file_name db "string.txt", 0
    file_mode db "w+", 0
    file_descr dd -1
    file_w_format db "%s", 0
    
    r_format db "%s", 0
    
    cuv times 100 db 0, 0
    ans times 100 db 0, 0
    cuv_len dd 0
    
    
segment code use32 class = code
    start:
        push dword cuv
        push dword r_format
        call [scanf]
        add esp, 4 * 2
        
        mov esi, 0
        
        rep_1:
            mov al, [cuv + esi]
            cmp al, 0
            je exit_rep_1
            
            inc esi
        
            jmp rep_1
            
        exit_rep_1:
        dec esi
        mov [cuv_len], esi
        mov esi, 0
        mov edi, 0
        
        rep_2:
            mov al, [cuv + esi]
            cmp al, 0
            je exit_rep_2
            
            cmp al, 'A'
            jb not_maj
            
            cmp al, 'Z'
            ja not_maj
            
            mov [ans + edi], al
            inc edi
        
            not_maj:
            inc esi
            
            jmp rep_2
        
        exit_rep_2:
        mov esi, [cuv_len]
        
        rep_3:
            cmp esi, -1
            je exit_rep_3 
            
            mov al, [cuv + esi]
            cmp al, 'a'
            jb not_min
        
            cmp al, 'z'
            ja not_min
            
            mov [ans + edi], al
            inc edi
        
            not_min:
            dec esi
            
            jmp rep_3
            
        exit_rep_3:
        push dword file_mode
        push dword file_name
        call [fopen]
        add esp, 4 * 2
        
        mov [file_descr], eax
        cmp eax, 0
        je final
        
        push dword ans
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