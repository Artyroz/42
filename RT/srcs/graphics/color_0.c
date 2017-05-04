/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallo <mgallo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 06:44:47 by mgallo            #+#    #+#             */
/*   Updated: 2016/11/07 12:04:56 by mgallo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "graphics/color.h"
#include "maths/rt_math.h"

t_color	*color_new(double r, double g, double b)
{
	t_color	*color;

	color = (t_color *)malloc(sizeof(t_color));
	if (color == NULL)
		return (NULL);
	color->r = CLAMP(r, 0.0, 1.0);
	color->g = CLAMP(g, 0.0, 1.0);
	color->b = CLAMP(b, 0.0, 1.0);
	return (color);
}

t_color	*color_new_rgb(int r, int g, int b)
{
	return (color_new((double)r / 255.0, (double)g / 255.0, (double)b / 255.0));
}

t_color	*color_new_hexa(int hexa)
{
	return (color_new_rgb((unsigned char)((hexa >> 16) & 0xff),
		(unsigned char)((hexa >> 8) & 0xff), (unsigned char)((hexa) & 0xff)));
}

void	color_free(t_color **c)
{
	if (*c == NULL)
		return ;
	free(*c);
	*c = NULL;
}

t_color	*color_mul(t_color *c0, t_color *c1)
{
	c0->r = CLAMP(c0->r * c1->r, 0.0, 1.0);
	c0->g = CLAMP(c0->g * c1->g, 0.0, 1.0);
	c0->b = CLAMP(c0->b * c1->b, 0.0, 1.0);
	return (c0);
}
