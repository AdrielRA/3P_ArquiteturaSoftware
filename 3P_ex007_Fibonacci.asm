.model small
.stack
.code 
mov ax, 36 ; posicao sequencia fibonacci
mov cx, ax
call fibonacci
call write_int
mov ah, 4ch
int 21h  

fibonacci proc
    push dx
    push bx
    
    mov bx, 1
    mov dx, 0
    cmp ax, 3
    jb pula
    dec cx
    calcula:
        mov ax, 0
        add ax, dx
        mov dx, bx
        add ax, bx
        mov bx, ax
        loop calcula
        jmp fim
    pula:
        mov ax, 1
    fim:
        pop bx 
        pop dx
    ret
fibonacci endp 


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

end