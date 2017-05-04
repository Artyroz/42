/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhusler <qhusler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 19:36:34 by qhusler           #+#    #+#             */
/*   Updated: 2016/05/12 03:13:31 by qhusler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	putchar_color(char *s1, char c)
{
	ft_putstr(s1);
	ft_putchar(c);
	ft_putstr("\x1b[0m");
}

void	print_map_color(char *map, t_tetris *pieces)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map && map[i])
	{
		if (map[i] == 10)
			ft_putchar(map[i++]);
		if (map[i] == '.')
			putchar_color("\x1b[38;5;232m", map[i++]);
		if (map[i] >= 'A' && map[i] <= 'Z')
		{
			while (map[i] != pieces[j].name)
				j++;
			putchar_color(pieces[j].lettre, map[i]);
			i++;
			j = 0;
		}
	}
	ft_putchar(10);
}
