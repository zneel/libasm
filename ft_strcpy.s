global ft_strcpy

ft_strcpy:
    xor rcx, rcx

.loop:
    mov rdx, [rsi + rcx] ; move str char (rdx+rcx) into rdx
    cmp rdx, 0 ; check if rdx+rcx is 0
    je .done ; goto done
    mov [rdi + rcx], rdx ; dst[i] = src[i]
    inc rcx ; i++
    jmp .loop

.done:
    mov byte [rdi + rcx], 0 ; nullbyte at end
    mov rax, rdi ; copy result in rax
    ret
