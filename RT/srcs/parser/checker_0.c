/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallo <mgallo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 12:07:18 by lvalenti          #+#    #+#             */
/*   Updated: 2016/11/15 23:37:02 by mgallo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/window.h"
#include "parser/parser.h"
#include "maths/vec3.h"
#include "libft.h"
#include "error.h"

static void		object_name(int id)
{
	if (id == OBJECTS_SPHERE)
		ft_putstr("\tSphere\n");
	else if (id == OBJECTS_PLANE)
		ft_putstr("\tPlane\n");
	else if (id == OBJECTS_CYLINDER)
		ft_putstr("\tCylinder\n");
	else if (id == OBJECTS_CONE)
		ft_putstr("\tCone\n");
	else if (id == OBJECTS_TRIANGLES)
		ft_putstr("\tTriangles\n");
}

static int		check_object(t_window *win)
{
	int i;
	int s;

	if ((s = ft_voidxxlen((void **)win->objects)) <= 0)
	{
		win->error = ERROR_OBJECT_NUMBER;
		return (0);
	}
	i = -1;
	while (win->objects[++i] != NULL)
	{
		object_name(win->objects[i]->type);
		verif_object(win, i);
		if (win->objects[i]->type == OBJECTS_TRIANGLES)
		{
			if ((s = ft_voidxxlen((void **)win->objects[i]->data)) <= 0)
				win->error = ERROR_TRIANGLE_NUMBER;
			else
				check_triangle(win, i, s);
		}
		if (win->error != 0)
			return (0);
	}
	return (1);
}

static int		check_lights(t_window *win)
{
	int			i;

	i = -1;
	while (win->lights[++i] != NULL)
	{
		if (win->lights[i]->dir == NULL)
			ft_putstr("\tPoint Light\n");
		else
		{
			if (win->lights[i]->angle_max > 0.0)
				ft_putstr("\tSpot Light\n");
			else
				ft_putstr("\tDirectional Light\n");
			vec3_normalize(win->lights[i]->dir);
		}
		if (win->lights[i]->pos == NULL)
			win->error = ERROR_LIGHT_POS;
		if (win->lights[i]->color == NULL)
			win->error = ERROR_LIGHT_COLOR;
		if (win->error != 0)
			return (0);
	}
	return (1);
}

static int		check_materials(t_window *win)
{
	int			i;

	i = -1;
	while (win->materials[++i] != NULL)
	{
		if (win->materials[i]->ambient_color == NULL)
			win->error = ERROR_MATERIAL_AMBIENT;
		if (win->materials[i]->specular_color == NULL)
			win->error = ERROR_MATERIAL_SPECULAR;
		if (win->materials[i]->shininess <= 0)
			win->error = ERROR_MATERIAL_SHININESS;
		if (win->error != 0)
			return (0);
	}
	return (1);
}

int				checker(t_window *win)
{
	ft_putstr("CAMERA:\n");
	if (!check_camera(win))
		return (0);
	ft_putstr("\tOK!\nOBJECT(S):\n");
	if (!check_object(win))
		return (0);
	ft_putstr("\tOK!\nLIGHT(S):\n");
	if (!check_lights(win))
		return (0);
	ft_putstr("\tOK!\nMATERIAL(S):\n");
	if (!check_materials(win))
		return (0);
	ft_putstr("\tOK!\n");
	return (1);
}
