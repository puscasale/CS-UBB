bits 32
global convert

extern fopen, fclose, fprintf
import fopen msvcrt.dll
import fclose msvcrt.dll
import fprintf msvcrt.dll


segment data use32 class = data
    file_name db "result.txt", 0
    access_mode db "a", 0
    file_descr dd -1

    w_format db "Number %d: <base8> %o, <ascii> %c%c", 0
    number dd 0

segment code use32 public code
    convert:
        push dword access_mode
        push dword file_name
        call [fopen]
        add esp, 4 * 2
        
        mov [file_descr], eax
        cmp eax, 0
        je final
    
        mov ebx, [esp + 4]
        mov [number], ebx
    
        push dword 10
        push dword [number]
        push dword [number]
        push dword [number]
        push dword w_format
        push dword [file_descr]
        call [fprintf]
        add esp, 4 * 6
        
        push dword [file_descr]
        call [fclose]
        add esp, 4 * 1
        
        final:
        
        ret 4