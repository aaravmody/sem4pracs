DATA SEGMENT
    N1 DB 5,4,3,2,1
    LEN DW 5
    ANS DW ?  
ENDS
        
          
CODE SEGMENT
    START:
    MOV AX,DATA
    MOV DS,AX
    
    LEA SI,N1
    MOV CX,LEN
    XOR AX,AX
    
    SUM:
    MOV AL,N1[SI]
    ADD BL,AL
    INC SI
    LOOP SUM
    
    MOV ANS,BX
    
    
ENDS
END START
    