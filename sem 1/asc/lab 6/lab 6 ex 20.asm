bits 32
global start

extern exit, printf
import exit msvcrt.dll
import printf msvcrt.dll

segment data use32 class=data
	text db "cuvant capac"
    b resb 1
    
;Se da un sir de octeti reprezentand un text (succesiune de cuvinte separate de spatii). Sa se identifice cuvintele de tip palindrom (ale caror oglindiri sunt similare cu cele de plecare): "cojoc", "capac" etc.
segment code use32 class=code
    start:
        mov esi, text       ; Adresa de început a textului
        mov ebx, 0
        cld

    find_palindromes:
        lodsb               ; Încarcă următorul caracter în AL
        cmp al, ' '         ; Verifică dacă am găsit un spațiu
        je  next_word

        ; Verificăm dacă cuvântul este palindrom
        mov edx, 0

    check_palindrome_loop:
        mov eax, esi        ; Adresa de început a cuvântului
        add eax, ebx        ; Adăugăm offset-ul la adresa de început a cuvântului
        add eax, edx        ; Adăugăm offset-ul în interiorul cuvântului
        mov al, [eax]       ; Încarcă caracterul curent

        cmp al, ' '         ; Verifică dacă am găsit un spațiu (sfârșitul cuvântului curent)
        je  palindrom_found ; Dacă da, este palindrom

        mov bl, [eax + edx - 1]   ; Încarcă caracterul corespunzător din oglindă
        cmp al, bl          ; Compară cele două caractere
        jne not_palindrome  ; Dacă nu sunt egale, nu este palindrom

        inc edx             ; Avansăm în interiorul cuvântului
        jmp check_palindrome_loop

    not_palindrome:
        ; Cuvântul nu este palindrom, trecem la următorul cuvântul
        mov ecx, 2
        mov [b], cl
        inc ebx
        jmp find_palindromes

    palindrom_found:
        ; Cuvântul este palindrom
        mov ecx, 1 
        mov [b+1], cl
        ; Trecem la următorul cuvânt
        inc ebx
        jmp find_palindromes

    next_word:
        ; Trecem peste spații
        jmp find_palindromes

    final:
        push dword 0
        call [exit]
