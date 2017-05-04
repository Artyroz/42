/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallo <mgallo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 17:59:21 by mgallo            #+#    #+#             */
/*   Updated: 2016/11/07 14:30:54 by mgallo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "maths/vec3.h"

t_vec3	*vec3_new(double x, double y, double z)
{
	t_vec3 *v;

	v = (t_vec3 *)malloc(sizeof(t_vec3));
	if (v == NULL)
		return (NULL);
	v->x = x;
	v->y = y;
	v->z = z;
	return (v);
}

void	vec3_free(t_vec3 **v)
{
	if (v == NULL || *v == NULL)
		return ;
	free(*v);
	*v = NULL;
}

t_vec3	*vec3_copy(t_vec3 *v)
{
	return (vec3_new(v->x, v->y, v->z));
}

double	vec3_lenght(t_vec3 *v)
{
	return (sqrt(v->x * v->x + v->y * v->y + v->z * v->z));
}

t_vec3	*vec3_normalize(t_vec3 *v)
{
	double len;

	len = vec3_lenght(v);
	v->x /= len;
	v->y /= len;
	v->z /= len;
	return (v);
}
