bits 32
global start

extern exit, scanf, printf
import exit msvcrt.dll
import scanf msvcrt.dll
import printf msvcrt.dll


segment data use32 class = data
    cuv times 20 db 0, 0
    number dd 0
    ans times 40 db 0, 0
    
    r_format_str db "%s", 0
    r_format_dec db "%d", 0
    w_format_str db "%s", 0
    
    divider dd 20
    adder db 0
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
        
        mov esi, 0
        mov edi, 0
        
        test dword [number], 01h
        jz is_par
        
        mov eax, [number]
        mov edx, 0
        div dword [divider]
        mov [adder], dl
        
        rep_1:
            mov al, [cuv + esi]
            cmp al, 0
            je exit_rep_1
            
            add al, [adder]
            mov [ans + edi], al
            
            inc esi
            inc edi
            jmp rep_1
        
        exit_rep_1:
        jmp skipper
        
        is_par:
        rep_2:
            mov dword [is_voc], 0
            mov al, [cuv + esi]
            cmp al, 0
            je exit_rep_2
            
            mov ebx, 0
            
            rep_3:
                mov cl, [voc + ebx]
                cmp cl, 0
                je exit_rep_3
                
                cmp al, cl
                jne not_eq
            
                mov dword [is_voc], 1
            
                not_eq:
                inc ebx
                jmp rep_3
                
            exit_rep_3:
            test dword [is_voc], 01h
            jnz impar
            
            mov [ans + edi], al
            inc edi
            mov [ans + edi], byte 'p'
            inc edi
            mov [ans + edi], al
            inc edi
            jmp jump_over
            
            impar:
            mov [ans + edi], al
            inc edi
            
            jump_over:
            inc esi
            jmp rep_2
        
        exit_rep_2:
        skipper:
        push dword ans
        push dword w_format_str
        call [printf]
        add esp, 4 * 2
        
        push dword 0
        call [exit]