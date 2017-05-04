/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhusler <qhusler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 19:46:05 by qhusler           #+#    #+#             */
/*   Updated: 2016/05/11 19:46:20 by qhusler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int					basic_test(char *s)
{
	int i;
	int c;

	if (!s)
		return (0);
	if (ft_strlen(s) == 20)
		return (s[4] == 10 && s[9] == 10 && s[14] == 10 && s[19] == 10 ? 1 : 0);
	i = 4;
	c = 0;
	while (s[i])
	{
		if (s[i] != 10)
			return (0);
		i += (c == 3) ? 6 : 5;
		c += (c == 4) ? 0 : 1;
		if (c == 4 && s[i] == 0)
			return (1);
		c = (c == 4) ? 0 : c;
	}
	return (0);
}

static int			connex_test(char *map, int i)
{
	int			n_co;
	static int	y = 0;

	y++;
	n_co = 0;
	i = (i == 2) ? 0 : i;
	while (map[i])
	{
		if (map[i] == 10 && (map[i + 1] == 10 || map[i + 1] == 0))
			return ((n_co >= 3) ? 1 : 0);
		if (map[i] == '#')
		{
			n_co += (map[i + 1] == '#') ? 1 : 0;
			n_co += (i + 5 < (y * 21) && map[i + 5] == '#') ? 1 : 0;
		}
		i++;
	}
	return ((n_co >= 3) ? 1 : 0);
}

int					hard_test(char *map, t_check_tet *t)
{
	while (map && map[t->i])
	{
		if (t->i == 0 || (map[t->i] == 10 && map[t->i + 1] == 10))
			if (connex_test(map, t->i + 2) == 0)
				return (0);
		if (map[t->i] != '.' && map[t->i] != '#' && map[t->i] != 10)
			return (0);
		t->nb_dot += (map[t->i] == '.') ? 1 : 0;
		t->nb_dieze += (map[t->i] == '#') ? 1 : 0;
		if (t->nb_dot > 12 || t->nb_dieze > 4)
			return (0);
		if (map[t->i] == 10 && (map[t->i + 1] == 10 || map[t->i + 1] == 0))
		{
			if (t->nb_dot != 12 || t->nb_dieze != 4 ||
					map[t->i - 1] == 10 || t->nb_tet > 26)
				return (0);
			t->nb_dieze = 0;
			t->nb_dot = 0;
			t->nb_tet++;
		}
		t->i++;
	}
	return (1);
}

int					parsing_main(char *map, int *nb_tetriminos)
{
	t_check_tet		t;

	t.i = 0;
	t.nb_tet = 0;
	t.nb_dieze = 0;
	t.nb_dot = 0;
	if (basic_test(map) == 0)
		return (0);
	if (hard_test(map, &t) == 0)
		return (0);
	if ((t.nb_tet) < 1)
		return (0);
	*nb_tetriminos = t.nb_tet;
	return (1);
}
