ASSUME DS:DATA, CS:CODE, ES:EXTRA

DATA    SEGMENT
        SRC     DB  0,1,2,3,4,5,6,7,8,9
        COUNT   DW  $-SRC
DATA    ENDS

EXTRA   SEGMENT
        DST     DB  10 DUP(?)
EXTRA   ENDS

CODE    SEGMENT
BEGIN:  MOV AX, DATA
        MOV DS, AX
        MOV AX, EXTRA
        MOV ES, AX
        LEA SI, SRC
        LEA DI, DST
        MOV CX, COUNT
L:      MOV DL, [SI]
        ;❌这里要指定ES段
        MOV ES:[DI], DL
        ;❌这里SI，DI不会自增
        INC SI
        INC DI
        LOOP L
        MOV AH, 4CH
        INT 21H
CODE    ENDS
        END BEGIN
