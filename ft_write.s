; section .data
;     extern __errno_location

global ft_write

ft_write:
    mov rax, 1 ; 1 = write syscall
    syscall
    ; jc _error ; if carryflag goto error
    ret

; _error:
;     mov rdi, rax ; set rax as param for errno
;     call __errno_location wrt ..plt
;     mov [rax], rdi ; set errno ptr to rdi;
;     mov rax, -1 ; return -1
;     ret

