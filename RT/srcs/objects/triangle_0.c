/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_0.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallo <mgallo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 12:24:05 by mgallo            #+#    #+#             */
/*   Updated: 2016/11/14 22:13:10 by mgallo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "graphics/color.h"
#include "objects/objects.h"
#include "maths/rt_math.h"
#include "parser/parser.h"

t_triangle		*triangle_new(t_vec3 *v0, t_vec3 *v1, t_vec3 *v2)
{
	t_triangle *obj;

	obj = (t_triangle *)malloc(sizeof(t_triangle));
	if (obj == NULL)
		return (NULL);
	obj->v0 = v0;
	obj->v1 = v1;
	obj->v2 = v2;
	return (obj);
}

void			triangle_free(t_triangle **t)
{
	if (*t == NULL)
		return ;
	vec3_free(&((*t)->v0));
	vec3_free(&((*t)->v1));
	vec3_free(&((*t)->v2));
	free(*t);
	*t = NULL;
}

t_vec3			*triangle_normal(t_objects *obj, t_ray *ray)
{
	t_vec3		*v;
	t_triangle	*tri;

	if (ray->data < 0)
		return (NULL);
	tri = obj->data[ray->data];
	v = vec3_new_cross3(tri->v0, tri->v1, tri->v2);
	vec3_normalize(v);
	vec3_rotate_xyz(v, obj->rot->x, obj->rot->y, obj->rot->z);
	return (v);
}
