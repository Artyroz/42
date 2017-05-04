/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   touche.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpollet <dpollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/10 21:39:12 by dpollet           #+#    #+#             */
/*   Updated: 2015/05/12 03:26:00 by dpollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			f_haut(t_lt **ax)
{
	t_lt			*tp;

	tp = (*ax);
	while ((*ax)->s != 1)
		(*ax) = (*ax)->bf;
	(*ax)->s = 0;
	(*ax)->nt->s = 1;
	(*ax) = tp;
}

void			f_bas(t_lt **ax)
{
	t_lt			*tp;

	tp = (*ax);
	while ((*ax)->s != 1)
		(*ax) = (*ax)->bf;
	(*ax)->s = 0;
	(*ax)->bf->s = 1;
	(*ax) = tp;
}

void			f_sel(t_lt **ax)
{
	t_lt			*tp;

	tp = (*ax);
	while ((*ax)->s != 1)
		(*ax) = (*ax)->bf;
	(*ax)->s = 0;
	(*ax)->bf->s = 1;
	(*ax)->sl = ((*ax)->sl) ? 0 : 1;
	(*ax) = tp;
}

void			f_del(t_lt **ax, t_tr **tr)
{
	t_lt			*tp;

	tp = (*ax);
	while ((*ax)->s != 1)
		(*ax) = (*ax)->bf;
	(*ax)->bf->s = 1;
	(*ax)->bf->nt = (*ax)->nt;
	(*ax)->nt->bf = (*ax)->bf;
	(*ax) = tp;
	(*tr)->ln--;
	if ((*tr)->ln == 0)
	{
		end_term(*tr);
		exit(0);
	}
}
