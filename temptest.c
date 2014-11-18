#include "libft.h"
#include <stdio.h>
#include <ctype.h>

int	main(void)
{
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
	return (0);
}
