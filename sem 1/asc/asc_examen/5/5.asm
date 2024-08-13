bits 32
global start

extern exit, scanf, printf
import exit msvcrt.dll
import scanf msvcrt.dll
import printf msvcrt.dll


segment data use32 class = data
    text times 100 db 0, 0
    lower times 100 db 0, 0
    upper times 100 db 0, 0
    
    r_format db "%s", 0
    w_format db "Lower: %s %cUpper: %s", 0
    

segment code use32 class = code
    start:
        push dword text
        push dword r_format
        call [scanf]
        add esp, 4 * 2
        
        mov esi, 0
        mov edi, 0
        mov ebx, 0
        
        rep_1:
            mov al, [text + esi]
            cmp al, 0
            je exit_rep_1
            
            cmp al, 'a'
            jb is_upper
            
            mov [lower + edi], al
            inc edi
            jmp skipper
            
            is_upper:
            mov [upper + ebx], al
            inc ebx
        
            skipper:
            inc esi
            jmp rep_1
         
        exit_rep_1:
        push dword upper
        push dword 10
        push dword lower
        push dword w_format
        call [printf]
        add esp, 4 * 4
        
        push dword 0
        call [exit]