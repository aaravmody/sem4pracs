
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

DATA SEGMENT
    N1 DW 05H
    FACT DW ?
    DATA ENDS

CODE SEGMENT
    START:
    MOV AX,DATA
    MOV DS,AX
    MOV AX,N1
    L1:
    DEC N1
    MUL N1
    MOV CX,N1
    CMP CX,01H
    JNZ L1
    MOV FACT,AX
    CODE ENDS
END START





