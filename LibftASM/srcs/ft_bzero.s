; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_bzero.s                                         :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: dpollet <dpollet@student.42.fr>            +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/11 23:20:12 by dpollet           #+#    #+#              ;
;    Updated: 2015/05/11 23:52:28 by dpollet          ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section	.text
	global	_ft_bzero

_ft_bzero:
	mov	rbx, rdi
	mov	rcx, 0
		
boucle:
	cmp	rcx, rsi
	je	fin
	mov	byte [rbx], 0
	inc	rbx
	inc	rcx
	jmp	boucle

fin:
	ret
