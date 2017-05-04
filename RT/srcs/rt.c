/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 19:05:55 by mgallo            #+#    #+#             */
/*   Updated: 2016/11/15 15:29:19 by lvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <SDL2/SDL.h>
#include "graphics/window.h"
#include "graphics/light.h"
#include "graphics/material.h"
#include "objects/objects.h"
#include "parser/parser.h"
#include "maths/rt_math.h"
#include "error.h"

static void			key_hook(t_window *win, int *quit)
{
	SDL_Keycode		sym;

	sym = win->event.key.keysym.sym;
	if (sym == SDLK_ESCAPE)
		*quit = 1;
}

void				default_value(t_window *win, char *file)
{
	win->width = 640;
	win->height = 480;
	win->camera = camera_new(70, DEPH_MIN, 1000);
	win->objects = (t_objects **)ft_voidxxnew(0);
	win->lights = (t_light **)ft_voidxxnew(0);
	win->materials = (t_material **)ft_voidxxnew(1);
	win->materials[0] = material_new(color_new(0.02, 0.02, 0.02),
		color_new(1.0, 1.0, 1.0));
	win->reflect = 5;
	win->aa = 1;
	parser(file, win);
	win->aa = CLAMP(win->aa, 1, 32);
}

static int			error_win(t_window *win)
{
	if (win->error > NO_ERROR)
	{
		rt_error(win->error);
		window_free(&win);
		return (-1);
	}
	return (0);
}

static void			launch_sdl(t_window *win, int quit)
{
	while (!quit)
	{
		while (SDL_PollEvent(&(win->event)))
		{
			if (win->event.window.event == SDL_WINDOWEVENT_CLOSE)
				quit = 1;
			if (win->event.type == SDL_KEYDOWN)
				key_hook(win, &quit);
		}
		SDL_RenderPresent(win->screen);
	}
}

int					main(int argc, char **argv)
{
	t_window		*win;
	int				quit;
	SDL_Thread		*thread;

	win = window_new();
	if (argc < 2)
	{
		rt_error(ERROR_BAD_FILE);
		return (-1);
	}
	default_value(win, argv[1]);
	if (window_check(win))
	{
		window_create(win, "RayTracer");
		thread = SDL_CreateThread(raytracer, "TestThread", (void *)win);
		SDL_DetachThread(thread);
		launch_sdl(win, quit);
	}
	error_win(win);
	return (0);
}
