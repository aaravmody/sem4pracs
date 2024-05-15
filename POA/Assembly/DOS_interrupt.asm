DATA SEGMENT
    MSG DB 'ENTER A CHARACTER:$'
DATA ENDS

CODE SEGMENT
    ASSUME CS:CODE,DS:DATA
    START:
    MOV AX,DATA
    MOV DS,AX
    LEA SI,MSG
    
    MOV AH,09H   ;printing the message
    INT 21H
    
    MOV AH,01H    ;taking input
    INT 21H
    
    MOV DL,AL      ;storing input into DL
    
    MOV AH,02H     ;printing the stored input
    INT 21H
    
    MOV AH,4CH     ;indicate the end the program
    INT 21H
CODE ENDS 
END START