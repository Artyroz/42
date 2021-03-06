/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlenc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpollet <dpollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 13:27:45 by dpollet           #+#    #+#             */
/*   Updated: 2015/04/30 14:26:20 by dpollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_strlenc(char *sc, int c)
{
	int				a;

	a = 0;
	while (sc[a])
	{
		if (sc[a] == (char)c)
			break ;
		a++;
	}
	return (a);
}
