/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 14:02:20 by amulin            #+#    #+#             */
/*   Updated: 2014/11/11 17:57:23 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int	main(void)
{
	int		i;
	int		indextest;
	char	*src;
	char	*dst;
	char	*haystack;
	char	*needle;
	char	*strstrresult;
	size_t	len;
	int		lower;
	int		upper;
	int		figure;
	int		symbol;
	int		*intStringMixed;
	char	*charStringMixed;

	i = 0;
	indextest = 0;
	src = (char*)malloc(sizeof(char) * 50);
	dst = (char*)malloc(sizeof(char) * 50);
	haystack = (char*)malloc(sizeof(char) * 50);
	needle = (char*)malloc(sizeof(char) * 50);
	strstrresult = (char*)malloc(sizeof(char) * 50);
	len = 3;
	lower = 'a';
	upper = 'Z';
	figure = '0';
	symbol = '?';
	intStringMixed = (int*)malloc(sizeof(int) * 42);
	charStringMixed = (char*)malloc(sizeof(char) * 42);
	strcpy(charStringMixed, "qwertyuiop-QWERTYUIOP-0123456789-!@#$%^&");

	while (charStringMixed[i] != '\0')
	{
		intStringMixed[i] = charStringMixed[i];
		i++;
	}
	intStringMixed[i] = charStringMixed[i];
	i = 0;
	printf("\n********** TEST - DEBUT DU TEST **********\n");
	printf("\n    ***** TEST %d - ft_putchar.c (2) : *****\n", indextest);
	ft_putchar('A');
	ft_putchar('\n');
	ft_putchar('1');
	ft_putchar('\n');
	indextest++;
	printf("\n    ***** TEST %d - ft_putstr.c (2) : *****\n", indextest);
	ft_putstr("Hello World! 1234567890 qwertyuiopasdfghjklzxcvbnm <>/#$ \n");
	ft_putstr("Looking good...\n");
	indextest++;
	printf("\n    ***** TEST %d - ft_putnbr.c (3) : *****\n", indextest);
	ft_putnbr(0);
	printf("\n");
	ft_putnbr(987654321);
	printf("\n");
	ft_putnbr(-987654321);
	printf("\n");
	indextest++;
	printf("\n    ***** TEST %d - ft_putendl.c (2) : *****\n", indextest);
	ft_putendl("This should be a line");
	ft_putendl("And this should be another line");
	indextest++;
	printf("\n    ***** TEST %d - ft_putchar_fd.c (2) : *****\n", indextest);
	ft_putchar_fd('1', 1);
	printf("\n");
	ft_putchar_fd('2', 2);
	printf("\n");
	indextest++;
	printf("\n    ***** TEST %d - ft_putstr_fd.c (3) : *****\n", indextest);
	ft_putstr_fd("Hello World! 1234567890\n", 1);
	ft_putstr_fd("Looking good...", 1);
	ft_putstr_fd("\nThis is an error, written on fd 2.\n", 2);
	indextest++;
	printf("\n    ***** TEST %d - ft_putnbr_fd.c (3) : *****\n", indextest);
	ft_putnbr_fd(0, 1);
	printf("\n");
	ft_putnbr_fd(987654321, 1);
	printf("\n");
	ft_putnbr_fd(-987654321, 2);
	printf("\n");
	indextest++;
	printf("\n    ***** TEST %d - ft_putendl_fd.c (2) : *****\n", indextest);
	ft_putendl_fd("This should be a line on the error output", 2);
	ft_putendl_fd("And this should be another line on the same output", 2);
	indextest++;
	printf("\n    ***** TEST %d - ft_strlen.c (2) : *****\n", indextest);
	printf("The char string is : Hello World!\n");
	printf("It is %zd character(s) long\n", ft_strlen("Hello World!"));
	indextest++;
	printf("\n    ***** TEST %d - ft_strdup.c (2) : *****\n", indextest);
	strcpy(src, "FeelsGoodMan Yeah!");
	printf("\nString to be copied : %s\n", src);
	printf("\nCopied string : %s\n", ft_strdup(src));
	indextest++;
	printf("\n    ***** TEST %d - ft_strcpy.c (2) : *****\n", indextest);
	strcpy(src, "Let's get drunk");
	printf("\nString to be copied : %s\n", src);
	dst = ft_strcpy(dst, src);
	printf("\nCopied string : %s\n", dst);
	indextest++;
	printf("\n    ***** TEST %d - ft_strncpy.c (4) : *****\n", indextest);
	strcpy(src, "I can eat pasta");
	printf("\nft_strncpy : String to be copied : << %s >>, on %zd characters only\n", src, len);
	dst = ft_strncpy(dst, src, len);
	printf("\nCopied string : %s\n", dst);
	strcpy(dst, "Let's get drunk");
	strcpy(src, "I can eat pasta");
	printf("\nstrncpy : String to be copied : << %s >>, on %zd characters only\n", src, len);
	dst = strncpy(dst, src, len);
	printf("\nCopied string : %s\n", dst);
	indextest++;
	printf("\n    ***** TEST %d - ft_strcat.c (2) : *****\n", indextest);
	strcpy(src, "tyuiop");
	strcpy(dst, "azer");
	printf("\nft_strcat : src: << %s >> will be copied at the end of dest: << %s >>\n", src, dst);
	dst = ft_strcat(dst, src);
	printf("\nThe resulting dest string is : << %s >>\n", dst);
	strcpy(src, "tyuiop");
	strcpy(dst, "azer");
	printf("\nstrcat : src: << %s >> will be copied at the end of dest: << %s >>\n", src, dst);
	dst = strcat(dst, src);
	printf("\nThe resulting dest string is : << %s >>\n", dst);
	indextest++;
	printf("\n    ***** TEST %d - ft_strncat.c (3) : *****\n", indextest);
	strcpy(src, "This is a test, don't worry");
	strcpy(dst, "PeekaBoo Trololo");
	printf("\n%zd characters of src: << %s >> will be copied at the end of dest: << %s >>\n", len, src, dst);
	dst = ft_strncat(dst, src, len);
	printf("\nWith ft_strncat, the resulting dest string is : << %s >>\n", dst);
	strcpy(src, "This is a test, don't worry");
	strcpy(dst, "PeekaBoo Trololo");
	dst = strncat(dst, src, len);
	printf("\nWith strncat, the resulting dest string is : << %s >>\n", dst);
	indextest++;
	printf("\n    ***** TEST %d - ft_strchr.c (4) : *****\n", indextest);
	i = 116;
	printf("\nft_strchr : Looking for << %c >> within << %s >>\n", i, src);
	printf("ft_strchr : Result:  << %s >>\n", ft_strchr(src, i));
	printf("\nstrchr : Looking for << %c >> within << %s >>\n", i, src);
	printf("strchr : Result:  << %s >>\n", strchr(src, i));
	indextest++;
	printf("\n    ***** TEST %d - ft_strrchr.c (4) : *****\n", indextest);
	i = 116;
	printf("\nft_strrchr : Looking for << %c >> within << %s >>\n", i, src);
	printf("ft_strrchr : Result:  << %s >>\n", ft_strrchr(src, i));
	printf("\nstrrchr : Looking for << %c >> within << %s >>\n", i, src);
	printf("strrchr : Result:  << %s >>\n", strrchr(src, i));
	indextest++;
	printf("\n    ***** TEST %d - ft_strstr.c (4) : *****\n", indextest);
	strcpy(haystack, "This is the haystack, follow the white rabbit");
	strcpy(needle, "the");
	printf("\nft_strstr : Looking for << %s >> within << %s >>\n", needle, haystack);
	strstrresult = ft_strstr(haystack, needle);
	printf("ft_strstr : Result : << %s >> at address << %p >>\n", strstrresult, strstrresult);
	printf("\nstrstr : Looking for << %s >> within << %s >>\n", needle, haystack);
	strstrresult = strstr(haystack, needle);
	printf("strstr : Result : << %s >> at address << %p >>\n", strstrresult, strstrresult);
	indextest++;	
	printf("\n    ***** TEST %d - ft_strnstr.c (4) : *****\n", indextest);
	strcpy(haystack, "This is the haystack, follow their white rabbit");
	strcpy(needle, "their");
	printf("\nft_strstr : Looking for << %s >> within << %s >> on << %zd >> character(s)\n", needle, haystack, len);
	strstrresult = ft_strnstr(haystack, needle, len);
	printf("ft_strstr : Result : << %s >> at address << %p >>\n", strstrresult, strstrresult);
//	printf("\nstrstr : Looking for << %s >> within << %s >> on << %zd >> character(s)\n", needle, haystack, len);
//	strstrresult = strnstr(haystack, needle, len);
//	printf("strstr : Result : << %s >> at address << %p >>\n", strstrresult, strstrresult);
	indextest++;
	printf("\n    ***** TEST %d - ft_strcmp.c (9) : *****\n", indextest);
	strcpy(haystack, "Reference string");
	strcpy(needle, "This is another string");
	printf("\nThe reference string is << %s >>, the secondary string is << %s >>\n", haystack, needle);
	printf("\nft_strcmp : result is %d\n", ft_strcmp(haystack, needle));
	printf("\nstrcmp : result is %d\n", strcmp(haystack, needle));
	strcpy(needle, "Reference a");
	printf("\nThe reference string is << %s >>, the secondary string is << %s >>\n", haystack, needle);
	printf("\nft_strcmp : result is %d\n", ft_strcmp(haystack, needle));
	printf("\nstrcmp : result is %d\n", strcmp(haystack, needle));
	strcpy(needle, "Reference string");
	printf("\nThe reference string is << %s >>, the secondary string is << %s >>\n", haystack, needle);
	printf("\nft_strcmp : result is %d\n", ft_strcmp(haystack, needle));
	printf("\nstrcmp : result is %d\n", strcmp(haystack, needle));
	indextest++;
	printf("\n    ***** TEST %d - ft_strncmp.c (9) : *****\n", indextest);
	strcpy(haystack, "Reference string");
	strcpy(needle, "This is another string");
	printf("\nThe reference string is << %s >>, the secondary string is << %s >>, comparison on << %zd >> bytes\n", haystack, needle, len);
	printf("\nft_strncmp : result is %d\n", ft_strncmp(haystack, needle, len));
	printf("\nstrncmp : result is %d\n", strncmp(haystack, needle, len));
	strcpy(needle, "Reference a");
	printf("\nThe reference string is << %s >>, the secondary string is << %s >>, comparison on << %zd >> bytes\n", haystack, needle, len);
	printf("\nft_strncmp : result is %d\n", ft_strncmp(haystack, needle, len));
	printf("\nstrncmp : result is %d\n", strncmp(haystack, needle, len));
	strcpy(needle, "Reaerence string");
	printf("\nThe reference string is << %s >>, the secondary string is << %s >>, comparison on << %zd >> bytes\n", haystack, needle, len);
	printf("\nft_strncmp : result is %d\n", ft_strncmp(haystack, needle, len));
	printf("\nstrncmp : result is %d\n", strncmp(haystack, needle, len));
	indextest++;
	printf("\n    ***** TEST %d - ft_isalpha.c (6) : *****\n", indextest);
	printf("\nChecking << %c >> with ft_isalpha : %d\n", lower, ft_isalpha(lower));
	printf("\nChecking << %c >> with isalpha : %d\n", lower, isalpha(lower));
	printf("\nChecking << %c >> with ft_isalpha : %d\n", upper, ft_isalpha(upper));
	printf("\nChecking << %c >> with isalpha : %d\n", upper, isalpha(upper));
	printf("\nChecking << %c >> with ft_isalpha : %d\n", figure, ft_isalpha(figure));
	printf("\nChecking << %c >> with isalpha : %d\n", figure, isalpha(figure));
	indextest++;
	printf("\n    ***** TEST %d - ft_isdigit.c (4) : *****\n", indextest);
	printf("\nChecking << %c >> with ft_isdigit : %d\n", lower, ft_isdigit(lower));
	printf("\nChecking << %c >> with isdigit : %d\n", lower, isdigit(lower));
	printf("\nChecking << %c >> with ft_isdigit : %d\n", figure, ft_isdigit(figure));
	printf("\nChecking << %c >> with isdigit : %d\n", figure, isdigit(figure));
	indextest++;
	printf("\n    ***** TEST %d - ft_isalnum.c (6) : *****\n", indextest);
	printf("\nChecking << %c >> with ft_isalnum : %d\n", lower, ft_isalnum(lower));
	printf("\nChecking << %c >> with isalnum : %d\n", lower, isalnum(lower));
	printf("\nChecking << %c >> with ft_isalnum : %d\n", figure, ft_isalnum(figure));
	printf("\nChecking << %c >> with isalnum : %d\n", figure, isalnum(figure));
	printf("\nChecking << %c >> with ft_isalnum : %d\n", symbol, ft_isalnum(symbol));
	printf("\nChecking << %c >> with isalnum : %d\n", symbol, isalnum(symbol));
	indextest++;
	printf("\n    ***** TEST %d - ft_isascii.c (6) : *****\n", indextest);
	printf("\nChecking << 0 (int) >> with ft_isascii : %d\n", ft_isascii(0));
	printf("\nChecking << 0 (int) >> with isascii : %d\n", isascii(0));
	printf("\nChecking << 127 (int) >> with ft_isascii : %d\n", ft_isascii(127));
	printf("\nChecking << 127 (int) >> with isascii : %d\n", isascii(127));
	printf("\nChecking << 128 (int) >> with ft_isascii : %d\n", ft_isascii(128));
	printf("\nChecking << 128 (int) >> with isascii : %d\n", isascii(128));
	indextest++;
	printf("\n    ***** TEST %d - ft_isprint.c (8) : *****\n", indextest);
	printf("\nChecking << 0 (int) >> with ft_isprint : %d\n", ft_isprint(0));
	printf("\nChecking << 0 (int) >> with isprint : %d\n", isprint(0));
	printf("\nChecking << 32 (int) >> with ft_isprint : %d\n", ft_isprint(32));
	printf("\nChecking << 32 (int) >> with isprint : %d\n", isprint(32));
	printf("\nChecking << 126 (int) >> with ft_isprint : %d\n", ft_isprint(126));
	printf("\nChecking << 126 (int) >> with isprint : %d\n", isprint(126));
	printf("\nChecking << 127 (int) >> with ft_isprint : %d\n", ft_isprint(127));
	printf("\nChecking << 127 (int) >> with isprint : %d\n", isprint(127));
	indextest++;
	printf("\n    ***** TEST %d - ft_toupper.c (2) : *****\n", indextest);
	printf("\nft_toupper Input : << ");
	while (intStringMixed[i] != '\0')
	{
		printf("%c", intStringMixed[i]);
		i++;
	}
	i = 0;
	printf(" >> Output : << ");
	while (intStringMixed[i] != '\0')
	{
		printf("%c", ft_toupper(intStringMixed[i]));
		i++;
	}
	i = 0;
	printf(" >>\n");
	printf("\ntoupper Input : << ");
	while (intStringMixed[i] != '\0')
	{
		printf("%c", intStringMixed[i]);
		i++;
	}
	i = 0;
	printf(" >> Output : << ");
	while (intStringMixed[i] != '\0')
	{
		printf("%c", toupper(intStringMixed[i]));
		i++;
	}
	i = 0;
	printf(" >>\n");
	indextest++;
	printf("\n    ***** TEST %d - ft_tolower.c (2) : *****\n", indextest);
	printf("\nft_tolower Input : << ");
	while (intStringMixed[i] != '\0')
	{
		printf("%c", intStringMixed[i]);
		i++;
	}
	i = 0;
	printf(" >> Output : << ");
	while (intStringMixed[i] != '\0')
	{
		printf("%c", ft_tolower(intStringMixed[i]));
		i++;
	}
	i = 0;
	printf(" >>\n");
	printf("\ntolower Input : << ");
	while (intStringMixed[i] != '\0')
	{
		printf("%c", intStringMixed[i]);
		i++;
	}
	i = 0;
	printf(" >> Output : << ");
	while (intStringMixed[i] != '\0')
	{
		printf("%c", tolower(intStringMixed[i]));
		i++;
	}
	i = 0;
	printf(" >>\n");
	indextest++;
	printf("\n*********** TEST - FIN DU TEST ***********\n");
	return (0);
}
