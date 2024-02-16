; char *strcpy(char *restrict dst, const char *restrict src)
; {
;     size_t i = 0;
;     while (src[i])
;     {
;         dst[i] = src[i];
;         i++;
;     }
;     dst[i] = 0;
;     return dst;
; }

section .text
    global ft_strcpy

ft_strcpy:
    push rbp;
    mov rbp, rsp; ; setup stack frame
    mov rdx, 0 ; size_t i = 0
    jmp .loop

.loop:
    cmp byte [rsi + rdx], 0 ; src[i] != 0
    je .done ; goto done
    movzx rax, byte [rsi + rdx] ; store temp src[i]
    mov byte [rdi + rdx], al ; dst[i] = src[i]
    add rdx, 1 ; i++

.done:
    mov byte [rdi + rdx], 0
    mov rax, rdi
    pop rbp;
    ret
