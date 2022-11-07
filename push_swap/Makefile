# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/04 19:10:29 by jincpark          #+#    #+#              #
#    Updated: 2022/11/07 22:25:25 by jincpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= push_swap

CC 				= cc
FLAGS 			= -Wall -Wextra -Werror
DEBUG			= -fsanitize=address -g

INC_DIR			= ./includes

LIBFT_DIR 		= ./libft
LIBFT_LIB 		= libft.a

SRCS_DIR		= ./sources
SRCS 			=

OBJS 			= $(SRCS:%.c=$(SRCS_DIR)/%.o)


%.o :	%.c
	$(CC) $(FLAGS) -c $^ -I $(INC_DIR) -L $(LIBFT_LIB) -o $@

$(NAME)	:	$(OBJS)
	@make -C $(MLX_DIR)
	@cp $(MLX_DIR)/$(MLX_LIB) .
	@make bonus -C $(LIBFT_DIR)
	$(CC) $(FLAGS) -I $(INC_DIR) $(LIBFT_DIR)/$(LIBFT_LIB) $(LIB_FLAGS) $^ -o $@

all	:	$(NAME)

clean	:
	@make clean -C $(LIBFT_DIR)
	rm -f $(OBJS)

fclean	:	clean
	@rm -f $(LIBFT_DIR)/$(LIBFT_LIB)
	rm -f $(NAME)

re	:	fclean all
