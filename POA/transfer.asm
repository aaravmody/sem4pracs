
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt
             
             

           
DATA SEGMENT
    N1 DB 45H,32H,36H
DATA ENDS    

EXTRA SEGMENT
    N2 DB ?
EXTRA ENDS


CODE SEGMENT
    START:
    MOV AX,DATA
    MOV DS,AX
    
    MOV AX,EXTRA
    MOV ES,AX
    
    LEA SI,N1
    LEA DI,N2    
    
    MOV CL,04H
    
    L1:
    MOV AX,DS:[SI]
    MOV ES:[DI],AX
    
    INC SI
    INC DI
    DEC CL
    
    JNZ L1
ENDS
END START



ret




