#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int	main(void)
{


/*
	printf("\n<< 'q', 'a', 0 >>, strncmp = %d, ft_strncmp = %d\n", strncmp("q", "a", 0), ft_strncmp("q", "a", 0));


	printf("\n<< 'Hello les genw', '', 3 >>, strnstr = %s, ft_strnstr = %s\n", strnstr("Hello les genw", "", 3), ft_strnstr("Hello les genw", "", 3));
	printf("\n<< 'Hello les genw', 'w', 1 >>, strnstr = %s, ft_strnstr = %s\n", strnstr("Hello les genw", "w", 14), ft_strnstr("Hello les genw", "w", 14));


	printf("\n<< Hello, 'H' >>, strchr = %s, ft_strchr = %s\n", strchr("Hello", 'H'), ft_strchr("Hello", 'H'));
	printf("\n<< Hello, 0 >>, strchr = %s, ft_strchr = %s\n", strchr("Hello", 0), ft_strchr("Hello", 0));

*/
	printf("\n<< 'Hello', '' >>, strstr = %s, ft_strstr = %s.\n", strstr("Hello", ""), ft_strstr("Hello", ""));
	printf("\n<< '', '' >>, strstr = %s, ft_strstr = %s.\n", strstr("", ""), ft_strstr("", ""));
	printf("\n<< 'gaaaaabcxxaabcdyy', 'aabcd' >>, strstr = %s, ft_strstr = %s.\n", strstr("gaaaaabcxxaabcdyy", "aabcd"), ft_strstr("gaaaaabcxxaabcdyy", "aabcd"));
//	printf("\n<< 'Bonjour', 'oj' >>, strstr = %s.\n", strstr("Bonjour", "oj"));
	printf("\n<< 'Bonjour', 'oj' >>, ft_strstr = %s.\n", ft_strstr("Bonjour", "oj"));
	printf("\n<< 'ozarabozaraboze', 'ozaraboze' >>, strstr = %s.\n", strstr("ozarabozaraboze", "ozaraboze"));
	printf("\n<< 'ozarabozaraboze', 'ozaraboze' >>, ft_strstr = %s.\n", ft_strstr("ozarabozaraboze", "ozaraboze"));

	printf("\n<< 'Ceci n'est pas une pipe.', 'une' >>, strstr = %s.\n", strstr("Ceci n'est pas une pipe.", "une"));
	printf("\n<< 'Ceci n'est pas une pipe.', 'une' >>, ft_strstr = %s.\n", ft_strstr("Ceci n'est pas une pipe.", "une"));

	printf("\n<< 'Ceci n'est pas une pipe.', '.' >>, strstr = %s.\n", strstr("Ceci n'est pas une pipe.", "."));
	printf("\n<< 'Ceci n'est pas une pipe.', '.' >>, ft_strstr = %s.\n", ft_strstr("Ceci n'est pas une pipe.", "."));

/*	
	printf("\n<< '', 'Hello' >>, strstr = %s, ft_strstr = %s.\n", strstr("", "Hello"), ft_strstr("", "Hello"));
	
*/
/*
	printf("\nft_strstr NULL sur haystack : %s", ft_strstr(NULL, "Hello"));
	printf("\nft_strstr NULL sur needle : %s", ft_strstr("Hello", NULL));


	printf("\nstrstr NULL sur haystack : %s", strstr(NULL, "Hello"));
	printf("\nstrstr NULL sur needle : %s", strstr("Hello", NULL));
	printf("\n<< NULL, 'Blah' >>, strstr = %s, ft_strstr = %s\n", strstr(NULL, "Blah"), ft_strstr(NULL, "Blah"));
	printf("\n<< 'Yop', NULL >>, strstr = %s, ft_strstr = %s\n", strstr("Yop", NULL), ft_strstr("Yop", NULL));
*/	
	/*	
	printf("\n << \n\v\t\r\f -123 >>, atoi: %d, ft_atoi: %d\n", atoi("\n\v\t\r\f -123"), ft_atoi("\n\v\t\r\f -123"));
	printf("\n << 12-3 >>, atoi: %d, ft_atoi: %d\n", atoi("12-3"), ft_atoi("12-3"));	
	printf("\n << -+123 >>, atoi: %d, ft_atoi: %d\n", atoi("-+123"), ft_atoi("-+123"));
	printf("\n << --123 >>, atoi: %d, ft_atoi: %d\n", atoi("--123"), ft_atoi("--123"));
	printf("\n << - 123 >>, atoi: %d, ft_atoi: %d\n", atoi("--123"), ft_atoi("--123"));	
	printf("\n << +123 >>, atoi: %d, ft_atoi: %d\n", atoi("+123"), ft_atoi("+123"));	
	printf("\n << -123 >>, atoi: %d, ft_atoi: %d\n", atoi("-123"), ft_atoi("-123"));
	printf("\n << a123 >>, atoi: %d, ft_atoi: %d\n", atoi("a123"), ft_atoi("a123"));
	printf("\n << 123a >>, atoi: %d, ft_atoi: %d\n", atoi("123a"), ft_atoi("123a"));	
	printf("\n << 059+0'8**8' >>, atoi: %d, ft_atoi: %d\n", atoi("059+0'8**8'"), ft_atoi("059+0'8**8'"));	
	printf("\n << //3253,-82, >>, atoi: %d, ft_atoi: %d\n", atoi("//3253,-82,"), ft_atoi("//3253,-83,"));
	printf("\n << ++165+3'2* >>, atoi: %d, ft_atoi: %d\n", atoi("++165+3'2*"), ft_atoi("++165+3'2*"));
	printf("\n << \n		 42 24 >>, atoi: %d, ft_atoi: %d\n", atoi("\n		42 24"), ft_atoi("\n		 42 24"));
	printf("\n << \200123 >>, atoi: %d, ft_atoi: %d\n", atoi("\200123"), ft_atoi("\200123"));
	printf("\n << 9223372036854775808 >>, atoi: %d, ft_atoi: %d\n", atoi("9223372036854775808"), ft_atoi("9223372036854775808"));
	printf("\n << 2147483647 >>, atoi: %d, ft_atoi: %d\n", atoi("2147483647"), ft_atoi("2147483647"));
	printf("\n << -2147483648 >>, atoi: %d, ft_atoi: %d\n", atoi("-2147483648"), ft_atoi("-2147483648"));
	printf("\n << 2947483649 >>, atoi: %d, ft_atoi: %d\n", atoi("2947483649"), ft_atoi("2947483649"));
	printf("\n << 94947483649 >>, atoi: %d, ft_atoi: %d\n", atoi("94947483649"), ft_atoi("94947483649"));
*/	
	/*
	int	c;

	c = -300;
	while (c < 300)
	{
		printf("c = %d, tolower = %d, ft_tolower = %d\n", c, tolower(c), ft_tolower(c));
		c++;
	}
	c = -300;
	while (c < 300)
	{
		printf("c = %d, isalpha = %d, ft_isalpha = %d\n", c, isalpha(c), ft_isalpha(c));
		c++;
	}
*/
	printf("\n");
	return (0);
}
