
global ft_strcmp

ft_strcmp:
    xor rcx, rcx
    xor rax, rax

.loop:
    cmp byte [rdi + rcx], 0; while (s1[i]
    je .end; if (s1[i] == 0)
    cmp byte [rsi + rcx], 0; && s2[i]
    je .end; && s2[i] == 0
    mov al, [rdi + rcx]; copy s1[i]
    cmp al, [rsi + rcx]; if (s1[i] == s2[i])
    jne .end; && s1[i] != s2[i]
    inc rcx; i++
    jmp .loop

.end:
    mov rax, [rdi + rcx]; push s1[i]
    sub rax, [rsi + rcx]; substract s1[i] with s2[i]
    ret

