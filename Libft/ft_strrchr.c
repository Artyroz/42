/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpollet <dpollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/09 18:02:12 by dpollet           #+#    #+#             */
/*   Updated: 2014/11/17 00:18:18 by dpollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	const char		*str;
	char			c2;

	str = s;
	c2 = (char)c;
	str = str + ft_strlen(s);
	while (*str != c2 && str != s)
		str--;
	if (*str == c2)
		return ((char *)str);
	return (NULL);
}
