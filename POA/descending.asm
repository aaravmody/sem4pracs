
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt


Data segment
    N1 DB 25h,64h,11h,28h,2h
Ends

CODE SEGMENT
    START:
    MOV AX,data
    Mov ds,ax
    
    mov ch,04h
    L1:
    LEA SI,N1
    MOV CL,04h
    
    L2:
    MOV AL,[SI]
    MOV BL,[SI+1]
    CMP AL,BL
    jnc down
    mov dl,[si+1]
    xchg [si],dl
    mov [si+1],dl
    
    down:
    inc si
    dec cl
    jnz L2
    
    dec ch
    jnz L1

CODE ENDS
END START



