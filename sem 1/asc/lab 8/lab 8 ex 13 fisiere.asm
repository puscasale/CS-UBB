bits 32
global start
extern exit, fopen, fclose, fread, printf
import exit msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import fread msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data 
    nume_fisier db "lab8pr2.txt", 0
    mod_acces db "r+", 0
    descriptor_fisier dd -1
    len equ 20
    text times (len+1) db 0
    format db "Numarul de consoane este %d", 0
    
    sir_vocale db 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U', ' '
    l_vocale equ $-sir_vocale
    aux resd 1
    auxesi resd 1
    nr_consoane dd 0
    afisare db 1
    
segment code use32 class=code
start:
   
        ;deschide fisier
        push dword mod_acces
        push dword nume_fisier
        call [fopen]
        add esp, 4*2
        
        mov [descriptor_fisier], eax
        
        cmp eax, 0
        je final
        
        ; eax = fread(text, 1, len, descriptor_fis)
        push dword [descriptor_fisier]
        push dword len
        push dword 1
        push dword text
        call [fread]
        add esp, 4*4
        
        ;dupa apelul functiei fread EAX contine numarul de caractere cititte din fisier 
        
        mov ecx, eax; parcurgem sirul citit din fisier 
        jecxz final 
        mov esi, text 
        mov edi, afisare 
        parcurgere:
            lodsb
            stosb
            
            ;parcurgem sirul de vocale si verificam daca litera se afiseaza in sir 
            mov [aux], ecx
            mov ecx, l_vocale
            jecxz sari 
            mov [auxesi], esi; salvam copia lui esi pentru a-l putea folosi
            mov esi, 0
            mov bl, 1; daca litera e consoana bl ramane 1, daca nu se face 0
            repeta:
                mov al, [edi-1]
                cmp al, [sir_vocale + esi]
                jne diferit 
                mov bl, 0
                diferit:
                inc esi 
            loop repeta 
            
            mov esi, [auxesi]
            cmp bl, 1; bl este 1 daca litera a fost consoana 
            jne sari 
            
            mov ebx, [nr_consoane]
            add ebx, 1
            mov [nr_consoane], ebx 
            
            sari:
            
            mov ecx, [aux]
        loop parcurgere 
        
        mov ebx, [nr_consoane]
        ;printf(format, nr_consoane)
        push dword [nr_consoane]
        push dword format 
        call [printf]
        add esp, 4*2
        
        
        final:
        
        ;fclose(descriptor_fisier)
        push dword [descriptor_fisier]
        call [fclose]
        add esp, 4*1
 
push dword 0
call [exit]
