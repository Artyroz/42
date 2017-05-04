/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpollet <dpollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 03:28:01 by dpollet           #+#    #+#             */
/*   Updated: 2015/05/12 02:59:44 by dpollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			signal_stop(void)
{
	t_tr			*tr;
	char			cp[2];

	tr = NULL;
	tr = stock(tr, 1);
	cp[0] = tr->tm.c_cc[VSUSP];
	cp[1] = 0;
	tr->tm.c_lflag |= (ICANON | ECHO);
	signal(SIGTSTP, SIG_DFL);
	tputs(tgetstr("cl", NULL), 1, ft_putchar_spe);
	tcsetattr(0, 0, &(tr->tm));
	tputs(tgetstr("te", NULL), 1, ft_putchar_spe);
	tputs(tgetstr("ve", NULL), 1, ft_putchar_spe);
	ioctl(0, TIOCSTI, cp);
}

void			signal_cont(void)
{
	t_tr			*tr;
	t_lt			*lt;

	tr = NULL;
	lt = NULL;
	tr = stock(tr, 1);
	lt = stock_lt(lt, 1);
	tr->tm.c_lflag &= ~(ICANON | ECHO);
	tr->tm.c_cc[VMIN] = 1;
	tr->tm.c_cc[VTIME] = 0;
	tcsetattr(0, 0, &(tr->tm));
	tputs(tgetstr("ti", NULL), 1, ft_putchar_spe);
	tputs(tgetstr("vi", NULL), 1, ft_putchar_spe);
	signal(SIGTSTP, analyse);
	aff_ls(lt, tr);
}

void			arret_forcer(void)
{
	t_tr			*tr;

	tr = NULL;
	tr = stock(tr, 1);
	end_term(tr);
	exit(0);
}

void			analyse(int a)
{
	if (a == SIGCONT)
		signal_cont();
	else if (a == SIGTSTP)
		signal_stop();
	else if (a == SIGWINCH)
		rediment();
	else
		arret_forcer();
}

void			ft_signal(void)
{
	int				a;

	a = 1;
	while (a < 32)
	{
		signal(a, analyse);
		a++;
	}
}
