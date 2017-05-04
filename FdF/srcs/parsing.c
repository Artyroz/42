/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpollet <dpollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 11:01:34 by dpollet           #+#    #+#             */
/*   Updated: 2015/05/19 17:16:10 by dpollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_init_mlx(t_env *e)
{
	if (!(e->mlx = mlx_init()))
		return (1);
	e->window = mlx_new_window(e->mlx, 1280, 720, "FDF");
	e->r = 100;
	e->g = 100;
	e->b = 100;
	e->zoom = 30;
	e->z_ch = 1;
	return (0);
}

int		event_demander(t_env *e)
{
	aff(e);
	return (0);
}

void	parse_final(t_env *e, char **split, int *x, int y)
{
	int		j;

	j = 0;
	while (split[j] && *x != e->max_x)
	{
		e->map[y][*x] = ft_atoi(split[j]);
		(*x)++;
		j++;
	}
	while (*x != e->max_x)
	{
		e->map[y][*x] = INVALID_Z;
		(*x)++;
	}
}
