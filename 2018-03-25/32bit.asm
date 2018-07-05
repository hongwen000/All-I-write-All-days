[BITS 16]
extern c_start
start:
    mov ax, 1
    mov bx, 2
    push ax
    push bx
    call c_start
    jmp $

    times 510 - ($ - $$) db 0
    db 0x55,0xaa

asm_func:
    push bp
    mov bp, sp