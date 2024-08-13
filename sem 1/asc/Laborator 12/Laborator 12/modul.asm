    
bits 32
global _conversie_rapida

segment data public data use32  
    rez times 8 db 0
    db 0
    TabOcta db '01234567'
   
segment code public code use32 
    _conversie_rapida:
        push ebp
        mov ebp, esp        
        
        mov ebx, TabOcta
        mov edx, [ebp + 8]  ; parametrul functiei
        mov ecx, 8
        
        mov edi, rez        ; EDI = adresa de inceput a rezultatului (rez)
        repeta:
            mov esi, 0
            
            cifra1:
            mov al, [edx]   ; AL = caracterul de la pointerul EDX
            inc edx         ; EDX "indica" urmatorul caracter
            
            cmp al, '1'     
            je egal        
            shl esi, 1      
            jmp dupa       
            egal:          
            shl esi, 1      
            inc esi         ; |-> conversie '0' si '1' in 0 si 1, rezultat pus in ESI
            dupa:
                            ; repetare actiune de inca 3 ori
            cifra2:
            mov al, [edx]
            inc edx
            
            cmp al, '1'
            je egal
            shl esi, 1
            jmp dupa
            egal:
            shl esi, 1
            inc esi
            dupa:
            
            cifra3:
            mov al, [edx]
            inc edx
            
            cmp al, '1'
            je egal
            shl esi, 1
            jmp dupa
            egal:
            shl esi, 1
            inc esi
            dupa:
            
            mov eax, esi    ; EAX = rezultatul in urma conversiei din char in int 
            xlat            
            
            mov [edi], al   ; se pune la adresa EDI rezultatul
            inc edi         ; EDI indica urmatorul byte din rez
            
            loop repeta     
            
        mov eax, rez ; EAX = numar convertit
        mov esp, ebp
        pop ebp
        ret        

        
        
 
        
        
 