; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_isalnum.s                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: dpollet <dpollet@student.42.fr>            +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/11 23:20:12 by dpollet           #+#    #+#              ;
;    Updated: 2015/05/11 23:43:07 by dpollet          ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section .text
    global  _ft_isalnum
    extern  _ft_isalpha
    extern  _ft_isdigit

_ft_isalnum:
    call _ft_isalpha
    cmp rax, 1
    je isalnum
    call _ft_isdigit
    cmp rax, 1
    je isalnum
    mov rax, 0
    ret

isalnum:
    mov rax, 1
    ret
