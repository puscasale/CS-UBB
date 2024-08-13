bits 32
global start
extern exit, fopen, fclose, fread, fwrite, fprintf
import exit msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import fread msvcrt.dll
import fwrite msvcrt.dll
import fprintf msvcrt.dll

section data use32 class=data 
    nume_fisier db "C:\Users\Ale\Desktop\asc lab\lab8p2.txt", 0
    mod_acces_r db "r", 0
    mod_acces_a db "a", 0 ; Modul de adăugare și citire
    descriptor_citire dd -1
    descriptor_scriere dd -1
    len equ 20
    text times (len+1) db 0
    format db "Textul transformt este: %s", 0
    
segment code use32 class=code
start:
    ; Deschide fisierul în modul de citire
    push dword mod_acces_r
    push dword nume_fisier
    call [fopen]
    add esp, 4*2
    
    mov [descriptor_citire], eax
    
    cmp eax, 0
    je final
    
    ; Citeste continutul fisierului in text
    push dword [descriptor_citire]
    push dword len
    push dword 1
    push dword text
    call [fread]
    add esp, 4*4
    
    ; Inchide fisierul de citire
    push dword [descriptor_citire]
    call [fclose]
    add esp, 4*1
    
    ; Deschide fisierul în modul de adăugare și citire
    push dword mod_acces_a
    push dword nume_fisier
    call [fopen]
    add esp, 4*2
    
    mov [descriptor_scriere], eax
    
    cmp eax, 0
    je final
    
    ; Transforma literele mici în litere mari
    mov esi, text
    transformare:
        lodsb
        cmp al, 'a'
        jb  nu_lit_mica
        cmp al, 'z'
        ja  nu_lit_mica
        sub al, 32 ; face conversia la litere mari
    nu_lit_mica:
        stosb
        cmp al, 0
        jne transformare
    
    ; Scrie textul transformat în fisier (adică adaugă la sfârșitul fișierului)
    push dword [descriptor_scriere]
    push dword format ; Formatul este pus pe stivă
    push dword text
    call [fprintf]
    add esp, 4*3
    
    ; Inchide fisierul de scriere
    push dword [descriptor_scriere]
    call [fclose]
    add esp, 4*1
    
    ; Ieșire din program
    push dword 0
    call [exit]

final:
    ; Ieșire din program în cazul în care nu s-a putut deschide fisierul
    push dword 0
    call [exit]
