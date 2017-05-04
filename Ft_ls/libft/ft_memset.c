/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 22:54:29 by dpollet           #+#    #+#             */
/*   Updated: 2014/11/10 23:06:50 by dpollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memset(void *b, int c, size_t len)
{
	size_t	a;
	char	*str;

	str = (char *)b;
	a = 0;
	while (a < len)
	{
		str[a] = (unsigned char)c;
		a++;
	}
	return (b);
}
