/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvalenti <lvalenti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 19:37:22 by mgallo            #+#    #+#             */
/*   Updated: 2016/10/18 11:23:22 by lvalenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_MATH_H
# define RT_MATH_H

# define ABS(n)			(n < 0 ? -n : n)
# define MAX(a,b)		((a) > (b) ? a : b)
# define MIN(a,b)		((a) < (b) ? a : b)
# define CLAMP(a,b,c)	((a < b) ? b : (a > c) ? c : a)

#endif
