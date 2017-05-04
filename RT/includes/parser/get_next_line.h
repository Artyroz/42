/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 14:46:58 by gmorer            #+#    #+#             */
/*   Updated: 2016/11/11 10:37:41 by lvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 456

# include "libft.h"
# include <unistd.h>

typedef struct				s_line
{
	int						oct;
	char					*tmp;
	char					*chr;
	char					*buff;
}							t_line;

int							get_next_line(int const fd, char **line);

#endif
