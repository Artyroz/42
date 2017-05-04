/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpollet <dpollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/10 19:37:25 by dpollet           #+#    #+#             */
/*   Updated: 2015/05/12 02:27:10 by dpollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		aff(char *vl)
{
	ft_putstr_fd("\033[36m", 2);
	ft_putendl_fd(vl, 2);
	ft_putstr_fd("\033[00m", 2);
}

void		affichage_element(t_lt *ax)
{
	if ((ax->s == 1) && (ax->sl == 1))
	{
		tputs(tgetstr("us", NULL), 1, ft_putchar_spe);
		tputs(tgetstr("so", NULL), 1, ft_putchar_spe);
		aff(ax->vl);
		tputs(tgetstr("se", NULL), 1, ft_putchar_spe);
		tputs(tgetstr("ue", NULL), 1, ft_putchar_spe);
	}
	else if (ax->s == 1)
	{
		tputs(tgetstr("us", NULL), 1, ft_putchar_spe);
		aff(ax->vl);
		tputs(tgetstr("ue", NULL), 1, ft_putchar_spe);
	}
	else if (ax->sl == 1)
	{
		tputs(tgetstr("so", NULL), 1, ft_putchar_spe);
		aff(ax->vl);
		tputs(tgetstr("se", NULL), 1, ft_putchar_spe);
	}
	else
		ft_putendl_fd(ax->vl, 2);
}

void		aff_ls(t_lt *ax, t_tr *tr)
{
	int				a;

	a = 0;
	ax = ax->bf;
	while (a != tr->ln)
	{
		affichage_element(ax);
		ax = ax->bf;
		a++;
	}
}

void		add_cir(t_lt **ax, char *vl)
{
	t_lt			*ns;

	ns = (t_lt *)ft_memalloc(sizeof(t_lt));
	ns->nt = ns;
	ns->bf = ns;
	ns->vl = vl;
	ns->s = ((*ax)) ? 0 : 1;
	ns->sl = 0;
	ns->ln = ft_strlen(vl);
	if ((*ax) == NULL)
		(*ax) = ns;
	ns->bf = (*ax)->bf;
	ns->nt = (*ax);
	(*ax)->bf->nt = ns;
	(*ax)->bf = ns;
	(*ax) = ns;
}
