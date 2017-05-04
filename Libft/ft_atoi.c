/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpollet <dpollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 20:00:59 by dpollet           #+#    #+#             */
/*   Updated: 2014/11/27 01:10:26 by dpollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_excep(char *s1)
{
	char		*s2;

	s2 = "9223372036854775808";
	if (ft_isdigit(*s1) == 0)
		return (1);
	while (*s1 && *s2 && *s1 == *s2 && ft_isdigit(*s1) == 1)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

static int		ft_digitlen(char const *s1)
{
	int			a;

	a = 0;
	while (s1[a] && ft_isdigit(s1[a]) == 1)
		a++;
	return (a);
}

int				ft_atoi(const char *str)
{
	int			positive;
	int			value;

	value = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v'
			|| *str == '\r' || *str == '\f')
		str++;
	positive = (*str == '-' ? -1 : 1);
	if (*str == '-' || *str == '+')
		str++;
	while (*str == '0')
		str++;
	if (ft_digitlen(str) > 19 || (ft_digitlen(str) == 19 &&
				(ft_excep((char *)(str)) >= 0)))
		return (positive == 1 ? -1 : 0);
	while (ft_isdigit(*str) && *str != '\0')
	{
		value = (value * 10) + (int)(*str - '0');
		str++;
	}
	return (value * positive);
}
