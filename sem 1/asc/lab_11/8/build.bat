nasm -fobj main.asm
nasm -fobj convert.asm

alink main.obj convert.obj -oPE -subsys console -entry start