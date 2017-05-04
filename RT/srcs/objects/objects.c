/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 14:33:46 by mgallo            #+#    #+#             */
/*   Updated: 2016/11/15 15:10:47 by lvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "objects/objects.h"
#include "parser/parser.h"

t_objects		*objects_new(int type)
{
	t_objects	*obj;

	obj = (t_objects *)malloc(sizeof(t_objects));
	if (obj == NULL)
		return (NULL);
	obj->type = type;
	obj->pos = vec3_new(0, 0, 0);
	obj->rot = vec3_new(0, 0, 0);
	obj->color = color_new(1, 1, 1);
	obj->radius = 1;
	obj->material = 0;
	obj->normal = vec3_new(0, -1, 0);
	obj->data = (t_triangle **)ft_voidxxnew(1);
	return (obj);
}

void			objects_add_triangle(t_objects *obj, t_triangle *t)
{
	int			i;
	t_triangle	**data;

	i = 0;
	while (obj->data[i] != NULL)
		i++;
	data = (t_triangle **)malloc(sizeof(t_triangle *) * (i + 1));
	i = -1;
	while (obj->data[++i] != NULL)
		data[i] = obj->data[i];
	data[i] = t;
	data[i + 1] = NULL;
	obj->data = data;
}

void			objects_free(t_objects **obj)
{
	int i;

	if (*obj == NULL)
		return ;
	vec3_free(&((*obj)->pos));
	vec3_free(&((*obj)->rot));
	color_free(&((*obj)->color));
	vec3_free(&((*obj)->normal));
	i = -1;
	if ((*obj)->data != NULL)
	{
		while ((*obj)->data[++i] != NULL)
			triangle_free(&((*obj)->data[i]));
		free((*obj)->data);
	}
	free(*obj);
	*obj = NULL;
}

t_vec3			*objects_normal(t_objects *obj, t_vec3 *impact, t_ray *ray)
{
	t_vec3		*normal;

	if (obj->type == OBJECTS_SPHERE)
		normal = vec3_new_sub(impact, obj->pos);
	else if (obj->type == OBJECTS_PLANE)
		normal = plane_normal(obj, impact);
	else if (obj->type == OBJECTS_CYLINDER)
		normal = cylinder_normal(obj, impact);
	else if (obj->type == OBJECTS_CONE)
		normal = vec3_new_sub(obj->pos, impact);
	else if (obj->type == OBJECTS_TRIANGLES)
		normal = triangle_normal(obj, ray);
	return (normal);
}
