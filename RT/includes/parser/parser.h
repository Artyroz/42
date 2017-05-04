/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 10:09:53 by gmorer            #+#    #+#             */
/*   Updated: 2016/11/11 10:38:28 by lvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdlib.h>
# include <fcntl.h>
# include "error.h"
# include "libft.h"
# include "graphics/color.h"
# include "graphics/light.h"
# include "graphics/material.h"
# include "graphics/window.h"
# include "parser/get_next_line.h"
# include "maths/camera.h"
# include "maths/vec3.h"
# include "objects/objects.h"

size_t		ft_voidxxlen(void **c);
int			ft_voidxxfree(void ***data);
void		**ft_voidxxadd(void *str, void **tab);
void		**ft_voidxxnew(size_t i);
t_color		*char2color(char *temp, t_color *color);
t_vec3		*char2xyz(char *temp, t_vec3 *v);
double		char2double(char *temp);
t_window	*parser(char *str, t_window *win);
t_material	*ft_rempmaterial(char **file, int *i);
t_window	*ft_rempcamera(char **file, int *i, t_window *win);
t_light		*ft_remplight(char **file, int *i);
t_objects	*ft_rempobject(char **file, int *i);
t_window	*ft_rempscene(char **file, int *i, t_window *scene);
int			object_type(char *type);
int			freefile(char **file);
t_window	*ft_redirect(char **file, int *i, t_window *result);
t_triangle	*ft_remptriangle(char **file, int *i);
t_color		*color_new(double r, double g, double b);
t_color		*color_new_rgb(int r, int g, int b);
int			checker(t_window *win);
int			check_triangle(t_window *win, int i, int s);
void		verif_object(t_window *win, int i);
int			check_camera(t_window *win);

#endif
