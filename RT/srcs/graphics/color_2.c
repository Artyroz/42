/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 00:53:11 by mgallo            #+#    #+#             */
/*   Updated: 2016/11/15 15:09:32 by lvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "graphics/color.h"
#include "maths/rt_math.h"

t_color		*color_pow(t_color *c0, double v)
{
	c0->r = CLAMP(pow(c0->r, v), 0.0, 1.0);
	c0->g = CLAMP(pow(c0->g, v), 0.0, 1.0);
	c0->b = CLAMP(pow(c0->b, v), 0.0, 1.0);
	return (c0);
}
