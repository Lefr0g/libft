/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabmin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amulin <amulin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 19:38:17 by amulin            #+#    #+#             */
/*   Updated: 2016/01/06 19:40:52 by amulin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tabmin(int *t, int siz)
{
	int	min;

	min = INT_MAX;
	while (siz--)
		if (min > t[siz])
			min = t[siz];
	return (min);
}