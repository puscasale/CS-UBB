bits 32
global start
extern exit, fopen, fclose, fread, fwrite, fprintf, printf
import exit msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import fread msvcrt.dll
import fwrite msvcrt.dll
import fprintf msvcrt.dll
import printf msvcrt.dll

section data use32 class=data 
    nume_fisier db "ana.txt", 0
    mod_acces db "w", 0
    descriptor_fis dd -1
    text db "ana are 4 mere"
    
;Se dau un nume de fisier si un text (definite in segmentul de date). Textul contine litere mici, litere mari, cifre si caractere speciale. Sa se transforme toate literele mici din textul dat in litere mari. Sa se creeze un fisier cu numele dat si sa se scrie textul obtinut in fisier.

segment code use32 class=code
start:
   
        
    ; apelam fopen pentru a crea fisierul
    push dword mod_acces     
    push dword nume_fisier
    call [fopen]
    add esp, 4*2                

    mov [descriptor_fis], eax   
        
    cmp eax, 0
    je final
    
    ;Conversie litere mici -> litere mari
    mov esi, text
    mov edi, esi
    converteste_litere_mici:
    lodsb
    cmp al, 'a'
    jb  nu_lit_mica
    cmp al, 'z'
    ja  nu_lit_mica
    sub al, 32 ; face conversia la litere mari
    nu_lit_mica:
    stosb
    cmp al, 0
    jne converteste_litere_mici
    
    ; scriem textul in fisierul deschis folosind functia fprintf
    push dword text
    push dword [descriptor_fis]
    call [fprintf]
    add esp, 4*2
    
    ; apelam functia fclose pentru a inchide fisierul
    push dword [descriptor_fis]
    call [fclose]
    add esp, 4
        
      final:
        
        ; exit(0)
        push    dword 0      
        call    [exit]       
        
        