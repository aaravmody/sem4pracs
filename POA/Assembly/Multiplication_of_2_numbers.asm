data segment
    num1 dw 2
    num2 dw 3
    result dw ?
ends

code segment
    start:
    mov ax, data
    mov ds, ax
    
    mov ax, num1
    mov bx, num2
    mul bx 
    
    mov result, ax  
ends
end start