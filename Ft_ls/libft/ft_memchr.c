/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpollet <dpollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 06:37:41 by dpollet           #+#    #+#             */
/*   Updated: 2014/11/16 17:18:20 by dpollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;
	char	rech;
	size_t	a;

	if (s == NULL)
		return (NULL);
	a = 0;
	str = (char *)s;
	rech = (char)c;
	while (a < n)
	{
		if (str[a] == rech)
			return (&(str[a]));
		a++;
	}
	return (NULL);
}
