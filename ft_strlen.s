; size_t ft_strlen(const char *s)
; {
;     size_t i = 0;
;     while (s[i])
;         i++;
;     return (i);
; }

section .text
    global ft_strlen

ft_strlen:
    push rbp
    mov rbp, rsp ; setup stackframe
    mov rdx, 0 ; size_t i = 0
    jmp .loop

.loop:
    cmp byte [rdi + rdx], 0 ; compare str[i]
    je .done ; if str[i] == '\0' goto done
    add rdx, 1 ; i++
    jmp .loop ; goto loop

.done:
    mov rax, rdx ; return i
    pop rbp ; restore stack
    ret