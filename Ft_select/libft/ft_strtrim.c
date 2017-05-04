/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpollet <dpollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 19:16:01 by dpollet           #+#    #+#             */
/*   Updated: 2014/11/25 02:53:12 by dpollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_isspace(int c)
{
	int		rsl;

	rsl = 0;
	if (c == 32 || (c >= 9 && c <= 13))
		rsl = 1;
	return (rsl);
}

char				*ft_strtrim(char const *s)
{
	char	*rtn;
	int		i;
	int		lens;

	i = 0;
	if (s)
	{
		lens = ft_strlen(s) - 1;
		while (ft_isalnum(s[i]) == 0 && i <= lens)
			i++;
		while (ft_isspace(s[lens]) != 0 && lens >= i)
			lens--;
		if ((rtn = (char *)malloc(lens - i + 1)))
		{
			ft_strclr(rtn);
			ft_strncpy(rtn, (s + i), (lens - i + 1));
			return (rtn);
		}
	}
	return (NULL);
}
