# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/04 19:10:29 by jincpark          #+#    #+#              #
#    Updated: 2022/11/11 23:28:28 by jincpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= push_swap

CC 				= cc
FLAGS 			= -Wall -Wextra -Werror
DEBUG			= -fsanitize=address -g3

INC_DIR			= ./includes

LIBFT_DIR 		= ./libft
LIBFT_LIB 		= libft.a

SRCS_DIR		= ./sources
SRCS 			= push_swap.c stack.c parse.c error.c \
				  instructions1.c instructions2.c \
				  get_distance.c move_stack.c \
				  sort.c sort_small.c utils.c utils2.c get_distance.c

OBJS 			= $(SRCS:%.c=$(SRCS_DIR)/%.o)

ifeq ($(DEBUG_FLAG), 1)
	FLAGS += $(DEBUG)
endif

%.o :	%.c
	$(CC) $(FLAGS) -c $^ -I $(INC_DIR) -o $@

$(NAME)	:	$(OBJS)
	@make -C $(LIBFT_DIR)
	$(CC) $(FLAGS) -I $(INC_DIR) $(LIBFT_DIR)/$(LIBFT_LIB) $(LIB_FLAGS) $^ -o $@

all	:	$(NAME)

clean	:
	@make clean -C $(LIBFT_DIR)
	rm -f $(OBJS)

fclean	:	clean
	@rm -f $(LIBFT_DIR)/$(LIBFT_LIB)
	rm -f $(NAME)

re	:	fclean all

debug	:
	$(MAKE) DEBUG_FLAG=1 all

.PHONY	:	all clean fclean re debug
