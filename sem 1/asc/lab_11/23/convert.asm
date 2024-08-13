bits 32
global convert


segment data use32 class = data
    hundred dw 100
    ten db 10
    

segment code use32 public code
    convert:
        mov edx, 0
        mov eax, [esp + 4]
        div word [hundred]
        div byte [ten]
            
        and eax, 0000FF00h
        mov al, ah
        mov ah, 0
        
        ret 4