/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 23:23:41 by mgallo            #+#    #+#             */
/*   Updated: 2016/11/11 10:53:00 by lvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "graphics/color.h"
#include "graphics/material.h"

t_material		*material_new(t_color *amb, t_color *spec)
{
	t_material	*mat;

	mat = (t_material *)malloc(sizeof(t_material));
	if (mat == NULL)
		return (NULL);
	mat->ambient_color = amb;
	mat->specular_color = spec;
	mat->shininess = 128.0f;
	mat->blinn = 0;
	mat->reflection = 0;
	return (mat);
}

void			material_free(t_material **mat)
{
	if (*mat == NULL)
		return ;
	color_free(&((*mat)->ambient_color));
	color_free(&((*mat)->specular_color));
	free(*mat);
	*mat = NULL;
}

int				material_size(t_material **mat)
{
	int	size;

	size = 0;
	while (mat[size] != NULL)
		size++;
	return (size);
}
