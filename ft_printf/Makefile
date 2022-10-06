# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/29 15:18:35 by jincpark          #+#    #+#              #
#    Updated: 2022/07/29 20:48:06 by jincpark         ###   ########.fr        #
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
		@make bonus -C libft
		@cp libft/libft.a .
		@mv libft.a $(NAME)
		ar rc $(NAME) $(OBJS)

all	:	$(NAME)


clean	:
		rm -f libft/*.o
		rm -f $(OBJS)

fclean	:	clean
		rm -f libft/libft.a
		rm -f $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
