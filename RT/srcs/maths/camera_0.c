/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallo <mgallo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 06:06:48 by mgallo            #+#    #+#             */
/*   Updated: 2016/10/06 06:24:35 by mgallo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "maths/vec3.h"
#include "maths/camera.h"

t_cam	*camera_new(double fov, double znear, double zfar)
{
	t_cam *cam;

	cam = (t_cam *)malloc(sizeof(t_cam));
	if (cam == NULL)
		return (NULL);
	cam->pos = vec3_new(0, 0, 0);
	cam->rot = vec3_new(0, 0, 0);
	cam->fov = fov;
	cam->znear = znear;
	cam->zfar = zfar;
	return (cam);
}

void	camera_free(t_cam **cam)
{
	if (*cam == NULL)
		return ;
	vec3_free(&((*cam)->pos));
	vec3_free(&((*cam)->rot));
	free(*cam);
	*cam = NULL;
}

t_cam	*camera_set(t_cam *cam, double fov, double znear, double zfar)
{
	cam->fov = fov;
	cam->znear = znear;
	cam->zfar = zfar;
	return (cam);
}
