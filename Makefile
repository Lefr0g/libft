# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amulin <amulin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 16:56:12 by amulin            #+#    #+#              #
#    Updated: 2014/11/08 18:56:26 by amulin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAGS = -Wall -Werror -Wextra

SRCS = ft_putchar.c ft_putstr.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c \
	   ft_putnbr_fd.c ft_putendl.c ft_putendl_fd.c ft_strlen.c ft_strdup.c \
	   ft_strcpy.c ft_strncpy.c

OBJECTS = $(subst .c,.o,$(SRCS))

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

$(OBJECTS):
	gcc $(FLAGS) -c $(SRCS)

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
