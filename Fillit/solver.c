/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhusler <qhusler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 19:46:28 by qhusler           #+#    #+#             */
/*   Updated: 2016/05/11 19:46:40 by qhusler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	new_map(int size_map, char *map, t_tetris *p)
{
	int		i;
	int		x;

	x = 1;
	i = 0;
	while (x < size_map)
	{
		while (i < (size_map * x - 1))
			map[i++] = '.';
		map[i] = 10;
		i++;
		x++;
	}
	map[i - 1] = 0;
	i = 0;
	while (p[i].position != -1)
		p[i++].position = -1;
}

int		check_place(char *map, char *piece, int i, int size_map)
{
	int	z;
	int nb_ret;
	int	pos_x;

	nb_ret = 0;
	z = 0;
	pos_x = 0;
	while (piece[z] != '\0')
	{
		if (piece[z] == '#' && (map[i + pos_x + (size_map * nb_ret)] != '.'))
			return (0);
		pos_x++;
		if (piece[z] == '\n')
		{
			pos_x = 0;
			nb_ret++;
		}
		z++;
	}
	return (1);
}

void	place_piece(char *map, t_tetris pp, int i, int size_map)
{
	int	z;
	int nb_ret;
	int	pos_x;
	int pos;

	pos = 0;
	nb_ret = 0;
	z = 0;
	pos_x = 0;
	while (pp.piece[z] != '\0')
	{
		if (pp.piece[z] == '#' && map[i + pos_x + (size_map * nb_ret)] == '.')
		{
			map[i + pos_x + (size_map * nb_ret)] = pp.name;
			pos++;
		}
		pos_x++;
		if (pp.piece[z] == '\n')
		{
			pos_x = 0;
			nb_ret++;
		}
		z++;
	}
}

void	endmap(char *map, t_tetris *p, int y[2], int *i)
{
	int		iter;

	if (y[0] == 0)
	{
		y[1]++;
		new_map(y[1], map, p);
		*i = 0;
	}
	else if (y[0] >= 1)
	{
		y[0]--;
		iter = -1;
		while (map[++iter])
			if (map[iter] == p[y[0]].name)
				map[iter] = '.';
		*i = p[y[0]].position + 1;
	}
}

char	*ft_solve(char *map, t_tetris *p)
{
	int		i;
	int		y[2];

	y[1] = 3;
	y[0] = 0;
	i = 0;
	while (p[y[0]].piece != NULL)
	{
		if ((check_place(map, p[y[0]].piece, i, y[1])) == 1)
		{
			p[y[0]].position = i;
			place_piece(map, p[y[0]], i, y[1]);
			i = 0;
			y[0]++;
		}
		else
			i++;
		if (map[i] == '\0')
			endmap(map, p, y, &i);
	}
	return (map);
}
