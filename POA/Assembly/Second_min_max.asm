

DATA SEGMENT
    N1 DB 45H,78H,98H,89H,66H
    SECMAX DB ?
    SECMIN DB ?
DATA ENDS

CODE SEGMENT
ASSUME CS:CODE,DS:DATA
START:
    MOV AX,DATA
    MOV DS,AX
    MOV CH,04H                ;CX(16 bytes) register mein 2 parts hote hai CL(low byte-8bytes) and CH(high byte-8bytes) IMP FOR VIVA

    L1:
        LEA SI,N1             ;load address of array N1 into Start index
        MOV CL, 04H           ;counter of main loop to iterate over all elements in array N1

        L2:
            MOV AL,[SI]       ;index i in AL and index i+1 in BL
            MOV BL,[SI+1]
            CMP AL,BL
            JC JUMP           ;index [i] value < index [i+1] value , sorted hai dono aapas mein
            MOV DL,[SI+1]     ;DL is used as a temp in basic bubble sort to swap places
            XCHG [SI],DL
            MOV [SI+1],DL
    
    JUMP:
    INC SI
    DEC CL
    JNZ L2
    DEC CH
    JNZ L1 
MOV DL,[SI-1]
MOV SECMAX,DL
MOV DL,[SI-3]
MOV SECMIN,DL

CODE ENDS    
END START

ret



