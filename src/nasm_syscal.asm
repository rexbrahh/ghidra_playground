; nasm_syscall.asm
; prints "NASM-OK\n" using write(1,buf,8), then exit(0)
BITS 64
GLOBAL _start
SECTION .data
msg db "NASM-OK",10
SECTION .text
_start:
    mov rax,1          ; sys_write
    mov rdi,1
    lea rsi,[rel msg]
    mov rdx,8
    syscall
    mov rax,60         ; sys_exit
    xor rdi,rdi
    syscall

