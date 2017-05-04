/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallo <mgallo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 09:04:36 by mgallo            #+#    #+#             */
/*   Updated: 2016/11/15 11:18:10 by mgallo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "graphics/window.h"
#include "maths/camera.h"
#include "objects/objects.h"
#include "parser/parser.h"
#include "error.h"
#include "libft.h"

t_window		*window_new(void)
{
	t_window	*win;

	win = (t_window *)malloc(sizeof(t_window));
	if (win == NULL)
		return (NULL);
	win->error = NO_ERROR;
	return (win);
}

void			window_free(t_window **w)
{
	int		i;

	if (*w == NULL)
		return ;
	if ((*w)->camera != NULL)
		camera_free(&((*w)->camera));
	if ((*w)->objects != NULL)
	{
		i = -1;
		while ((*w)->objects[++i] != NULL)
			objects_free(&((*w)->objects[i]));
		free((*w)->objects);
	}
	if ((*w)->screen != NULL)
		image_free(*w, (*w)->screen);
	if ((*w)->win != NULL)
		SDL_DestroyWindow((*w)->win);
	free(*w);
	*w = NULL;
}

void			window_create(t_window *w, char *title)
{
	if (w->width <= 0 || w->height <= 0)
	{
		w->error = ERROR_WINDOW_SIZE;
		return ;
	}
	if (SDL_Init(SDL_INIT_VIDEO) == -1)
	{
		w->error = ERROR_SDL_INIT;
		return ;
	}
	w->win = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, w->width, w->height, 0);
	if (w->win == NULL)
	{
		w->error = ERROR_WINDOW_CREATE;
		return ;
	}
	w->screen = image_new(w);
}

void			draw_pixel(t_window *w, int x, int y, t_color *color)
{
	Uint8	r;
	Uint8	g;
	Uint8	b;

	if (x < 0 || y < 0 || x >= w->width || y >= w->height)
		return ;
	r = (Uint8)(color->r * 255);
	g = (Uint8)(color->g * 255);
	b = (Uint8)(color->b * 255);
	SDL_SetRenderDrawColor(w->screen, r, g, b, 255);
	SDL_RenderDrawPoint(w->screen, x, y);
}

int				window_check(t_window *win)
{
	size_t	s;

	s = ft_voidxxlen((void **)win->objects);
	ft_putstr("Object(s) Loaded: ");
	ft_putnbr(s);
	s = ft_voidxxlen((void **)win->lights);
	ft_putstr("\nLight(s) Loaded: ");
	ft_putnbr(s);
	s = ft_voidxxlen((void **)win->materials);
	ft_putstr("\nMaterial(s) Loaded: ");
	ft_putnbr(s);
	ft_putstr("\n");
	return (checker(win));
}
