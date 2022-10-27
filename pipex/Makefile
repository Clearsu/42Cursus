# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/27 20:40:49 by jincpark          #+#    #+#              #
#    Updated: 2022/10/28 01:33:21 by jincpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex

CC		= cc
FLAGS	= -Wall -Wextra -Werror -I .
DEBUG_OPT	= -g3 -fsanitize=address

ifeq ($(DEBUG_FLAG), 1)
FLAGS += $(DEBUG_OPT)
endif

SRCS	= main.c \
		  pipex.c \
		  parse.c \
		  free.c \
		  ft_printf.c \
		  ft_printf_utils_nbr.c \
		  ft_printf_utils_str.c \
		  format_char.c \
		  format_hexa.c \
		  format_nbr.c \
		  ft_split.c \
		  ft_strncmp.c \
		  get_next_line_bonus.c \
		  get_next_line_utils_bonus.c \
		  ft_error.c \
		  arg_check.c

OBJS	= $(SRCS:%.c=%.o)

%.o	:	%.c
	$(CC) $(FLAGS) -c $^ -o $@

$(NAME)	:	$(OBJS)
	$(CC) $(FLAGS) $^ -o $@

all	:	$(NAME)

clean	:
	rm -f $(OBJS)

fclean	:	clean
	rm -f $(NAME)

re	:	fclean all

debug:
	$(MAKE) DEBUG_FLAG=1 all
