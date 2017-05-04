/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpollet <dpollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 17:33:09 by dpollet           #+#    #+#             */
/*   Updated: 2015/03/26 14:07:29 by dpollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_read		*ft_free(t_read *encours, t_read *prec, t_read **start)
{
	if (!prec)
		*start = encours->next;
	else
		prec->next = encours->next;
	free(encours->str);
	free(encours);
	if (!prec)
		return (*start);
	else
		return (prec->next);
}

static t_read		*ft_news(int fd)
{
	t_read			*news;
	char			*tmp;
	int				lu;

	news = (t_read *)malloc(sizeof(t_read));
	tmp = (char *)malloc(sizeof(char) * BUFF_SIZE);
	if ((lu = read(fd, tmp, BUFF_SIZE)) < 0)
	{
		free(news);
		free(tmp);
		return (NULL);
	}
	news->str = tmp;
	news->fd = fd;
	news->len = lu;
	news->idx = 0;
	news->next = NULL;
	return (news);
}

static int			ft_final(int b, t_read **glob, t_read **s, char **l)
{
	char			*tmp;
	int				a;

	if (!glob[0])
		return (-1);
	a = glob[0]->idx;
	if (b == -1 || !(tmp = (char *)malloc(sizeof(char) * (b + 1))))
		return (-1);
	*l = tmp;
	while (b--)
	{
		*tmp++ = glob[0]->str[a++];
		if (a == glob[0]->len)
		{
			glob[0] = ft_free(glob[0], glob[1], s);
			a = 0;
		}
	}
	*tmp = 0;
	if (!glob[0] || (a == glob[0]->len && glob[0]->len < BUFF_SIZE))
		return (0);
	glob[0]->idx = a + 1;
	if (glob[0]->idx == glob[0]->len)
		glob[0] = ft_free(glob[0], glob[1], s);
	return (1);
}

static int			ft_strlen_read(int fd, t_read *encours)
{
	int				a;
	int				size;
	t_read			*tmp;

	size = 0;
	a = encours->idx;
	while (encours->str[a] != '\n' && a < encours->len)
	{
		a++;
		size++;
		if (a == encours->len && encours->len == BUFF_SIZE)
		{
			if (!(tmp = ft_news(fd)))
				return (-1);
			tmp->next = encours->next;
			encours->next = tmp;
			encours = tmp;
			a = 0;
		}
	}
	return (size);
}

int					get_next_line(int const fd, char **line)
{
	static t_read	*start = NULL;
	t_read			**glob;
	int				taille;

	glob = (t_read **)malloc(sizeof(t_read *) * 2);
	if (fd < 0 || !line)
		return (-1);
	glob[1] = NULL;
	if (!start)
		start = ft_news(fd);
	glob[0] = start;
	while (glob[0]->fd != fd)
	{
		if (!(glob[0]->next))
			glob[0]->next = ft_news(fd);
		glob[1] = glob[0];
		glob[0] = glob[0]->next;
	}
	if (!glob[0] || !start)
		return (-1);
	taille = ft_strlen_read(fd, glob[0]);
	return (ft_final(taille, glob, &start, line));
}
