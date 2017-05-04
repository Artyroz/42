; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isascii.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: dpollet <dpollet@student.42.fr>            +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/11 23:20:12 by dpollet           #+#    #+#              ;
;    Updated: 2015/05/11 23:44:25 by dpollet          ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section .text
	global  _ft_isascii

_ft_isascii:
    cmp rdi, 0
    jl fin
    cmp rdi, 127
    jg fin
    mov rax, 1
    ret

fin:
    mov rax, 0
    ret
