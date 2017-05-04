/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execut.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpollet <dpollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/10 19:50:54 by dpollet           #+#    #+#             */
/*   Updated: 2015/05/12 03:05:46 by dpollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_tr			*stock(t_tr *tr, int a)
{
	static t_tr		*tp = NULL;

	if (a == 0)
		tp = tr;
	return (tp);
}

t_lt			*stock_lt(t_lt *lt, int a)
{
	static t_lt		*tp = NULL;

	if (a == 0)
		tp = lt;
	return (tp);
}

void			analyse_touche(char **buf, t_tr *tr, t_lt **ax)
{
	if (BUF == F_HAUT)
		f_haut(ax);
	if (BUF == F_BAS)
		f_bas(ax);
	if (BUF == ESP)
		f_sel(ax);
	if ((BUF == DEL) || (BUF == DEL2))
		f_del(ax, &tr);
	if (BUF == HOME)
		f_home(*ax);
	if (BUF == END)
		f_end(*ax);
	if (BUF == A)
		f_a(*ax, tr);
	if (BUF == TAB)
		f_tab(*ax, tr);
}

void			ft_select(t_tr *tr, t_lt **ax)
{
	char			*buf[5];

	tr = stock(tr, 0);
	while (1)
	{
		ft_bzero(buf, 5);
		*ax = stock_lt(*ax, 0);
		rediment();
		read(0, buf, 4);
		if (tr->st == 0)
		{
			analyse_touche(buf, tr, ax);
			if (BUF == ENTRER)
				break ;
		}
		if (BUF == ESC)
			break ;
		tputs(tgetstr("cl", NULL), 1, ft_putchar_spe);
	}
}
