/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tab_of_tet.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhusler <qhusler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 19:45:32 by qhusler           #+#    #+#             */
/*   Updated: 2016/05/13 03:32:19 by qhusler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		*initializes(int *pos, int *i, int sit)
{
	pos[0] = -1;
	pos[1] = -1;
	pos[2] = -1;
	pos[3] = -1;
	if (sit == 1)
		i += 2;
	else if (sit == 0)
		pos[4] = 0;
	return (pos);
}

void	init_if_forest(char *input, int i, int *pos, t_tetris *p)
{
	if (input[i] == '#')
	{
		if (pos[2] != -1)
			pos[3] = i;
		else if (pos[1] != -1)
			pos[2] = i;
		else if (pos[0] != -1)
			pos[1] = i;
		else if (pos[0] == -1)
			pos[0] = i;
		if (pos[3] != -1)
		{
			p[pos[4]].piece = give_good_tetriminos(pos);
			p[pos[4]].lettre = tet_lettre(p[pos[4]].piece);
			p[pos[4]].position = -1;
			p[pos[4]].name = 65 + pos[4];
			pos[4]++;
		}
	}
}

void	tab_of_struct_initializer(int nb_tet, char *input, t_tetris *p)
{
	int pos[5];
	int i;

	i = 0;
	initializes(pos, &i, 0);
	p[nb_tet].piece = NULL;
	while (input[i])
	{
		if (input[i] == '\n' && input[i + 1] == '\n')
			initializes(pos, &i, 1);
		init_if_forest(input, i, pos, p);
		i++;
	}
}
