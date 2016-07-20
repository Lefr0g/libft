# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amulin <amulin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/06/10 17:35:06 by amulin            #+#    #+#              #
#    Updated: 2016/04/14 18:47:15 by amulin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# *************************** #
# OS detection (Linux / OSX)

OS_NAME = $(shell uname -s)

ifeq ($(OS_NAME),Linux)
	CC = clang
endif
ifeq ($(OS_NAME),Darwin)
	CC = clang
endif
# *************************** #

NAME = libftprintf.a

UIALIGN = \r\t\t

UICEPTION = \033[34m └─ ft_printf\033[0m$(UIALIGN)

UIWAIT = $(UIALIGN)[ \xE2\x8C\x9B ]

UIOK = $(UIALIGN)[\033[32m \xE2\x9C\x94 \033[0m]

UIINFO = $(UIALIGN)[\033[32m i \033[0m]

FLAGS = -Wall -Werror -Wextra

ifeq ($(CC),gcc)
	FLAGS += -std=c99
endif

PRINTHDRS = ft_printf.h

PRINTINCLUDIR = includes/

PRINTHEADERS = $(addprefix $(PRINTINCLUDIR), $(PRINTHDRS))

PRINTSRCS = ft_printf.c ftpf_init.c \
			ftpf_lenmods_signed.c ftpf_lenmods_unsigned.c \
			ftpf_lenmods_text.c ftpf_lenmods_xp.c \
			ftpf_flags.c ftpf_output_rules.c \
			ftpf_conversions_text.c ftpf_conversions_signed.c \
			ftpf_conversions_unsigned.c ftpf_conversions_bonus.c \
			ftpf_directives.c

PRINTSRCDIR = sources/

PRINTSOURCES = $(addprefix $(PRINTSRCDIR), $(PRINTSRCS))

PRINTOBJECTS = $(subst .c,.o, $(PRINTSRCS))

LIBFTHDRS = libft.h libft_extra.h

LIBFTINCLUDIR = ../includes/

LIBFTHEADERS = $(addprefix $(LIBFTINCLUDIR), $(LIBFTHDRS))

LIBFTSRCS_VA = ft_atoi.c ft_isdigit.c ft_itoa.c ft_putchar.c ft_putendl.c \
			ft_putendl_fd.c ft_putchar_fd.c \
			ft_putstr.c ft_putnbr.c ft_strcmp.c ft_strdup.c ft_strlen.c \
			ft_strnequ.c ft_strncmp.c \
			ft_isascii.c ft_isprint.c ft_strcpy.c ft_strnew.c ft_memalloc.c \
			ft_bzero.c ft_memset.c ft_strchr.c ft_strncpy.c ft_memmove.c \
			ft_memdel.c \
			ft_memcpy.c ft_isalpha.c ft_strdel.c \

LIBFTSRCS_XT = ft_uni_to_utf8.c ft_putwchar.c ft_putwstr.c ft_wstr_memsize.c \
			ft_wchar_utf8len.c ft_wstr_utf8len.c ft_wcslen.c ft_wcsncpy.c \
			ft_utf8ncpy.c \
			ft_getmax.c ft_itoa_ll.c ft_itoa_ull.c ft_putnbr_ll.c \
			ft_putnbr_ull.c ft_puthex_ull.c ft_putoctal.c \
			ft_abs.c ft_abs_ll.c ft_putbin.c \

LIBFTSRCS = $(LIBFTSRCS_VA) $(LIBFTSRCS_XT)

LIBFTSOURCES_VA = $(addprefix ../sources/vanilla/, $(LIBFTSRCS_VA))

LIBFTSOURCES_XT = $(addprefix ../sources/extra/, $(LIBFTSRCS_XT))

LIBFTSOURCES = $(LIBFTSOURCES_VA) $(LIBFTSOURCES_XT)

HEADERS = $(PRINTHEADERS) $(LIBFTHEADERS)

LIBFTOBJDIR = ../

LIBFTOBJECTS = $(addprefix $(LIBFTOBJDIR), $(subst .c,.o, $(LIBFTSRCS)))

SOURCES = $(PRINTSOURCES) $(LIBFTSOURCES)

OBJECTS = $(PRINTOBJECTS) $(LIBFTOBJECTS)

.PHONY: all, clean, fclean, re

all: $(NAME)

objects: $(OBJECTS)

$(NAME): $(LIBFTOBJECTS) $(PRINTOBJECTS)
	@printf "$(UICEPTION)$(UIWAIT) Generating library archive $(NAME)"
	@ar rcs $(NAME) $(OBJECTS)
	@printf " $(UIOK)\n"

$(PRINTOBJECTS): $(SOURCES) $(HEADERS) $(LIBFT)
	@printf "$(UICEPTION)$(UIWAIT) Creating objects for $(NAME)"
	@$(CC) -g $(FLAGS) -c $(PRINTSOURCES) -I $(PRINTINCLUDIR) -I $(LIBFTINCLUDIR)
	@printf " $(UIOK)\n"

$(LIBFTOBJECTS):
	@make -C .. extra

clean:
	@printf "$(UICEPTION)$(UIWAIT) Deleting objects for ft_printf"
	@rm -f $(OBJECTS)
	@printf " $(UIOK)\n"

fclean: clean
	@printf "$(UICEPTION)$(UIWAIT) Deleting $(NAME)"
	@rm -f $(NAME)
	@printf " $(UIOK)\n"

re: fclean all
