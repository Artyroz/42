/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallo <mgallo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 18:44:26 by mgallo            #+#    #+#             */
/*   Updated: 2016/10/05 18:55:37 by mgallo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "maths/vec3.h"

t_vec3	*vec3_new_normalize(t_vec3 *v)
{
	double len;

	len = vec3_lenght(v);
	return (vec3_new(v->x / len, v->y / len, v->z / len));
}

double	vec3_dot(t_vec3 *v0, t_vec3 *v1)
{
	return (v0->x * v1->x + v0->y * v1->y + v0->z * v1->z);
}

t_vec3	*vec3_sub(t_vec3 *v0, t_vec3 *v1)
{
	v0->x -= v1->x;
	v0->y -= v1->y;
	v0->z -= v1->z;
	return (v0);
}

t_vec3	*vec3_new_sub(t_vec3 *v0, t_vec3 *v1)
{
	return (vec3_new(v0->x - v1->x, v0->y - v1->y, v0->z - v1->z));
}

t_vec3	*vec3_negate(t_vec3 *v)
{
	v->x = -v->x;
	v->y = -v->y;
	v->z = -v->z;
	return (v);
}
