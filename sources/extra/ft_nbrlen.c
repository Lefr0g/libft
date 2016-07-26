/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 18:27:55 by amulin            #+#    #+#             */
/*   Updated: 2016/07/26 18:28:36 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extra.h"

/*
**	This function is designed to act like the combination of ft_strlen on
**	ft_itoa, but without all the memory allocation and processing involved.
**	Its primary goal is to be fast and efficient.
** 	To be added to libft
*/

int		ft_nbrlen(int nbr)
{
	int	div;
	int res;
	int	minus;

	if (nbr < 0)
		minus = 1;
	else
		minus = 0;
	div = 1000000000;
	res = 10;
	while (div)
	{
		if (nbr / div)
			return (res + minus);
		div /= 10;
		res--;
	}
	return (0);
}
