/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpollet <dpollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/29 16:15:02 by dpollet           #+#    #+#             */
/*   Updated: 2015/04/30 14:25:54 by dpollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_pwd(void)
{
	char			*cwd;
	char			*buff;

	buff = NULL;
	cwd = (char *)ft_memalloc(sizeof(char) * (MAX + 1));
	cwd = getcwd(buff, MAX + 1);
	if (cwd != NULL)
		return (cwd);
	return (NULL);
}
