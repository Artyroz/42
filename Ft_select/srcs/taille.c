/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   taille.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpollet <dpollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 04:44:29 by dpollet           #+#    #+#             */
/*   Updated: 2015/05/12 02:25:21 by dpollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int				recup_ln(t_lt *lt, t_tr *tr)
{
	int					a;
	int					mx;

	a = 0;
	mx = lt->ln;
	while (a < tr->ln)
	{
		if (lt->ln > mx)
			mx = lt->ln;
		lt = lt->bf;
		a++;
	}
	return (mx);
}

void			rediment(void)
{
	t_tr				*tr;
	t_lt				*lt;
	struct winsize		wn;
	int					a;

	a = 0;
	tr = NULL;
	lt = NULL;
	lt = stock_lt(lt, 1);
	tr = stock(tr, 1);
	tputs(tgetstr("cl", NULL), 1, ft_putchar_spe);
	ioctl(0, TIOCGWINSZ, &wn);
	tr->col = wn.ws_col;
	tr->lig = wn.ws_row;
	a = recup_ln(lt, tr);
	if ((tr->col > a) && (tr->lig > tr->ln))
	{
		aff_ls(lt, tr);
		tr->st = 0;
	}
	else
	{
		ft_putstr_fd("Trop petit !!!", 2);
		tr->st = 1;
	}
}
