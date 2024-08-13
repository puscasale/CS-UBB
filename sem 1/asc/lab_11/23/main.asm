bits 32 
global start

extern exit, printf, scanf, fopen, fclose, fprintf
import exit msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll
import fclose msvcrt.dll
import fopen msvcrt.dll
import fprintf msvcrt.dll

extern convert


segment data use32 class = data
    file_name db "res.txt", 0
    access_mode db "a", 0
    file_descr dd -1

    counter dd 0
    number dd 0
    result dd 0
    w_format db "%u%c", 0
    r_format db "%u", 0

    
segment code use32 class = code
    start:
        push dword access_mode
        push dword file_name
        call [fopen]
        add esp, 4 * 2
        
        mov [file_descr], eax
        cmp eax, 0
        je final
    
        push dword counter
        push dword r_format
        call [scanf]
        add esp, 4 * 2
        
        reads:
            cmp dword [counter], 0
            je exit_reads

            push dword number
            push dword r_format
            call [scanf]
            add esp, 4 * 2
            
            push dword [number]
            call convert
            
            push dword 10
            push eax
            push dword w_format
            push dword [file_descr]
            call [fprintf]
            add esp, 4 * 4
            
            dec dword [counter]
            jmp reads
            
        exit_reads:
        
        push dword [file_descr]
        call [fclose]
        add esp, 4 * 1
        
        final:
            push dword 0
            call [exit]