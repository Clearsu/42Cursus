# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/04 19:10:29 by jincpark          #+#    #+#              #
#    Updated: 2022/11/14 18:00:36 by jincpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= push_swap
BNS_NAME		= checker

CC 				= cc
FLAGS 			= -Wall -Wextra -Werror
DEBUG			= -fsanitize=address -g3

INC_DIR			= ./includes

LIBFT_DIR 		= ./libft
LIBFT_LIB 		= libft.a

SRCS_DIR		= ./sources
SRCS 			= stack.c parse.c error.c \
				  operations1.c operations2.c\
				  get_distance.c move_stack.c \
				  sort.c sort_small.c sort_3_4_5.c \
				  get_distance.c \
				  info.c \
				  utils.c utils2.c

MAN_SRC			= push_swap.c
BNS_SRC			= push_swap_bonus.c

OBJS 			= $(SRCS:%.c=$(SRCS_DIR)/%.o)

ifeq ($(DEBUG_FLAG), 1)
	FLAGS += $(DEBUG)
endif

ifeq ($(BONUS_FLAG), 1)
	SRCS += $(BNS_SRC)
	NAME = $(BNS_NAME)
else
	SRCS += $(MAN_SRC)
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
	rm -f $(BNS_NAME)

re	:	fclean all

bonus	:
	$(MAKE) BONUS_FLAG=1 all

debug	:
	$(MAKE) DEBUG_FLAG=1 all

.PHONY	:	all clean fclean re bonus debug
