/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpollet <dpollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/19 09:59:29 by dpollet           #+#    #+#             */
/*   Updated: 2015/05/19 17:18:21 by dpollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <math.h>

# define INVALID_Z	2000000

typedef struct	s_env{

	void	*mlx;
	void	*window;
	void	*img_ptr;
	char	*data;
	int		max_x;
	int		max_y;
	int		r;
	int		g;
	int		b;
	int		zoom;
	int		z_ch;
	int		x1;
	int		x2;
	int		y1;
	int		y2;
	int		**map;
}				t_env;

int				strlen_espace(char *line);
void			compteur_max(char *argv, t_env *e);
void			parse_map(char *argv, t_env *e);
int				commande_touche(int keycode, t_env *e);
void			pixel(t_env *e, int y, int x);
void			aff_line(t_env *e);
void			transforme(t_env *e, int x, int y, int n);
void			creat_img(t_env *e, int n);
void			aff(t_env *e);
int				ft_init_mlx(t_env *e);
int				event_demander(t_env *e);
void			parse_final(t_env *e, char **split, int *x, int y);

#endif
