/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpollet <dpollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 14:24:52 by dpollet           #+#    #+#             */
/*   Updated: 2015/03/27 14:33:11 by dpollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_minimum(int *tab, int len)
{
	int			min;
	int			i;

	i = 0;
	min = tab[i];
	while (i < len)
	{
		if (min > tab[i])
			min = tab[i];
		i++;
	}
	return (min);
}
