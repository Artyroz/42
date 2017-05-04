/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallo <mgallo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:36:47 by lvalenti          #+#    #+#             */
/*   Updated: 2016/11/16 00:09:37 by mgallo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/parser.h"
#include "objects/objects.h"

void				ft_rempobject2(t_objects *object, char **file, int *i)
{
	if (ft_strstr(file[*i], "type ") != NULL)
		object->type = object_type(ft_strstr(file[*i], "type ")
			+ ft_strlen("type "));
	else if (ft_strstr(file[*i], "pos ") != NULL)
		object->pos = char2xyz(ft_strstr(file[*i], "pos ")
			+ ft_strlen("pos "), object->pos);
	else if (ft_strstr(file[*i], "rot ") != NULL)
		object->rot = char2xyz(ft_strstr(file[*i], "rot ")
			+ ft_strlen("rot "), object->rot);
	else if (ft_strstr(file[*i], "radius ") != NULL)
		object->radius = char2double(ft_strstr(file[*i], "radius ")
			+ ft_strlen("radius "));
	else if (ft_strstr(file[*i], "color ") != NULL)
		object->color = char2color(ft_strstr(file[*i], "color ")
			+ ft_strlen("color "), object->color);
	else if (ft_strstr(file[*i], "material ") != NULL)
		object->material = ft_atoi(ft_strstr(file[*i], "material ")
			+ ft_strlen("material "));
	else if (ft_strstr(file[*i], "normal ") != NULL)
		object->normal = char2xyz(ft_strstr(file[*i], "normal ")
			+ ft_strlen("normal "), object->normal);
	else if (ft_strstr(file[*i], "ADD ") != NULL)
		object->data = (void*)ft_voidxxadd(ft_remptriangle(file, i),
			(void**)object->data);
}

t_objects			*ft_rempobject(char **file, int *i)
{
	t_objects		*object;

	(*i)++;
	object = objects_new(0);
	while (file[*i] && (ft_strstr(file[*i], "{") == NULL ||
		ft_strstr(file[*i], "ADD {") != NULL))
	{
		ft_putstr("object:");
		ft_putendl(file[*i]);
		ft_rempobject2(object, file, i);
		(*i)++;
	}
	return (object);
}

void				ft_remplight2(t_light *light, char **file, int *i)
{
	if (ft_strstr(file[*i], "pos ") != NULL)
		light->pos = char2xyz(ft_strstr(file[*i], "pos ")
			+ ft_strlen("pos "), light->pos);
	else if (ft_strstr(file[*i], "color ") != NULL)
		light->color = char2color(ft_strstr(file[*i], "color ")
			+ ft_strlen("color "), light->color);
	else if (ft_strstr(file[*i], "attenuation ") != NULL)
		light->attenuation = char2double(ft_strstr(file[*i], "attenuation ")
			+ ft_strlen("attenuation "));
	else if (ft_strstr(file[*i], "dir ") != NULL)
	{
		if (!(light->dir))
			light->dir = vec3_new(0.0, 0.0, 0.0);
		light->dir = char2xyz(ft_strstr(file[*i], "dir ")
			+ ft_strlen("dir "), light->dir);
	}
	else if (ft_strstr(file[*i], "angle ") != NULL)
		light->angle_max = char2double(ft_strstr(file[*i], "angle ") + ft_strlen("angle "));
}

t_light				*ft_remplight(char **file, int *i)
{
	t_light			*light;

	light = light_new(vec3_new(0, 0, 0), color_new(1.0, 1.0, 1.0), 0.2f);
	(*i)++;
	while (file[*i] && ft_strstr(file[*i], "{") == NULL)
	{
		ft_putstr("light:");
		ft_putendl(file[*i]);
		ft_remplight2(light, file, i);
		(*i)++;
	}
	return (light);
}
