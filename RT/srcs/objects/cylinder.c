/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 14:49:50 by mgallo            #+#    #+#             */
/*   Updated: 2016/11/11 12:20:42 by lvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "graphics/window.h"
#include "maths/vec3.h"
#include "maths/camera.h"

void	cylinder_intersect(t_objects *o, t_ray *ray, double znear)
{
	t_vec3	*dist;
	t_vec3	*rd;
	t_point	p;
	double	t0;
	double	t1;

	rd = vec3_new_rotate_xyz(ray->dir, -o->rot->x, -o->rot->y, -o->rot->z);
	dist = vec3_new_sub(o->pos, ray->pos);
	vec3_rotate_xyz(dist, -o->rot->x, -o->rot->y, -o->rot->z);
	p.a = rd->x * rd->x + rd->z * rd->z;
	p.d = (rd->x * dist->x + rd->z * dist->z) / p.a;
	p.f = p.d * p.d - ((pow(dist->x, 2) + pow(dist->z, 2) -
			pow(o->radius, 2)) / p.a);
	vec3_free(&dist);
	vec3_free(&rd);
	if (p.f < 0)
		return ;
	p.f = sqrtf(p.f);
	t0 = p.d - p.f;
	t1 = p.d + p.f;
	if (t0 > znear && t0 < ray->deph)
		ray->deph = t0;
	if (t1 > znear && t1 < ray->deph)
		ray->deph = t1;
}

t_vec3	*cylinder_normal(t_objects *o, t_vec3 *impact)
{
	t_vec3 *rd;
	t_vec3 *v;

	rd = vec3_new_rotate_xyz(impact, -o->rot->x, -o->rot->y, -o->rot->z);
	rd->y = o->pos->y;
	v = vec3_new_sub(rd, o->pos);
	vec3_free(&rd);
	vec3_normalize(v);
	vec3_rotate_xyz(v, -o->rot->x, -o->rot->y, -o->rot->z);
	return (v);
}
