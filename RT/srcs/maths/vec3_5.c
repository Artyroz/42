/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 22:06:42 by mgallo            #+#    #+#             */
/*   Updated: 2016/10/18 10:32:36 by lvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "maths/vec3.h"

t_vec3		*vec3_new_add(t_vec3 *v0, t_vec3 *v1)
{
	t_vec3	*v;

	v = vec3_copy(v0);
	vec3_add(v, v1);
	return (v);
}
