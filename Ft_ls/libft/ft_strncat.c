/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpollet <dpollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/16 06:37:41 by dpollet           #+#    #+#             */
/*   Updated: 2014/11/16 17:16:25 by dpollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *dest, const char *src, size_t n)
{
	int	a;
	int	b;

	b = 0;
	a = ft_strlen(dest);
	while (n > 0)
	{
		dest[a] = src[b];
		a++;
		b++;
		n--;
	}
	dest[a] = '\0';
	return (dest);
}
