/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallo <mgallo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 18:57:19 by mgallo            #+#    #+#             */
/*   Updated: 2016/10/10 19:07:36 by mgallo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "maths/vec3.h"

t_vec3	*vec3_rotate_x(t_vec3 *v, float degree)
{
	double	tmp_y;
	double	tmp_z;
	double	rx;

	rx = degree * M_PI / 180.0;
	tmp_y = v->y;
	tmp_z = v->z;
	v->y = tmp_y * cos(rx) - tmp_z * sin(rx);
	v->z = tmp_y * sin(rx) + tmp_z * cos(rx);
	return (v);
}

t_vec3	*vec3_rotate_y(t_vec3 *v, float degree)
{
	double	tmp_x;
	double	tmp_z;
	double	ry;

	ry = degree * M_PI / 180.0;
	tmp_x = v->x;
	tmp_z = v->z;
	v->x = tmp_z * sin(ry) + tmp_x * cos(ry);
	v->z = tmp_z * cos(ry) - tmp_x * sin(ry);
	return (v);
}

t_vec3	*vec3_rotate_z(t_vec3 *v, float degree)
{
	double	tmp_x;
	double	tmp_y;
	double	rz;

	rz = degree * M_PI / 180.0;
	tmp_x = v->x;
	tmp_y = v->y;
	v->x = tmp_x * cos(rz) - tmp_y * sin(rz);
	v->y = tmp_x * sin(rz) + tmp_y * cos(rz);
	return (v);
}

t_vec3	*vec3_rotate_xyz(t_vec3 *v, float dx, float dy, float dz)
{
	vec3_rotate_z(v, dz);
	vec3_rotate_y(v, dy);
	vec3_rotate_x(v, dx);
	return (v);
}

t_vec3	*vec3_new_rotate_xyz(t_vec3 *v, float dx, float dy, float dz)
{
	t_vec3 *nv;

	nv = vec3_copy(v);
	vec3_rotate_z(nv, dz);
	vec3_rotate_y(nv, dy);
	vec3_rotate_x(nv, dx);
	return (nv);
}
