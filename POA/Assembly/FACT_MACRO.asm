FACT MACRO NUM
    MOV AX,01H
    L1:
    MUL NUM
    DEC NUM
    JNZ L1
    
ENDM

DATA SEGMENT
    NUM DW 5H  
    RESULT DW ?
ENDS

CODE SEGMENT
    START:
    MOV AX,DATA 
    MOV DS,AX
    MOV CX,NUM
    
    MOV AX,01H
    FACT NUM  
    MOV RESULT,AX
    
    CODE ENDS
END START
    
    
    
    
    