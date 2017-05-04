/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpollet <dpollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 06:37:41 by dpollet           #+#    #+#             */
/*   Updated: 2014/11/16 17:18:26 by dpollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	a;
	char	*dest2;
	char	*src2;

	if (dest == NULL || src == NULL)
		return (NULL);
	a = 0;
	dest2 = (char *)dest;
	src2 = (char *)src;
	while (a < n)
	{
		if (src2[a] == (char)c)
		{
			dest2[a] = src2[a];
			return (dest + a + 1);
		}
		dest2[a] = src2[a];
		a++;
	}
	return (NULL);
}
