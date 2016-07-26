# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amulin <amulin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/03 16:56:12 by amulin            #+#    #+#              #
#    Updated: 2016/07/26 18:30:51 by amulin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# README
# 
# Here are the different flavors available for the libft:
# 	- vanilla: standard libft, as specified in the 42 project
# 	- extra: extension of the features of the vanilla libtf, plus various handy
# 		functions
#	- ft_printf: vanilla libft + ft_printf function
#	- errno: functions requiring errno.h header
# 	- all: all of the above at once


############################## OS DETECTION FOR COMPILER SELECTION (Linux / OSX)

OS_NAME = $(shell uname -s)
ifeq ($(OS_NAME),Linux)
	CC = gcc
endif
ifeq ($(OS_NAME),Darwin)
	CC = clang
endif


################################################################## OUTPUTS NAMES

NAME = libft.a

FULL_NAME = libft_all.a

VA_NAME = libft_vanilla.a

XT_NAME = libft_extended.a

ER_NAME = libft_errmgmt.a

FTPF_NAME = libft_with_ftprintf.a


########################################################### USER INTERFACE STUFF

UIALIGN = \r\t\t

UICEPTION = \033[34m└─ libft\033[0m$(UIALIGN)

UIWAIT = $(UIALIGN)[ \xE2\x8C\x9B ]

UIOK = $(UIALIGN)[\033[32m \xE2\x9C\x94 \033[0m]

UIINFO = $(UIALIGN)[\033[36m i \033[0m]


############################################################### COMMON VARIABLES

FLAGS = -Wall -Werror -Wextra

ifeq ($(CC),gcc)
	FLAGS += -std=c99
endif

INCLUDIR = includes/

SRCDIR = sources/

OBJDIR = .objects/

################################################################## VANILLA LIBFT

VA_DIR = $(addprefix $(SRCDIR), vanilla/)

VA_SRCS = ft_putchar.c ft_putstr.c ft_putnbr.c ft_putchar_fd.c \
		  ft_putstr_fd.c ft_putnbr_fd.c ft_putendl.c ft_putendl_fd.c \
		  ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c \
		  ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c \
		  ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c \
		  ft_strnew.c ft_strdel.c ft_strclr.c ft_itoa.c \
		  ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
		  ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c \
		  ft_strtrim.c ft_strsplit.c \
		  ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
		  ft_memchr.c ft_memcmp.c ft_memalloc.c ft_memdel.c \
		  ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
		  ft_isprint.c ft_toupper.c ft_tolower.c \
		  ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstiter.c \
		  ft_lstappend.c ft_lstmap.c ft_lstadd.c

VA_SOURCES = $(addprefix $(VA_DIR), $(VA_SRCS))

VA_HEADER = libft.h

VA_INCLUDES = $(addprefix $(INCLUDIR),$(VA_HEADER))

VA_OBJECTS = $(subst .c,.o,$(VA_SRCS))


##################################################### EXTENSION OF VANILLA LIBFT

XT_DIR = $(addprefix $(SRCDIR), extra/)

XT_SRCS = get_next_line.c \
		  ft_abs.c ft_abs_ll.c ft_tabmax.c ft_tabmin.c ft_getmax.c ft_getmin.c \
		  ft_print_memory.c \
		  ft_endian_swap.c \
		  ft_uni_to_utf8.c ft_putwchar.c ft_putwstr.c ft_wstr_memsize.c \
		  ft_wchar_utf8len.c ft_wstr_utf8len.c ft_wcslen.c ft_wcsncpy.c \
		  ft_utf8ncpy.c \
		  ft_itoa_ll.c ft_itoa_ull.c ft_putnbr_ll.c ft_putnbr_ull.c \
		  ft_puthex.c ft_puthex_ull.c ft_putoctal.c ft_putbin.c \
		  ft_hexchartoi.c ft_hexbytetoi.c ft_ishexa.c \
		  ft_find_double_str.c ft_parse_options.c \
		  ft_parse_options_keep_doubles.c \
		  ft_strarray_dup.c ft_strarray_del.c \
		  ft_lstdetach.c ft_lstinsertright.c ft_lstsort.c ft_lstflip.c \
		  ft_humanize_size.c ft_nbrlen.c

XT_SOURCES = $(addprefix $(XT_DIR), $(XT_SRCS))

XT_HEADER = libft_extra.h

XT_INCLUDES = $(addprefix $(INCLUDIR),$(XT_HEADER))

XT_OBJECTS = $(subst .c,.o,$(XT_SRCS))


############################################################# FT_PRINTF SPECIFIC

FTPF_DIR = ft_printf/

FTPF_INCLUDES = $(addprefix $(FTPF_DIR), includes/ft_printf.h)

FTPF_SRCS = ft_printf.c ftpf_init.c \
			ftpf_lenmods_signed.c ftpf_lenmods_unsigned.c \
			ftpf_lenmods_text.c ftpf_lenmods_xp.c \
			ftpf_flags.c ftpf_output_rules.c \
			ftpf_conversions_text.c ftpf_conversions_signed.c \
			ftpf_conversions_unsigned.c ftpf_conversions_bonus.c \
			ftpf_directives.c

FTPF_OBJ = $(subst .c,.o,$(FTPF_SRCS))

FTPF_SOURCES = $(addprefix sources/, $(FTPF_SRC))

FTPF_SOURCES_ORIG = $(addprefix $(FTPF_DIR), $(FTPF_SOURCES))

FTPF_OBJECTS = $(addprefix $(FTPF_DIR), $(FTPF_OBJ))


######################################################## ERRNO-RELATED FUNCTIONS

ER_DIR = $(addprefix $(SRCDIR), errmgmt/)

ER_SRCS = ft_print_error.c

ER_SOURCES = $(addprefix $(ER_DIR), $(ER_SRCS))

ER_HEADER = errmgmt.h

ER_INCLUDES = $(addprefix $(INCLUDIR),$(ER_HEADER))

ER_OBJECTS = $(subst .c,.o,$(ER_SRCS))


################################################################# CONCATENATIONS

# $(FTPF_OBJECTS)

ALL_OBJECTS = $(VA_OBJECTS) $(XT_OBJECTS) $(ER_OBJECTS) $(FTPF_OBJECTS)

ALL_NAMES = $(NAME) $(FULL_NAME) $(VA_NAME) $(XT_NAME) $(FTPF_NAME) $(ER_NAME)


########################################################################## PHONY

.PHONY: all, clean, fclean, re, vanilla, extra, ft_printf, errno


######################################################### RULES (to be improved)

all: $(FULL_NAME)
	@ln -sf $(FULL_NAME) $(NAME)
	@printf "$(UICEPTION)$(UIINFO) All fine for full libft\n"

$(FULL_NAME): $(ALL_OBJECTS)
	@printf "$(UICEPTION)$(UIWAIT) Generating $(FULL_NAME) library archive"
	@ar rcs $(FULL_NAME) $(ALL_OBJECTS)
	@printf " $(UIOK)\n"

extra: $(XT_NAME)
	@ln -sf $(XT_NAME) $(NAME)
	@printf "$(UICEPTION)$(UIINFO) All fine for extended libft\n"
	
$(XT_NAME): $(VA_OBJECTS) $(XT_OBJECTS)
	@printf "$(UICEPTION)$(UIWAIT) Generating $(XT_NAME) library archive"
	@ar rcs $(XT_NAME) $(VA_OBJECTS) $(XT_OBJECTS)
	@printf " $(UIOK)\n"

$(XT_OBJECTS): $(XT_SOURCES) $(XT_INCLUDES)
	@printf "$(UICEPTION)$(UIWAIT) Creating objects for extended functions"
	@$(CC) $(FLAGS) -c $(XT_SOURCES) -I $(INCLUDIR)
	@printf " $(UIOK)\n"

ft_printf: $(FTPF_NAME)
	@ln -sf $(FTPF_NAME) $(NAME)
	@printf "$(UICEPTION)$(UIINFO) All fine for ft_printf-enriched libft\n"

$(FTPF_NAME): $(VA_OBJECTS) $(XT_OBJECTS) $(FTPF_OBJECTS)
	@printf "$(UICEPTION)$(UIWAIT) Generating $(FTPF_NAME) library archive"
	@ar rcs $(FTPF_NAME) $(VA_OBJECTS) $(XT_OBJECTS) $(FTPF_OBJECTS)
	@printf " $(UIOK)\n"

$(FTPF_OBJECTS): $(FTPF_SOURCES_ORIG) $(FTPF_INCLUDES)
	@printf "$(UICEPTION)$(UIINFO) Calling ft_printf Makefile...\n"
	@make -C ft_printf objects

errno: $(ER_NAME)
	@ln -sf $(ER_NAME) $(NAME)
	@printf "$(UICEPTION)$(UIINFO) All fine for errno libft\n"

$(ER_NAME): $(VA_OBJECTS) $(ER_OBJECTS)
	@printf "$(UICEPTION)$(UIWAIT) Generating $(ER_NAME) library archive"
	@ar rcs $(ER_NAME) $(VA_OBJECTS) $(ER_OBJECTS)
	@printf " $(UIOK)\n"

$(ER_OBJECTS): $(ER_SOURCES) $(ER_INCLUDES)
	@printf "$(UICEPTION)$(UIWAIT) Creating objects for errno-related functions"
	@$(CC) $(FLAGS) -c $(ER_SOURCES) -I $(INCLUDIR)
	@printf " $(UIOK)\n"

vanilla: $(VA_NAME)
	@ln -sf $(VA_NAME) $(NAME)
	@printf "$(UICEPTION)$(UIINFO) All fine for vanilla libft\n"

$(VA_NAME): $(VA_OBJECTS)
	@printf "$(UICEPTION)$(UIWAIT) Generating $(VA_NAME) library archive"
	@ar rcs $(VA_NAME) $(VA_OBJECTS)
	@printf " $(UIOK)\n"

$(VA_OBJECTS): $(VA_SOURCES) $(VA_INCLUDES)
	@printf "$(UICEPTION)$(UIWAIT) Creating objects for vanilla functions"
	@$(CC) $(FLAGS) -c $(VA_SOURCES) -I $(INCLUDIR)
	@printf " $(UIOK)\n"


################################################################################

clean:
	@printf "$(UICEPTION)$(UIWAIT) Deleting objects for $(NAME)"
	@rm -f $(ALL_OBJECTS)
	@printf " $(UIOK)\n"
	@make -C ft_printf clean

fclean: clean
	@printf "$(UICEPTION)$(UIWAIT) Deleting $(NAME)"
	@rm -f $(ALL_NAMES)
	@printf " $(UIOK)\n"

re: fclean all
