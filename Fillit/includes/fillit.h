/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhusler <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 19:48:34 by qhusler           #+#    #+#             */
/*   Updated: 2016/05/12 03:32:16 by qhusler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <fcntl.h>

typedef struct		s_check_tet
{
	int				i;
	int				nb_tet;
	int				nb_dieze;
	int				nb_dot;
}					t_check_tet;

typedef struct		s_tetris
{
	int				position;
	char			*piece;
	char			name;
	char			*lettre;
}					t_tetris;

int					parsing_main(char *map, int *nb_tetriminos);
void				tab_of_struct_initializer(int nb_tet, char *s, t_tetris *p);
char				*give_good_tetriminos(int pos[5]);
void				new_map(int size_map, char *map, t_tetris *p);
char				*ft_solve(char *map, t_tetris *p);

char				*tet_lettre(char *s);
char				*tet_color(char *s);
void				putchar_color(char *s1, char c);
void				print_map_color(char *s, t_tetris *pieces);

#endif
