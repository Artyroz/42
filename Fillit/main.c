/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qhusler <qhusler@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 19:42:54 by qhusler           #+#    #+#             */
/*   Updated: 2016/05/13 03:36:34 by qhusler          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void			error(void)
{
	ft_putendl("error");
	exit(1);
}

void			usage(void)
{
	ft_putendl("usage: fillit [file]");
	exit(0);
}

char			*read_file(char *file, char **av)
{
	char	buff;
	int		fd;
	int		len;
	int		ret;

	if ((fd = open(av[1], O_RDONLY)) < 0)
		error();
	len = 0;
	while ((ret = read(fd, &buff, 1)) != 0)
		len++;
	close(fd);
	if ((fd = open(av[1], O_RDONLY)) < 0)
		error();
	file = ft_strnew(len);
	while (read(fd, file, len))
		;
	file[len] = 0;
	close(fd);
	return (file);
}

int				main(int ac, char **av)
{
	char		*file;
	char		*map;
	int			nb_tet;
	t_tetris	*pieces;

	if (ac != 2)
		usage();
	file = NULL;
	file = read_file(file, av);
	if (parsing_main(file, &nb_tet) == 0)
		error();
	pieces = NULL;
	pieces = (t_tetris*)malloc(sizeof(t_tetris) * (nb_tet + 1));
	tab_of_struct_initializer(nb_tet, file, pieces);
	map = ft_strnew(800);
	new_map(3, map, pieces);
	map = ft_solve(map, pieces);
	ft_putendl(map);
	return (0);
}
