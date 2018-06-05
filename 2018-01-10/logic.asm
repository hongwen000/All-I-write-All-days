ASSUME  CS:CODE, DS:DATA

DATA    SEGMENT
        OP1 DB  1,2,3,4,5,6,7,8,9
        OP2 DB  4,3,5,6,1,2,4,7,8
        CNT EQU $-OP2
        ;❌这里要填满16位，不然前面会自动填充很多零
        RUL DW  0000111110000000B
DATA    ENDS

EXTRA   SEGMENT
        ANS DB  CNT DUP(?)
EXTRA   ENDS

CODE    SEGMENT
BEGIN:
        MOV AX, DATA
        MOV DS, AX
        MOV AX, EXTRA
        MOV ES, AX
        LEA SI, OP1
        LEA DI, ANS
        MOV BX, RUL
        MOV CX, CNT
L:      
        LODSB
        SHL BX, 1
        JC  SUBT
        ;❌，LODSB后SI已经+1，所以要减1
        ADD AL, [SI + CNT - 1]
        JMP SAVE
SUBT:    
        SUB AL, [SI + CNT - 1]
SAVE:   
        STOSB
        CMP CX, CNT
        LOOP L
DONE:   MOV AH, 4CH
        INT 21H
CODE    ENDS
        END BEGIN