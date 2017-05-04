/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   touche2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpollet <dpollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/12 02:36:47 by dpollet           #+#    #+#             */
/*   Updated: 2015/05/12 03:12:07 by dpollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	f_home(t_lt *lt)
{
	t_lt			*tp;

	tp = lt->bf;
	lt->bf->s = 1;
	lt = lt->bf->bf;
	while (lt->s != 1)
		lt = lt->bf;
	if (tp != lt)
		lt->s = 0;
}

void	f_end(t_lt *lt)
{
	t_lt			*tp;

	tp = lt;
	lt->s = 1;
	lt = lt->bf;
	while (lt->s != 1)
		lt = lt->bf;
	if (tp != lt)
		lt->s = 0;
}

void	f_deselect(t_lt *lt, t_tr *tr)
{
	int		a;

	a = 0;
	while (a < tr->ln)
	{
		lt->sl = 0;
		lt = lt->bf;
		a++;
	}
}

void	f_a(t_lt *lt, t_tr *tr)
{
	int		a;
	int		fl;

	a = 0;
	fl = 0;
	while (a < tr->ln)
	{
		if (lt->sl == 0)
		{
			lt->sl = 1;
			fl = 1;
		}
		lt = lt->bf;
		a++;
	}
	if (!fl)
		f_deselect(lt, tr);
}

void	f_tab(t_lt *lt, t_tr *tr)
{
	f_deselect(lt, tr);
	f_sel(&lt);
}
