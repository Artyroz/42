; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strlen.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: dpollet <dpollet@student.42.fr>            +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/11 23:20:12 by dpollet           #+#    #+#              ;
;    Updated: 2015/05/11 23:51:18 by dpollet          ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global  _ft_strlen
    section .text

_ft_strlen:
    cmp rdi, 0
    je fin
    mov rcx, -1
    mov al, 0
    repnz scasb
    mov rax, rcx
    neg rax
    sub rax, 2
    ret

fin:
    mov rax, 0
    ret
