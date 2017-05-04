/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpollet <dpollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 06:37:41 by dpollet           #+#    #+#             */
/*   Updated: 2014/11/16 17:23:06 by dpollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			a;

	if (s1 && s2)
	{
		a = 0;
		str1 = (unsigned char *)s1;
		str2 = (unsigned char *)s2;
		while (a < n)
		{
			if (str1[a] != str2[a])
				return (str1[a] - str2[a]);
			a++;
		}
	}
	return (0);
}
