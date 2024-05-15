
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

DATA SEGMENT
    N1 DW 5H
    FACT DW ?
ENDS
        
FACTO MACRO 
    MOV AX,N1
    
    L1:
    DEC N1
    MUL N1
    MOV CX,N1
    CMP CX,01H
    JNZ L1
ENDM

    
CODE SEGMENT 
    START:
    MOV AX,DATA
    MOV DS,AX
    FACTO
    MOV FACT,AX
ENDS
END START
    
ret




