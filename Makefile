# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbach <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/13 20:17:05 by jbach             #+#    #+#              #
#    Updated: 2021/12/15 18:19:01 by jbach            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC=gcc

CFLAGS=-Wall -Wextra -Werror

RM=rm -f

SRCS = ft_printf.c\
fonctions_utils/ft_basic.c\
fonctions_utils/ft_dechex.c

FILES = $(SRCS:.c=.o)

INC = ./inc/

$(NAME): $(FILES)
	ar rc $(NAME) $(FILES)

%.o: %.c
	$(CC) -I. -o $@ -c $? $(CFLAGS)

all: $(NAME)

clean: 
	$(RM) $(FILES)

fclean: clean 
	$(RM) $(NAME)

re: fclean all
	
.PHONY: all clean fclean re
