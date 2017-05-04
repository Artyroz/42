/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgallo <mgallo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:11:55 by lvalenti          #+#    #+#             */
/*   Updated: 2016/11/04 14:03:43 by mgallo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
char				*ft_dtoa(double n);
size_t				ft_strlen(const char *s);
void				ft_putendl(char const *s);
int					ft_atoi(const char *s);
char				*ft_strchr(const char *s, int c);
char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strdup(const char *s1);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strnew(size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strcat(char *s1, const char *s2);
void				ft_bzero(void *s, size_t n);
void				ft_strdel(char **as);
void				ft_putstr(const char *s);
void				ft_putnbr(int n);

#endif
