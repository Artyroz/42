; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_tolower.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: dpollet <dpollet@student.42.fr>            +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/10 02:35:48 by dpollet           #+#    #+#              ;
;    Updated: 2015/05/11 23:51:39 by dpollet          ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section .text
	global _ft_tolower

_ft_tolower:
	cmp rdi, 0
	je false
	cmp rdi, 65
	jl false
	cmp rdi, 90
	jle true

false:
	mov rax, rdi
	ret

true:
	mov rax, rdi
	add rax, 32
	ret