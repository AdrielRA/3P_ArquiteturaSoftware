.model small
.stack
.code
    mov ax,5
    mov cx,ax
    dec cx
repita:
    mul cx
    loop repita
    
    mov ah,4ch
    int 21h
end    