# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amulin <amulin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 16:56:12 by amulin            #+#    #+#              #
#    Updated: 2016/04/06 17:26:00 by amulin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# OS detection (Linux / OSX)
#
OS_NAME = $(shell uname -s)
ifeq ($(OS_NAME),Linux)
	CC = gcc
endif
ifeq ($(OS_NAME),Darwin)
	CC = clang
endif


NAME = libft.a

UIALIGN = \r\t\t

UICEPTION = \033[34m└─ libft\033[0m$(UIALIGN)

UIWAIT = $(UIALIGN)[ \xE2\x8C\x9B ]

UIOK = $(UIALIGN)[\033[32m \xE2\x9C\x94 \033[0m]

UIINFO = $(UIALIGN)[\033[36m i \033[0m]

FLAGS = -Wall -Werror -Wextra

SRCS = ft_putchar.c ft_putstr.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c \
	   ft_putnbr_fd.c ft_putendl.c ft_putendl_fd.c ft_strlen.c ft_strdup.c \
	   ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c \
	   ft_strchr.c ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c \
	   ft_strncmp.c ft_atoi.c ft_strnew.c ft_strdel.c ft_strclr.c ft_itoa.c\
	   ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
	   ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c \
	   ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
	   ft_memchr.c ft_memcmp.c ft_memalloc.c ft_memdel.c \
	   ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	   ft_toupper.c ft_tolower.c \
	   ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstiter.c ft_lstappend.c \
	   ft_lstmap.c ft_lstadd.c \
	   get_next_line.c \
	   ft_abs.c ft_abs_ll.c ft_tabmax.c ft_tabmin.c ft_getmax.c \
	   ft_print_memory.c \
	   ft_endian_swap.c \
	   ft_uni_to_utf8.c ft_putwchar.c ft_putwstr.c ft_wstr_memsize.c \
	   ft_wchar_utf8len.c ft_wstr_utf8len.c ft_wcslen.c ft_wcsncpy.c \
	   ft_utf8ncpy.c \
	   ft_itoa_ll.c ft_itoa_ull.c ft_putnbr_ll.c ft_putnbr_ull.c \
	   ft_puthex.c ft_puthex_ull.c ft_putoctal.c ft_putbin.c \
	   ft_hexchartoi.c ft_hexbytetoi.c ft_ishexa.c

LFTHEADER = libft.h

INCLUDIR = includes/

INCLUDES = $(addprefix $(INCLUDIR),$(LFTHEADER))

OBJECTS = $(subst .c,.o,$(SRCS))


FTPF_DIR = ft_printf/

FTPF_HEADER = $(addprefix $(FTPF_DIR), includes/ft_printf.h)

FTPF_SRC = ft_printf.c ftpf_init.c \
		   ftpf_lenmods_signed.c ftpf_lenmods_unsigned.c \
		   ftpf_lenmods_text.c ftpf_lenmods_xp.c \
		   ftpf_flags.c ftpf_output_rules.c \
		   ftpf_conversions_text.c ftpf_conversions_signed.c \
		   ftpf_conversions_unsigned.c ftpf_conversions_bonus.c \
		   ftpf_directives.c

FTPF_OBJ = $(subst .c,.o,$(FTPF_SRC))

FTPF_SOURCES = $(addprefix sources/, $(FTPF_SRC))

FTPF_SOURCES_ORIG = $(addprefix $(FTPF_DIR), $(FTPF_SOURCES))

FTPF_OBJECTS = $(addprefix $(FTPF_DIR), $(FTPF_OBJ))

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME): $(OBJECTS) $(FTPF_OBJECTS)
	@printf "$(UICEPTION)$(UIWAIT) Generating library archive $(NAME)"
	@ar rcs $(NAME) $(OBJECTS) $(FTPF_OBJECTS)
	@printf " $(UIOK)\n"

$(OBJECTS): $(SRCS) $(INCLUDES)
	@printf "$(UICEPTION)$(UIWAIT) Creating objects for $(NAME)"
	@$(CC) $(FLAGS) -c $(SRCS) -I $(INCLUDIR)
	@printf " $(UIOK)\n"

$(FTPF_OBJECTS): $(FTPF_HEADER) $(FTPF_SOURCES_ORIG)
	@printf "$(UICEPTION)$(UIINFO) Calling ft_printf Makefile...\n"
	@make -C ft_printf objects

clean:
	@printf "$(UICEPTION)$(UIWAIT) Deleting objects for $(NAME)"
	@rm -f $(OBJECTS)
	@printf " $(UIOK)\n"
	@make -C ft_printf clean

fclean: clean
	@printf "$(UICEPTION)$(UIWAIT) Deleting $(NAME)"
	@rm -f $(NAME)
	@printf " $(UIOK)\n"

re: fclean all
