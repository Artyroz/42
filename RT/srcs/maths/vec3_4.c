/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallo <mgallo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 06:22:47 by mgallo            #+#    #+#             */
/*   Updated: 2016/10/26 13:24:12 by mgallo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "maths/vec3.h"

t_vec3		*vec3_reflect(t_vec3 *v, t_vec3 *normal)
{
	t_vec3	*n;
	t_vec3	*r;

	n = vec3_copy(normal);
	vec3_mul_value(n, 2.0 * vec3_dot(v, normal));
	r = vec3_new_sub(v, n);
	vec3_free(&n);
	return (r);
}

t_vec3		*vec3_set(t_vec3 *v, double x, double y, double z)
{
	v->x = x;
	v->y = y;
	v->z = z;
	return (v);
}

t_vec3		*vec3_new_cross(t_vec3 *v1, t_vec3 *v2)
{
	t_vec3	*n;

	n = vec3_new(0, 0, 0);
	n->x = v1->y * v2->z - v1->z * v2->y;
	n->y = v1->z * v2->x - v1->x * v2->z;
	n->z = v1->x * v2->y - v1->y * v2->x;
	return (n);
}

t_vec3		*vec3_new_cross3(t_vec3 *v0, t_vec3 *v1, t_vec3 *v2)
{
	t_vec3	*d0;
	t_vec3	*d1;
	t_vec3	*n;

	d0 = vec3_new_sub(v1, v0);
	d1 = vec3_new_sub(v2, v0);
	n = vec3_new_cross(d0, d1);
	vec3_free(&d0);
	vec3_free(&d1);
	return (n);
}

t_vec3		*vec3_add(t_vec3 *v0, t_vec3 *v1)
{
	v0->x += v1->x;
	v0->y += v1->y;
	v0->z += v1->z;
	return (v0);
}
