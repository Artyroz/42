# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpollet <dpollet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/10 17:58:07 by dpollet           #+#    #+#              #
#    Updated: 2016/08/26 11:06:54 by Artyroz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= ft_ls

DEBUG 		= no
ifeq ($(DEBUG),no)
    FLAGS	= -Wall -Werror -Wextra
else
    FLAGS	=-g3
endif
SRC 		=	ft_ls.c

OBJ 		= $(SRC:.c=.o)
INC 		= ft_ls.h
LIBFLAGS 	= -L./libft/ -lft
SRCDIR  	= ./srcs/
OBJDIR  	= ./obj/
INCDIRLIB	= ./libft/includes/
INCDIR		= ./includes/
SRCS    	= $(addprefix $(SRCDIR), $(SRC))
OBJS    	= $(addprefix $(OBJDIR), $(OBJ))

.SILENT:

all : 		$(NAME)

$(NAME) :
ifeq ($(DEBUG),yes)
		echo "\\033[1;31mDEBUG COMPILATION.. (no flags except -g)\\033[0;39m"
else
		echo "\\033[1;31mCompilation with -Wall -Wextra -Werror...\\033[0;39m"
endif
		echo "\\033[1;34mGenerating objects... Please wait.\\033[0;39m"
			Make -C libft/
			gcc $(FLAGS) -c $(SRCS) -I $(INCDIR) -I $(INCDIRLIB)
			echo "compiling $(NAME)..."
			mkdir -p $(OBJDIR)
			mv $(OBJ) $(OBJDIR)
			gcc $(FLAGS) -o $(NAME) $(OBJS) $(LIBFLAGS)
			echo "$(NAME) has been created !"

.PHONY: 	clean fclean re

clean :
			Make -C ./libft/ clean
			rm -rf $(OBJS)
			rm -rf $(OBJDIR)
			echo "objects files has been removed !"

fclean :	clean
			Make -C ./libft/ fclean
			rm -rf $(NAME)
			echo "$(NAME) has been removed !"

re		: 	fclean all

git :
			git add .
			echo "Enter Your Commit : "
			read root_path ; git commit -m "$$root_path"
			git push
