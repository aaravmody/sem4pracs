data segment
    arr db 1,2,3,4,5 
    len dw $-arr 
    avg dw ? 
ends

code segment
    assume cs:code, ds:data
    start:
    mov ax, data
    mov ds, ax
    lea si, arr
    mov cx, len
    xor ax, ax
    sum:
    mov al, arr[si]
    add bx, ax
    inc si
    loop sum
    mov ax,bx   
    mov cx, len
    div cx     
    mov avg, ax
    mov ax, 4ch
    int 21h
ends
end start