/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 12:41:33 by amulin            #+#    #+#             */
/*   Updated: 2014/11/19 14:03:20 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	int		result;
	char	negflag;
	char	started;

	i = 0;
	result = 0;
	negflag = 1;
	started = 0;
	while (nptr[i] != '\0')
	{
		if (nptr[i] == '-')
		{
			if (started == 0 && ft_isdigit(nptr[i + 1]))
				negflag = -1;
			else
				break ;
		}
		if (ft_isdigit(nptr[i]))
		{
			result = result * 10 + (nptr[i] - '0');
			started = 1;
		}
		if (!ft_isdigit(nptr[i + 1]) && started == 1)
			break ;
		if (nptr[i] == '+')
		{
			if (started == 0)
				started = 1;
			else if (started == 1)
				break ;
		}
		if (ft_isprint(nptr[i]) && !ft_isdigit(nptr[i]) &&
				nptr[i] != '-' && nptr[i] != ' ' && nptr[i] != '+')
			break ;
		i++;
	}
	return (negflag * result);
}
