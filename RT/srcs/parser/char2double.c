/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char2double.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 11:42:24 by paim              #+#    #+#             */
/*   Updated: 2016/11/11 12:18:36 by lvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/parser.h"
#include "math.h"

void	sign_verif(char *str, int *i, int *sign, double *val)
{
	if (str[*i] == '-')
	{
		*sign = -1;
		(*i)++;
	}
	while (str[*i] && str[*i] >= '0' && str[*i] <= '9')
	{
		*val = *val * 10;
		*val = (str[*i] - 48) + *val;
		(*i)++;
	}
}

double	char2double(char *str)
{
	int		i;
	double	val;
	char	check;
	int		i2;
	int		sign;

	i = 0;
	i2 = 1;
	val = 0;
	check = 0;
	sign = 1;
	if (str == NULL)
		return (0);
	sign_verif(str, &i, &sign, &val);
	if (str[i] == 46)
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		val = val + ((str[i] - 48) / pow(10, i2));
		i2++;
		i++;
	}
	return (val * sign);
}
