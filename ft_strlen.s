global ft_strlen

ft_strlen:
    xor rax, rax

.loop:
    cmp byte [rdi], 0 ; check if current byte is null
    je .done
    inc rax ; increment output
    inc rdi ; increment str
    jmp .loop

.done:
    ret
