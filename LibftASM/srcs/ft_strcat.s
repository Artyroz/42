; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcat.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: dpollet <dpollet@student.42.fr>            +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2015/05/11 23:20:12 by dpollet           #+#    #+#              ;
;    Updated: 2015/05/14 01:37:10 by dpollet          ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

section .text
    global _ft_strcat
    extern _ft_strlen
    extern _ft_memcpy

_ft_strcat:
    mov rax, rdi
    cmp rsi, 0
    je finish
    jmp boucle1

boucle1:
    cmp [rdi], byte 0
    je boucle2
    inc rdi
    jmp boucle1

boucle2:
    cmp [rsi], byte 0
    je finish
    mov cl, [rsi]
    mov [rdi], cl
    inc rdi
    inc rsi
    jmp boucle2

finish:
    mov [rdi], byte 0
    ret 
