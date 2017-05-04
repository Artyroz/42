/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallo <mgallo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 13:21:25 by lvalenti          #+#    #+#             */
/*   Updated: 2016/11/16 00:15:25 by mgallo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "graphics/color.h"
#include "objects/objects.h"
#include "maths/rt_math.h"
#include "parser/parser.h"

void				free_triangle(t_vec3 *vec[6], int size)
{
	int				i;

	i = 0;
	while (i < size)
	{
		vec3_free(&vec[i]);
		i++;
	}
}

static void			intersect(t_triangle *tri, t_ray *ray, double znear)
{
	t_vec3	*vec[5];
	double	det;
	double	inv_det;
	double	calcul[3];

	vec[0] = vec3_new_sub(tri->v1, tri->v0);
	vec[1] = vec3_new_sub(tri->v2, tri->v0);
	vec[2] = vec3_new_cross(ray->dir, vec[1]);
	det = vec3_dot(vec[0], vec[2]);
	if (det < DEPH_MIN)
	{
		free_triangle(vec, 3);
		return ;
	}
	inv_det = 1.0 / det;
	vec[3] = vec3_new_sub(ray->pos, tri->v0);
	calcul[0] = vec3_dot(vec[3], vec[2]) * inv_det;
	if (calcul[0] < 0.0 || calcul[0] > 1.0)
	{
		free_triangle(vec, 4);
		return ;
	}
	vec[4] = vec3_new_cross(vec[3], vec[0]);
	calcul[1] = vec3_dot(ray->dir, vec[4]) * inv_det;
	if (calcul[1] < 0.0 || (calcul[0] + calcul[1]) > 1.0)
	{
		free_triangle(vec, 5);
		return ;
	}
	calcul[2] = vec3_dot(vec[1], vec[4]) * inv_det;
	if (calcul[2] > znear && calcul[2] < ray->deph)
		ray->deph = calcul[2];
	free_triangle(vec, 5);
}

void				inter_triangle(t_objects *obj, t_vec3 *v[3], int i)
{
	v[0] = vec3_copy(obj->data[i]->v0);
	vec3_rotate_xyz(v[0], obj->rot->x, obj->rot->y, obj->rot->z);
	v[1] = vec3_copy(obj->data[i]->v1);
	vec3_rotate_xyz(v[1], obj->rot->x, obj->rot->y, obj->rot->z);
	v[2] = vec3_copy(obj->data[i]->v2);
	vec3_rotate_xyz(v[2], obj->rot->x, obj->rot->y, obj->rot->z);
}

void				triangle_inter(t_objects *obj, t_ray *ray, double z)
{
	int			i;
	double		tmp;
	t_triangle	*tri;
	t_vec3		*v[3];

	i = -1;
	tmp = ray->deph;
	while (obj->data[++i] != NULL)
	{
		inter_triangle(obj, v, i);
		tri = triangle_new(vec3_add(v[0], obj->pos), vec3_add(v[1], obj->pos),
			vec3_add(v[2], obj->pos));
		intersect(tri, ray, z);
		triangle_free(&tri);
		if (tmp != ray->deph)
		{
			tmp = ray->deph;
			ray->data = i;
		}
	}
}
