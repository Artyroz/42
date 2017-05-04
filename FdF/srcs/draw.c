/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpollet <dpollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 11:07:29 by dpollet           #+#    #+#             */
/*   Updated: 2015/05/19 17:15:53 by dpollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pixel(t_env *e, int y, int x)
{
	if ((x > 0 && y > 0) && (x <= 1280 && y <= 720))
	{
		e->data[(x * 4) + (y * 1280 * 4)] = e->r;
		e->data[(x * 4) + (y * 1280 * 4) + 1] = e->g;
		e->data[(x * 4) + (y * 1280 * 4) + 2] = e->b;
	}
}

void	aff_line(t_env *e)
{
	double dx;
	double dy;
	double x;
	double y;
	double temp;

	x = e->x1;
	y = e->y1;
	dx = e->x2 - e->x1;
	dy = e->y2 - e->y1;
	temp = sqrt((dx * dx) + (dy * dy));
	dx /= temp;
	dy /= temp;
	while (temp >= 0)
	{
		pixel(e, y, x);
		x += dx;
		y += dy;
		temp--;
	}
}

void	transforme(t_env *e, int x, int y, int n)
{
	int		xt;
	int		yt;

	xt = x - e->max_x / 2;
	yt = y - e->max_y / 2;
	e->x1 = 0.40 * (xt - yt) * e->zoom;
	e->y1 = 0.20 * (xt + yt) * e->zoom;
	e->y1 -= e->map[y][x] * e->z_ch;
	if (n)
	{
		e->x2 = 0.40 * ((xt + 1) - yt) * e->zoom;
		e->y2 = 0.20 * ((xt + 1) + yt) * e->zoom;
		e->y2 -= e->map[y][x + 1] * e->z_ch;
	}
	else
	{
		e->x2 = 0.40 * (xt - (yt + 1)) * e->zoom;
		e->y2 = 0.20 * (xt + (yt + 1)) * e->zoom;
		e->y2 -= e->map[y + 1][x] * e->z_ch;
	}
	e->x1 += 1280 / 2;
	e->x2 += 1280 / 2;
	e->y1 += 720 / 2;
	e->y2 += 720 / 2;
}

void	creat_img(t_env *e, int n)
{
	int		sizeline;
	int		endian;
	int		bpp;

	if (n == 1)
	{
		e->img_ptr = mlx_new_image(e->mlx, 1280, 720);
		e->data = mlx_get_data_addr(e->img_ptr, &bpp, &sizeline, &endian);
	}
	if (n == 2)
	{
		mlx_put_image_to_window(e->mlx, e->window, e->img_ptr, 0, 0);
		mlx_destroy_image(e->mlx, e->img_ptr);
	}
}

void	aff(t_env *e)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	creat_img(e, 1);
	while (y != e->max_y)
	{
		while (x != e->max_x)
		{
			e->x1 = x;
			e->y1 = y;
			if (x + 1 < e->max_x && e->map[y][x] !=\
				INVALID_Z && e->map[y][x + 1] != INVALID_Z)
				transforme(e, x, y, 1), aff_line(e);
			if (y + 1 < e->max_y && e->map[y][x] != \
				INVALID_Z && e->map[y + 1][x] != INVALID_Z)
				transforme(e, x, y, 0), aff_line(e);
			x++;
		}
		x = 0;
		y++;
	}
	creat_img(e, 2);
}
