bits 32
global start

extern exit, scanf, printf
import exit msvcrt.dll
import scanf msvcrt.dll
import printf msvcrt.dll


segment data use32 class = data
    counter times 255 db 0, 0
    token times 10 db 0, 0
    
    r_format db "%s", 0
    w_format db "%c - %d%c", 0
    
    curr dd 0
    

segment code use32 class = code
    start:
        rep_1:
            push dword token
            push dword r_format
            call [scanf]
            add esp, 4 * 2
            
            mov esi, token
            mov al, [esi]
            cmp al, '.'
            je exit_rep_1
            
            rep_2:
                mov eax, 0
                lodsb
                cmp al, 0
                je exit_rep_2
                
                inc byte [counter + eax]
            
                jmp rep_2
            
            exit_rep_2:
            jmp rep_1
        
        exit_rep_1:
        rep_3:
            cmp dword [curr], 255
            je exit_rep_3
            
            mov ecx, [curr]
            mov eax, 0
            mov al, [counter + ecx]
            cmp eax, 0
            je no_display
            
            push dword 10
            push eax
            push ecx
            push dword w_format
            call [printf]
            add esp, 4 * 4
            
            no_display:
            inc dword [curr]
            jmp rep_3
       
        exit_rep_3:
        push dword 0
        call [exit]