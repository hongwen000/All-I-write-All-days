[BITS 16]
extern c_start
global start
global asm_func
%define KERNEL_LOAD_ADDR 0x7e00
start:
    mov ax,cs                ;段地址 ; 存放数据的内存基地址
    mov es,ax                ;设置段地址（不能直接mov es,段地址）
    mov ds,ax                ;设置数据段
    mov bx, KERNEL_LOAD_ADDR ;内核加载地址
    mov ah,2                 ;功能号
    mov al,1                 ;扇区数
    mov dl,0                 ;驱动器号 ; 软盘为0，硬盘和U盘为80H
    mov dh,0                 ;磁头号 ; 起始编号为0
    mov ch,0                 ;柱面号 ; 起始编号为0
    mov cl,2                 ;起始扇区号 ; 起始编号为1
    int 13H                  ;调用读磁盘BIOS的13h功能 

    mov ax, 1
    mov bx, 2
    push ax
    push bx
    call c_start
    jmp $

asm_func:
    push bp
    mov bp, sp

times 510-($-$$) db 0
db 0x55,0xaa
