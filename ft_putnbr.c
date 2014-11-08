/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 11:30:24 by amulin            #+#    #+#             */
/*   Updated: 2014/11/05 13:48:39 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_putnbr(int n)
{
	int i;
	int buf;

	i = 1;
	buf = n;
	if (n < 0)
	{
		n = -n;
		ft_putchar('-');
		buf = n;
	}
	while (buf > 9)
	{
		buf = buf / 10;
		i = i * 10;
	}
	while (i > 0)
	{
		ft_putchar((n / i) + '0');
		n = n % i;
		i = i / 10;
	}
}
