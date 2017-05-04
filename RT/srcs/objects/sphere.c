/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallo <mgallo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 14:57:56 by mgallo            #+#    #+#             */
/*   Updated: 2016/10/13 21:45:22 by mgallo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "graphics/window.h"
#include "maths/vec3.h"
#include "maths/camera.h"

void	sphere_intersect(t_objects *obj, t_ray *ray, double znear)
{
	t_vec3 *distance;
	double b;
	double d;
	double t0;
	double t1;

	distance = vec3_new_sub(obj->pos, ray->pos);
	b = vec3_dot(ray->dir, distance);
	d = b * b - vec3_dot(distance, distance) + obj->radius * obj->radius;
	if (d < 0.0)
	{
		vec3_free(&distance);
		return ;
	}
	d = sqrtf(d);
	t0 = b - d;
	t1 = b + d;
	if (t0 > znear && t0 < ray->deph)
		ray->deph = t0;
	if (t1 > znear && t1 < ray->deph)
		ray->deph = t1;
	vec3_free(&distance);
}

t_vec3	*sphere_normal(t_objects *obj, t_vec3 *impact)
{
	t_vec3	*v;

	v = vec3_new_sub(impact, obj->pos);
	vec3_normalize(v);
	return (v);
}
