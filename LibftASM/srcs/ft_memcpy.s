; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_memcpy.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: dpollet <dpollet@student.42.fr>            +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/10 17:30:23 by dpollet           #+#    #+#              ;
;    Updated: 2015/05/11 23:51:55 by dpollet          ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section .text
	global _ft_memcpy

_ft_memcpy:
	mov rax, rdi
	mov rcx, rdx
	push rsi
	cmp rsi, 0
	je fin
	rep movsb

fin:
	pop rsi
	ret