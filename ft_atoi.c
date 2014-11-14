/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 12:41:33 by amulin            #+#    #+#             */
/*   Updated: 2014/11/14 12:41:36 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
