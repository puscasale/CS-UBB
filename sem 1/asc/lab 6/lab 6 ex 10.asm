bits 32
global start

extern exit
import exit msvcrt.dll

segment data use32 class=data
	s dw 1122h, 3344h, 5566h, 7788h
    l equ ($-s)/2         
    b1 times l db 0
    b2 times l db 0
    
;Se da un sir A de cuvinte. Construiti doua siruri de octeti  
; - B1: contine ca elemente partea superioara a cuvintelor din A
; - B2: contine ca elemente partea inferioara a cuvintelor din A
segment code use32 class=code
    start:
        mov ecx, l        
        jecxz final         
        cld                 
        mov esi, s          
        mov ebx, b1         
        mov edi, b2 
        
    repeta:
        lodsw               
        stosb               ; partea inferioara din al in sirul b2 si inc edi
        push edi            
        mov edi, ebx        
        ror ax, 8           ; mutam partea superioara din ah in al
        stosb               ; partea superioara din al in sirul b1 si inc edi
        mov ebx, edi        
        pop edi             
        loop repeta
        
    final:
        push dword 0
        call [exit]
