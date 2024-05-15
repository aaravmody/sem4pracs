
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

DATA SEGMENT
    N1 DB 12H,33H,75H,21H,45H  
    MAX DB ?
    MIN DB ?
ENDS

CODE SEGMENT
    START:
    MOV AX,DATA
    MOV DS,AX
    
    MOV CH,04H
    L1:
    LEA SI,N1  
    MOV CL,04H
    
    L2:
    MOV AL,[SI]
    MOV BL,[SI+1]
    CMP AL,BL
    JC JUMP
    MOV DL,[SI]
    XCHG [SI+1],DL
    MOV [SI],DL
    
    JUMP:
    INC SI
    DEC CL
    JNZ L2
    
    DEC CH
    JNZ L1 
    
MOV DL,[SI]
MOV MAX,DL
MOV DL,[SI-4]  
MOV MIN,DL

ENDS
END START


ret




