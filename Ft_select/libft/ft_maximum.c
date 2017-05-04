/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maximum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpollet <dpollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 14:30:43 by dpollet           #+#    #+#             */
/*   Updated: 2015/03/27 14:33:49 by dpollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_maximum(int *tab, int len)
{
	int			i;
	int			max;

	i = 0;
	max = tab[i];
	while (i < len)
	{
		if (max < tab[i])
			max = tab[i];
		i++;
	}
	return (max);
}
