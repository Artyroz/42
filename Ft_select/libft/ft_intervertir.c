/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intervertir.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpollet <dpollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/27 15:09:31 by dpollet           #+#    #+#             */
/*   Updated: 2015/03/27 15:13:41 by dpollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				*ft_intervertir(int *tab, int a, int b)
{
	int			tmp;

	tmp = 0;
	tmp = tab[a];
	tab[a] = tab[b];
	tab[b] = tmp;
	return (tab);
}
