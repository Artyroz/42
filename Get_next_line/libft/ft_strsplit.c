/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpollet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 00:22:18 by dpollet           #+#    #+#             */
/*   Updated: 2014/11/27 01:42:56 by dpollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_mots(char const *s, char c)
{
	int		a;
	int		b;

	a = 0;
	b = 0;
	if (s[b] != c)
		a = 1;
	else
		a = 0;
	while (s[b + 1] != '\0')
	{
		if (s[b] == c && s[b + 1] != c)
			a++;
		b++;
	}
	return (a);
}

static int		ft_len(char *s, char c, int b)
{
	int		a;

	a = 0;
	while (s[b] != c)
	{
		if (s[b] == '\0')
			return (a);
		a++;
		b++;
	}
	return (a);
}

static char		*ft_ecrire(char *s, char c, int b)
{
	char	*dest;
	int		a;

	a = 0;
	dest = (char *)ft_memalloc(sizeof(char) * (ft_len((char *)s, c, b)));
	while (s[b] != c && s[b] != '\0')
	{
		dest[a] = s[b];
		b++;
		a++;
	}
	dest[a] = '\0';
	return (dest);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**dest;
	int		mots;
	int		a;
	int		b;

	b = 0;
	a = 0;
	if (!s)
		return (NULL);
	mots = ft_mots(s, c);
	dest = (char **)ft_memalloc(sizeof(char *) * (mots + 1));
	while (s[b] != '\0')
	{
		if (s[b] != c)
		{
			dest[a] = ft_ecrire((char *)s, c, b);
			a++;
			b = b + ft_len((char *)s, c, b);
		}
		if (s[b] == '\0')
			return (dest);
		b++;
	}
	return (dest);
}
