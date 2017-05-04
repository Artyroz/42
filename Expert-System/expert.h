/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expert.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbert <jbert@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/07/21 18:19:31 by jbert             #+#    #+#             */
/*   Updated: 2015/09/16 17:46:10 by jbert            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPERT_H
# define EXPERT_H

typedef struct s_cond	t_cond;
typedef struct s_var	t_var;

struct					s_cond
{
	char			*cond;
	t_cond			*next;
	t_cond			*prev;
};

struct					s_var
{
	char			car;
	int				bin:2;
	t_var			*next;
	t_var			*prev;
};

#endif
