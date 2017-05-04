# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbert <jbert@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/21 04:09:22 by jbert             #+#    #+#              #
#    Updated: 2015/07/21 18:18:46 by jbert            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	expert

SRC	=	main.c gnl/get_next_line.c

OBJ	=	main.o ./get_next_line.o

$(NAME):
		@make all -C libftprintf/
		@gcc -c $(SRC) -Wall -Wextra -Werror -g3 -I ./
		@gcc -o $(NAME) -Wall -Wextra -Werror $(OBJ) libftprintf/libftprintf.a

all: $(NAME)

clean:
		@make clean -C libftprintf
		@rm -f $(OBJ)

fclean:
		@make fclean -C libftprintf
		@rm -f $(OBJ) $(NAME)

re : fclean all

.PHONY: NAME all clean re
