/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/06 14:29:50 by lvalenti          #+#    #+#             */
/*   Updated: 2016/11/14 18:56:14 by mabuchwa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libft.h"

void	rt_error(int erreur)
{
	if (erreur == ERROR_WINDOW_SIZE)
		ft_putstr_fd("Error on the window size.\n", 2);
	else if (erreur == ERROR_WINDOW_MLX)
		ft_putstr_fd("Error mlx_init.\n", 2);
	else if (erreur == ERROR_WINDOW_CREATE)
		ft_putstr_fd("Error create window.\n", 2);
	else if (erreur == ERROR_WINDOW_NOCREATE)
		ft_putstr_fd("Window not created.\n", 2);
	else if (erreur == ERROR_SDL_INIT)
		ft_putstr_fd("Size unallocated.\n", 2);
	else if (erreur == ERROR_CREATE_RENDERER)
		ft_putstr_fd("Image not created.\n", 2);
	else if (erreur == ERROR_IMAGE_DATA)
		ft_putstr_fd("Buffer of image not created.\n", 2);
	else if (erreur == ERROR_PARSER_MALLOC)
		ft_putstr_fd("Malloc error in parser\n", 2);
	else if (erreur == ERROR_BAD_FILE)
		ft_putstr_fd("Unvalid file\n", 2);
	else if (erreur == ERROR_RT_MALLOC)
		ft_putstr_fd("Malloc error in RT", 2);
	else if (erreur == ERROR_CAMERA_NULL)
		ft_putstr_fd("Error of the camera\n", 2);
	rt_error2(erreur);
	rt_error3(erreur);
}

void	rt_error2(int erreur)
{
	if (erreur == ERROR_CAMERA_POS_NULL)
		ft_putstr_fd("Error of the camera position\n", 2);
	else if (erreur == ERROR_CAMERA_ROT_NULL)
		ft_putstr_fd("Error of the camera rotation\n", 2);
	else if (erreur == ERROR_CAMERA_FOV)
		ft_putstr_fd("FOV of camera is negative\n", 2);
	else if (erreur == ERROR_CAMERA_ZNEAR_ZFAR)
		ft_putstr_fd("Zfar of camera is less than Znear of camera\n", 2);
	else if (erreur == ERROR_CAMERA_NEGATE_ZFAR)
		ft_putstr_fd("Zfar of camera is negative\n", 2);
	else if (erreur == ERROR_OBJECT_NUMBER)
		ft_putstr_fd("No objects\n", 2);
	else if (erreur == ERROR_OBJECT_TYPE)
		ft_putstr_fd("No valid objects\n", 2);
	else if (erreur == ERROR_OBJECT_POS)
		ft_putstr_fd("Error of the position of objects\n", 2);
	else if (erreur == ERROR_OBJECT_ROT)
		ft_putstr_fd("Error of rotating objects\n", 2);
	else if (erreur == ERROR_OBJECT_COLOR)
		ft_putstr_fd("Error of the color of objects\n", 2);
	else if (erreur == ERROR_OBJECT_NORMAL)
		ft_putstr_fd("Error of the plane normal\n", 2);
	else if (erreur == ERROR_TRIANGLE_NUMBER)
		ft_putstr_fd("No triangles\n", 2);
}

void	rt_error3(int erreur)
{
	if (erreur == ERROR_TRIANGLE_VERTEX)
		ft_putstr_fd("Error of the triangle vertex\n", 2);
	else if (erreur == ERROR_LIGHT_POS)
		ft_putstr_fd("Error of the position of lights\n", 2);
	else if (erreur == ERROR_LIGHT_COLOR)
		ft_putstr_fd("Error of the color of lights\n", 2);
	else if (erreur == ERROR_MATERIAL_AMBIENT)
		ft_putstr_fd("Error ambient light\n", 2);
	else if (erreur == ERROR_MATERIAL_SPECULAR)
		ft_putstr_fd("Error specular light\n", 2);
	else if (erreur == ERROR_MATERIAL_SHININESS)
		ft_putstr_fd("Error shine light\n", 2);
}
