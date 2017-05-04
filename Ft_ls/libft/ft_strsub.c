/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpollet <dpollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 22:38:43 by dpollet           #+#    #+#             */
/*   Updated: 2015/03/26 14:13:25 by dpollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*dest;
	unsigned int	a;

	dest = NULL;
	if (s)
	{
		dest = (char *)malloc(len + 1);
		if (!dest)
			return (NULL);
		a = 0;
		while ((int)len > 0)
		{
			dest[a] = s[start];
			a++;
			start++;
			len--;
		}
		dest[a] = '\0';
	}
	return (dest);
}
