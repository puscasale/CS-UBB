; Sa se determine litera (lowercase 'a' - 'z') cu cel mai mare numar de aparitii intr-un fisier. 
; Sa se afiseze litera si numarul de aparitii.

bits 32
global start

extern exit, fopen, fclose, printf, fread
import exit msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import printf msvcrt.dll
import fread msvcrt.dll


segment data use32 class = data
    file_name db "pb.txt", 0
    file_mode db "r", 0
    file_descr dd -1
   
    w_format db "%c - %d", 0
    
    max_len equ 100
    text resb max_len
    
    freq times 255 db 0, 0
    most_freq dd 0
    chr dd 0
    
    
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
            push dword [file_descr]
            push dword max_len
            push dword 1
            push dword text
            call [fread]
            add esp, 4 * 4
            
            cmp eax, 0
            je exit_rep_1
        
            mov esi, 0
        
            rep_2:
                mov eax, 0
                mov al, [text + esi]
                cmp al, 0
                je exit_rep_2
                
                cmp al, 'a'
                jb not_lower
                
                cmp al, 'z'
                ja not_lower
                
                inc dword [freq + eax]
                
                not_lower:
                inc esi
                jmp rep_2
        
            exit_rep_2:
            jmp rep_1
        
        exit_rep_1:
        mov esi, 0
        
        rep_3:
            cmp esi, 256
            je exit_rep_3
            
            mov eax, 0
            mov al, [freq + esi]
            cmp al, [most_freq]
            jbe not_greater
            
            mov [most_freq], eax
            mov [chr], esi
            
            not_greater:
            inc esi
            jmp rep_3
            
        exit_rep_3:
        push dword [most_freq]
        push dword [chr]
        push dword w_format
        call [printf]
        add esp, 4 * 3
        
        push dword [file_descr]
        call [fclose]
        add esp, 4 * 1
        
        final:
        push dword 0
        call [exit]