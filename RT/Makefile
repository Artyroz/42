# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgallo <mgallo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/24 12:41:09 by lvalenti          #+#    #+#              #
#    Updated: 2016/11/16 00:17:35 by mgallo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RT
INC_DIR = includes
SRC_DIR = srcs
OBJ_DIR = obj

SRCS = $(shell find $(SRC_DIR) -name '*.c' -type f)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Arborescence de fichier
SRC_ALL_DIR = $(shell find $(SRC_DIR) -type d)
OBJ_ALL_DIR = $(SRC_ALL_DIR:$(SRC_DIR)%=$(OBJ_DIR)%)

IFLAGS = -I $(INC_DIR) -I ./libsdl/include
# FLAGS = -Wall -Werror -Wextra -O2 -O3

CC = gcc -g $(FLAGS)
LIBFLAGS = -L ./libsdl/lib -lSDL2
RM = /bin/rm -f

all: build $(NAME)

build :
	mkdir -p $(OBJ_ALL_DIR)

install:
	@./install_sdl.sh

$(NAME) : $(OBJS)
	@echo "Make Objects :\033[1;32m DONE !\033[m"
	$(CC) -o $@ $^ $(LIBFLAGS)
	@echo "Make $(NAME) :\033[1;32m DONE !\033[m"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -MMD $(IFLAGS) -o $@ -c $<

clean:
	$(RM) $(OBJS)
	@echo "Make clean :\033[1;31m DONE !\033[m"

fclean : clean
	$(RM) -rf $(OBJ_ALL_DIR)
	$(RM) $(NAME)
	@echo "Make fclean :\033[1;31m DONE !\033[m"

re: fclean all

.PHONY: all clean fclean re build install
