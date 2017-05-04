/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpollet <dpollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/17 01:48:46 by dpollet           #+#    #+#             */
/*   Updated: 2014/11/17 01:57:13 by dpollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * size);
	if (!str)
		return (NULL);
	else
		ft_strclr(str);
	return (str);
}
