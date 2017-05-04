/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpollet <dpollet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/10 19:34:13 by dpollet           #+#    #+#             */
/*   Updated: 2015/05/12 03:11:42 by dpollet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H

# define FT_SELECT_H
# define BUF *(unsigned int *)buf
# define F_BAS 4348699
# define F_HAUT 4283163
# define ESC 27
# define ESP 32
# define ENTRER 10
# define DEL 127
# define DEL2 2117294875
# define HOME 4741915
# define END 4610843
# define A 1
# define TAB 9

# include "libft.h"
# include <term.h>
# include <termios.h>
# include <signal.h>
# include <sys/ioctl.h>

typedef struct	s_lt
{
	struct s_lt		*nt;
	struct s_lt		*bf;
	char			*vl;
	int				s;
	int				sl;
	int				ln;
}				t_lt;

typedef struct	s_tr
{
	struct termios	tm;
	int				ln;
	int				col;
	int				lig;
	int				st;
}				t_tr;

void			f_deselect(t_lt *lt, t_tr *tr);
void			f_a(t_lt *lt, t_tr *tr);
void			f_tab(t_lt *lt, t_tr *tr);
void			analyse_touche(char **buf, t_tr *tr, t_lt **ax);
void			f_home(t_lt *lt);
void			f_end(t_lt *lt);
int				recup_ln(t_lt *lt, t_tr *tr);
void			ft_signal(void);
void			analyse(int a);
void			arret_forcer(void);
void			signal_cont(void);
void			signal_stop(void);
t_tr			*stock(t_tr *tr, int a);
t_lt			*stock_lt(t_lt *lt, int a);
void			aff(char *vl);
void			f_del(t_lt **ax, t_tr **tr);
void			affichage_element(t_lt *ax);
void			f_sel(t_lt **ax);
void			f_bas(t_lt **ax);
void			f_haut(t_lt **ax);
void			add_cir(t_lt **ax, char *vl);
void			aff_ls(t_lt *ax, t_tr *tr);
int				ft_putchar_spe(int c);
int				end_term(t_tr *tr);
int				init_term(t_tr *tr);
void			parse_agrv(t_lt **ax, char **av);
void			ft_select(t_tr *tr, t_lt **ax);
void			rediment(void);

#endif
