/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:02:20 by amulin            #+#    #+#             */
/*   Updated: 2014/11/08 16:43:13 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("\n********** TEST - DEBUT DU TEST **********\n");
	printf("\n    ***** TEST 1 - ft_putchar.c (2) : *****\n");
	ft_putchar('A');
	ft_putchar('\n');
	ft_putchar('1');
	ft_putchar('\n');
	printf("\n    ***** TEST 2 - ft_putstr.c (2) : *****\n");
	ft_putstr("Hello World! 1234567890 qwertyuiopasdfghjklzxcvbnm <>/#$ \n");
	ft_putstr("Looking good...\n");
	printf("\n    ***** TEST 3 - ft_putnbr.c (3) : *****\n");
	ft_putnbr(0);
	printf("\n");
	ft_putnbr(987654321);
	printf("\n");
	ft_putnbr(-987654321);
	printf("\n");
	printf("\n    ***** TEST 4 - ft_putendl.c (2) : *****\n");
	ft_putendl("This should be a line");
	ft_putendl("And this should be another line");
	printf("\n    ***** TEST 5 - ft_putchar_fd.c (2) : *****\n");
	ft_putchar_fd('1', 1);
	printf("\n");
	ft_putchar_fd('2', 2);
	printf("\n");
	printf("\n    ***** TEST 6 - ft_putstr_fd.c (3) : *****\n");
	ft_putstr_fd("Hello World! 1234567890\n", 1);
	ft_putstr_fd("Looking good...", 1);
	ft_putstr_fd("\nThis is an error, written on fd 2.\n", 2);	
	printf("\n    ***** TEST 7 - ft_putnbr_fd.c (3) : *****\n");
	ft_putnbr_fd(0, 1);
	printf("\n");
	ft_putnbr_fd(987654321, 1);
	printf("\n");
	ft_putnbr_fd(-987654321, 2);
	printf("\n");
	printf("\n    ***** TEST 8 - ft_putendl_fd.c (2) : *****\n");
	ft_putendl_fd("This should be a line on the error output", 2);
	ft_putendl_fd("And this should be another line on the same output", 2);
	printf("\n    ***** TEST 9 - ft_strlen.c (2) : *****\n");
	printf("The char string is : Hello World!\n");
	printf("It is %zd character(s) long\n", ft_strlen("Hello World!"));
	printf("\n*********** TEST - FIN DU TEST ***********\n");
	printf("\n    ***** TEST 10 - ft_strdup.c (2) : *****\n");
	printf("\nString to be copied : Brian is in the kitchen.\n");
	printf("\nCopied string : %s\n", ft_strdup("Brian is in the kitchen."));
	return (0);
}
