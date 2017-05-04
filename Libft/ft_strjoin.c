/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpollet <dpollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 18:54:47 by dpollet           #+#    #+#             */
/*   Updated: 2015/03/26 14:12:39 by dpollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	size_t		comp;
	size_t		a;
	char		*dest;

	dest = NULL;
	if (s1 && s2)
	{
		comp = ft_strlen(s1) + ft_strlen(s2) + 1;
		dest = (char *)malloc(sizeof(char) * comp);
		if (!dest)
			return (NULL);
		a = 0;
		while (comp > a)
		{
			if (a < ft_strlen(s1))
				dest[a] = s1[a];
			else
				dest[a] = s2[a - ft_strlen(s1)];
			a++;
		}
	}
	return (dest);
}
