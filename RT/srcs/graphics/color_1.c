/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallo <mgallo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 19:41:32 by mgallo            #+#    #+#             */
/*   Updated: 2016/11/03 02:36:44 by mgallo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/color.h"
#include "maths/rt_math.h"
#include "maths/vec3.h"

t_color	*color_mul_value(t_color *c0, double v)
{
	c0->r = CLAMP(c0->r * v, 0.0, 1.0);
	c0->g = CLAMP(c0->g * v, 0.0, 1.0);
	c0->b = CLAMP(c0->b * v, 0.0, 1.0);
	return (c0);
}

t_color	*color_mul_vec3(t_color *c0, t_vec3 *vec)
{
	c0->r = CLAMP(c0->r * vec->x, 0.0, 1.0);
	c0->g = CLAMP(c0->g * vec->y, 0.0, 1.0);
	c0->b = CLAMP(c0->b * vec->z, 0.0, 1.0);
	return (c0);
}

t_color	*color_add(t_color *c0, t_color *c1)
{
	c0->r = CLAMP(c0->r + c1->r, 0.0, 1.0);
	c0->g = CLAMP(c0->g + c1->g, 0.0, 1.0);
	c0->b = CLAMP(c0->b + c1->b, 0.0, 1.0);
	return (c0);
}

t_color	*color_copy(t_color *c)
{
	return (color_new(c->r, c->g, c->b));
}

t_color	*color_set(t_color *c, double r, double g, double b)
{
	c->r = CLAMP(r, 0.0, 1.0);
	c->g = CLAMP(g, 0.0, 1.0);
	c->b = CLAMP(b, 0.0, 1.0);
	return (c);
}
