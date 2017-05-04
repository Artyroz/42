/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallo <mgallo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 00:38:04 by mgallo            #+#    #+#             */
/*   Updated: 2016/11/15 06:59:21 by mgallo           ###   ########.fr       */
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

t_color		*light_ambiant(t_objects *obj, t_light *li, t_material *mat)
{
	t_color		*color_ambiant;

	color_ambiant = color_copy(obj->color);
	if (li != NULL)
		color_mul(color_ambiant, li->color);
	if (mat != NULL)
		color_mul(color_ambiant, mat->ambient_color);
	return (color_ambiant);
}

t_color		*light_diffuse(t_objects *obj, t_light *li, double diffuse)
{
	t_color		*color_diff;

	color_diff = color_copy(obj->color);
	if (li != NULL)
		color_mul(color_diff, li->color);
	color_mul_value(color_diff, diffuse);
	return (color_diff);
}

t_color		*light_specular(t_light *li, t_material *mat, double diffuse, t_vec3 *light_dir, t_ray *ray, t_vec3 *normal)
{
	t_vec3		*light_calc;
	t_vec3		*reflect;
	t_color		*color_spec;
	double		spec;

	spec = 0.0;
	if (diffuse > 0.0)
	{
		if (mat->blinn)
		{
			light_calc = vec3_new_add(light_dir, ray->dir);
			vec3_normalize(light_calc);
			spec = CLAMP(vec3_dot(normal, light_calc), 0.0, 1.0);
		}
		else
		{
			light_calc = vec3_copy(light_dir);
			vec3_negate(light_calc);
			reflect = vec3_reflect(light_calc, normal);
			spec = CLAMP(vec3_dot(ray->dir, reflect), 0.0, 1.0);
			vec3_free(&reflect);
		}
		spec = pow(spec, mat->shininess);
		vec3_free(&light_calc);
	}
	color_spec = color_copy(li->color);
	color_mul(color_spec, mat->specular_color);
	color_mul_value(color_spec, spec);
	return (color_spec);
}

t_color	*light_color(t_objects *obj, t_light *li, t_ray *ray, t_material *mat)
{
	t_vec3		*impact;
	t_vec3		*normal;
	t_vec3		*light_dir;
	t_color		*color[4];
	double		calc[3];

	impact = get_impact(ray);
	light_dir = vec3_new_sub(li->pos, impact);
	calc[1] = vec3_lenght(light_dir);
	vec3_normalize(light_dir);
	normal = objects_normal(obj, impact, ray);
	if (normal == NULL)
		return (color_copy(obj->color));
	vec3_normalize(normal);
	color[0] = light_ambiant(obj, li, mat);
	calc[0] = MAX(vec3_dot(normal, light_dir), 0.0);
	color[1] = light_diffuse(obj, li, calc[0]);
	calc[2] = 1.0 / (1.0 + li->attenuation * pow(calc[1], 2.0));
	color[3] = color_copy(color[1]);
	if (li != NULL)
	{
		color[2] = light_specular(li, mat, calc[0], light_dir, ray, normal);
		color_add(color[3], color[2]);
		color_free(&color[2]);
	}
	color_mul_value(color[3], calc[2]);
	color_add(color[3], color[0]);
	vec3_free(&impact);
	vec3_free(&normal);
	vec3_free(&light_dir);
	color_free(&color[0]);
	color_free(&color[1]);
	return (color[3]);
}

t_color	*ambiant_color(t_objects *obj, t_ray *ray, t_material *mat)
{
	t_color		*color;
	t_vec3		*impact;
	t_vec3		*normal;

	impact = get_impact(ray);
	normal = objects_normal(obj, impact, ray);
	if (normal == NULL)
		return (color_copy(obj->color));
	vec3_normalize(normal);
	color = color_copy(obj->color);
	color_add(color, mat->ambient_color);
	color_mul_value(color, 1.0 - 1.0 / (1.0 + pow(vec3_dot(normal, ray->dir), 2)));
	vec3_free(&normal);
	vec3_free(&impact);
	return (color);
}
