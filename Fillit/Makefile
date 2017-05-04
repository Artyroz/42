# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qhusler <qhusler@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/11 19:46:55 by qhusler           #+#    #+#              #
#    Updated: 2016/05/13 03:40:57 by qhusler          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
CFLAG = -c -Wall -Werror -Wextra
HDR = -I./includes
LIBLINK = ./libft
RM = rm -f

SRC = main.c \
	  parseur.c \
	  init_tab_of_tet.c \
	  data_base.c \
	  solver.c \
	  bonus.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@make -C $(LIBLINK)
	@$(CC) $(CFLAG) $(SRC) $(HDR)
	@$(CC) $(OBJ) -o $(NAME) $(HDR) -L$(LIBLINK) -lft

clean:
	@make clean -C $(LIBLINK)
	@$(RM) $(OBJ)

fclean: clean
	@make fclean -C $(LIBLINK)
	@$(RM) $(NAME)

re: fclean all
	@make re -C $(LIBLINK)

norme:
	@echo "-----NORMINETTE-----"
	norminette -RCheckForbiddenSourceHeader ./*.c
	norminette -RCheckForbiddenSourceHeader ./includes/*.h

