#!/bin/sh

make re
gcc -Wall -Werror -Wextra temptest.c libft.a -o temptest.out
./temptest.out
make fclean
