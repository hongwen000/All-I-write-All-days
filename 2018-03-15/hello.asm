[section .data]
strHello    db  "Hello, world!", 0Ah
STRLEN      equ $ - strHello

[section .text]

global start
start:
    mov rax, 0x2000004
    mov rdi, 1
    mov rsi, strHello
    mov rdx, STRLEN
    syscall
    mov rax, 0x2000001
    mov rdi, 0
    syscall
