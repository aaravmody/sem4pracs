
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt


; add your code here   

DATA SEGMENT
    N1 DB 99h,20h,33h,44h,11h
    
ENDS

CODE SEGMENT
    Start:
    mov ax,data
    mov ds,ax
    
    mov ch,04h
    L1:
    LEA SI,N1
    MOV CL,04h
    
    L2:
    mov al,[si]
    mov bl,[si+1]
    cmp al,bl
    jc down
    mov dl,[si+1]
    xchg [si],dl
    mov [si+1],dl
    
    down:
    inc si
    dec cl
    jnz L2
    
    dec CH
    JNZ L1
    
CODE ENDS
END START

ret




