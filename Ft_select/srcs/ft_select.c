/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpollet <dpollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/10 19:34:55 by dpollet           #+#    #+#             */
/*   Updated: 2015/05/12 03:20:17 by dpollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		parse_agrv(t_lt **ax, char **av)
{
	int				a;

	a = 1;
	while (av[a])
	{
		add_cir(ax, av[a]);
		a++;
	}
}

int			compteur_ele(t_lt *ax, t_tr *tr)
{
	int				a;
	int				t;

	a = 0;
	t = 0;
	ax = ax->bf;
	while (a != tr->ln)
	{
		if (ax->sl == 1)
			t++;
		ax = ax->bf;
		a++;
	}
	return (t);
}

void		aff_sortie(char **sp)
{
	int				b;

	b = 0;
	while (sp[b])
	{
		ft_putstr(sp[b]);
		if (sp[b + 1])
			ft_putchar(' ');
		b++;
	}
}

void		aff_final(t_lt *ax, t_tr *tr)
{
	int				a;
	char			**sp;
	int				b;

	sp = (char **)ft_memalloc(sizeof(char *) * (compteur_ele(ax, tr) + 1));
	sp[compteur_ele(ax, tr)] = NULL;
	a = 0;
	b = 0;
	ax = ax->bf;
	while (a != tr->ln)
	{
		if (ax->sl == 1)
		{
			sp[b] = ft_strdup(ax->vl);
			b++;
		}
		ax = ax->bf;
		a++;
	}
	aff_sortie(sp);
}

int			main(int ac, char **av)
{
	t_lt			*ax;
	t_tr			tr;

	tr.ln = ac - 1;
	ax = NULL;
	parse_agrv(&ax, av);
	ft_signal();
	if (!init_term(&tr))
		return (-1);
	if (ac != 1)
		ft_select(&tr, &ax);
	if (!end_term(&tr))
		return (-1);
	aff_final(ax, &tr);
	return (0);
}
