bits 32
global start

extern exit, scanf, printf
import exit msvcrt.dll
import scanf msvcrt.dll
import printf msvcrt.dll


segment data use32 class = data
    r_format_dec db "%d", 0
    r_format_str db "%s", 0
    w_format db "%s", 0
    
    cuv times 20 db 0, 0
    ans times 60 db 0, 0
    number dd 0
    voc db "aeiouAEIOU", 0
    is_voc dd 0
    

segment code use32 class = code
    start:
        push dword cuv
        push dword r_format_str
        call [scanf]
        add esp, 4 * 2
        
        push dword number
        push dword r_format_dec
        call [scanf]
        add esp, 4 * 2
        
        test dword [number], 01h
        jz par
        
        mov esi, 0
        mov edi, 0
        
        rep_1:
            mov dword [is_voc], 0
            mov al, [cuv + esi]
            cmp al, 0
            je exit_rep_1
            
            mov ebx, 0
            
            rep_2:
                mov cl, [voc + ebx]
                cmp cl, 0
                je exit_rep_2
                
                cmp al, cl
                jne not_eq
            
                mov dword [is_voc], 1
            
                not_eq:
                inc ebx
                jmp rep_2
        
            exit_rep_2:
            test dword [is_voc], 01h
            jz not_voc
            
            mov [ans + edi], al
            inc edi
            mov [ans + edi], byte 'p'
            inc edi
            mov [ans + edi], al
            inc edi
            jmp jump_over
            
            not_voc:
            mov [ans + edi], al
            inc edi
            
            jump_over:
            inc esi
            jmp rep_1
     
        exit_rep_1:
        jmp skip
        
        par:
        mov esi, 0
        
        rep_3:
            mov al, [cuv + esi]
            cmp al, 0
            je exit_rep_3
            
            add al, 20
            mov [ans + esi], al
            
            inc esi
            jmp rep_3
            
        exit_rep_3:
        skip:
        push dword ans
        push dword w_format
        call [printf]
        add esp, 4 * 2
    
        push dword 0
        call [exit]