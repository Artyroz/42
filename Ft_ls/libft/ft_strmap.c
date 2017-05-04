/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpollet <dpollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 02:07:23 by dpollet           #+#    #+#             */
/*   Updated: 2015/03/26 14:12:52 by dpollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	int		comp;
	char	*str;

	str = NULL;
	if (s && f)
	{
		comp = ft_strlen(s);
		str = (char *)malloc(sizeof(char) * comp);
		comp = 0;
		while (s[comp] != '\0')
		{
			str[comp] = (*f)(s[comp]);
			comp++;
		}
	}
	return (str);
}
