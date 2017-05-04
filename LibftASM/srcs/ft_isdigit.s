; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isdigit.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: dpollet <dpollet@student.42.fr>            +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/11 23:20:12 by dpollet           #+#    #+#              ;
;    Updated: 2015/05/11 23:45:08 by dpollet          ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section .text
	global _ft_isdigit

_ft_isdigit:
    cmp rdi, 48
    jl fin
    cmp rdi, 57
    jg fin
    mov rax, 1
    ret

fin:
    mov rax, 0
    ret
