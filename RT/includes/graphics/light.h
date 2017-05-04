/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallo <mgallo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 13:27:03 by mgallo            #+#    #+#             */
/*   Updated: 2016/11/16 00:10:58 by mgallo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "material.h"
# include "maths/vec3.h"
# include "maths/camera.h"
# include "objects/objects.h"
# include "color.h"
# include "objects/objects.h"

# define LIGHT_TYPE_POINT 0
# define LIGHT_TYPE_DIR 1
# define LIGHT_TYPE_SPOT 2

typedef struct	s_light
{
	t_vec3		*pos;
	t_color		*color;
	float		attenuation;
	t_vec3		*dir;
	double		angle_max;
}				t_light;

t_light			*light_new(t_vec3 *p, t_color *c, float attenuation);
void			light_free(t_light **light);
int				light_type(t_light *light);
t_color			*light_color(t_objects *obj, t_light *light, t_ray *ray,
				t_material *mat);
t_color			*lights(void *window, t_ray *ray);
double			shadow(void *window, t_ray *ray, t_light *light, int object);
void			reflect_color(void *window, t_color *color, t_objects *obj,
				t_ray *ray);
t_color			*light_ambiant(t_objects *obj, t_light *li, t_material *mat);
t_color			*light_diffuse(t_objects *obj, t_light *li, double diffuse);
t_color			*light_specular(t_light *li, t_material *mat, double diffuse,
					t_vec3 *light_dir, t_ray *ray, t_vec3 *normal);
t_color			*ambiant_color(t_objects *obj, t_ray *ray, t_material *mat);
t_color			*spot_light(t_objects *obj, t_light *spot, t_ray *ray,
					t_vec3 *impact);
t_color 		*dir_light(t_objects *obj, t_light *dir_light);
#endif
