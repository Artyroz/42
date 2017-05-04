/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 09:18:46 by mgallo            #+#    #+#             */
/*   Updated: 2016/11/15 15:09:57 by lvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "graphics/window.h"
#include "error.h"

SDL_Renderer		*image_new(t_window *w)
{
	SDL_Renderer	*img;

	if (w == NULL)
	{
		w->error = ERROR_WINDOW_NOCREATE;
		return (NULL);
	}
	img = SDL_CreateRenderer(w->win, 1, SDL_RENDERER_ACCELERATED);
	if (img == NULL)
	{
		w->error = ERROR_CREATE_RENDERER;
		return (NULL);
	}
	SDL_RenderClear(img);
	return (img);
}

void				image_free(t_window *w, SDL_Renderer *img)
{
	if (w == NULL)
		return ;
	SDL_DestroyRenderer(img);
}
