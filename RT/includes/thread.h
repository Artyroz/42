/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallo <mgallo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 02:41:35 by mgallo            #+#    #+#             */
/*   Updated: 2016/11/16 02:49:38 by mgallo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREAD_H
# define THREAD_H

# include <SDL2/SDL.h>
# include "graphics/window.h"

typedef struct	s_thread
{
	int			x;
	int			y;
	t_window	*win;
	SDL_Thread	*thread;
}				t_thread;

#endif
