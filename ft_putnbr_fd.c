/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 16:46:20 by amulin            #+#    #+#             */
/*   Updated: 2014/11/05 16:51:51 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_putnbr_fd(int n, int fd)
{
	int i;
	int buf;

	i = 1;
	buf = n;
	if (n < 0)
	{
		n = -n;
		ft_putchar_fd('-', fd);
		buf = n;
	}
	while (buf > 9)
	{
		buf = buf / 10;
		i = i * 10;
	}
	while (i > 0)
	{
		ft_putchar_fd((n / i) + '0', fd);
		n = n % i;
		i = i / 10;
	}
}
