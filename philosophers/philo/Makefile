# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jincpark <jincpark@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 04:04:53 by jincpark          #+#    #+#              #
#    Updated: 2022/11/18 19:01:27 by jincpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= philo

CC 				= cc
FLAGS 			= -Wall -Wextra -Werror -lpthread
DEBUG			= -fsanitize=address -g3

SRCS 			= philo.c

OBJS 			= $(SRCS:%.c=%.o)

ifdef IF_DEBUG
	FLAGS += $(DEBUG)
endif

%.o :	%.c
	$(CC) $(FLAGS) -c $^ -I. -o $@

$(NAME)	:	$(OBJS)
	$(CC) $(FLAGS) -I. $^ -o $@

all	:	$(NAME)

clean	:
	rm -f $(OBJS)

fclean	:	clean
	rm -f $(NAME)

re	:	fclean all

debug	:
	$(MAKE) IF_DEBUG=1 all

.PHONY	:	all clean fclean re debug
