/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpollet <dpollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 01:29:55 by dpollet           #+#    #+#             */
/*   Updated: 2014/11/17 00:39:23 by dpollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t		s2in;

	if (*s2 == '\0')
		return (char *)s1;
	s2in = ft_strlen(s2);
	while (*s1 != '\0' && len >= s2in)
	{
		if (*s1 == *s2 && ft_memcmp(s1, s2, s2in) == 0)
			return ((char *)s1);
		len--;
		s1++;
	}
	return (NULL);
}
