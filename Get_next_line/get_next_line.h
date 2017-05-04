/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpollet <dpollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 17:33:19 by dpollet           #+#    #+#             */
/*   Updated: 2015/03/26 17:01:10 by dpollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 10

# include "libft/includes/libft.h"

typedef struct	s_read
{
	char			*str;
	int				fd;
	int				len;
	int				idx;
	struct s_read	*next;
}				t_read;

int				get_next_line(int const fd, char **line);

#endif
