/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 09:08:14 by mgallo            #+#    #+#             */
/*   Updated: 2016/11/14 18:30:03 by mabuchwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# define NO_ERROR 0
# define ERROR_WINDOW_SIZE 1
# define ERROR_WINDOW_MLX 2
# define ERROR_WINDOW_CREATE 3
# define ERROR_WINDOW_NOCREATE 4
# define ERROR_SDL_INIT 5
# define ERROR_CREATE_RENDERER 6
# define ERROR_IMAGE_DATA 7
# define ERROR_PARSER_MALLOC 8
# define ERROR_BAD_FILE 9
# define ERROR_RT_MALLOC 10
# define ERROR_CAMERA_NULL 11
# define ERROR_CAMERA_POS_NULL 12
# define ERROR_CAMERA_ROT_NULL 13
# define ERROR_CAMERA_FOV 14
# define ERROR_CAMERA_ZNEAR_ZFAR 15
# define ERROR_CAMERA_NEGATE_ZFAR 16
# define ERROR_OBJECT_NUMBER 17
# define ERROR_OBJECT_TYPE 18
# define ERROR_OBJECT_POS 19
# define ERROR_OBJECT_ROT 20
# define ERROR_OBJECT_COLOR 21
# define ERROR_OBJECT_NORMAL 22
# define ERROR_TRIANGLE_NUMBER 23
# define ERROR_TRIANGLE_VERTEX 24
# define ERROR_LIGHT_POS 25
# define ERROR_LIGHT_COLOR 26
# define ERROR_MATERIAL_AMBIENT 27
# define ERROR_MATERIAL_SPECULAR 28
# define ERROR_MATERIAL_SHININESS 29

void	rt_error(int erreur);
void	rt_error2(int erreur);
void	rt_error3(int erreur);

#endif
