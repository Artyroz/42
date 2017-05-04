/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallo <mgallo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 16:31:00 by stmartin          #+#    #+#             */
/*   Updated: 2016/11/16 00:20:08 by mgallo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "graphics/window.h"
#include "graphics/light.h"
#include "graphics/color.h"
#include "maths/camera.h"
#include "maths/rt_math.h"
#include "maths/vec3.h"
#include "objects/objects.h"

double	shadow(void *window, t_ray *ray, t_light *light, int object)
{
	t_window	*win;
	t_vec3		*impact;
	t_ray		*ray_light;
	double		light_far;

	win = (t_window *)window;
	impact = get_impact(ray);
	ray_light = ray_new(impact);
	vec3_free(&(ray_light->dir));
	ray_light->dir = vec3_new_sub(light->pos, impact);
	light_far = vec3_lenght(ray_light->dir);
	vec3_normalize(ray_light->dir);
	ray_light->deph = light_far;
	rt_check(win, ray_light, DEPH_MIN, ray->object);
	light_far = (ray_light->deph / light_far);
	ray_free(&ray_light);
	return (light_far);
}

void	reflect_color(void *window, t_color *color, t_objects *obj, t_ray *ray)
{
	t_window	*win;
	t_vec3		*impact;
	t_vec3		*normal;
	t_ray		*reflect_ray;
	int			i;
	t_color		*r_color;
	t_color		*tmp;
	int			mat_size;
	int			mat_select;
	double		shadow_attenuation;

	if (ray->reflect <= 0)
		return ;
	win = (t_window *)window;
	impact = get_impact(ray);
	normal = objects_normal(obj, impact, ray);
	if (normal == NULL)
		return ;
	reflect_ray = ray_new(impact);
	vec3_free(&(reflect_ray->dir));
	reflect_ray->dir = vec3_reflect(ray->dir, normal);
	reflect_ray->deph = win->camera->zfar;
	reflect_ray->reflect = ray->reflect - 1;
	rt_check(win, reflect_ray, win->camera->znear + DEPH_MIN, -1);
	mat_size = material_size(win->materials);
	if (reflect_ray->object >= 0 && win->lights[0] != NULL)
	{
		i = -1;
		r_color = NULL;
		tmp = NULL;
		shadow_attenuation = 0.0;
		while (win->lights[++i] != NULL)
		{
			mat_select = CLAMP(win->objects[reflect_ray->object]->material, 0,
					mat_size - 1);
			if (r_color != NULL)
			{
				tmp = light_color(win->objects[reflect_ray->object],
					win->lights[i], reflect_ray, win->materials[mat_select]);
				color_add(r_color, tmp);
				color_free(&tmp);
			}
			else
				r_color = light_color(win->objects[reflect_ray->object],
					win->lights[i], reflect_ray, win->materials[mat_select]);
			shadow_attenuation += shadow(win, reflect_ray, win->lights[i],
				reflect_ray->object);
		}
		if (r_color != NULL)
		{
			if (win->materials[mat_select]->reflection > 0 && (r_color->r > COLOR_MIN || r_color->g > COLOR_MIN || r_color->b > COLOR_MIN))
				reflect_color(win, r_color, win->objects[reflect_ray->object], reflect_ray);
			color_mul_value(r_color, shadow_attenuation);
			color_mul_value(r_color, win->materials[CLAMP(obj->material, 0, mat_size - 1)]->reflection);
			color_add(color, r_color);
		}
	}
	else if (ray->object >= 0 && win->lights[0] == NULL)
	{
		mat_select = CLAMP(win->objects[ray->object]->material, 0, mat_size - 1);
		color = ambiant_color(win->objects[ray->object], ray, win->materials[mat_select]);
	}
	vec3_free(&(normal));
	ray_free(&reflect_ray);
}
