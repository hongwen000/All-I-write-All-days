.text
.globl main
main:
    la $a0, str
    li $v0, 4
    syscall

    li $v0, 10
    syscall

.data
    str:    
        .asciiz "hello world\n"
    memdata:
        .word  0xabcde080

