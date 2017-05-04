; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_memset.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: dpollet <dpollet@student.42.fr>            +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/11 23:20:12 by dpollet           #+#    #+#              ;
;    Updated: 2015/05/11 23:52:09 by dpollet          ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section .text
    global _ft_memset

_ft_memset:
    cmp rdi, 0
    je fin
    mov r9, rdi
    mov rcx, rdx
    mov al, sil
    rep stosb
    mov rax, r9
    ret

fin:
    mov rax, rdi
    ret
