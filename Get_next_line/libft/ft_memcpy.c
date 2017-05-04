/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpollet <dpollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 06:37:41 by dpollet           #+#    #+#             */
/*   Updated: 2014/11/16 17:18:10 by dpollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dest, const void *src, size_t n)
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
		dest2[a] = src2[a];
		a++;
	}
	return (dest);
}
