/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 23:23:59 by mgallo            #+#    #+#             */
/*   Updated: 2016/11/11 10:36:26 by lvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

# include "color.h"

typedef struct	s_material
{
	t_color		*ambient_color;
	t_color		*specular_color;
	float		shininess;
	int			blinn;
	float		reflection;
}				t_material;

t_material		*material_new(t_color *amb, t_color *spec);
void			material_free(t_material **mat);
int				material_size(t_material **mat);
#endif
