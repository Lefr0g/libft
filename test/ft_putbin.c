

/*
 * 			2.7 2.6 2.5 2.4 2.3 2.2 2.1 2.0
 * 7 -> 	0	0	0	0	0	1	1	1
 *
 * 7/2 = 3 r 1
 * 3/2 = 1 r 1
*/

#include "../includes/libft.h"

static void	manage_neg(char *out, int *negflag)
{
	int	i;

	i = 0;
	while (out[i])
	{
		(out[i] == '0') ? (out[i] = '1') : (out[i] = '0');
		i++;
	}
	i--;
	while (negflag && i >= 0)
	{
		if (out[i] == '0')
		{
			out[i] = '1';
			negflag = 0;
		}
		else
			out[i] = '0';
		i--;
	}
}

static void	fill_table(int *n, char *out)
{
	int	i;

	out[32] = '\0';
	i = 31;
	while (*n)
	{
		if (*n % 2)
			out[i] = '1';
		else
			out[i] = '0';
		*n = *n / 2;
		i--;
	}
	while (i >= 0)
	{
		out[i] = '0';
		i--;
	}
}

void	ft_putbin(int n)
{
	int		i;
	int		negflag;
	char	out[33];

	if (n < 0)
		negflag = 1;
	else
		negflag = 0;
	fill_table(&n, out);
	if (negflag)
		manage_neg(out, &negflag);

	i = 0;
	while (out[i])
	{
		if (!(i % 8))
			ft_putchar(' ');
		ft_putchar(out[i]);
		i++;
	}
}


/*
 *************************************************************************
*/
int		main(void)
{
	int	i;

	i = -42;
	while (i <= 42)
	{
		ft_putstr("i = ");
		ft_putnbr(i);
		ft_putchar('\t');
		ft_putbin(i);
		ft_putchar('\n');
		i++;
	}
	i = INT_MAX;
	{
		ft_putstr("i = ");
		ft_putnbr(i);
		ft_putchar('\t');
		ft_putbin(i);
		ft_putchar('\n');
		i++;
	}
	i = INT_MIN;
	{
		ft_putstr("i = ");
		ft_putnbr(i);
		ft_putchar('\t');
		ft_putbin(i);
		ft_putchar('\n');
		i++;
	}
	return (0);
}
