; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isprint.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: dpollet <dpollet@student.42.fr>            +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/11 23:20:12 by dpollet           #+#    #+#              ;
;    Updated: 2015/05/11 23:45:56 by dpollet          ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section .text
    global _ft_isprint

_ft_isprint:
    cmp rdi, 32
    jl fin
    cmp rdi, 127
    jge analyse
    mov rax, 1
    ret

analyse:
    cmp rdi, 130
    jl fin
    cmp rdi, 176
    jg fin
    mov rax, 1
    ret

fin:
    mov rax, 0
    ret
