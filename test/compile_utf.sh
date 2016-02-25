#!/bin/sh

make -C ..
gcc -Wall -Werror -Wextra ft_uni_to_utf8.c -L../ -lft
