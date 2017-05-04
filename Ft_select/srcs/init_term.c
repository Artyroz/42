/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_term.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpollet <dpollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/10 19:45:10 by dpollet           #+#    #+#             */
/*   Updated: 2015/05/12 03:18:47 by dpollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			init_term(t_tr *tr)
{
	char			*nt;

	nt = NULL;
	if ((nt = getenv("TERM")) < 0)
		return (0);
	if (tgetent(NULL, nt) < 1)
		return (0);
	if (tcgetattr(0, &(tr->tm)) == -1)
		return (0);
	tr->tm.c_lflag &= ~(ICANON);
	tr->tm.c_lflag &= ~(ECHO);
	tr->tm.c_cc[VMIN] = 1;
	tr->tm.c_cc[VTIME] = 0;
	tr->st = 0;
	if (tcsetattr(0, TCSADRAIN, &(tr->tm)) == -1)
		return (0);
	tputs(tgetstr("ti", NULL), 1, ft_putchar_spe);
	tputs(tgetstr("vi", NULL), 1, ft_putchar_spe);
	return (1);
}

int			end_term(t_tr *tr)
{
	if (tcgetattr(0, &(tr->tm)) == -1)
		return (0);
	tr->tm.c_lflag |= (ICANON | ECHO);
	if (tcsetattr(0, 0, &(tr->tm)) == -1)
		return (0);
	tputs(tgetstr("te", NULL), 1, ft_putchar_spe);
	tputs(tgetstr("ve", NULL), 1, ft_putchar_spe);
	return (1);
}

int			ft_putchar_spe(int c)
{
	return (write(2, &c, 1));
}
