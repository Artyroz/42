/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/16 15:33:08 by jbert             #+#    #+#             */
/*   Updated: 2015/09/23 17:10:03 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert.h"
#include "libftprintf/printf.h"
#include "gnl/get_next_line.h"

#include <stdio.h>

char	*ft_save_av(char *s)
{
	static char	*str = NULL;

	if (s)
		str = s;
	return (str);
}

char	ft_issign(char *l)
{
	int	i;

	i = 0;
	while (l[i] && !(l[i] == '>' && l[i - 1] == '=') && \
			l[i] != '+' && l[i] != '|' && l[i] != '^')
		i++;
	return (l[i]);
}

int		error_arg(void)
{
	ft_putendl_fd("Error : you shall give exactly 1 argument", 2);
	return (1);
}

int		check_cars(char c)
{
	if (c != ' ' && c != '=' && c != '>' && c != '<' \
			&& c != '+' && c != '|' && c != '^' && \
			c != '!' && c != '(' && c != ')' && \
			(c > 90 || c < 65))
		return (1);
	return (0);
}

char	*trim_my_cond(char *l)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	while (l[i] && l[i] != '#')
	{
		if (l[i] != ' ')
			j++;
		if (check_cars(l[i]))
			return (NULL);
		i++;
	}
	s = (char *)malloc(sizeof(char) * (j + 1));
	i = 0;
	j = 0;
	while (l[i] && l[i] != '#')
	{
		if (l[i] != ' ')
			s[j++] = l[i];
		i++;
	}
	s[j] = '\0';
	return (s);
}

t_cond	*ft_addcond(char *l)
{
	static t_cond	*cond = NULL;
	t_cond			*tmp;

	tmp = NULL;
	while (cond)
	{
		tmp = cond;
		cond = cond->next;
	}
	cond = (t_cond *)malloc(sizeof(t_cond));
	cond->prev = tmp;
	if (tmp)
		tmp->next = cond;
	cond->next = NULL;
	if ((cond->cond = trim_my_cond(l)) == NULL)
		return (NULL);
	while (cond->prev)
		cond = cond->prev;
	return (cond);
}

t_cond	*stat_cond(t_cond *c, int i)
{
	static t_cond	*cond = NULL;

	if (i == 1)
		cond = c;
	return (cond);
}

int		ft_isuppercase(char c)
{
	if (c >= 65 && c <= 90)
		return (1);
	return (0);
}

void	sub_add_exist(t_var *var, char c, int i)
{
	t_var			*tmp;

	tmp = var->next;
	var->next = (t_var *)malloc(sizeof(t_var));
	var->next->prev = var;
	var = var->next;
	if (tmp)
		tmp->prev = var;
	var->next = tmp;
	var->car = c;
	var->bin = i;
}

t_var	*ft_add_exist(char c, int i)
{
	static t_var	*var = NULL;

	while (var && var->next && var->next->car < c)
		var = var->next;
	if (!var)
	{
		var = (t_var *)malloc(sizeof(t_var));
		var->next = NULL;
		var->prev = NULL;
		var->car = c;
		var->bin = i;
		return (var);
	}
	else if ((var->next && var->next->car > c) || !(var->next))
		sub_add_exist(var, c, i);
	if (var->next && var->next->car == c)
		var->next->bin = i;
	while (var->prev)
		var = var->prev;
	return (var);
}

int		exist_var(char c, t_var *var)
{
	while (var)
	{
		if (var->car == c)
			return (var->bin);
		var = var->next;
	}
	return (-1);
}

void	var_change(t_var *var, char *cond)
{
	while (var)
	{
		if (var->bin == -1 && ft_strchr(cond, var->car) && \
				(ft_strchr(cond, var->car) - 1)[0] == '!')
		{
			if (ft_save_av(NULL))
				printf("On confirme que [%c] a pour valeur 0 pour \
rendre vrai la condition [%s]\n", var->car, cond);
			var->bin = 0;
		}
		var = var->next;
	}
}

void	set_vars(char *cond, t_var **var, int i, int j)
{
	*var = ft_add_exist(cond[i], j);
	if (j != -1 && ft_save_av(NULL))
		printf("On set [%c] a %d a cause de la condition :[%s]\n", \
	cond[i], j, cond);
	else if (ft_save_av(NULL))
		printf("On set [%c] a %d pour tester la condition :[%s]\n", \
	cond[i], j, cond);
}

int		add_if_needed(char *cond, t_var **var)
{
	int	i;
	int	j;
	int	f;

	i = 0;
	f = 0;
	while (cond[i] && cond[i] != '=')
	{
		if (cond[i] == '(')
		{
			j = add_if_needed(&(cond[++i]), var);
			if (j >= 0)
				return (-j);
			i -= j;
		}
		else if (cond[i] == ')')
			return (-i);
		else if (cond[i + 1] == '^' && ((exist_var(cond[i], *var) <= 0 && \
					((i > 0 && cond[i - 1] != '!') || i == 0)) || \
					(exist_var(cond[i], *var) > 0 && i > 0 && \
					cond[i - 1] == '!')))
			f = 1;
		else if (cond[i + 1] == '|' && ((exist_var(cond[i], *var) == 0 && \
					((i > 0 && cond[i - 1] != '!') || i == 0)) || \
					(exist_var(cond[i], *var) > 0 && i > 0 && \
					cond[i - 1] == '!')))
			f = 2;
		else if (i > 0 && f == 1 && cond[i - 1] == '^' && \
				(exist_var(cond[i], *var) <= 0 || \
				(cond[i] == '!' && exist_var(cond[i + 1], *var) > 0)))
			return (0);
		else if (i > 0 && f == 2 && cond[i - 1] == '|' && \
				(exist_var(cond[i], *var) <= 0 || \
				(cond[i] == '!' && exist_var(cond[i + 1], *var) > 0)))
			return (0);
		else if (i > 0 && !f && cond[i - 1] == '^' && \
				(exist_var(cond[i], *var) > 0 || \
				(exist_var(cond[i + 1], *var) <= 0 && cond[i] == '!')))
			return (0);
		else if (i > 0 && !f && cond[i - 1] == '|')
			i += cond[i] == '!' ? 1 : 0;
		else if (i > 0 && (cond[i - 1] == '^' || cond[i - 1] == '|'))
			f = 0;
		else if (ft_isuppercase(cond[i]) && exist_var(cond[i], *var) != 0 && \
				i > 0 && cond[i - 1] == '!')
			return (0);
		else if (ft_isuppercase(cond[i]) && exist_var(cond[i], *var) <= 0 && \
				((i > 0 && cond[i - 1] != '!') || i == 0))
			return (0);
		i++;
	}
	if (!cond[i] || (cond[i++] == '=' && cond[i] != '>'))
		return (-1);
	i++;
	j = 0;
	while (cond[i])
	{
		if (exist_var(cond[i], *var) == -1 && ft_isuppercase(cond[i]) && \
			cond[i - 1] != '!' && (++j))
			set_vars(cond, var, i, 1);
		if (exist_var(cond[i], *var) == -1 && ft_isuppercase(cond[i]) && \
			cond[i - 1] == '!' && (++j))
			set_vars(cond, var, i, 0);
		if (exist_var(cond[i], *var) == 0 && ft_isuppercase(cond[i]) && \
			cond[i - 1] != '!')
			return (-1);
		if (exist_var(cond[i], *var) == 1 && ft_isuppercase(cond[i]) && \
			cond[i - 1] == '!')
			return (-1);
		i++;
	}
	return ((j != 0));
}

int		add_if_needed_2(char *cond, t_var **var)
{
	int	i;
	int	j;
	int	f;

	i = 0;
	f = 0;
	while (cond[i] && cond[i] != '=')
	{
		if (cond[i] == '(')
		{
			j = add_if_needed_2(&(cond[++i]), var);
			if (j >= 0)
				return (-j);
			i -= j;
		}
		else if (cond[i] == ')')
			return (-i);
		else if (cond[i + 1] == '^' && ((exist_var(cond[i], *var) <= 0 && \
					((i > 0 && cond[i - 1] != '!') || i == 0)) || \
					(exist_var(cond[i], *var) > 0 && i > 0 && \
					cond[i - 1] == '!')))
			f = 1;
		else if (cond[i + 1] == '|' && ((exist_var(cond[i], *var) <= 0 && \
					((i > 0 && cond[i - 1] != '!') || i == 0)) || \
					(exist_var(cond[i], *var) > 0 && i > 0 && \
					cond[i - 1] == '!')))
			f = 2;
		else if (i > 0 && f == 1 && cond[i - 1] == '^' && \
				(exist_var(cond[i], *var) <= 0 || \
				(cond[i] == '!' && exist_var(cond[i + 1], *var) > 0)))
			return (0);
		else if (i > 0 && f == 2 && cond[i - 1] == '|' && \
				(exist_var(cond[i], *var) <= 0 || \
				(cond[i] == '!' && exist_var(cond[i + 1], *var) > 0)))
			return (0);
		else if (i > 0 && !f && cond[i - 1] == '^' && \
				(exist_var(cond[i], *var) > 0 || \
				(exist_var(cond[i + 1], *var) <= 0 && cond[i] == '!')))
			return (0);
		else if (i > 0 && !f && cond[i - 1] == '|')
			i += cond[i] == '!' ? 1 : 0;
		else if (i > 0 && (cond[i - 1] == '^' || cond[i - 1] == '|'))
			f = 0;
		else if (ft_isuppercase(cond[i]) && exist_var(cond[i], *var) > 0 && \
				i > 0 && cond[i - 1] == '!')
			return (0);
		else if (ft_isuppercase(cond[i]) && exist_var(cond[i], *var) <= 0 && \
				((i > 0 && cond[i - 1] != '!') || i == 0))
			return (0);
		if (ft_isuppercase(cond[i]) && exist_var(cond[i], *var) == -1 && \
				(i > 0 && cond[i - 1] == '!'))
			set_vars(cond, var, i, -1);
		i++;
	}
	if (!cond[i] || (cond[i++] == '=' && cond[i] != '>'))
		return (-1);
	i++;
	var_change(*var, cond);
	j = 0;
	while (cond[i])
	{
		if (exist_var(cond[i], *var) == -1 && ft_isuppercase(cond[i]) && \
			cond[i - 1] != '!' && (++j))
			set_vars(cond, var, i, 1);
		if (exist_var(cond[i], *var) == -1 && ft_isuppercase(cond[i]) && \
			cond[i - 1] == '!' && (++j))
			set_vars(cond, var, i, 0);
		if (exist_var(cond[i], *var) == 0 && ft_isuppercase(cond[i]) && \
			cond[i - 1] != '!')
			return (-1);
		if (exist_var(cond[i], *var) == 1 && ft_isuppercase(cond[i]) && \
			cond[i - 1] == '!')
			return (-1);
		i++;
	}
	return ((j != 0));
}

int		add_if_needed_3(char *cond, t_var **var)
{
	int	i;
	int	j;
	int	f;

	i = ft_strchr(cond, '>') - cond;
	f = 0;
	while (cond[i])
	{
		if (cond[i] == '(')
		{
			j = add_if_needed_3(&(cond[++i]), var);
			if (j >= 0)
				return (-j);
			i -= j;
		}
		else if (cond[i] == ')')
			return (-i);
		else if (cond[i + 1] == '^' && ((exist_var(cond[i], *var) <= 0 && \
					((i > 0 && cond[i - 1] != '!') || i == 0)) || \
					(exist_var(cond[i], *var) > 0 && i > 0 && \
					cond[i - 1] == '!')))
			f = 1;
		else if (cond[i + 1] == '|' && ((exist_var(cond[i], *var) == 0 && \
					((i > 0 && cond[i - 1] != '!') || i == 0)) || \
					(exist_var(cond[i], *var) > 0 && i > 0 && \
					cond[i - 1] == '!')))
			f = 2;
		else if (i > 0 && f == 1 && cond[i - 1] == '^' && \
				(exist_var(cond[i], *var) <= 0 || \
				(cond[i] == '!' && exist_var(cond[i + 1], *var) > 0)))
			return (0);
		else if (i > 0 && f == 2 && cond[i - 1] == '|' && \
				(exist_var(cond[i], *var) <= 0 || \
				(cond[i] == '!' && exist_var(cond[i + 1], *var) > 0)))
			return (0);
		else if (i > 0 && !f && cond[i - 1] == '^' && \
				(exist_var(cond[i], *var) > 0 || \
				(exist_var(cond[i + 1], *var) <= 0 && cond[i] == '!')))
			return (0);
		else if (i > 0 && !f && cond[i - 1] == '|')
			i += cond[i] == '!' ? 1 : 0;
		else if (i > 0 && (cond[i - 1] == '^' || cond[i - 1] == '|'))
			f = 0;
		else if (ft_isuppercase(cond[i]) && exist_var(cond[i], *var) != 0 && \
				i > 0 && cond[i - 1] == '!')
			return (0);
		else if (ft_isuppercase(cond[i]) && exist_var(cond[i], *var) <= 0 && \
				((i > 0 && cond[i - 1] != '!') || i == 0))
			return (0);
		i++;
	}
	i = 0;
	j = 0;
	while (cond[i] != '<')
	{
		if (exist_var(cond[i], *var) == -1 && ft_isuppercase(cond[i]) && \
			cond[i - 1] != '!' && (++j))
			set_vars(cond, var, i, 1);
		if (exist_var(cond[i], *var) == -1 && ft_isuppercase(cond[i]) && \
			cond[i - 1] == '!' && (++j))
			set_vars(cond, var, i, 0);
		if (exist_var(cond[i], *var) == 0 && ft_isuppercase(cond[i]) && \
			cond[i - 1] != '!')
			return (-1);
		if (exist_var(cond[i], *var) == 1 && ft_isuppercase(cond[i]) && \
			cond[i - 1] == '!')
			return (-1);
		i++;
	}
	return ((j != 0));
}

int		add_var(t_cond *cond, t_var **var)
{
	int	i;
	int	j;

	i = 0;
	while (cond)
	{
		j = i;
		i += add_if_needed(cond->cond, var);
		if (j > i)
			return (-1);
		cond = cond->next;
	}
	return (i);
}

int		add_var_2(t_cond *cond, t_var **var)
{
	int	i;
	int	j;

	i = 0;
	while (cond)
	{
		j = i;
		i += add_if_needed_2(cond->cond, var);
		if (j > i)
			return (-1);
		cond = cond->next;
	}
	return (i);
}

int		add_var_3(t_cond *cond, t_var **var)
{
	int	i;
	int	j;

	i = 0;
	while (cond)
	{
		j = i;
		if (ft_strchr(cond->cond, '<'))
			i += add_if_needed_3(cond->cond, var);
		if (j > i)
			return (-1);
		cond = cond->next;
	}
	return (i);
}

int		stock_my_vars(t_cond *cond, t_var **exist)
{
	int		i;

	while ((i = add_var(cond, exist)) > 0)
		;
	if (i < 0)
		return (0);
	while ((i = add_var_3(cond, exist)) > 0)
		;
	if (i < 0)
		return (0);
	while ((i = add_var_2(cond, exist)) > 0)
		;
	if (i < 0)
		return (0);
	return (1);
}

t_var	*stock_var(t_cond *cond, char *l)
{
	t_var	*exist;
	int		f;

	exist = ft_add_exist('\0', -1);
	f = 1;
	while (ft_isuppercase(*l) || *l == '!')
	{
		if (*l == '!')
			f = 0;
		if (ft_isuppercase(*l))
		{
			exist = ft_add_exist(*l, f);
			f = 1;
		}
		l++;
	}
	if (*l && *l != ' ' && *l != '\n')
		return (NULL);
	if (!stock_my_vars(cond, &exist))
		return (NULL);
	return (exist);
}

void	aff_vars(t_var *vars, char *l)
{
	if (ft_save_av(NULL))
		ft_putchar('\n');
	while (vars)
	{
		if ((ft_save_av(NULL) || ft_strchr(l, vars->car)) && vars->car)
			printf("La variable : [%c] est set a : [%d]\n", \
				vars->car, vars->bin);
		vars = vars->next;
	}
	printf("Every other resquested are false.\n");
}

int		treat(char *l)
{
	static t_var	*vars = NULL;

	if (ft_strchr(l, '=') && !ft_strchr(l, '?'))
	{
		if (l[0] == '=')
		{
			if (ft_strchr(l + 1, '=') || ft_issign(l))
				return (-1);
			if ((vars = stock_var(stat_cond(NULL, 0), l + 1)) == NULL)
				return (-1);
		}
		else
		{
			if (!ft_issign(l))
				return (-1);
			if (stat_cond(ft_addcond(l), 1) == NULL)
				return (-1);
		}
	}
	else if (!ft_strchr(l, '=') && ft_strchr(l, '?'))
		aff_vars(vars, l);
	else
		return (-1);
	return (1);
}

int		read_file(int i)
{
	int		j;
	char	*l;

	if (i == -1)
		return (-2);
	while ((j = get_next_line(i, &l)) > 0)
	{
		if (l[0] != '#')
			j = treat(l);
		if (j < 0)
			return (-3);
		free(l);
	}
	if (j < 0)
		return (-4);
	close(i);
	return (1);
}

int		error_file(int i)
{
	if (i == -2)
		ft_putendl_fd("This file is not openable", 2);
	if (i == -3)
		ft_putendl_fd("This file is invalid", 2);
	if (i == -4)
		ft_putendl_fd("This file couldn't be fully read", 2);
	return (-i);
}

int		main(int ac, char **av)
{
	if (ac < 2)
		ft_save_av("-v");
	if (ac > 3)
		return (error_arg());
	if (ac == 3 && ft_strcmp(av[1], "-v") != 0)
		return (error_arg());
	if (ac == 3)
		ft_save_av(av[1]);
	ac = read_file((ac < 2 ? 0 : open( av[ac - 1], O_RDONLY)));
	if (ac < 0)
		return (error_file(ac));
	return (0);
}
