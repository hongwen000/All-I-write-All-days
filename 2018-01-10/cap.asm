DATA    SEGMENT
        SRC     DB  'abcdefGHIJ'
        COUNT   EQU  $-SRC
DATA    ENDS

EXTRA   SEGMENT
        DST     DB  COUNT DUP(?)
EXTRA   ENDS

CODE    SEGMENT
ASSUME  CS:CODE, DS:DATA, ES:EXTRA
BEGIN:  MOV AX, DATA
        MOV DS, AX
        MOV AX, EXTRA
        MOV ES, AX
        LEA SI, SRC
        LEA DI, DST
        MOV CX, COUNT
L:      LODS SRC
        AND AL, 0DFH
        STOS DST
        LOOP L
DONE:   MOV AH, 4CH
        INT 21H
CODE    ENDS
        END BEGIN