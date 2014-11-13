//

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	result;
	int negflag;

	i = 0;
	result = 0;
	negflag = 1;
	if (nptr[i] == '-')
	{
		negflag = -1;
		i++;
	}
	while (nptr[i] != '\0')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (negflag * result);
}
