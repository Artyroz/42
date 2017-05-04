; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_toupper.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: dpollet <dpollet@student.42.fr>            +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/10 01:40:45 by dpollet           #+#    #+#              ;
;    Updated: 2015/05/11 23:51:49 by dpollet          ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section .text
	global _ft_toupper

_ft_toupper:
	cmp rdi, 0
	je false
	cmp rdi, 97
	jl false
	cmp rdi, 122
	jle true

false:
	mov rax, rdi
	ret

true:
	mov rax, rdi
	sub rax, 32
	ret