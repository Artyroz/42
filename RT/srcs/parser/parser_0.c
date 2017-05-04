/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:36:06 by lvalenti          #+#    #+#             */
/*   Updated: 2016/11/10 16:40:10 by lvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/parser.h"
#include "objects/objects.h"

#include <stdio.h>

t_triangle			*ft_remptriangle(char **file, int *i)
{
	t_triangle		*triangle;

	triangle = (t_triangle*)malloc(sizeof(t_triangle));
	(*i)++;
	triangle->v0 = vec3_new(0.0, 0.0, 0.0);
	triangle->v1 = vec3_new(0.0, 0.0, 0.0);
	triangle->v2 = vec3_new(0.0, 0.0, 0.0);
	while (file[*i] && ft_strstr(file[*i], "{") == NULL)
	{
		ft_putstr("triangle:");
		ft_putendl(file[*i]);
		if (ft_strstr(file[*i], "v0 ") != NULL)
			triangle->v0 = char2xyz(ft_strstr(file[*i], "v0 ")
				+ ft_strlen("v0 "), triangle->v0);
		else if (ft_strstr(file[*i], "v1 ") != NULL)
			triangle->v1 = char2xyz(ft_strstr(file[*i], "v1 ")
				+ ft_strlen("v1 "), triangle->v1);
		else if (ft_strstr(file[*i], "v2 ") != NULL)
			triangle->v2 = char2xyz(ft_strstr(file[*i], "v2 ")
				+ ft_strlen("v2 "), triangle->v2);
		(*i)++;
	}
	(*i)--;
	return (triangle);
}

void				ft_rempmaterial2(t_material *material, char **file, int *i)
{
	if (ft_strstr(file[*i], "blinn ") != NULL)
		material->blinn = ft_atoi(ft_strstr(file[*i], "blinn ")
			+ ft_strlen("blinn "));
	else if (ft_strstr(file[*i], "ambient ") != NULL)
		material->ambient_color = char2color(ft_strstr(file[*i], "ambient ")
			+ ft_strlen("ambient "), material->ambient_color);
	else if (ft_strstr(file[*i], "specular ") != NULL)
		material->specular_color = char2color(ft_strstr(file[*i],
				"specular ") + ft_strlen("specular "),
					material->specular_color);
	else if (ft_strstr(file[*i], "shininess ") != NULL)
		material->shininess = char2double(ft_strstr(file[*i], "shininess ")
			+ ft_strlen("shininess "));
	else if (ft_strstr(file[*i], "reflection ") != NULL)
		material->reflection = char2double(ft_strstr(file[*i],
				"reflection ") + ft_strlen("reflection "));
}

t_material			*ft_rempmaterial(char **file, int *i)
{
	t_material		*material;

	if ((material = (t_material*)malloc(sizeof(t_material))) == NULL)
		rt_error(ERROR_RT_MALLOC);
	(*i)++;
	*material = (t_material){color_new(1, 1, 1),
			color_new(1, 1, 1), 128.0, 0, 0.0};
	while (file[*i] && ft_strstr(file[*i], "{") == NULL)
	{
		ft_putstr("material:");
		ft_putendl(file[*i]);
		ft_rempmaterial2(material, file, i);
		(*i)++;
	}
	return (material);
}

static char			**filedup(int fd)
{
	char			**result;
	char			*temp;
	int				i;

	i = 0;
	temp = NULL;
	result = (char**)ft_voidxxnew(0);
	while (get_next_line(fd, &temp) > 0)
	{
		if (i == 0 && (!temp || ft_strcmp(temp, "Scene {") != 0))
		{
			rt_error(ERROR_BAD_FILE);
			exit(1);
		}
		result = (char**)ft_voidxxadd(temp, (void**)result);
		i++;
	}
	if (i == 0 && (!temp || ft_strcmp(temp, "Scene {") != 0))
	{
		rt_error(ERROR_BAD_FILE);
		exit(1);
	}
	return (result);
}

t_window			*parser(char *str, t_window *result)
{
	int				fd;
	int				i;
	char			**file;
	int				*error;

	if ((fd = open(str, O_RDONLY)) == -1)
	{
		rt_error(ERROR_BAD_FILE);
		exit(1);
	}
	i = 1;
	if ((file = filedup(fd)) == NULL)
	{
		rt_error(ERROR_BAD_FILE);
		exit(1);
	}
	ft_putendl("chekpoint");
	result = ft_rempscene(file, &i, result);
	result = ft_redirect(file, &i, result);
	while (file[i] && ft_strstr(file[i], "}") == NULL)
		result = ft_redirect(file, &i, result);
	freefile(file);
	return (result);
}
