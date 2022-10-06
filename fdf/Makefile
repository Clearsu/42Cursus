# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/04 19:10:29 by jincpark          #+#    #+#              #
#    Updated: 2022/10/06 16:22:55 by jincpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
FLAGS = -I ./
MLX_DIR = ./minilibx
MLX_LIB = libmlx.dylib
LIBFT_DIR = ./libft
LIBFT_LIB = libft.a
LIB_FLAGS = -lmlx -L$(MLX_DIR) -framework OpenGL -framework Appkit
SRCS = windowtest.c
SRCS_DIR = ./sources
OBJS = windowtest.o

all	:	$(NAME)

$(SRCS_DIR)/$(OBJS)	:	$(SRCS)
	$(CC) $(FLAGS) -c $^

$(NAME)	:	$(OBJS)
	@make -C $(MLX_DIR)
	@cp $(MLX_DIR)/$(MLX_LIB) ./
	@make bonus -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/$(LIBFT_LIB) ./
	$(CC) $(FLAGS) $(LIB_FLAGS) $^ -o $@

clean	:
	@make clean -C $(MLX_DIR)
	@make fclean -C $(LIBFT_DIR)
	rm -f $(OBJS)

fclean	:	clean
	rm -f $(NAME)
	rm -f $(MLX_LIB)
	rm -f $(LIBFT_LIB)

re	:	fclean all
