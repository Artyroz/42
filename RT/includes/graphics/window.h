/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallo <mgallo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 09:01:51 by mgallo            #+#    #+#             */
/*   Updated: 2016/11/16 00:16:53 by mgallo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include "maths/camera.h"
# include "objects/objects.h"
# include "SDL2/SDL.h"
# include "light.h"
# include "material.h"

typedef struct		s_window
{
	SDL_Window		*win;
	int				width;
	int				height;
	SDL_Renderer	*screen;
	SDL_Event		event;
	int				error;
	t_cam			*camera;
	t_objects		**objects;
	t_light			**lights;
	t_material		**materials;
	int				reflect;
	int				aa;
}					t_window;

t_window			*window_new(void);
void				window_free(t_window **w);
void				window_create(t_window *w, char *title);
SDL_Renderer		*image_new(t_window *w);
void				image_free(t_window *w, SDL_Renderer *img);
void				draw_pixel(t_window *w, int x, int y, t_color *color);
int					window_check(t_window *win);
void				rt_check(t_window *win, t_ray *ray, double znear, int excl);
int					raytracer(void *w);
#endif
