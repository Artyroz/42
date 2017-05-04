; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_cat.s                                           :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: dpollet <dpollet@student.42.fr>            +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/11 23:20:12 by dpollet           #+#    #+#              ;
;    Updated: 2015/05/11 23:59:37 by dpollet          ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;


section	.data
	_null:	db	0

section	.text
	global	_ft_cat

_ft_cat:
	push rdi
	mov r9, rdi
	jmp boucle

boucle:

	mov rax, 0x2000003
	mov rdi, r9
	lea rsi, [rel _null]
	mov rdx, 1
	syscall
	cmp rax, 1
	jne fin
	mov rax, 0x2000004
	mov rdi, 1
	lea rsi, [rel _null]
	mov rdx, 1
	syscall
	cmp rax, -1
	je fin
	jmp boucle

fin:
	pop 	rdi
	mov 	rax, 0
	ret
