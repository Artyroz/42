/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallo <mgallo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 18:52:39 by mgallo            #+#    #+#             */
/*   Updated: 2016/10/06 01:04:12 by mgallo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "maths/vec3.h"

t_vec3	*vec3_mul(t_vec3 *v0, t_vec3 *v1)
{
	v0->x *= v1->x;
	v0->y *= v1->y;
	v0->z *= v1->z;
	return (v0);
}

t_vec3	*vec3_mul_value(t_vec3 *v0, double value)
{
	v0->x *= value;
	v0->y *= value;
	v0->z *= value;
	return (v0);
}

t_vec3	*vec3_new_mul(t_vec3 *v0, t_vec3 *v1)
{
	return (vec3_new(v0->x * v1->x, v0->y * v1->y, v0->z * v1->z));
}

t_vec3	*vec3_div(t_vec3 *v0, t_vec3 *v1)
{
	v0->x /= v1->x;
	v0->y /= v1->y;
	v0->z /= v1->z;
	return (v0);
}

t_vec3	*vec3_new_div(t_vec3 *v0, t_vec3 *v1)
{
	return (vec3_new(v0->x / v1->x, v0->y / v1->y, v0->z / v1->z));
}
