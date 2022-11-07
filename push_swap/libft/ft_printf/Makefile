# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/29 15:18:35 by jincpark          #+#    #+#              #
#    Updated: 2022/11/04 16:50:56 by jincpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

FLAGS = -Wall -Wextra -Werror -I.

SRCS = ft_printf.c \
	   format_char.c \
	   format_hexa.c \
	   format_nbr.c \
	   ft_printf_utils_nbr.c \
	   ft_printf_utils_str.c

.o	:	$(SRCS)
	$(CC) $(FLAGS) -c $^

OBJS = $(SRCS:.c=.o)

$(NAME) :	$(OBJS)
		ar rc $(NAME) $(OBJS)

all	:	$(NAME)


clean	:
		rm -f $(OBJS)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
