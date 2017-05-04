/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpollet <dpollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 23:12:37 by dpollet           #+#    #+#             */
/*   Updated: 2014/11/17 22:18:05 by dpollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		taille(int n, size_t *a, int *b)
{
	*a = 1;
	if (n >= 0)
	{
		*a = 0;
		n = -n;
	}
	*b = 1;
	while (n / *b < -9)
	{
		*b *= 10;
		*a += 1;
	}
}

char			*ft_itoa(int n)
{
	size_t		a;
	int			b;
	size_t		res;
	char		*str;

	taille(n, &a, &b);
	str = (char *)malloc(sizeof(*str) * (a + 1));
	if (str == NULL)
		return (NULL);
	res = 0;
	if (n < 0)
	{
		str[res] = '-';
		res++;
	}
	if (n > 0)
		n = -n;
	while (b >= 1)
	{
		str[res++] = -(n / b % 10) + 48;
		b /= 10;
	}
	str[res] = '\0';
	return (str);
}
