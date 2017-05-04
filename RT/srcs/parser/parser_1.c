/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:23:06 by lvalenti          #+#    #+#             */
/*   Updated: 2016/11/10 13:46:01 by lvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/parser.h"
#include "objects/objects.h"

t_window		*ft_rempscene(char **file, int *i, t_window *scene)
{
	while (file[*i] && ft_strstr(file[*i], "{") == NULL)
	{
		if (ft_strstr(file[*i], "width") != NULL)
			scene->width = ft_atoi(ft_strstr(file[*i], "width ")
				+ ft_strlen("width "));
		else if (ft_strstr(file[*i], "height") != NULL)
			scene->height = ft_atoi(ft_strstr(file[*i], "height ")
				+ ft_strlen("height "));
		else if (ft_strstr(file[*i], "max_reflect") != NULL)
			scene->reflect = ft_atoi(ft_strstr(file[*i], "max_reflect ")
				+ ft_strlen("max_reflect "));
		(*i)++;
	}
	return (scene);
}

int				object_type(char *type)
{
	int i;

	if (ft_strstr(type, "sphere") != NULL)
		return (OBJECTS_SPHERE);
	else if (ft_strstr(type, "plane") != NULL)
		return (OBJECTS_PLANE);
	else if (ft_strstr(type, "cylinder") != NULL)
		return (OBJECTS_CYLINDER);
	else if (ft_strstr(type, "cone") != NULL)
		return (OBJECTS_CONE);
	else if (ft_strstr(type, "triangle") != NULL)
		return (OBJECTS_TRIANGLES);
	else
		return (ft_atoi(type));
	return (0);
}

int				freefile(char **file)
{
	int i;

	i = 0;
	while (file[i])
	{
		free(file[i]);
		i++;
	}
	free(file);
	return (0);
}

t_window		*ft_redirect(char **file, int *i, t_window *result)
{
	int	x;

	x = -1;
	if (!file || !file[*i])
	{
		ft_putendl("ici");
		rt_error(ERROR_BAD_FILE);
	}
	ft_putendl(file[*i]);
	if (ft_strstr(file[*i], "Camera") != NULL)
		result = ft_rempcamera(file, i, result);
	else if (ft_strstr(file[*i], "Material") != NULL)
		result->materials = (void*)ft_voidxxadd(ft_rempmaterial(file, i),
			(void**)result->materials);
	else if (ft_strstr(file[*i], "Object") != NULL)
		result->objects = (void*)ft_voidxxadd(ft_rempobject(file, i),
			(void**)result->objects);
	else if (ft_strstr(file[*i], "Light") != NULL)
		result->lights = (void*)ft_voidxxadd(ft_remplight(file, i),
			(void**)result->lights);
	else
		(*i)++;
	return (result);
}

t_window		*ft_rempcamera(char **file, int *i, t_window *win)
{
	(*i)++;
	while (file[*i] && ft_strstr(file[*i], "{") == NULL)
	{
		ft_putstr("camera:");
		ft_putendl(file[*i]);
		if (ft_strstr(file[*i], "pos ") != NULL)
			win->camera->pos = char2xyz(ft_strstr(file[*i], "pos ")
				+ ft_strlen("pos "), win->camera->pos);
		else if (ft_strstr(file[*i], "rot ") != NULL)
			win->camera->rot = char2xyz(ft_strstr(file[*i], "rot ")
				+ ft_strlen("rot "), win->camera->rot);
		else if (ft_strstr(file[*i], "fov ") != NULL)
			win->camera->fov = char2double(ft_strstr(file[*i], "fov ")
				+ ft_strlen("fov "));
		else if (ft_strstr(file[*i], "znear ") != NULL)
			win->camera->znear = char2double(ft_strstr(file[*i], "znear ")
				+ ft_strlen("znear "));
		else if (ft_strstr(file[*i], "zfar ") != NULL)
			win->camera->zfar = char2double(ft_strstr(file[*i], "zfar ")
				+ ft_strlen("zfar "));
		(*i)++;
	}
	return (win);
}
