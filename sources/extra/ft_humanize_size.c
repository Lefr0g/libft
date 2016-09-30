/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_humanize_size.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 16:33:20 by amulin            #+#    #+#             */
/*   Updated: 2016/07/28 15:35:51 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extra.h"

/*
** This function returns a malloced string containing the human-readable value
** of the size passed as parameter.
** NB: size off_t are int64
**	1024 (K)
**	1048576 (M)
**	1073741024 (G)
**	1099511627776 (T)
**	The maximum size unit managed is Terabyte
**	*
**	Notice : this implementation is not optimal and should be refactored.
*/

/*
** ex: 1042    1067
** 	   |	   |
** 	  1.0	  1.1
** ALGO
** 	- Obtenir rest = nbr % divider
** 	- Si len(rest) == len(nbr) - 2
** 		- Comparer chiffre suivant
** 			- Si > 5, retourner 1
** 			- Sinon, retourner 0
** 	- Sinon is len(rest) == len(nbr) - 1
** 		- Retourner rest / 10
** 	- Sinon
** 		- Retourner 0
*/

static int	get_first_rounded_digit(long nbr, long divider)
{
	long	rest;
	char	*reststr;
	char	*nbrstr;
	int		result;

	if (!divider)
		return (-1);
	nbrstr = ft_itoa_ll(nbr, 10);
	rest = nbr % divider;
	reststr = ft_itoa_ll(rest, 10);
	if (ft_strlen(reststr) == ft_strlen(nbrstr) - 1)
		result = rest / 10;
	else if (ft_strlen(reststr) == ft_strlen(nbrstr) - 2)
	{
		rest %= 10;
		if (rest / 10 >= 5)
			result = 1;
		else
			result = 0;
	}
	else
		result = 0;
	ft_strdel(&reststr);
	ft_strdel(&nbrstr);
	return (result);
}

/*
**	Subfunction for ft_humanize_size(), for norme compliance.
*/

static void	transform_size_into_str(off_t size, long divider,
		char *str, int i)
{
	static char	unit[5] = {'T', 'G', 'M', 'K', 'B'};
	char		*buf;

	buf = divider > 1 ? ft_itoa(size / divider) : ft_itoa_ll(size, 10);
	ft_strcpy(str, buf);
	ft_strdel(&buf);
	if (divider > 1 && ft_strlen(str) == 1)
	{
		ft_strlcat(str, ".", 100);
		buf = ft_itoa(get_first_rounded_digit((long)size, divider));
		ft_strncat(str, buf, 1);
		ft_strdel(&buf);
	}
	ft_strncat(str, &unit[i], 1);
}

char		*ft_humanize_size(off_t size)
{
	char		*str;
	long long	divider;
	int			i;

	i = 0;
	str = ft_strnew(100);
	divider = 1099511627776;
	while (divider > 0)
	{
		if (size / divider)
		{
			transform_size_into_str(size, divider, str, i);
			return (str);
		}
		divider >= 1 ? (divider /= 1024) : (void)divider;
		i++;
	}
	ft_strcpy(str, "0B");
	return (str);
}
