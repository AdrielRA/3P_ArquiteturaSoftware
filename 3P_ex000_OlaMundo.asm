.model small
.stack
.code
    mov AH,2
    mov DL,79
    int 21h
    mov DL,76
    int 21h
    mov DL,160
    int 21h
    mov DL,' '
    int 21h
    mov DL,'M'
    int 21h
    mov DL,'u'
    int 21h
    mov DL,'n'
    int 21h
    mov DL,'d'
    int 21h
    mov DL,'o'
    int 21h
    mov DL,'!'
    int 21h
    
    mov AH,4CH
    int 21h
end