.model small
.stack
.code

mov cx, 10
mov ax, 5
call fatorial 
call write_int  ; funcao que imprime inteiros      
call endl       ; funcao mudar de linha 
mov ax, 12345
call write_int

mov ah, 4ch
int 21h
      

fatorial proc 
    push cx
    mov cx, ax
    dec cx
repita:
    mul cx
    loop repita 
    pop cx
    ret
fatorial endp 

write_int proc
    push ax
    push bx
    push cx
    push dx
    
    mov bx, 10    ; base resultante na conversao
    mov cx, 0     ; conta os restos empilhados
    dividir:
        mov dx,0
        div bx
        push dx
        inc cx    ; incrementa o contador de restos
        cmp ax, 0
        jne dividir
    mov ah, 02h   ; funcao para imprimir char na tela
    imprime:      
       pop dx
       add dl, 48
       int 21h
       loop imprime 
    
    pop dx
    pop cx
    pop bx
    pop ax
    ret
write_int endp

endl proc  
    push ax
    push dx
    mov ah, 02h 
    mov dl, 10
    int 21h
    mov dl, 13
    int 21h
    pop dx
    pop ax
    ret
endl endp
end 