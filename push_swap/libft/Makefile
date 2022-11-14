# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jincpark <jincpark@student.42seoul.>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/16 11:08:32 by jincpark          #+#    #+#              #
#    Updated: 2022/11/14 17:22:28 by jincpark         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME					= libft.a

CC						= gcc

FLAGS					= -Wall -Wextra -Werror -I.

SRCS					= ft_atoi.c ft_atol.c ft_bzero.c ft_calloc.c \
					  ft_isalnum.c ft_isalpha.c ft_isascii.c \
					  ft_isdigit.c ft_isprint.c ft_itoa.c \
					  ft_memchr.c ft_memcmp.c ft_memcpy.c \
					  ft_memmove.c ft_memset.c ft_putchar_fd.c \
					  ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
					  ft_split.c ft_strchr.c ft_strdup.c \
					  ft_striteri.c ft_strjoin.c ft_strlcat.c \
					  ft_strlcpy.c ft_strlen.c ft_strmapi.c \
					  ft_strcmp.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
					  ft_strtrim.c ft_substr.c ft_tolower.c \
					  ft_toupper.c get_next_line.c \
					  ft_lstsize.c ft_lstadd_back.c ft_lstadd_front.c \
					  ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
					  ft_lstmap.c ft_lstnew.c

FT_PRINTF_DIR			= ft_printf
FT_PRINTF_AR			= libftprintf.a

%.o	:	%.c
	@$(CC) $(FLAGS) -c $^

OBJS		= $(SRCS:%.c=%.o)

$(NAME)		:	$(OBJS)
			@make -C $(FT_PRINTF_DIR) 
			@cp $(FT_PRINTF_DIR)/$(FT_PRINTF_AR) .
			@mv $(FT_PRINTF_AR) $(NAME)
			@ar rc $(NAME) $(OBJS)

all	:	$(NAME)

clean	:
		@make clean -C $(FT_PRINTF_DIR)
		@rm -f $(OBJS)

fclean	:	clean
		@rm -f $(FT_PRINTF_DIR)/$(FT_PRINTF_AR)
		@rm -f $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
