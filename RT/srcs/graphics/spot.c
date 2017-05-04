/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alesecq <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 16:45:26 by alesecq           #+#    #+#             */
/*   Updated: 2016/11/15 18:08:31 by alesecq          ###   ########.fr       */
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

/*Dans Scene preciser ou se trouve le spot, et la taille maximale de l'angle du spot*/

t_color	*spot_light(t_objects *obj, t_light *spot, t_ray *ray)
{
	t_vec3 *impact;
	t_vec3 *spot_dir;
	t_vec3 *normal;
	double angle;
	t_color *color_spot;

	impact = get_impact(ray);
	spot_dir = vec3_new_sub(spot->pos, impact);
	vec3_normalize(spot_dir);
	normal = objects_normal(obj, impact, ray);
	vec3_normalize(normal);
	angle = vec3_dot(normal, spot_dir);
	vec3_free(&impact);
	vec3_free(&normal);
	vec3_free(&spot_dir);
	spot->angle_max = 0.2;
	if (angle <= spot->angle_max)
		color_spot = color_mul(obj->color, spot->color);
	else
		color_spot = color_new(0, 0, 0);
	return (color_spot);
}

t_color *dir_light(t_objects *obj, t_ray *ray, t_color *color, t_vec3 *dir, t_light *dir_light)
{
	t_color *color_dir;
	t_vec3 *impact;

	impact = get_impact(ray);
	if (impact)
		color_dir = color_mul(obj->color, dir_light->color);
	else
		color_dir = color_new(0, 0, 0);
	return (color_dir);
}
