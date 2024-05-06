
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

; add your code here  

org 100h
mov AX,30h
mov BX,10h
mov CL,00h
SUB AX,BX
MOV [1004h],AX
JNC jump
INC CL
jump:
MOV [1006h],CL
HLT
ret




