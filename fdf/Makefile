# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/04 19:10:29 by jincpark          #+#    #+#              #
#    Updated: 2022/10/06 09:35:57 by jincpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
FLAGS =
MLX_DIR = ./minilibx
LIB = libmlx.dylib
LIB_FLAGS = -lmlx -L$(MLX_DIR) -framework OpenGL -framework Appkit
INC = -I$(MLX_DIR)
SRCS = $(SRCS_DIR)/windowtest.c
SRCS_DIR = ./srcs
OBJS = $(SRCS_DIR)/windowtest.o

all	:	$(NAME)

$(SRCS_DIR)/$(OBJS)	:	$(SRCS)
	$(CC) $(FLAGS) -c $^

$(NAME)	:	$(OBJS)
	make -C $(MLX_DIR)
	cp $(MLX_DIR)/$(LIB) .
	$(CC) $(FLAGS) $(LIB_FLAGS) $(INC) $^ -o $@

clean	:
	make clean -C $(MLX_DIR)
	rm -f $(OBJS)

fclean	:	clean
	rm -f $(NAME)
	rm -f $(LIB)

re	:	fclean all
