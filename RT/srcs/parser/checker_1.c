/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallo <mgallo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 12:07:07 by lvalenti          #+#    #+#             */
/*   Updated: 2016/11/10 18:26:42 by mgallo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/window.h"
#include "parser/parser.h"
#include "maths/vec3.h"
#include "libft.h"
#include "error.h"

int		check_camera(t_window *win)
{
	if (win->camera == NULL)
		win->error = ERROR_CAMERA_NULL;
	if (win->camera->pos == NULL)
		win->error = ERROR_CAMERA_POS_NULL;
	if (win->camera->rot == NULL)
		win->error = ERROR_CAMERA_ROT_NULL;
	if (win->camera->fov <= 0)
		win->error = ERROR_CAMERA_FOV;
	if (win->camera->zfar <= win->camera->znear)
		win->error = ERROR_CAMERA_ZNEAR_ZFAR;
	if (win->camera->zfar <= 0)
		win->error = ERROR_CAMERA_NEGATE_ZFAR;
	return (win->error == 0);
}

int		check_triangle(t_window *win, int i, int s)
{
	ft_putstr("\t- Face(s): ");
	ft_putnbr(s);
	ft_putstr("\n");
	ft_putstr("\t- Vertex: ");
	ft_putnbr(s * 3);
	ft_putstr("\n");
	s = -1;
	while (win->objects[i]->data[++s] != NULL)
	{
		if (win->objects[i]->data[s]->v0 == NULL)
			win->error = ERROR_TRIANGLE_VERTEX;
		if (win->objects[i]->data[s]->v1 == NULL)
			win->error = ERROR_TRIANGLE_VERTEX;
		if (win->objects[i]->data[s]->v2 == NULL)
			win->error = ERROR_TRIANGLE_VERTEX;
		if (win->error != 0)
			return (0);
	}
	return (0);
}

void	verif_object(t_window *win, int i)
{
	if (win->objects[i]->type > OBJECTS_TRIANGLES)
		win->error = ERROR_OBJECT_TYPE;
	else if (win->objects[i]->pos == NULL)
		win->error = ERROR_OBJECT_POS;
	else if (win->objects[i]->rot == NULL)
		win->error = ERROR_OBJECT_ROT;
	else if (win->objects[i]->color == NULL)
		win->error = ERROR_OBJECT_COLOR;
	else if (win->objects[i]->type == OBJECTS_PLANE)
	{
		if (win->objects[i]->normal == NULL ||
				(win->objects[i]->normal->x == 0
					&& win->objects[i]->normal->y == 0
						&& win->objects[i]->normal->z == 0))
			win->error = ERROR_OBJECT_NORMAL;
		else
			vec3_normalize(win->objects[i]->normal);
	}
}
