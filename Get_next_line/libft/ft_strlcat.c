/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpollet <dpollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 20:09:40 by dpollet           #+#    #+#             */
/*   Updated: 2014/11/16 23:21:26 by dpollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		temp;
	size_t		dstin;
	size_t		srcin;

	dstin = 0;
	srcin = ft_strlen(src);
	temp = size;
	while (size != 0 && *dst != '\0')
	{
		size--;
		dst++;
		dstin++;
	}
	if (size == 0)
		return (temp + srcin);
	while (size > 1 && src != '\0')
	{
		*dst = *src;
		dst++;
		src++;
		size--;
	}
	*dst = '\0';
	return (dstin + srcin);
}
