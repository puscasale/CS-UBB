bits 32 
global start

extern exit
import exit msvcrt.dll

extern convert


segment data use32 class = data
    counter dd 32
    
    
segment code use32 class = code
    start:
        repeats:
            cmp dword [counter], 126
            ja exit_loop
            
            push dword [counter]
            call convert
            
            inc dword [counter]
            jmp repeats
    
        exit_loop:
        
        push dword 0
        call [exit]