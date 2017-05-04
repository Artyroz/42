/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char2xyz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/11 10:53:44 by gmorer            #+#    #+#             */
/*   Updated: 2016/11/10 17:11:30 by lvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/parser.h"

t_vec3	*char2xyz(char *str, t_vec3 *t)
{
	t->x = char2double(str);
	if ((str = strchr(str, ' ')) == NULL)
		return (t);
	str++;
	t->y = char2double(str);
	if ((str = strchr(str, ' ')) == NULL)
		return (t);
	str++;
	t->z = char2double(str);
	return (t);
}
