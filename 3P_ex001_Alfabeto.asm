.model small
.stack
.code
    mov AH,2
    mov DL,65
    mov CX,26
    
inicio:
    int 21h   
    inc DL
    loop inicio            
            
    mov AH,4CH
    int 21h
end