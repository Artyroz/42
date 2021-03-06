/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 13:36:13 by jbert             #+#    #+#             */
/*   Updated: 2015/08/22 19:06:15 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(void *s, int c, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if ((unsigned char)(((char *)s)[i]) == (unsigned char)c)
			return (&((char *)s)[i]);
		i++;
	}
	return (NULL);
}
