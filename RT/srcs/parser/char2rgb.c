/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char2rgb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 17:18:34 by paim              #+#    #+#             */
/*   Updated: 2016/11/10 12:12:06 by lvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/parser.h"

static int			hex2int(char c, char v)
{
	int				result;

	result = 0;
	if (c >= '0' && c <= '9')
		c = c - '0';
	else if (c >= 'A' && c <= 'F')
		c = c - 'A' + 10;
	else
		return (result);
	if (v >= '0' && v <= '9')
		v = v - '0';
	else if (v >= 'A' && v <= 'F')
		v = v - 'A' + 10;
	else
		return (result);
	return (c * 16 + v);
}

static t_color		*char2hexa(char *str, t_color *color)
{
	int				r;
	int				g;
	int				b;

	if (ft_strlen(str) != ft_strlen("0x000000"))
	{
		ft_putendl("no color1");
		return (color);
	}
	str += 2;
	r = hex2int(str[0], str[1]);
	str += 2;
	g = hex2int(str[0], str[1]);
	str += 2;
	b = hex2int(str[0], str[1]);
	color->r = (double)r / 255.0;
	color->g = (double)g / 255.0;
	color->b = (double)b / 255.0;
	return (color);
}

static t_color		*char2rgb(char *str, t_color *color)
{
	int				r;
	int				g;
	int				b;

	r = ft_atoi(str);
	str = strchr(str, ' ');
	str++;
	g = ft_atoi(str);
	str = strchr(str, ' ');
	str++;
	b = ft_atoi(str);
	if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 ||
				b > 255))
	{
		ft_putendl("no color2");
		return (color);
	}
	color->r = (double)r / 255.0;
	color->g = (double)g / 255.0;
	color->b = (double)b / 255.0;
	return (color);
}

static t_color		*char2rgbdouble(char *str, t_color *color)
{
	double			r;
	double			g;
	double			b;

	r = char2double(str);
	if ((str = strchr(str, ' ')) == NULL)
		return (color);
	str++;
	g = char2double(str);
	if ((str = strchr(str, ' ')) == NULL)
		return (color);
	str++;
	b = char2double(str);
	color->r = r;
	color->g = g;
	color->b = b;
	return (color);
}

t_color				*char2color(char *str, t_color *color)
{
	char			*s;

	if ((s = ft_strchr(str, ' ')))
	{
		if ((&s[1]) && (s = ft_strchr(s + 1, ' ')))
		{
			if ((s = ft_strchr(str, '.')))
			{
				ft_putendl("test2");
				if ((&s[1]) && (s = ft_strchr(s + 1, '.')))
					if ((s = ft_strchr(s + 1, '.')))
						return (char2rgbdouble(str, color));
			}
			else
				return (char2rgb(str, color));
		}
	}
	if ((ft_strlen(str) == ft_strlen("0x000000"))
			&& (ft_strncmp(str, "0x0", 2) == 0))
		return (char2hexa(str, color));
	ft_putendl("no color3");
	return (color);
}
