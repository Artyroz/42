/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpollet <dpollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 10:06:04 by dpollet           #+#    #+#             */
/*   Updated: 2015/05/19 17:14:33 by dpollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		strlen_espace(char *line)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i] + 0) == 1)
		{
			j++;
			while (ft_isdigit(line[i] + 0) == 1)
				i++;
		}
		i++;
	}
	return (j);
}

void	compteur_max(char *argv, t_env *e)
{
	char	*line;
	int		x;
	int		y;
	int		l;
	int		fd;

	l = 0;
	y = 0;
	x = 0;
	fd = 0;
	fd = open(argv, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		l = strlen_espace(line);
		if (l > x)
			x = l;
		y++;
		if (line)
			free(line);
	}
	close(fd);
	e->max_x = x;
	e->max_y = y - 1;
}

void	parse_map(char *argv, t_env *e)
{
	char	*line;
	char	**split;
	int		y;
	int		x;
	int		fd;

	x = 0;
	y = 0;
	split = NULL;
	if (!argv)
		return ;
	fd = open(argv, O_RDONLY);
	e->map = (int**)malloc(sizeof(int*) * e->max_y);
	while (get_next_line(fd, &line) == 1 && y != e->max_y)
	{
		e->map[y] = (int*)malloc(sizeof(int) * e->max_x);
		split = ft_strsplit(line, ' ');
		if (split)
			parse_final(e, split, &x, y);
		x = 0;
		if (split)
			free(split);
		y++;
	}
	close(fd);
}

int		commande_touche(int keycode, t_env *e)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 12 && e->r + 10 < 255)
		e->r = e->r + 10;
	if (keycode == 13 && e->g + 10 < 255)
		e->g = e->g + 10;
	if (keycode == 14 && e->b + 10 < 255)
		e->b = e->b + 10;
	if (keycode == 34)
	{
		e->r = 100;
		e->g = 100;
		e->b = 100;
	}
	if (keycode == 116)
		e->zoom = e->zoom + 1;
	if (keycode == 121 && e->zoom - 1 > 0)
		e->zoom = e->zoom - 1;
	if (keycode == 0 && e->z_ch + 2 < 15)
		e->z_ch = e->z_ch + 2;
	if (keycode == 6 && e->z_ch - 2 > -15)
		e->z_ch = e->z_ch - 2;
	return (0);
}

int		main(int ac, char **av)
{
	t_env	*e;

	if (ac == 1)
		return (0);
	e = (t_env *)malloc(sizeof(t_env));
	if (ft_init_mlx(e) == 1)
		return (0);
	compteur_max(av[1], e);
	parse_map(av[1], e);
	mlx_hook(e->window, 2, 3, commande_touche, e);
	mlx_loop_hook(e->mlx, &event_demander, e);
	mlx_loop(e->mlx);
	return (0);
}
