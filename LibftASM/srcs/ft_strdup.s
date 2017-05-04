; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strdup.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: dpollet <dpollet@student.42.fr>            +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/11 23:20:12 by dpollet           #+#    #+#              ;
;    Updated: 2015/05/14 01:35:20 by dpollet          ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section .text
	global  _ft_strdup
	extern  _ft_strlen
	extern 	_malloc
	extern	_ft_memcpy

_ft_strdup:
	mov	rbx, rdi
	call _ft_strlen
	mov	rdi, rax
	inc	rdi
	push rdi
	call _malloc
	cmp rax, 0
	je fin
	mov rdi, rax
	mov rsi, rbx
	pop rdx
	call _ft_memcpy

fin:
	ret