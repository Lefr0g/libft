/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 14:57:44 by amulin            #+#    #+#             */
/*   Updated: 2016/02/25 21:47:31 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	manage_neg(char *out, int *negflag)
{
	int	i;

	i = 0;
	while (out[i])
	{
		(out[i] == '0') ? '1' : '0';
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

void		ft_putbin(int n)
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
