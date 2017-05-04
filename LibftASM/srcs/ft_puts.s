; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_puts.s                                          :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: dpollet <dpollet@student.42.fr>            +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/10 02:41:58 by dpollet           #+#    #+#              ;
;    Updated: 2015/05/11 23:59:36 by dpollet          ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section .data
    null:
        .string db "(null)"
    
section .text
    global _ft_puts
    extern _ft_strlen

_ft_puts:
    cmp rdi, 0x0
    je fin
    push rdi
    call _ft_strlen
    mov rdx, rax
    pop rsi
    mov rdi, 1
    mov rax, 0x2000004
    syscall
    jmp final

fin:
    mov rdi, 1
    lea rsi, [rel null.string]
    mov rdx, 6
    mov rax, 0x2000004
    syscall

final:
    push 0xa
    mov rsi, rsp 
    mov rdi, 1
    mov rdx, 1
    mov rax, 0x2000004
    syscall
    pop rax
    ret
