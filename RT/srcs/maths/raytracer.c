/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallo <mgallo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 16:00:40 by mgallo            #+#    #+#             */
/*   Updated: 2016/11/16 02:54:47 by mgallo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "graphics/window.h"
#include "graphics/light.h"
#include "graphics/material.h"
#include "maths/vec3.h"
#include "objects/objects.h"
#include "thread.h"

void			check_objects(t_window *win, t_ray *ray, int i, double znear)
{
	if (win->objects[i]->type == OBJECTS_SPHERE)
		sphere_intersect(win->objects[i], ray, znear);
	else if (win->objects[i]->type == OBJECTS_PLANE)
		plane_intersect(win->objects[i], ray, znear);
	else if (win->objects[i]->type == OBJECTS_CYLINDER)
		cylinder_intersect(win->objects[i], ray, znear);
	else if (win->objects[i]->type == OBJECTS_TRIANGLES)
		triangle_inter(win->objects[i], ray, znear);
}

void			rt_check(t_window *win, t_ray *ray, double znear, int exclu)
{
	int			i;
	double		last;

	last = ray->deph;
	ray->object = -1;
	ray->data = -1;
	i = -1;
	while (win->objects[++i] != NULL)
	{
		if (i == exclu)
			continue ;
		check_objects(win, ray, i, znear);
		if (ray->deph < last)
		{
			last = ray->deph;
			ray->object = i;
		}
	}
}

int				rt_thread(void *d)
{
	t_thread	*data;

	data = (t_thread *)d;
	t_ray		*ray;
	t_color		*color;

	ray = ray_new(data->win->camera->pos);
	ray->focale = (data->win->width / (2 * tan(data->win->camera->fov / 2)));
	vec3_set(ray->dir, data->x - data->win->width / 2.0, data->y - data->win->height / 2.0, ray->focale);
	vec3_normalize(ray->dir);
	vec3_rotate_z(ray->dir, data->win->camera->rot->z);
	vec3_rotate_y(ray->dir, data->win->camera->rot->y);
	vec3_rotate_x(ray->dir, data->win->camera->rot->x);
	ray->deph = data->win->camera->zfar;
	ray->reflect = data->win->reflect;
	rt_check(data->win, ray, data->win->camera->znear, -1);
	color = lights(data->win, ray);
	if (color != NULL)
	{
		draw_pixel(data->win, data->x, data->y, color);
		color_free(&color);
	}
	ray_free(&(ray));
	return (1);
}

int				raytracer(void *w)
{
	int			y;
	int			x;
	t_window	*win;
	t_thread	*thread_data;
	int			index;
	/*t_ray		*ray;
	t_color		*color;*/

	win = (t_window *)w;
	if ((thread_data = (t_thread *)malloc(sizeof(t_thread) * (win->height * win->width))) == NULL)
		return (0);
	/*ray = ray_new(win->camera->pos);
	ray->focale = (win->width / (2 * tan(win->camera->fov / 2)));*/
	y = -1;
	while (++y < win->height)
	{
		x = -1;
		while (++x < win->width)
		{
			index = x + y * win->width;
			thread_data[index].win = win;
			thread_data[index].x = x;
			thread_data[index].y = y;
			thread_data[index].thread = SDL_CreateThread(rt_thread, "rayon", (void *)(thread_data + index));
			SDL_DetachThread(thread_data[index].thread);
			/*vec3_set(ray->dir, x - win->width / 2.0, y - win->height / 2.0, ray->focale);
			vec3_normalize(ray->dir);
			vec3_rotate_z(ray->dir, win->camera->rot->z);
			vec3_rotate_y(ray->dir, win->camera->rot->y);
			vec3_rotate_x(ray->dir, win->camera->rot->x);
			ray->deph = win->camera->zfar;
			ray->reflect = win->reflect;
			rt_check(win, ray, win->camera->znear, -1);
			color = lights(win, ray);
			if (color != NULL)
			{
				draw_pixel(win, x, y, color);
				color_free(&color);
			}*/
		}
	}
	free(thread_data);
	/*ray_free(&(ray));*/
	return (1);
}
