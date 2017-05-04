/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallo <mgallo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 06:18:23 by mgallo            #+#    #+#             */
/*   Updated: 2016/10/13 21:41:02 by mgallo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "maths/vec3.h"
#include "maths/camera.h"

t_ray	*ray_new(t_vec3 *pos)
{
	t_ray *ray;

	ray = (t_ray *)malloc(sizeof(t_ray));
	if (ray == NULL)
		return (NULL);
	ray->pos = vec3_copy(pos);
	ray->dir = vec3_new(0, 0, 1);
	ray->focale = 0;
	ray->deph = 0;
	return (ray);
}

void	ray_free(t_ray **ray)
{
	if (*ray == NULL)
		return ;
	vec3_free(&((*ray)->pos));
	vec3_free(&((*ray)->dir));
	free(*ray);
	*ray = NULL;
}

t_vec3	*get_impact(t_ray *ray)
{
	t_vec3	*vec;

	vec = vec3_copy(ray->dir);
	vec3_mul_value(vec, ray->deph);
	vec3_add(vec, ray->pos);
	return (vec);
}
