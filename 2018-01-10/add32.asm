DATA    SEGMENT
        OP1     DW  5678H, 1234H
        ;❌这里别忘了开头的0️⃣
        OP2     DW  0EF01H, 0ABCDH
        RESULT  DW  2 DUP(?)
DATA    ENDS

CODE    SEGMENT
        ASSUME  DS:DATA, CS:CODE
BEGIN:  MOV AX, DATA
        ;❌这里写成了MOV DX, AX
        MOV DS, AX
        MOV AX, OP1
        MOV BX, OP2
        ADD AX, BX
        MOV RESULT, AX
        ;❌这里要+2而不是+1
        MOV AX, OP1 + 2
        MOV BX, OP2 + 2
        ADC AX, BX
        ;❌这里也是要加2
        MOV RESULT + 2, AX
        ;❌这里别忘了返回DOS
        MOV AH, 4CH
        INT 21H
CODE    ENDS
        END BEGIN