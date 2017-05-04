/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallo <mgallo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 06:43:49 by mgallo            #+#    #+#             */
/*   Updated: 2016/11/14 13:48:45 by mgallo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "maths/vec3.h"
# define COLOR_MIN 0.001

typedef struct	s_color
{
	double	r;
	double	g;
	double	b;
}				t_color;

t_color			*color_new(double r, double g, double b);
t_color			*color_new_rgb(int r, int g, int b);
t_color			*color_new_hexa(int hexa);
void			color_free(t_color **c);
t_color			*color_mul(t_color *c0, t_color *c1);
t_color			*color_mul_value(t_color *c0, double v);
t_color			*color_mul_vec3(t_color *c0, t_vec3 *vec);
t_color			*color_add(t_color *c0, t_color *c1);
t_color			*color_copy(t_color *c);
t_color			*color_set(t_color *c, double r, double g, double b);
t_color			*color_pow(t_color *c0, double v);
#endif
