/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft/ft_tabmax.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpoujade <lpoujade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 19:38:17 by lpoujade          #+#    #+#             */
/*   Updated: 2016/04/14 18:37:10 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_extra.h"

int		ft_tabmax(int *t, int siz)
{
	int	max;

	max = INT_MIN;
	while (siz--)
		if (max < t[siz])
			max = t[siz];
	return (max);
}
