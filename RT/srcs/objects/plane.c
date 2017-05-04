/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallo <mgallo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 13:36:33 by mgallo            #+#    #+#             */
/*   Updated: 2016/11/15 04:43:59 by mgallo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "graphics/window.h"
#include "objects/objects.h"
#include "maths/vec3.h"
#include "maths/camera.h"
#include "maths/rt_math.h"

void	plane_intersect(t_objects *obj, t_ray *ray, double znear)
{
	t_vec3	*n;
	t_vec3	*p;
	double	a;
	double	deph;

	n = vec3_copy(obj->normal);
	vec3_rotate_z(n, obj->rot->z);
	vec3_rotate_y(n, obj->rot->y);
	vec3_rotate_x(n, obj->rot->x);
	a = vec3_dot(n, ray->dir);
	if (ABS(a) < DEPH_MIN)
	{
		vec3_free(&n);
		return ;
	}
	p = vec3_new_sub(obj->pos, ray->pos);
	deph = vec3_dot(p, n) / a;
	if (deph > znear && deph < ray->deph)
		ray->deph = deph;
	vec3_free(&n);
	vec3_free(&p);
}

t_vec3	*plane_normal(t_objects *obj, t_vec3 *impact)
{
	t_vec3	*v;

	v = vec3_copy(obj->normal);
	vec3_rotate_z(v, obj->rot->z);
	vec3_rotate_y(v, obj->rot->y);
	vec3_rotate_x(v, obj->rot->x);
	vec3_normalize(v);
	return (v);
}
