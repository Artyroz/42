/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpollet <dpollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 10:30:33 by dpollet           #+#    #+#             */
/*   Updated: 2014/11/17 01:44:35 by dpollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		res;
	size_t	s1in;
	size_t	s2in;

	s1in = ft_strlen(s1);
	s2in = ft_strlen(s2);
	if (s1in <= s2in)
		s1in++;
	else
		s1in = s2in + 1;
	if (s1in > n)
		s1in = n;
	res = ft_memcmp(s1, s2, s1in);
	return (res);
}
