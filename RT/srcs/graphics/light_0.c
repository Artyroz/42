/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallo <mgallo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 13:32:38 by mgallo            #+#    #+#             */
/*   Updated: 2016/11/16 00:12:22 by mgallo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "graphics/window.h"
#include "graphics/light.h"
#include "graphics/color.h"
#include "graphics/material.h"
#include "maths/camera.h"
#include "maths/rt_math.h"
#include "maths/vec3.h"
#include "objects/objects.h"

t_light	*light_new(t_vec3 *p, t_color *c, float attenuation)
{
	t_light	*light;

	light = (t_light *)malloc(sizeof(t_light));
	if (light == NULL)
		return (NULL);
	light->pos = p;
	light->color = c;
	light->attenuation = attenuation;
	light->dir = NULL;
	light->angle_max = 0.0;
	return (light);
}

void	light_free(t_light **light)
{
	if (*light == NULL)
		return ;
	vec3_free(&((*light)->pos));
	color_free(&((*light)->color));
	free(*light);
	*light = NULL;
}

int		light_type(t_light *light)
{
	if (light->dir == NULL)
		return (LIGHT_TYPE_POINT);
	if (light->angle_max > 0.0)
		return (LIGHT_TYPE_SPOT);
	return (LIGHT_TYPE_DIR);
}

t_color	*lights(void *window, t_ray *ray)
{
	t_window	*win;
	t_color		*color;
	t_color		*tmp;
	int			i;
	double		shadow_attenuation;
	int			mat_size;
	int			mat_select;

	win = (t_window *)window;
	mat_size = material_size(win->materials);
	if (ray->object >= 0 && win->lights[0] != NULL)
	{
		i = -1;
		color = NULL;
		tmp = NULL;
		shadow_attenuation = 0.0;
		while (win->lights[++i] != NULL)
		{
			mat_select = CLAMP(win->objects[ray->object]->material, 0, mat_size - 1);
			if (color != NULL)
			{
				tmp = light_color(win->objects[ray->object],
						win->lights[i], ray, win->materials[mat_select]);
				color_add(color, tmp);
				color_free(&tmp);
			}
			else
				color = light_color(win->objects[ray->object], win->lights[i], ray, win->materials[mat_select]);
			shadow_attenuation += shadow(win, ray, win->lights[i], ray->object);
		}
		color_mul_value(color, shadow_attenuation);
		if (win->materials[mat_select]->reflection > 0)
			reflect_color(win, color, win->objects[ray->object], ray);
	}
	else if (ray->object >= 0 && win->lights[0] == NULL)
	{
		mat_select = CLAMP(win->objects[ray->object]->material, 0, mat_size - 1);
		color = ambiant_color(win->objects[ray->object], ray, win->materials[mat_select]);
	}
	else
		color = color_new(0, 0, 0);
	color_pow(color, 1.0 / 2.2);
	return (color);
}
