/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libvoidxx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/06 10:58:14 by gmorer            #+#    #+#             */
/*   Updated: 2016/11/10 17:10:35 by lvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/parser.h"

size_t	ft_voidxxlen(void **c)
{
	size_t i;

	i = 0;
	while (c[i] != NULL)
		i++;
	return (i);
}

void	**ft_voidxxnew(size_t i)
{
	void	**rslt;
	size_t	x;

	if (!(rslt = malloc(sizeof(void*) * (i + 1))))
		rt_error(ERROR_RT_MALLOC);
	x = 0;
	while (x <= i)
	{
		rslt[x] = NULL;
		x++;
	}
	return (rslt);
}

void	**ft_voidxxadd(void *str, void **tab)
{
	void	**rslt;
	int		i;

	i = 0;
	rslt = ft_voidxxnew(ft_voidxxlen(tab) + 1);
	while (tab[i] != NULL)
	{
		rslt[i] = (tab[i]);
		i++;
	}
	rslt[i] = str;
	i = 0;
	free(tab);
	return (rslt);
}
