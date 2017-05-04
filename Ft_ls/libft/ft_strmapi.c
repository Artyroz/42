/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpollet <dpollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 18:18:35 by dpollet           #+#    #+#             */
/*   Updated: 2015/03/26 14:13:09 by dpollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	a;
	unsigned int	b;
	char			*str;

	a = 0;
	str = NULL;
	if (s && f)
	{
		b = ft_strlen(s);
		str = (char *)malloc(sizeof(char) * b);
		while (a < b)
		{
			str[a] = (*f)(a, s[a]);
			a++;
		}
	}
	return (str);
}
