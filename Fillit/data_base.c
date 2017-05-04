/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhusler <qhusler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 19:44:50 by qhusler           #+#    #+#             */
/*   Updated: 2016/05/12 19:33:33 by qhusler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*more_option(int p[5])
{
	if ((p[1] == p[0] + 1) && (p[2] == p[1] + 4) && (p[3] == p[2] + 1))
		return ("##\n##\0");
	else if ((p[1] == p[0] + 1) && (p[2] == p[1] + 1) && (p[3] == p[2] + 4))
		return ("###\n.#.\0");
	else if ((p[1] == p[0] + 4) && (p[2] == p[1] + 1) && (p[3] == p[2] + 1))
		return (".#.\n###\0");
	else if ((p[1] == p[0] + 5) && (p[2] == p[1] + 1) && (p[3] == p[2] + 4))
		return ("#.\n##\n#.\0");
	else if ((p[1] == p[0] + 4) && (p[2] == p[1] + 1) && (p[3] == p[2] + 5))
		return (".#\n##\n.#\0");
	else if ((p[1] == p[0] + 1) && (p[2] == p[1] + 5) && (p[3] == p[2] + 1))
		return ("##.\n.##\0");
	else if ((p[1] == p[0] + 4) && (p[2] == p[1] + 1) && (p[3] == p[2] + 4))
		return (".#\n##\n#.\0");
	else if ((p[1] == p[0] + 5) && (p[2] == p[1] + 1) && (p[3] == p[2] + 5))
		return ("#.\n##\n.#\0");
	else if ((p[1] == p[0] + 1) && (p[2] == p[1] + 3) && (p[3] == p[2] + 1))
		return (".##\n##.\0");
	return (NULL);
}

char	*give_good_tetriminos(int p[5])
{
	if (p[1] == (p[0] + 1) && p[2] == (p[1] + 4) && p[3] == p[2] + 5)
		return ("##\n#.\n#.\0");
	else if ((p[1] == p[0] + 5) && (p[2] == p[1] + 4) && (p[3] == p[2] + 1))
		return (".#\n.#\n##\0");
	else if ((p[1] == p[0] + 5) && (p[2] == p[1] + 1) && (p[3] == p[2] + 1))
		return ("#..\n###\0");
	else if ((p[1] == p[0] + 1) && (p[2] == p[1] + 1) && (p[3] == p[2] + 5))
		return ("###\n..#\0");
	else if ((p[1] == p[0] + 1) && (p[2] == p[1] + 1) && (p[3] == p[2] + 3))
		return ("###\n#..\0");
	else if ((p[1] == p[0] + 1) && (p[2] == p[1] + 5) && (p[3] == p[2] + 5))
		return ("##\n.#\n.#\0");
	else if ((p[1] == p[0] + 3) && (p[2] == p[1] + 1) && (p[3] == p[2] + 1))
		return ("..#\n###\0");
	else if ((p[1] == p[0] + 5) && (p[2] == p[1] + 5) && (p[3] == p[2] + 1))
		return ("#.\n#.\n##\0");
	else if ((p[1] == p[0] + 5) && (p[2] == p[1] + 5) && (p[3] == p[2] + 5))
		return ("#\n#\n#\n#\0");
	else if ((p[1] == p[0] + 1) && (p[2] == p[1] + 1) && (p[3] == p[2] + 1))
		return ("####\0");
	else
		return (more_option(p));
}

char	*tet_lettre(char *s)
{
	if (ft_strcmp(s, "#\n#\n#\n#\0") == 0 ||
			ft_strcmp(s, "####\0") == 0)
		return ("\x1b[38;5;39m");
	else if (ft_strcmp(s, "##\n##\0") == 0)
		return ("\x1b[38;5;11m");
	else if (ft_strcmp(s, "###\n#..\0") == 0 ||
			ft_strcmp(s, "##\n.#\n.#\0") == 0 ||
			ft_strcmp(s, "..#\n###\0") == 0 ||
			ft_strcmp(s, "#.\n#.\n##\0") == 0)
		return ("\x1b[38;5;202m");
	else if (ft_strcmp(s, "##\n#.\n#.\0") == 0 ||
			ft_strcmp(s, ".#\n.#\n##\0") == 0 ||
			ft_strcmp(s, "#..\n###\0") == 0 ||
			ft_strcmp(s, "###\n..#\0") == 0)
		return ("\x1b[38;5;19m");
	else if (ft_strcmp(s, ".#\n##\n#.\0") == 0 ||
			ft_strcmp(s, "##.\n.##\0") == 0)
		return ("\x1b[38;5;160m");
	else if (ft_strcmp(s, ".##\n##.\0") == 0 ||
			ft_strcmp(s, "#.\n##\n.#\0") == 0)
		return ("\x1b[38;5;82m");
	return ("\x1b[38;5;62m");
}

char	*tet_color(char *s)
{
	if (ft_strcmp(s, "#\n#\n#\n#\0") == 0 ||
			ft_strcmp(s, "####\0") == 0)
		return ("\x1b[48;5;39m");
	else if (ft_strcmp(s, "##\n##\0") == 0)
		return ("\x1b[48;5;220m");
	else if (ft_strcmp(s, "###\n#..\0") == 0 ||
			ft_strcmp(s, "##\n.#\n.#\0") == 0 ||
			ft_strcmp(s, "..#\n###\0") == 0 ||
			ft_strcmp(s, "#.\n#.\n##\0") == 0)
		return ("\x1b[48;5;166m");
	else if (ft_strcmp(s, "##\n#.\n#.\0") == 0 ||
			ft_strcmp(s, ".#\n.#\n##\0") == 0 ||
			ft_strcmp(s, "#..\n###\0") == 0 ||
			ft_strcmp(s, "###\n..#\0") == 0)
		return ("\x1b[48;5;19m");
	else if (ft_strcmp(s, ".#\n##\n#.\0") == 0 ||
			ft_strcmp(s, "##.\n.##\0") == 0)
		return ("\x1b[48;5;160m");
	else if (ft_strcmp(s, ".##\n##.\0") == 0 ||
			ft_strcmp(s, "#.\n##\n.#\0") == 0)
		return ("\x1b[48;5;34m");
	return ("\x1b[48;5;90m");
}
