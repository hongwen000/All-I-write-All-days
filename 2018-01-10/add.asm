DATA    SEGMENT
BUF1    DB  6
        DB  ?
        DB  6 DUP (?)
RES1    DW  ?
BUF2    DB  6
        DB  ?
        DB  6 DUP (?)
MSG1    DB  'ERROR: Input contains non-digit character', 0DH, 0AH, '$'
MSG2    DB  'ERROR: Input overflow', 0DH, 0AH, '$'
DATA    ENDS

CODE    SEGMENT
ASSUME  DS:DATA, CS:CODE
BEGIN:  
        MOV AX, DATA
        MOV DS, AX

        MOV DX, OFFSET BUF1
        MOV AH, 0AH
        INT 21H
        MOV DL, 0AH
        MOV AH, 02H
        INT 21H

        MOV DX, OFFSET BUF2
        MOV AH, 0AH
        INT 21H
        MOV DL, 0AH
        MOV AH, 02H
        INT 21H

        MOV BX, 0       ;储存临时结果
        MOV CH, 0
        MOV CL, BUF1 + 1 ;对于每一个字符
        MOV AH, 0
        LEA SI, BUF1 + 2
        CALL CONV
        MOV RES1, BX

        MOV BX, 0       ;储存临时结果
        MOV CH, 0
        MOV CL, BUF2 + 1 ;对于每一个字符
        MOV AH, 0
        LEA SI, BUF2 + 2
        CALL CONV

        ADD BX, RES1
        JC  ERR2
        MOV AX, BX
        MOV CX, 0
        MOV BX, 0AH
        ;❎用16位除数除法较方便，因为商直接更新给AX
        ;⚠️八位的话，新的商是AL
        ;所以要DX清零
        ;❌❎❌
        ;错误，是每次都要DX清零
        ;MOV DX, 0

EXTR:   MOV DX, 0
        DIV BX
        ;❎PUSH AX
        PUSH DX
        INC CX
        CMP AL, 0
        JNZ EXTR

RESULT: POP DX
        OR DL, 30H
        MOV AH, 02H
        INT 21H
        DEC CX
        JNZ RESULT

        ;❌❎❌
        ;搞了半天，是这儿AH
DONE:   MOV AH, 4CH
        INT 21H
ERR1:   LEA DX, MSG1
        JMP OUTPUT
ERR2:   LEA DX, MSG2
OUTPUT: MOV AH, 9
        INT 21H
        JMP DONE
CONV    PROC    NEAR
L1:     CLD     
        LODSB           ;将一个字符载入AL
        CMP AL, 30H
        JB  ERR1
        CMP AL, 39H
        JA  ERR1
        AND AL, 0FH
        ADD BX, BX      ;2 * BX
        JC  ERR2
        MOV DX, BX      ;DX = 2 * BX
        ADD BX, BX      ;4 * BX
        JC  ERR2
        ADD BX, BX      ;8 * BX
        JC  ERR2
        ADD BX, DX
        JC  ERR2        ;10 * BX
        ADD BX, AX
        JC ERR2
        LOOP L1
        RET
CODE    ENDS
        END BEGIN
