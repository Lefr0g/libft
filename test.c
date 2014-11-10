/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:02:20 by amulin            #+#    #+#             */
/*   Updated: 2014/11/08 19:04:03 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*src;
	char	*dst;
	size_t	len;

	src = (char*)malloc(sizeof(char) * 25);
	dst = (char*)malloc(sizeof(char) * 25);
	len = 3;
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
	printf("\n    ***** TEST 10 - ft_strdup.c (2) : *****\n");
	strcpy(src, "FeelsGoodMan Yeah!");
	printf("\nString to be copied : %s\n", src);
	printf("\nCopied string : %s\n", ft_strdup(src));
	printf("\n    ***** TEST 11 - ft_strcpy.c (2) : *****\n");
	strcpy(src, "Let's get drunk");
	printf("\nString to be copied : %s\n", src);
	dst = ft_strcpy(dst, src);
	printf("\nCopied string : %s\n", dst);
	printf("\n    ***** TEST 12 - ft_strncpy.c (2) : *****\n");
	strcpy(src, "I can eat pasta");
	printf("\nString to be copied : %s, on %zd characters only\n", src, len);
	dst = ft_strncpy(dst, src, len);
	printf("\nCopied string : %s\n", dst);
	printf("\n    ***** TEST 13 - ft_strcat.c (2) : *****\n");
	strcpy(src, "tyuiop");
	strcpy(dst, "azer");
	printf("\nsrc: %s will be copied at the end of dest:%s\n", src, dst);
	dst = ft_strcat(dst, src);
	printf("\nThe resulting dest string is : %s\n", dst);
	printf("\n    ***** TEST 14 - ft_strcat.c (3) : *****\n");
	strcpy(src, "This is a test, don't worry");
	strcpy(dst, "PeekaBoo Trololo");
	printf("\n%zd characters of src: << %s >> will be copied at the end of dest: << %s >>\n", len, src, dst);
	dst = ft_strncat(dst, src, len);
	printf("\nWith ft_strncat, the resulting dest string is : %s\n", dst);
	strcpy(src, "This is a test, don't worry");
	strcpy(dst, "PeekaBoo Trololo");
	dst = strncat(dst, src, len);
	printf("\nWith strncat, the resulting dest string is : %s\n", dst);
	printf("\n*********** TEST - FIN DU TEST ***********\n");
	return (0);
}
