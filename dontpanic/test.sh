#!/bin/sh

echo "\033[32m\n>>> PHASE 1 - Verification Norme...\033[00m"
norminette *.c
echo "\033[32m\n>>> PHASE 2 - Makefile : make re...\033[00m"
sleep 1
make re
sleep 1
echo "\033[32m\n>>> PHASE 3 - Compilation du test...\033[00m"
sleep 1
gcc -Wall -Werror -Wextra test.c libft.a -o test.out
ls -l *.out
sleep 1
echo "\033[32m\n>>> PHASE 4 - Test...\033[00m"
sleep 1
./test.out
./test.out > /dev/null 2> error.log
sleep 1
echo "\033[32m\n>>> PHASE 5 - Test, sortie d'erreur...\n\033[00m"
sleep 1
cat error.log
echo "\033[32m\n\n>>> PHASE 6 - Suppression des fichiers...\n\033[00m"
make fclean
echo "\033[32m\n>>> SEQUENCE DE TEST TERMINEE\n\033[00m"
