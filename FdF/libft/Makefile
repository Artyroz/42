# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpollet <dpollet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/16 06:37:41 by dpollet           #+#    #+#              #
#    Updated: 2015/04/29 16:50:30 by dpollet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re;

NAME = libft.a

SOURCE = ft_memccpy.c ft_putendl_fd.c ft_strdel.c ft_strncat.c ft_strtrim.c \
		ft_atoi.c ft_memchr.c ft_putnbr.c ft_strdup.c ft_strncmp.c \
		ft_tolower.c ft_bzero.c ft_memcmp.c ft_putnbr_fd.c ft_strequ.c \
		ft_strncpy.c ft_toupper.c ft_isalnum.c ft_memcpy.c ft_putstr.c \
		ft_striter.c ft_strnequ.c ft_isalpha.c ft_memdel.c ft_putstr_fd.c \
		ft_striteri.c ft_strnew.c ft_isascii.c ft_memmove.c ft_strcat.c \
		ft_strjoin.c ft_strnstr.c ft_isdigit.c ft_memset.c ft_strchr.c \
		ft_strlcat.c ft_strrchr.c ft_isprint.c ft_putchar.c ft_strclr.c \
		ft_strlen.c ft_strsplit.c ft_itoa.c ft_putchar_fd.c ft_strcmp.c \
		ft_strmap.c ft_strstr.c ft_memalloc.c ft_putendl.c ft_strcpy.c \
		ft_strmapi.c ft_strsub.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
		ft_lstadd.c ft_lstiter.c ft_lstmap.c get_next_line.c ft_arg.c \
		ft_minimum.c ft_maximum.c ft_intervertir.c ft_getnbr.c ft_strlenc.c \
		ft_pwd.c ft_efface_tab.c

OBJECTS = $(SOURCE:.c=.o)

all : $(NAME)

$(NAME) :
	gcc -Werror -Wextra -Wall -I ./includes -c $(SOURCE)
	ar rc $(NAME) $(OBJECTS)
	ranlib $(NAME)

clean :
	rm -rf $(OBJECTS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
