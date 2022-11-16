# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/04 19:10:29 by jincpark          #+#    #+#              #
#    Updated: 2022/11/17 04:03:41 by jincpark         ###   ########.fr        #
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
MAN_OBJS		= $(MAN_SRC:%.c=$(SRCS_DIR)/%.o)
BNS_OBJS		= $(BNS_SRC:%.c=$(SRCS_DIR)/%.o)

ifdef IF_DEBUG
	FLAGS += $(DEBUG)
endif

ifdef IF_BONUS
	OBJS += $(BNS_OBJS)
	NAME = $(BNS_NAME)
else
	OBJS += $(MAN_OBJS)
endif

%.o :	%.c
	$(CC) $(FLAGS) -c $^ -I $(INC_DIR) -o $@

$(NAME)	:	$(OBJS)
	@make -C $(LIBFT_DIR)
	$(CC) $(FLAGS) -I $(INC_DIR) $(LIBFT_DIR)/$(LIBFT_LIB) $(LIB_FLAGS) $^ -o $@

all	:	$(NAME)

clean	:
	@make clean -C $(LIBFT_DIR)
	rm -f $(OBJS) $(MAN_OBJS) $(BNS_OBJS)

fclean	:	clean
	@make fclean -C $(LIBFT_DIR)
	rm -f $(NAME) $(BNS_NAME)

re	:	fclean all

bonus	:
	$(MAKE) IF_BONUS=1 all

debug	:
	$(MAKE) IF_DEBUG=1 all

debugbonus	:
	$(MAKE) IF_DEBUG=1 IF_BONUS=1 all

.PHONY	:	all clean fclean re bonus debug debugbonus
